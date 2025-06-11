#include <Keypad.h>
#include "SevSeg.h"

SevSeg S;
byte CommonPins[] = {}; // Not used for 1-digit display
byte SegPins[] = {10, 11, 12, 13, A0, A1, A2}; // a, b, c, d, e, f, g

const char number_of_rows = 4;
const char number_of_columns = 4;

char row_pins[number_of_rows] = {2, 3, 4, 5};
char column_pins[number_of_columns] = {6, 7, 8, 9};

char key_array[number_of_rows][number_of_columns] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

Keypad k = Keypad(makeKeymap(key_array), row_pins, column_pins, number_of_rows, number_of_columns);

void setup() {
  Serial.begin(9600);
  S.begin(COMMON_CATHODE, 1, CommonPins, SegPins, true); // true enables leading zero blanking
  S.setBrightness(90);

  // Segment pins are already handled by SevSeg, no need for pinMode()
}

void displayChar(char ch) {
  byte segments[1]; // for 1-digit display

  switch (ch) {
    case 'A': segments[0] = 0b01110111; break; // A
    case 'B':
    case 'b': segments[0] = 0b01111100; break; // b
    case 'C': segments[0] = 0b00111001; break; // C
    case 'D':
    case 'd': segments[0] = 0b01011110; break; // d
    case '*': segments[0] = 0b00000001; break; // just 'a' segment lit
    case '#': segments[0] = 0b01111111; break; // all segments ON (unique symbol)
    default:
      if (ch >= '0' && ch <= '9') {
        S.setNumber(ch - '0');
        return;
      } 
      else {
        return; // Do nothing for other keys
      }
  }

  S.setSegments(segments); // Manually display custom segment pattern
}

void loop() {
  char key_pressed = k.getKey();
  if (key_pressed) {
    Serial.print("Key: ");
    Serial.println(key_pressed);
    displayChar(key_pressed);
  delay(300);
  }
  S.refreshDisplay();
}
