#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

int in1 = 3;
int in2 = 4;
int en1 = 5; //Connected to PWM pin
int fanSpeed;

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(en1, OUTPUT);

  digitalWrite(in1, HIGH); // Setting initial motor direction
  digitalWrite(in2, LOW);
}

void loop() {
  delay(2000);
  float temperature = dht.readTemperature();

  if (isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  
  if (temperature < 20){  // If temperature is below 20°C, turning off the fan
    fanSpeed = 0;
  }
  
  else{
    fanSpeed = map(temperature, 20, 50, 0, 255); // Mapping temperature 20–50°C to PWM range 0–255
    fanSpeed = constrain(fanSpeed, 0, 255);
  }

  analogWrite(en1, fanSpeed);

  Serial.print("Fan Speed (PWM): ");
  Serial.println(fanSpeed);
}
