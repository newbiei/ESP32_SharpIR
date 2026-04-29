#ifndef WERA_SharpIR_h
#define WERA_SharpIR_h

#include <Arduino.h>

class WERASharpIR {
  public:
    WERASharpIR(uint8_t pin);
    float readCM(); // hasil jarak dalam cm (integer)
    float readCMv2();
  private:
    uint8_t _pin;
    int medianRead(int samples);
};

#endif
