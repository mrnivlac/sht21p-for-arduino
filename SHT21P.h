/*
  SHT21P.h - Library for controlling
  and reading data from the SHT21P sensor.
  Created by Rupert Calvin Sievert, September 7, 2016
*/

#ifndef SHT21P_h
#define SHT21P_h

#include "Arduino.h"

class SHT21P {
  int pSDA, pSCL, pPWR;
  
  public:
    SHT21P(int pwr, int sda, int scl);
    float readTemp();
    float readRelHumidity();
    void begin();
    void stop();
};

#endif