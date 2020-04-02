/**
 * @file C:\Users\leona\source\repos\Shared\include\Signal\Blocks\SinusoidalSource.h.
 *
 * Declares the sinusoidal source class
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
       * A sinusoidal source. This class cannot be inherited..
       *
       * @author Rod Leonard
       * @date 4/2/2020
       **/
      class SinusoidalSource final : public SignalBlock
      {
      public:
        #pragma region Enumerations
        /** Values that represent parameters */
        enum Parameters
        {
          Amplitude,
          Frequency
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
        SinusoidalSource();
        #pragma endregion

        #pragma region SignalBlock
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
        #pragma region Constants
        /** The two pi */
        static const double TWO_PI;
        #pragma endregion
      };
    }
  }
}