#include "MNA/Blocks/Resistor.h"

using namespace ELCT350::MNA::Blocks;

#pragma region Constructors
Resistor::Resistor()
        : SimulationBlock(1), MnaBlock(2)
{
}
#pragma endregion

#pragma region MnaBlock
void Resistor::step(double time, double timeStep)
{
  double conductance = 1.0 / getParameter(Resistance);

  setJacobian(Positive, Positive, conductance);
  setJacobian(Positive, Negative, -conductance);
  setJacobian(Negative, Positive, -conductance);
  setJacobian(Negative, Negative, conductance);
}
#pragma endregion