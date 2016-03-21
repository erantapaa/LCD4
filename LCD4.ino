
#include "LCD164.h"
#include "my_util.h"

LCD164 lcd(12, 8, 13); // DATA, CLK, E

const int CAP1 = 2; // reed relay control line for CAP1

void init_counter1() {
  // Set up the clock for TCNT1 to be the T1 input (falling edge)
  TCCR1A = 0;
  TCCR1B = _BV(CS12) | _BV(CS11);
  TCNT1 = 0;
}

void stop_counter1() {
  TCCR1B = 0;
}

char buf[32];

void displayInt(uint16_t x) {
  toString(x, 5, buf);
  for (uint8_t i = 0; i < 5; ++i) {
    lcd.putch(buf[i]);
  }
}

void setup() {
  digitalWrite(CAP1, LOW);
  pinMode(CAP1, OUTPUT);
  lcd.init16x2(); delay(1);
  lcd.putch('H');
  lcd.putch('e');
  lcd.putch('l');
  lcd.putch('l');
  lcd.putch('o');
  delay(1000);
  digitalWrite(CAP1, HIGH);
}

void displayKHz(uint16_t x) {
  toString(x, 5, buf);
  lcd.putch(buf[0]);
  lcd.putch(buf[1]);
  lcd.putch(buf[2]);
  lcd.putch('.');
  lcd.putch(buf[3]);
  lcd.putch(buf[4]);
  lcd.putch(' ');
  lcd.putch('K');
  lcd.putch('H');
  lcd.putch('z');
}

int x = 0;

void loop() {
  init_counter1();
  delay(100);
  stop_counter1();
  lcd.sendbyte(2, 0);
  displayKHz(TCNT1);
}

void loop1() {
  delay(1000);
  lcd.sendbyte(2, 0);  // home cursor
  displayInt(x);
  x++;
}

