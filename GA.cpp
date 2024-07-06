#include "arduino.h"
#include "GA.h"

Gall::Gall(int connectedPinNo, float workingVoltage, int samplingCount)
    : port(connectedPinNo), v(workingVoltage), s(samplingCount) {
    // Additional initialization if necessary
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
  float intensity = read_mV / 2383.0;
  return intensity;
}

float Gall::index(float read_mV) {
  float voltage = read_mV / 1024.0;
  float intensity = voltage / 0.3;
  int UV_index = intensity / 2.2;
  return UV_index;
}

float Gall::dose(float read_mV, int threshold) {
  float intensity = read_mV / 2383.0;
  float summ=0;
  while(1){
    summ = summ + intensity;
    if(summ >= threshold){
      break;
    }
    delay(1000);

  }
  return summ;
}

