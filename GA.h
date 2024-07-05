#ifndef _GA_h
#define _GA_h
#include "arduino.h"

class Galliumoxide
{
  public:
    Galliumoxide(int connectedPinNo, float workingVoltage = 5.0, int samplingCount = 1000);
  public:
    float read();
    float index(float read_V);
  private:
    int port, s;
    float v;
};

#endif