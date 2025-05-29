int trig = 7;
int echo = 6;
int timeInmicro;
int distanceIncm;

void setup(){
  	Serial.begin(9600);
	pinMode(trig, OUTPUT);
  	pinMode(echo, INPUT);
}

void loop(){
	digitalWrite(trig, LOW);
  	delay(200);
  	digitalWrite(trig, HIGH);
  	delay(200);
  	digitalWrite(trig, LOW);//pulse generated
  
  	timeInmicro = pulseIn(echo, HIGH);
  	distanceIncm = timeInmicro/29/2;
  	Serial.println(timeInmicro);
}