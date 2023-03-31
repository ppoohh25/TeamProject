#include <LedControl.h>

#define DIN 11
#define CLK 13
#define CS 10

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

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}

void loop() {
  test();
}