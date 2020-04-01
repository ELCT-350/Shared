#pragma once
#include "MNA/MnaBlock.h"

namespace ELCT350
{
  namespace MNA
  {
    namespace Blocks
    {
      class Resistor final : public MnaBlock
      {
      public:
        #pragma region Enumerations
        enum Parameters
        {
          Resistance
        };

        enum Ports
        {
          Positive,
          Negative
        };
        #pragma endregion

        #pragma region Constructor
        Resistor();
        #pragma endregion

        #pragma region MnaBlock
        virtual void step(double time, double timeStep) override;
        #pragma endregion
      };
    }
  }
}