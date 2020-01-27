#include <cmath>
#include "Sinusoidal.h"

double sinusoidal(double time, double amplitude, double frequency, double phase, double offset)
{
  frequency *= 2 * 3.14;
  phase *= 3.14 / 180;
  return amplitude * sin(frequency * time + phase) + offset;
}