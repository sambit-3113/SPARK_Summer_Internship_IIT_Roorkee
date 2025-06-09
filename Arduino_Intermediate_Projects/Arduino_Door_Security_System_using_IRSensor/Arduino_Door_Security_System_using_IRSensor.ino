byte buzzer = 11;
byte ir_sensor = 2;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(ir_sensor, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensor_state = digitalRead(ir_sensor);
  Serial.println(sensor_state);
  if (sensor_state == LOW){
    analogWrite(buzzer, 200);
    delay(110);
    analogWrite(buzzer, 100);
    delay(110);
  }

  else{
    digitalWrite(buzzer, HIGH);
    delay(110);
  }
}
