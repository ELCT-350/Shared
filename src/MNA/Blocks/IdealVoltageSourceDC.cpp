#include "MNA/Blocks/IdealVoltageSourceDC.h"

using namespace ELCT350::MNA::Blocks;

#pragma region Constructors
IdealVoltageSourceDC::IdealVoltageSourceDC()
                    : SimulationBlock(1), MnaBlock(3)
{
}
#pragma endregion

#pragma region MnaBlock
void IdealVoltageSourceDC::step(double time, double timeStep)
{
  setJacobian(Positive, SupplyCurrent_Internal, -1);
  setJacobian(Negative, SupplyCurrent_Internal, 1);
  setJacobian(SupplyCurrent_Internal, Positive, 1);
  setJacobian(SupplyCurrent_Internal, Negative, -1);

  setIntercept(SupplyCurrent_Internal, getParameter(Vdc));
}
#pragma endregion