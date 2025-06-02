#include "SevSeg.h"
SevSeg S;
byte CommonPins[] = {};
byte SegPins[] = {2,3,4,5,6,7,8}; 
int red = 9;
int yellow = 10;
int green = 11;

void setup() {
  S.begin(COMMON_CATHODE, 1, CommonPins, SegPins, 1);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  digitalWrite(red, HIGH); //it begins with red on
}

void loop() {
  for(int  i = 9; i>=0; i--){
    if(i <= 3){
      digitalWrite(yellow, HIGH);
      digitalWrite(red, LOW);
    }
    display(i); //displays number
  }

  digitalWrite(green , HIGH);
  digitalWrite(yellow, LOW);

  for(int  i = 9; i>=0; i--){
    if(i <= 3){
      digitalWrite(yellow, HIGH);
      digitalWrite(green, LOW);
    }
    display(i); //displays number
  }

  digitalWrite(red, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
}

void display(int num) {
  unsigned long start = millis();
  while (millis() - start < 1000) {
    S.setNumber(num);
    S.refreshDisplay();
  }
}