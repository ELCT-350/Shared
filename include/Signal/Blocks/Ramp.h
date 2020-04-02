/**
 * @file C:\Users\leona\source\repos\Shared\include\Signal\Blocks\Ramp.h.
 *
 * Declares the ramp class
 **/

#pragma once
#include "Signal/SignalBlock.h"

/** . */
namespace ELCT350
{
/** . */
  namespace Signal
  {
/** . */
    namespace Blocks
    {
      /**
       * A ramp. This class cannot be inherited..
       *
       * @author Rod Leonard
       * @date 4/2/2020
       **/
      class Ramp final : public SignalBlock
      {
      public:
        #pragma region Enumerations
        /** Values that represent parameters */
        enum Parameters
        {
          InitialCondition,
          Slope
        };

        /** Values that represent input ports */
        enum InputPorts
        {
          Input
        };

        /** Values that represent output ports */
        enum OutputPorts
        {
          Output
        };
        #pragma endregion

        #pragma region Constructor
        /**
         * Default constructor
         *
         * @author Rod Leonard
         * @date 4/2/2020
         **/
        Ramp();
        #pragma endregion

        #pragma region SignalBlock
        /**
         * Initializes this 
         *
         * @author Rod Leonard
         * @date 4/2/2020
         **/
        void init() override;
        /**
         * Steps
         *
         * @author Rod Leonard
         * @date 4/2/2020
         *
         * @param  time     The time.
         * @param  timeStep The time step.
         **/
        void step(double time, double timeStep) override;
        #pragma endregion
      private:
        #pragma region Variables
        /** The gain */
        double _gain;
        #pragma endregion
      };
    }
  }
}