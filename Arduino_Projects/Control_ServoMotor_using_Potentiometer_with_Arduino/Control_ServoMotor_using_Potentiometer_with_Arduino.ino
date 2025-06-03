#include <Servo.h>
int pot = A0;
Servo s1;
int x;
int value;

void setup(){
	Serial.begin(9600);
  s1.attach(6);
  pinMode(A0, INPUT);
}

void loop(){
  x = analogRead(pot);
  value = map(x,0,1023,0,180);
  s1.write(value);  	
}