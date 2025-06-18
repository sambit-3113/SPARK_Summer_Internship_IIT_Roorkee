#define VRx A0  // Joystick X-axis
#define VRy A1  // Joystick Y-axis
#define SW 2    // Joystick button switch

void setup() {
  Serial.begin(9600);
  
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); // Joystick button is LOW when pressed
}

void loop() {
  int xVal = analogRead(VRx);
  int yVal = analogRead(VRy);
  int swVal = digitalRead(SW);

  Serial.print("X: ");
  Serial.print(xVal);
  Serial.print("  Y: ");
  Serial.print(yVal);
  Serial.print("  SW: ");
  Serial.println(swVal == LOW ? "Pressed" : "Released");

  delay(200); // Refresh every 200ms
}
