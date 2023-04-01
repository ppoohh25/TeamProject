#include<LedControl.h>

#define DIN 11
#define CLK 13
#define CS 10
#define BTN_1 2
#define BTN_2 3
#define LEDR 4
#define LEDG 5
#define LEDY 6

volatile bool pooh = false;
volatile bool mok = false;
volatile int present1 = 0;
volatile int present2 = 0;
const int debounce = 50;

LedControl lc = LedControl(DIN, CLK, CS, 0);

void wow() {
  if (millis() - present1 > debounce) {
    if (digitalRead(BTN_1) == LOW) {
      pooh = !pooh;
    }
    if (pooh == true) {
      digitalWrite(LEDR, HIGH);
    } else {
      digitalWrite(LEDR, LOW);
    }
    present1 = millis();
  }
}

void omg() {
  if (millis() - present2 > debounce) {
    if (digitalRead(BTN_2) == LOW) {
      mok = !mok;
    }
    if (mok == true) {
      digitalWrite(LEDG, HIGH);
    } else {
      digitalWrite(LEDG, LOW);
    }
    present2 = millis();
  }
}

void test() {
  byte t[8] = {
    B11111111,
    B11111111,
    B11111111,
    B11111111,
    B11111111,
    B11111111,
    B11111111,
    B11111111
  };
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, t[i]);
  }
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      lc.setLed(0, i, j, 0);
      delay(50);
    }
  }
}

void triangle() {
  byte a[8] = {
    B10000000,
    B11000000,
    B10100000,
    B10010000,
    B10001000,
    B10000100,
    B10000010,
    B11111111
  };

  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, a[i]);
  }
}

void n() {
  byte P[8] = {
    B11111100,
    B10000010,
    B10000010,
    B10000010,
    B11111100,
    B10000000,
    B10000000,
    B10000000
  };

  byte O[8] = {
    B00111100,
    B01000010,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B01000010,
    B00111100
  };

  byte H[8] = {
    B11000011,
    B11000011,
    B11000011,
    B11111111,
    B11111111,
    B11000011,
    B11000011,
    B11000011
  };

  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, P[i]);
  }
  delay(500);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, O[i]);
  }
  delay(150);
  lc.clearDisplay(0);
  delay(150);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, O[i]);
  }
  delay(500);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, H[i]);
  }
  delay(500);
}

void num() {
  //1070
  byte one[8] = {
    B00001000,
    B00011000,
    B00101000,
    B00001000,
    B00001000,
    B00001000,
    B00001000,
    B00011100
  };

  byte zero[8] = {
    B00111100,
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B00111100
  };

  byte seven[8] = {
    B11111111,
    B10000010,
    B00000100,
    B00111110,
    B00010000,
    B00100000,
    B01000000,
    B10000000
  };

  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, one[i]);
  }
  delay(500);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, zero[i]);
  }
  delay(500);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, seven[i]);
  }
  delay(500);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, zero[i]);
  }
  delay(500);
}

void yolo() {
  byte y[8] = {
    B11000111,
    B10001001,
    B00001001,
    B00001110,
    B01111110,
    B10011001,
    B10011001,
    B11100111

  };
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, y[i]);
  }
}

void extra() {
  byte F[8] = {
    B01111110,
    B01000000,
    B01000000,
    B01111000,
    B01000000,
    B01000000,
    B01000000,
    B01000000
  };
  byte U[8] = {
    B10000010,
    B10000010,
    B10000010,
    B10000010,
    B10000010,
    B10000010,
    B01000100,
    B00111000
  };
  byte L[8] = {
    B01000000,
    B01000000,
    B01000000,
    B01000000,
    B01000000,
    B01000000,
    B01000000,
    B01111110
  };
  byte E[8] {
    B01111110,
    B01000000,
    B01000000,
    B01000000,
    B01111110,
    B01000000,
    B01000000,
    B01111110
  };
  byte S[8] = {
    B00111111,
    B01000000,
    B10000000,
    B10000000,
    B01111110,
    B00000001,
    B00000001,
    B11111110
  };
  byte smile[8] = {
    B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100
  };
  byte sad[8] = {
    B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10011001,
    B10100101,
    B01000010,
    B00111100
  };
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, F[i]);
  }
  delay(800);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, U[i]);
  }
  delay(800);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, L[i]);
  }
  delay(800); for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, L[i]);
  }
  delay(800);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, smile[i]);
  }
  delay(800);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, E[i]);
  }
  delay(800);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, L[i]);
  }
  delay(800);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, S[i]);
  }
  delay(800); for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, E[i]);
  }
  delay(800);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, sad[i]);
  }
  delay(800);
}


void setup() {
  pinMode(BTN_1, INPUT_PULLUP);
  pinMode(BTN_2, INPUT_PULLUP);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDY, OUTPUT);
  digitalWrite(LEDR, LOW);
  digitalWrite(LEDG, LOW);
  digitalWrite(LEDY, LOW);

  attachInterrupt(digitalPinToInterrupt(BTN_1), wow, CHANGE);
  pinMode(BTN_2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BTN_2), omg, CHANGE);
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
  //test();

}

void loop() {
  int mode = 0;
  if (pooh == true && mok == true) {
    mode = 1;
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDG, LOW);
    delay(100);
    digitalWrite(LEDR,HIGH);
    digitalWrite(LEDG,HIGH);
    digitalWrite(LEDY, HIGH);
    delay(100);
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDY, LOW);
    delay(100);
    digitalWrite(LEDR,HIGH);
    digitalWrite(LEDG,HIGH);
    digitalWrite(LEDY, HIGH);
  }
  switch (mode) {
    case 0:
      triangle();
      delay(1000);
      n();
      delay(1000);
      num();
      delay(1000);
      yolo();
      delay(1000);
      break;
    case 1:
      extra();
      digitalWrite(LEDR, LOW);
      digitalWrite(LEDG, LOW);
      digitalWrite(LEDY, LOW);
      pooh = false;
      mok = false;
      break;
  }

}