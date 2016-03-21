
// LCD164.h

#ifndef LCD164_h
#define LCD164_h

#include "Arduino.h"

class LCD164 {
  public:
    LCD164(uint8_t data, uint8_t clk, uint8_t e);
    void init16x2();
    void sendbyte(uint8_t d, uint8_t which);
    void sendbyte_nowait(uint8_t d, uint8_t which);
    void putch(uint8_t ch);

  private:
    uint8_t _data_pin;  // also the RS signal
    uint8_t _clk_pin;
    uint8_t _e_pin;  
};

#endif

