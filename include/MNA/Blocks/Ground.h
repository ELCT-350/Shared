/**
 * @file C:\Users\leona\source\repos\Shared\include\MNA\Blocks\Ground.h.
 *
 * Declares the ground class
 **/

#pragma once
#include "MNA/MnaBlock.h"

/** . */
namespace ELCT350
{
/** . */
  namespace MNA
  {
/** . */
    namespace Blocks
    {
      /**
       * A ground. This class cannot be inherited..
       *
       * @author Rod Leonard
       * @date 4/2/2020
       **/
      class Ground final : public MnaBlock
      {
      public:
        #pragma region Enumerations
        /** Values that represent ports */
        enum Ports
        {
          Reference
        };
        #pragma endregion

        #pragma region Constructor
        /**
         * Default constructor
         *
         * @author Rod Leonard
         * @date 4/2/2020
         **/
        Ground();
        #pragma endregion

        #pragma region MnaBlock
        /**
         * Steps
         *
         * @author Rod Leonard
         * @date 4/2/2020
         *
         * @param  time     The time.
         * @param  timeStep The time step.
         **/
        virtual void step(double time, double timeStep) override;
        #pragma endregion
      };
    }
  }
}