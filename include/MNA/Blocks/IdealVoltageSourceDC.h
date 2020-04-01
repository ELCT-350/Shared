#pragma once
#include "MNA/MnaBlock.h"

namespace ELCT350
{
  namespace MNA
  {
    namespace Blocks
    {
      class IdealVoltageSourceDC final : public MnaBlock
      {
      public:
        #pragma region Enumerations
        enum Parameters
        {
          Vdc
        };

        enum Ports
        {
          Positive,
          Negative,
          SupplyCurrent_Internal
        };
        #pragma endregion

        #pragma region Constructor
        IdealVoltageSourceDC();
        #pragma endregion

        #pragma region MnaBlock
        virtual void step(double time, double timeStep) override;
        #pragma endregion
      };
    }
  }
}