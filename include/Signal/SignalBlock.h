/**
 * @file C:\Users\leona\source\repos\Shared\include\Signal\SignalBlock.h.
 *
 * Declares the signal block class
 **/

#pragma once

#include "SimulationBlock.h"

/** . */
namespace ELCT350
{
/** . */
  namespace Signal
  {
    /**
     * A signal block.
     *
     * @author Rod Leonard
     * @date 4/2/2020
     **/
    class SignalBlock : public virtual SimulationBlock
    {
    public:
      #pragma region Modifiers
      /**
       * Sets input port value
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  portIndex Zero-based index of the port.
       * @param  portValue The port value.
       **/
      void setInputPortValue(size_t portIndex, double portValue);
      #pragma endregion

      #pragma region Observers
      /**
       * Gets output port value
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  portIndex Zero-based index of the port.
       *
       * @returns The output port value.
       **/
      double getOutputPortValue(size_t portIndex) const;
      #pragma endregion

      #pragma region SimulationBlock
      /**
       * Initializes this 
       *
       * @author Rod Leonard
       * @date 4/2/2020
       **/
      virtual void init() override;
      #pragma endregion
    protected:
      #pragma region Constructors
      /**
       * Constructor
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  numInputPorts  Number of input ports.
       * @param  numOutputPorts Number of output ports.
       **/
      SignalBlock(size_t numInputPorts, size_t numOutputPorts);
      #pragma endregion

      #pragma region Modifiers
      /**
       * Sets output port value
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  portIndex Zero-based index of the port.
       * @param  portValue The port value.
       **/
      void setOutputPortValue(size_t portIndex, double portValue);
      #pragma endregion

      #pragma region Observers
      /**
       * Gets input port value
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  portIndex Zero-based index of the port.
       *
       * @returns The input port value.
       **/
      double getInputPortValue(size_t portIndex) const;
      #pragma endregion
    private:
      #pragma region Variables
      /** Number of input ports */
      size_t _numInputPorts;
      /** Number of output ports */
      size_t _numOutputPorts;
      /** The input ports */
      std::unique_ptr<double[]> _inputPorts;
      /** The output ports */
      std::unique_ptr<double[]> _outputPorts;
      #pragma endregion

      #pragma region Modifiers
      /**
       * Zero port values
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param [in,out] portArray Array of ports.
       * @param          arraySize Size of the array.
       **/
      void zeroPortValues(std::unique_ptr<double[]>& portArray, size_t arraySize);
      #pragma endregion
    };
  }
}