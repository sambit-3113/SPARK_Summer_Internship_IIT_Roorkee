#include <Keypad.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);
Servo s1;

const int Actual_Pin_size = 4;
const int Password_size = (Actual_Pin_size + 1);
char password[Password_size] = "12AB"; //set password
char Entered_pin[Password_size];

const char no_of_rows =4;
const char no_of_columns = 4;
byte row_pins[] = {2,3,4,5};
byte column_pins[] = {6,7,8,9};
char key_array[no_of_rows][no_of_columns] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
Keypad k = Keypad(makeKeymap(key_array),row_pins,column_pins,no_of_rows,no_of_columns);

int Red = 12;
int Green = 13;
char key;
int i = 0;
int lock_status = 1; //initially locked

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.backlight();
  lcd.setBacklight(HIGH);

  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  digitalWrite(Red, HIGH);
  digitalWrite(Green, LOW);
  s1.attach(10);
  s1.write(0);

  lcd.setCursor(4,0);
  lcd.print("Welcome!");
  delay(2000);
  lcd.setCursor(1,0);
  lcd.print("Door: Locked");
  delay(2000);
  lcd.clear();
}

void loop() {
  if (lock_status == 1){ //Trigger unlock if door locked
    Unlock_activate();
  }

  if (lock_status == 0){ //Trigger lock if door unlocked
    lcd.setCursor(0,0);
    lcd.print("Enter * to lock:");

    key = k.getKey();
    if(key){
      //Serial.println(key);
      if (key == '*'){  //Use '' specifically "" 
        Lock_activate();
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Door Locked");
        delay(2000);
        lcd.clear();
        lock_status = 1;
      }
    } 
  }
}

void Unlock_activate(){
  lcd.setCursor(0,0);
  lcd.print("Enter Pin:");

  key = k.getKey();
  if(key){
    Entered_pin[i] = key;
    lcd.setCursor(i,1);
    lcd.print("*");
    i++;

    if(i == (Password_size - 1)){
      // Serial.println(Entered_pin);
      Entered_pin[i] = '\0';
      delay(1000);
      if(strcmp(Entered_pin,password)== 0){
        digitalWrite(Green, HIGH);
        digitalWrite(Red, LOW);
        s1.write(90);

        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Door: Unlocked");

        i = 0;
        delay(1000);
        lock_status = 0;
      }

      else{
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Wrong Pin");
        delay(2000);
        lcd.clear();
        i = 0;
        lock_status = 1; // Setting the lock to 1, calls the Unlock_function() in line 52
      }

    }
  }
}

void Lock_activate(){
  digitalWrite(Red, HIGH);
  digitalWrite(Green, LOW);
  s1.write(0);
  delay(1000);
}