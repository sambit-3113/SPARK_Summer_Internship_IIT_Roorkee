int ldr = A0;     // Now we use an analog pin
int led = 13;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  int lightLevel = analogRead(ldr); // Read analog voltage (0–1023)
  Serial.println(lightLevel);       // Debug: Print light level

  if (lightLevel < 500) {  // Threshold: darker -> light ON
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }

  delay(200);
}

