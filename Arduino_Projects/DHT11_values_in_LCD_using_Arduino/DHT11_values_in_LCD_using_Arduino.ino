#include "DHT.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Change to 0x3F if needed
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();  // Turn on backlight
  lcd.setCursor(0, 0);
  lcd.print("Starting...");
  delay(1000);
  lcd.clear();
}

void loop() {
  delay(100);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");
    return;
  }

  Serial.print("Humidity: "); 
  Serial.println(h);
  Serial.print("Temperature: "); 
  Serial.println(t);

  lcd.setCursor(0, 0);
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print("%   ");

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print("C     ");

  delay(3000);
}
