#pragma once
#include "MNA/MnaBlock.h"

namespace ELCT350
{
  namespace MNA
  {
    namespace Blocks
    {
      class Ground final : public MnaBlock
      {
      public:
        #pragma region Enumerations
        enum Ports
        {
          Reference
        };
        #pragma endregion

        #pragma region Constructor
        Ground();
        #pragma endregion

        #pragma region MnaBlock
        virtual void step(double time, double timeStep) override;
        #pragma endregion
      };
    }
  }
}