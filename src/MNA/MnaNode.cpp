#include "MNA/MnaNode.h"
#include <algorithm>

using namespace ELCT350::MNA;
using namespace std;

#pragma region Modifiers
void MnaNode::combineNode(MnaNode& node)
{
  for (auto& port : node._ports)
    addPort(*port.lock());
}

void MnaNode::addPort(MnaPort& port)
{
  port.setNode(*this);
  _ports.push_back(port.weak_from_this());
}

void MnaNode::setNodeIndex(size_t index)
{
  _nodeIndex = index;
}

void MnaNode::setAcross(double value)
{
  for (auto& port : _ports)
  {
    if (!port.expired())
      port.lock()->setAcross(value);
  }
}
#pragma endregion

#pragma region Observers
bool MnaNode::isReference() const
{
  return any_of(_ports.cbegin(), _ports.cend(), [](const auto& port) {return port.lock()->isReference(); });
}

size_t MnaNode::getNodeIndex() const
{
  return _nodeIndex;
}
#pragma endregion