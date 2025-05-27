int ir = 3;
int led = 13;
int x;

void setup(){
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(ir, INPUT);
}

void loop(){
  x = digitalRead(ir);
  Serial.println(x);
  delay(1000);
  
  if (x==1){ // sensor deactivated when x==1
  	digitalWrite(led , HIGH);
    delay(300);
  }
  else{      // sensor activated when x==0
  	digitalWrite(led, LOW);
  }
}