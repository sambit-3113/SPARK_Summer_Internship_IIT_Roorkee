//(Basic LED Blink Example)
const int ledPin = 13; // Pin where LED is connected

void setup() {
  pinMode(ledPin, OUTPUT); // Set the LED pin as output
}

void loop() {
  digitalWrite(ledPin, HIGH); // Turn the LED on
  delay(1000);                // Wait for 1 second
  digitalWrite(ledPin, LOW);  // Turn the LED off
  delay(1000);                // Wait for 1 second
}



