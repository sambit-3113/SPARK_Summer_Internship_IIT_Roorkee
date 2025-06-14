int x_pin = A0;
int y_pin = A1;
int sw_pin = 2;

void setup(){
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
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
}
