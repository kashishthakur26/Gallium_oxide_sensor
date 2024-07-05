#include "arduino.h"
#include "GA.h"

Galliumoxide::Galliumoxide(int connectedPinNo, float workingVoltage = 5.0, int samplingCount = 1000)
{
  port = connectedPinNo;
  v = workingVoltage;
  s = samplingCount;
}

float Galliumoxide::read()
{
  float sum = 0;
  for(int i=0; i<s; i++) {
    float v = analogRead(port);
    sum = v + sum;
    delay(2);
  }
  float sensor_value_average = sum / s;
  float mV = sensor_value_average * v;
  return mV;
}



float Galliumoxide::index(float read_mV) {
  float voltage = read_mV / 1024.0;
  int uv_index = voltage / 0.1;
  return uv_index;
}

float Galliumoxide::intensity(float read_mV) {
  float voltage = read_mV / 1024.0;
  int intensity = voltage / 0.1;
  return intensity;
}