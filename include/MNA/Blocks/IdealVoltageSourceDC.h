/**
 * @file C:\Users\leona\source\repos\Shared\include\MNA\Blocks\IdealVoltageSourceDC.h.
 *
 * Declares the ideal voltage source DC class
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
       * An ideal voltage source DC. This class cannot be inherited..
       *
       * @author Rod Leonard
       * @date 4/2/2020
       **/
      class IdealVoltageSourceDC final : public MnaBlock
      {
      public:
        #pragma region Enumerations
        /** Values that represent parameters */
        enum Parameters
        {
          Vdc
        };

        /** Values that represent ports */
        enum Ports
        {
          Positive,
          Negative,
          SupplyCurrent_Internal
        };
        #pragma endregion

        #pragma region Constructor
        /**
         * Default constructor
         *
         * @author Rod Leonard
         * @date 4/2/2020
         **/
        IdealVoltageSourceDC();
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