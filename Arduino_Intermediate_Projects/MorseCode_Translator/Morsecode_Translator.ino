int ledPin = 13;

char* letters[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",    // A-I
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",  // J-R
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."         // S-Z
};

char* numbers[] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....",
  "--...", "---..", "----."};

int dotDelay = 200;

void setup(){
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {               // put your main code here, to run repeatedly:
  char ch;
  if (Serial.available()) {               // is there anything to read from USB?
    char ch = Serial.read();              // read a single character

    if (ch >= 'a' && ch <= 'z') {
      flashSequence(letters[ch - 'a']);
    }
    else if (ch >= 'A' && ch <= 'Z') {
      flashSequence(letters[ch - 'A']);
    }
    else if (ch >= '0' && ch <= '9') {
      flashSequence(numbers[ch - '0']);
    }
    else if (ch == ' ') {
      delay(dotDelay * 4);                // space between words
    }
  }
}

void flashSequence(char* sequence) {
  int i = 0;
  while (sequence[i] != '\0') {           // loop through each symbol in Morse code
    flashDotOrDash(sequence[i]);
    i++;
  }
  delay(dotDelay * 3);                    // gap between letters
}

void flashDotOrDash(char dotOrDash) {
  digitalWrite(ledPin, HIGH);
  if (dotOrDash == '.') {
    delay(dotDelay);                      // dot = 1 unit
  } else {
    delay(dotDelay * 3);                  // dash = 3 units
  }
  digitalWrite(ledPin, LOW);
  delay(dotDelay);                        // gap between dots and dashes
}

