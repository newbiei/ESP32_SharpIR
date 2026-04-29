#ifndef ESP32_SharpIR_h
#define ESP32_SharpIR_h

#include <Arduino.h>

class ESP32_SharpIR {
  public:
    WERASharpIR(uint8_t pin);
    float readCM(); // hasil jarak dalam cm (integer)
    float readCMv2();
  private:
    uint8_t _pin;
    int medianRead(int samples);
};

#endif
