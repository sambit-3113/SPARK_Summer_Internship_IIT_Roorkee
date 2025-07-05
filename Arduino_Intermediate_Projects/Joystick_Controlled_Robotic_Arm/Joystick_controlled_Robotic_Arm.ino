#include<Servo.h>

int x_pin1 = A0;  //Joystick1 (X and Y axis) 
int y_pin1 = A1;

int x_pin2 = A2;  //Joystick2 (X axis)

int pos1, pos2, pos3 = 0; //Initialising all 3 servos with 0 degree

Servo s1;
Servo s2;
Servo s3;

void setup(){
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  
  s1.attach(3);          //Servo motor attached to pin 3
  s1.write(pos1);
  
  s2.attach(4);          //Servo motor attached to pin 4
  s2.write(pos2);
  
  s3.attach(5);          //Servo motor attached to pin 5
  s3.write(pos3);
}

void loop(){
  
  int x_data1 = analogRead(A0);  //Reading X and Y axis of joystick-1
  int y_data1 = analogRead(A1);

  int x_data2 = analogRead(A2);  //Reading X axis of joystick-2 
  
  Serial.print("x_data1:");
  Serial.print(x_data1);
  Serial.print("\t");
  Serial.print("y_data1:");
  Serial.print(y_data1);
  Serial.print("\t");
  Serial.print("x_data2:");
  Serial.print(x_data2);
  delay(20);

  //Servo 1 control with joystick-1
  if(x_data1 >= 550){
    if(pos1 <= 180){
      pos1 = pos1 + 3;
      s1.write(pos1);
    }
  }

  else if(x_data1 <= 450){
    if(pos1 >= 0){
      pos1 = pos1 - 3;
      s1.write(pos1);
    }
  }

  //Servo 2 control with joystick-1
  if(y_data1 >= 550){
    if(pos2 <= 180){
      pos2 = pos2 + 2;
      s2.write(pos2);
    }
  }

  else if(y_data1 <= 450){
    if(pos2 >= 0){
      pos2 = pos2 - 2;
      s2.write(pos2);
    }
  }

  //Servo 3 control with joystick-2
  if(x_data2 >= 550){
    if(pos3 <= 180){
      pos3 = pos3 + 3;
      s3.write(pos3);
    }
  }

  else if(x_data2 <= 450){
    if(pos3 >= 0){
      pos3 = pos3 - 3;
      s3.write(pos3);
    }
  }  
}
