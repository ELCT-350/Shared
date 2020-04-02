#include "Signal/SignalBlock.h"
#include <stdexcept>

using namespace ELCT350::Signal;
using namespace std;

#pragma region Constructors
SignalBlock::SignalBlock(size_t numInputPorts, size_t numOutputPorts)
           : _numInputPorts(numInputPorts), _numOutputPorts(numOutputPorts),
             _inputPorts(make_unique<double[]>(_numInputPorts)),
             _outputPorts(make_unique<double[]>(_numOutputPorts))
{
}
#pragma endregion

#pragma region Modifiers
void SignalBlock::setInputPortValue(size_t inputPortIndex, double value)
{
  if (inputPortIndex >= _numInputPorts)
    throw out_of_range("Input port index out of range");

  _inputPorts[inputPortIndex] = value;
}

void SignalBlock::setOutputPortValue(size_t outputPortIndex, double value)
{
  if (outputPortIndex >= _numOutputPorts)
    throw out_of_range("Output port index out of range");

  _outputPorts[outputPortIndex] = value;
}

void SignalBlock::zeroPortValues(unique_ptr<double[]>& portArray, size_t arraySize)
{
  for (size_t i = 0; i < arraySize; ++i)
    portArray[i] = 0.0;
}
#pragma endregion

#pragma region Observers
double SignalBlock::getInputPortValue(size_t inputPortIndex) const
{
  if (inputPortIndex >= _numInputPorts)
    throw out_of_range("Input port index out of range");

  return _inputPorts[inputPortIndex];
}

double SignalBlock::getOutputPortValue(size_t outputPortIndex) const
{
  if (outputPortIndex >= _numOutputPorts)
    throw out_of_range("Output port index out of range");

  return _outputPorts[outputPortIndex];
}
#pragma endregion

#pragma region SimulationBlock
void SignalBlock::init()
{
  zeroPortValues(_inputPorts, _numInputPorts);
  zeroPortValues(_outputPorts, _numOutputPorts);
}
#pragma endregion