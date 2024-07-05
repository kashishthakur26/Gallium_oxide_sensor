#include "arduino.h"
#include "GA.h"

Gall::Gall(int connectedPinNo, float workingVoltage = 5.0, int samplingCount = 1000)
{
  port = connectedPinNo;
  v = workingVoltage;
  s = samplingCount;
}

float Gall::read()
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


float Gall::intensity(float read_mV) {
  float voltage = read_mV / 1024.0;
  float intensity = voltage / 0.3;
  return intensity;
}

float Gall::index(float read_mV) {
  float voltage = read_mV / 1024.0;
  float intensity = voltage / 0.3;
  int UV_index = intensity / 2.2;
  return UV_index;
}

float Gall::dose(float read_mV, int exposure_time) {
  float voltage = read_mV / 1024.0;
  float intensity = voltage / 0.3;
  int UV_dose = intensity * exposure_time;
  return UV_dose;
}

