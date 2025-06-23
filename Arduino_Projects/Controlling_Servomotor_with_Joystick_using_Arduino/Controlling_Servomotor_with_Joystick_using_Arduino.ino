#include<Servo.h>
int x_pin = A0;
Servo s1;
int pos = 90;
void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  s1.attach(3);
  s1.write(pos);//start with 90 deg
}

void loop() {
  int x_data = analogRead(A0);
  Serial.print("x_data:");
  Serial.println(x_data);
  if (x_data >= 550){
    if(pos <= 180){
      pos = pos + 10;
      s1.write(pos);
    }
  }
  else if (x_data <= 500){
    if(pos >= 0){
      pos = pos - 10;
      s1.write(pos);
    }
  }
}
