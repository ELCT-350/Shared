#include "MNA/Blocks/Ground.h"

using namespace ELCT350::MNA::Blocks;

#pragma region Constructors
Ground::Ground()
  : SimulationBlock(0), MnaBlock(1)
{
  setReference(Reference);
}
#pragma endregion

#pragma region MnaBlock
void Ground::step(double time, double timeStep)
{
}
#pragma endregion