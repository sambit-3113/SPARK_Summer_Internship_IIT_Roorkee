int ledPin = 13;
int durations[] = {200,200,200,500,500,500,200,200,200};

void setup() {
  pinMode(ledPin, OUTPUT); // put your setup code here, to run once:
}

void flash(int duration) {
  digitalWrite(ledPin, HIGH);
  delay(duration);
  digitalWrite(ledPin, LOW);
  delay(duration);
}

void loop() {                     // put your main code here, to run repeatedly:
  for (int i = 0; i<9; i++){
    flash(durations[i]);
  }

  delay(1000);                    // wait 1 second before we start
}
