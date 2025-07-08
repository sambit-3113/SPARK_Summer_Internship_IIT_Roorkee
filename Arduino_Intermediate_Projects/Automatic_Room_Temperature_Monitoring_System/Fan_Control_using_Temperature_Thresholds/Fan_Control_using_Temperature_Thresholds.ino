#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht (DHTPIN, DHTTYPE);

int in1 = 3;
int in2 = 4;
int en1 = 5;
int y;

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(en1,OUTPUT);
}

void loop() {
  delay(2000);
  float t = dht.readTemperature();
  //checking if senor is reading inputs
  if (isnan(t)){
    Serial.println("Failed to read from DHT");
    return;
  }

  if (t <= 28){
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    analogWrite(en1,0);
  }

  else if ((t > 28) && (t <= 30)){
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    analogWrite(en1,100);
  }

  else if (t > 30){
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    analogWrite(en1,255);
  }

