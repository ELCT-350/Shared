#include "SimulationBlock.h"
#include <stdexcept>

using namespace ELCT350;
using namespace std;

#pragma region Constructors
SimulationBlock::SimulationBlock(size_t numParameters)
               : _numParameters(numParameters),
                 _parameters(make_unique<double[]>(_numParameters))
{
}
#pragma endregion

#pragma region Modifiers
void SimulationBlock::setParameter(size_t parameterIndex, double parameter)
{
  if (parameterIndex >= _numParameters)
    throw out_of_range("Parameter index out of range");

  _parameters[parameterIndex] = parameter;
}
#pragma endregion

#pragma region Observers
double SimulationBlock::getParameter(size_t parameterIndex) const
{
  if (parameterIndex >= _numParameters)
    throw out_of_range("Parameter index out of range");

  return _parameters[parameterIndex];
}
#pragma endregion