int s = 6;
int LED = 7;
intx;

void setup() {
  serial.begin(9600);
  pinMdoe(6,INPUT);
  pinMode(7,OUTPUT);
}

void loop() {
  x = digitalRead(s);
  serial.println(x);
  delay(1000);

  if (x == 0){
    digitalWrite(7, LOW);
  }

  else{
    digitalWrite(7,HIGH);
  }
}
