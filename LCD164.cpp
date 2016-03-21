
// LCD164.cpp

#include "LCD164.h"

LCD164::LCD164(uint8_t data, uint8_t clk, uint8_t e)
{
  _data_pin = data;
  _clk_pin = clk;
  _e_pin = e;
  pinMode(_data_pin, OUTPUT);
  pinMode(_clk_pin, OUTPUT);
  pinMode(_e_pin, OUTPUT);
  digitalWrite(_clk_pin, LOW);
  digitalWrite(_e_pin, LOW);
}

void LCD164::sendbyte_nowait(uint8_t d, uint8_t which) {
  for (uint8_t i = 0; i < 8; ++i) {
    digitalWrite(_data_pin, d & 0x80);
    digitalWrite(_clk_pin, HIGH);
    digitalWrite(_clk_pin, LOW);
    d = d << 1;
  }
  digitalWrite(_data_pin, which);  // set the RS signal
  digitalWrite(_e_pin, HIGH);
  delayMicroseconds(1);
  digitalWrite(_e_pin, LOW);
}

void LCD164::sendbyte(uint8_t d, uint8_t which) {
  sendbyte_nowait(d, which);
  delay(1);
}

void LCD164::putch(uint8_t ch) {
  sendbyte(ch, 1);
}

void LCD164::init16x2() {
  // initialize for 2x16
  sendbyte(0x38, 0);
  sendbyte(0x06, 0);
  sendbyte(0x0e, 0);
  sendbyte(0x01, 0);
}

