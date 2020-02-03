#pragma once

double sinusoidal(double time, double amplitude, double frequency, double phase, double offset);

namespace Leonard
{
  class Sinusoidal final
  {
  public:
    Sinusoidal(double amplitude, double frequency, double phase, double offset);

    double getValue(double time);
  private:
    double _amplitude;
    double _frequency;
    double _phase;
    double _offset;
  };
}