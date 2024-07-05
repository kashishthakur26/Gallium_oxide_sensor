#ifndef _GA_h
#define _GA_h
#include "arduino.h"

class Gall {
  public:
    Gall(int connectedPinNo, float workingVoltage = 5.0, int samplingCount = 1000);

    float read();
    float index(float read_mV);
    float dose(float read_mV, int exposure_ime);
    float intensity(float read_mV);

  private:
    int port, s;
    float v;
};

#endif // _GA_h
