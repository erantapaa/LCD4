
#include "Arduino.h"
#include "my_util.h"

uint8_t toString(uint16_t x, uint8_t len, char* s) {
  for (uint8_t i = 0; i < len; ++i) {
    s[i] = ' ';
  }
  s[len] = 0;
  uint8_t i = len-1;
  uint8_t j = 0;
  while (i >= 0 && x > 0) {
    j++;
    uint8_t d = x % 10;
    s[i] = '0' + d;
    x = x / 10;
    i--;
  }
  if (j == 0) {
    s[len-1] = '0';
    j = 1;
  }
  return j;  // number of digits
}
