//automatic street lamp control using LDR sensors
int ldr = 7;
int led = 13;
int x;
void setup() {
  Serial.begin(9600);
  pinMode(ldr, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  x = digitalRead(ldr);
  Serial.println(x);

  delay(200);

  if (x == 1){
    digitalWrite(led, LOW);
  }
  else{
    digitalWrite(led, HIGH);
  }
}
