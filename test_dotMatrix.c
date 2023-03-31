#include <LedControl.h>

#define DIN 11
#define CLK 13
#define CS 10
#define BTN_1 2
#define BTN_2 3
#define LEDR 4
#define LEDG 5
#define LEDY 6

volatile int present1 = 0;
volatile int present2 = 0;
const int debounce = 50;
volatile bool one = false;
volatile bool two = false;

LedControl lc = LedControl(DIN, CLK, CS, 0);

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

void wow() {
  if (millis() - present1 > debounce) {
    if (digitalRead(BTN_1) == LOW) {
      one = !one;
    }
    if (one == true) {
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
      two = !two;
    }
    if (two == true) {
      digitalWrite(LEDG, HIGH);
    } else {
      digitalWrite(LEDG, LOW);
    }
    present2 = millis();
  }
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
}

void loop() {
  test();
  digitalWrite(LEDY, HIGH);
  delay(500);
  digitalWrite(LEDY, LOW);
  delay(500);
  digitalWrite(LEDG, HIGH);
  delay(500);
  digitalWrite(LEDG, LOW);
  delay(500);
  digitalWrite(LEDR, HIGH);
  delay(500);
  digitalWrite(LEDR, LOW);
  delay(500);
}