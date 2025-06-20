int x_pin = A0; //Joystick X axis
int y_pin = A1; //Joystick y axis
int sw_pin = 2;
int led_F = 3;
int led_B = 5;
int led_R = 6;
int led_L = 9;

void setup(){
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT); 
}
void loop(){
  int x_data = analogRead(A0);
  int y_data = analogRead(A1);
  int sw_data = digitalRead(2);
  Serial.print("x_data:");
  Serial.print(x_data);
  Serial.print("\t");
  Serial.print("y_data:");
  Serial.print(y_data);
  Serial.print("\t");
  Serial.print("sw_data:");
  Serial.println(sw_data);
  delay(100);

  if(y_data <= 500){  //Forward LED
    int brightness_F = map(y_data, 500, 0, 0, 255);
    analogWrite(led_F, brightness_F);
  }

  else if(y_data >= 550){ //Backward LED
    int brightness_B = map(y_data, 550, 1022, 0, 255);
    analogWrite(led_B, brightness_B);
  }

  else if(x_data >= 550){  //Right LED
    int brightness_R = map(x_data, 550, 1022, 0, 255);
    analogWrite(led_R, brightness_R);
  }

  else if(x_data <= 500){  //Left LED
    int brightness_L = map(x_data, 500, 0, 0, 255);
    analogWrite(led_L, brightness_L);
  }

  else{
    digitalWrite(led_F, LOW);
    digitalWrite(led_B, LOW);
    digitalWrite(led_R, LOW);
    digitalWrite(led_L, LOW);
  }
}
