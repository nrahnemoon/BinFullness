#include "Arduino.h"
#include "IRSensor.h"
#include <SharpIR.h>

SharpIR sharp = SharpIR(A0, 20150);

IRSensor::IRSensor(int pin)
{
  sharp = SharpIR(pin, 20150);
}

int IRSensor::getBinFullness()
{
   return sharp.distance();
}
