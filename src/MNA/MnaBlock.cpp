#include "MNA/MnaBlock.h"
#include <stdexcept>

using namespace ELCT350::MNA;
using namespace std;

#pragma region Constructors
MnaBlock::MnaBlock(size_t numPorts)
        : _numPorts(numPorts),
          _ports(make_unique<shared_ptr<MnaPort>[]>(_numPorts)),
          _interceptVector(make_unique<double[]>(_numPorts)),
          _jacobianMatrix(make_unique<unique_ptr<double[]>[]>(_numPorts))
{
  for (size_t row = 0; row < _numPorts; ++row)
  {
    _ports[row] = make_shared<MnaPort>();
    _jacobianMatrix[row] = make_unique<double[]>(_numPorts);
    _ports[row]->setEngine(*this);
  }
}
#pragma endregion

#pragma region Modifiers
void MnaBlock::setReference(size_t portIndex)
{
  checkPortIndex(portIndex);
  _ports[portIndex]->setReference();
}

void MnaBlock::setIntercept(size_t portIndex, double value)
{
  checkPortIndex(portIndex);
  _interceptVector[portIndex] = value;
}

void MnaBlock::setJacobian(size_t rowPortIndex, size_t columnPortIndex, double value)
{
  checkPortIndex(rowPortIndex);
  checkPortIndex(columnPortIndex);

  _jacobianMatrix[rowPortIndex][columnPortIndex] = value;
}

void MnaBlock::solveThrough()
{
  for (size_t row = 0; row < _numPorts; ++row)
  {
    double through = -_interceptVector[row];
    for (size_t column = 0; column < _numPorts; ++column)
    {
      through += _ports[column]->getAcross() * _jacobianMatrix[row][column];
    }
    _ports[row]->setThrough(through);
  }
}
#pragma endregion

#pragma region Observers
void MnaBlock::checkPortIndex(size_t portIndex) const
{
  if (portIndex >= _numPorts)
    throw out_of_range("Port index is out of range");
}

size_t MnaBlock::getNumPorts() const
{
  return _numPorts;
}

const MnaPort& MnaBlock::getPort(size_t portIndex) const
{
  checkPortIndex(portIndex);
  return *_ports[portIndex];
}

double MnaBlock::getIntercept(size_t portIndex) const
{
  checkPortIndex(portIndex);
  return _interceptVector[portIndex];
}

double MnaBlock::getJacobian(size_t rowPortIndex, size_t columnPortIndex) const
{
  checkPortIndex(rowPortIndex);
  checkPortIndex(columnPortIndex);

  return _jacobianMatrix[rowPortIndex][columnPortIndex];
}
#pragma endregion

#pragma region SimulationBlock
void MnaBlock::init()
{
  for (size_t row = 0; row < _numPorts; ++row)
  {
    _interceptVector[row] = 0.0;
    for (size_t column = 0; column < _numPorts; ++column)
    {
      _jacobianMatrix[row][column] = 0.0;
    }
  }
}
#pragma endregion