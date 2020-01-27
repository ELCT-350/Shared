#pragma once

double sinusoidal(double time, double amplitude, double frequency, double phase, double offset);

namespace Leonard
{
  class Sinusoidal final
  {
  public:
    Sinusoidal(double amplitude, double frequency, double phase, double offset)
      : _amplitude(amplitude), _frequency(frequency * 2.0 * 3.14), _phase(phase * 3.14 / 180.0),
        _offset(offset)
    {
    }

    double getValue(double time)
    {
      return _amplitude * sin(_frequency * time + _phase) + _offset;
    }
  private:
    double _amplitude;
    double _frequency;
    double _phase;
    double _offset;
  };
}