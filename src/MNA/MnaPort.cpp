#include "MNA/MnaPort.h"
#include "MNA/MnaNode.h"

using namespace ELCT350::MNA;

#pragma region Constructors
MnaPort::MnaPort()
       : _reference(false), _engine(nullptr), _across(0.0), _through(0.0)
{

}
#pragma endregion

#pragma region Observers
bool MnaPort::hasAssignedNode() const
{
  return !_containingNode.expired();
}

bool MnaPort::isReference() const
{
  return _reference;
}

double MnaPort::getAcross() const
{
  return _across;
}

double MnaPort::getThrough() const
{
  return _through;
}
#pragma endregion

#pragma region Modifiers
MnaNode& MnaPort::getNode()
{
  return *_containingNode.lock();
}

void MnaPort::setNode(MnaNode& node)
{
  _containingNode = node.weak_from_this();
}

MnaBlock& MnaPort::getEngine()
{
  return *_engine;
}

void MnaPort::setEngine(MnaBlock& engine)
{
  _engine = &engine;
}

void MnaPort::setReference()
{
  _reference = true;
}

void MnaPort::setAcross(double value)
{
  _across = value;
}

void MnaPort::setThrough(double value)
{
  _through = value;
}
#pragma endregion