#include "MNA/MnaSolver.h"
#include <stdexcept>

using namespace ELCT350::Math;
using namespace ELCT350::MNA;
using namespace std;

#pragma region Constants
const double MnaSolver::MAX_ERROR = 1e-7;
const size_t MnaSolver::MAX_ITERATIONS = 500;
#pragma endregion

#pragma region Modifiers
void MnaSolver::connect(const MnaPort& port1_const, const MnaPort& port2_const)
{
  //We're going to modify the ports, even though they're const. This is internal stuff, such as which node
  //the port belongs to, so it's not betraying the contract as far as the user of the API is concerned
  auto& port1 = const_cast<MnaPort&>(port1_const);
  auto& port2 = const_cast<MnaPort&>(port2_const);

  //We're going to add the blocks the ports are a part of to our engine list
  addEngine(port1.getEngine());
  addEngine(port2.getEngine());

  //First we're going to see if port1 is already in a node
  if (port1.hasAssignedNode())
  {
    //if so, we get the node...
    auto& node = port1.getNode();
    //...and check to see if port2 is also in a node
    if (port2.hasAssignedNode())
    {
      //if so, we get the node port2 belongs to...
      auto& oldNode = port2.getNode();
      //...and check to see if it's the same node as port1. If it is, we don't need to do anything
      if (&node != &oldNode)
      {
        //if it's not, we combine the nodes, into the node port1 belongs to
        node.combineNode(oldNode);

        //and delete the node from port2
        _nodes.erase(find(_nodes.begin(), _nodes.end(), oldNode.shared_from_this()));
      }
    }
    else //if port2 doesn't belong to a node, we add it to the node of port1
      node.addPort(port2);
  }
  else
  {
    //Port1 doesn't belong to a node, so we check to see if port2 does
    if (port2.hasAssignedNode())
    {
      //If so, we add port1 to the node of port2
      auto& node = port2.getNode();
      node.addPort(port1);
    }
  }
}

void MnaSolver::init()
{
  //First we figure out which nodes are reference nodes, since we won't use those. The rest, we assign
  //a node index
  _nonReferenceNodes.clear();
  for (auto& node : _nodes)
  {
    if (!node->isReference())
    {
      node->setNodeIndex(_nonReferenceNodes.size());
      _nonReferenceNodes.push_back(node);
    }
  }
  //We give all the nodes an index that will be associated with matrix cell locations
  size_t numNodes = _nonReferenceNodes.size();

  //Then we initialize our system matrices and vectors to the number of non-reference nodes
  _jacobianMatrix = Matrix(numNodes, numNodes);
  _interceptVector = Vector(numNodes);
  _acrossVector = Vector(numNodes);

  initEngines();
}

void MnaSolver::step(double time, double timeStep)
{
  stepEngines(time, timeStep);
  solve();

  bool converged = false;
  for (size_t iteration = 0; iteration < MAX_ITERATIONS && !converged; ++iteration)
  {
    stepEngines(time, timeStep);
    converged = newtonRaphson();
  }

  if (!converged)
    throw runtime_error("Failed to converge solution");
}

void MnaSolver::initEngines()
{
  for (auto* engine : _engines)
    engine->init();
}

void MnaSolver::stepEngines(double time, double timeStep)
{
  for (auto* engine : _engines)
    engine->step(time, timeStep);
}

void MnaSolver::solve()
{
  copyJacobian();
  copyIntercept();

  #pragma region TODO: Solve for across vector here
  #pragma endregion

  propagateSolution();
}

bool MnaSolver::newtonRaphson()
{
  #pragma region implement Newton-Raphson here
  bool converged = false;
  #pragma endregion

  return converged;
}

void MnaSolver::propagateSolution()
{
  for (size_t row = 0; row < _acrossVector.getSize(); ++row)
  {
    _nonReferenceNodes[row]->setAcross(_acrossVector[row]);
  }

  for (auto* engine : _engines)
  {
    engine->solveThrough();
  }
}

void MnaSolver::copyIntercept()
{
  _interceptVector.clear();
  for (const auto* engine : _engines)
  {
    for (size_t row = 0; row < engine->getNumPorts(); ++row)
    {
      const auto& port = engine->getPort(row);
      if (!port.isReference())
      {
        const auto& node = const_cast<MnaPort&>(port).getNode();
        _interceptVector[node.getNodeIndex()] += engine->getIntercept(row);
      }
    }
  }
}

void MnaSolver::copyJacobian()
{
  #pragma region TODO: Copy Block jacobian into system jacobian here
  #pragma endregion
}

void MnaSolver::addEngine(MnaBlock& engine)
{
  if (find(_engines.begin(), _engines.end(), &engine) == _engines.end())
  {
    _engines.push_back(&engine);

    //add all ports from engine to their own individual node
    for (size_t row = 0; row < engine.getNumPorts(); ++row)
    {
      auto node = make_shared<MnaNode>();
      node->addPort(const_cast<MnaPort&>(engine.getPort(row)));
      _nodes.push_back(move(node));
    }
  }
}
#pragma endregion