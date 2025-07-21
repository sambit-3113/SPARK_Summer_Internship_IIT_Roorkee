#include <DHT.h>

// Pins
#define DHTPIN 13
#define DHTTYPE DHT11   
#define SOIL_PIN 34
#define RELAY_PIN 27   // Connect LED or relay IN pin

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);  // Initially off
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int soil = analogRead(SOIL_PIN);

  if (!isnan(temp) && !isnan(hum)) {
    // Send sensor data to Python
    Serial.print(temp);
    Serial.print(",");
    Serial.print(hum);
    Serial.print(",");
    Serial.println(soil);
  }

  // Wait for command from Python
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    if (command == "ON") {
      digitalWrite(RELAY_PIN, HIGH);
    } else if (command == "OFF") {
      digitalWrite(RELAY_PIN, LOW);
    }
  }

  delay(2000);
}