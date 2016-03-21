
#include "LCD164.h"
#include "util.h"

LCD164 lcd(12, 8, 13); // DATA, CLK, E

char buf[32];
void displayInt(uint16_t x) {
  toString(x, 5, buf);
  for (uint8_t i = 0; i < 5; ++i) {
    lcd.putch(buf[i]);
  }
}

void setup() {
  lcd.init16x2();
  lcd.putch('H');
  lcd.putch('e');
  lcd.putch('l');
  lcd.putch('l');
  lcd.putch('o');
  delay(1000);
}

int x = 0;

void loop() {
  delay(1000);
  lcd.sendbyte(2, 0);  // home cursor
  displayInt(x);
  x++;
}

