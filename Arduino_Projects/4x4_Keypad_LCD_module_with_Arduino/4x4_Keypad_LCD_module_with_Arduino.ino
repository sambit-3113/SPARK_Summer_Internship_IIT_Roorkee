#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int i;
const char number_of_rows = 4;
const char number_of_columns = 4;

char row_pins[number_of_rows] = {2,3,4,5};
char column_pins[number_of_columns] = {6,7,8,9};
char key_array[number_of_rows][number_of_columns]= {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

Keypad k = Keypad(makeKeymap(key_array),row_pins,column_pins,number_of_rows,number_of_columns);

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.backlight();
  lcd.setBacklight(HIGH);
}

void loop() {
  char key_pressed = k.getKey();
  if (key_pressed){
    Serial.println(key_pressed);
    lcd.setCursor(i,0);
    lcd.print(key_pressed);
    i = i+1;
  }
}
