/**
 * @file C:\Users\leona\source\repos\Shared\include\MNA\MnaBlock.h.
 *
 * Declares the mna block class
 **/

#pragma once
#include "SimulationBlock.h"
#include "MNA/MnaPort.h"
#include <map>

/** . */
namespace ELCT350
{
/** . */
  namespace MNA
  {
    /**
     * A mna block.
     *
     * @author Rod Leonard
     * @date 4/2/2020
     **/
    class MnaBlock : public virtual SimulationBlock
    {
    public:
      #pragma region Constructor
      /**
       * Constructor
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  numPorts Number of ports.
       **/
      MnaBlock(size_t numPorts);
      #pragma endregion

      #pragma region Observers
      /**
       * Gets number ports
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @returns The number ports.
       **/
      size_t getNumPorts() const;
      /**
       * Gets a port
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  portIndex Zero-based index of the port.
       *
       * @returns The port.
       **/
      const MnaPort& getPort(size_t portIndex) const;
      /**
       * Gets an intercept
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  portIndex Zero-based index of the port.
       *
       * @returns The intercept.
       **/
      double getIntercept(size_t portIndex) const;
      /**
       * Gets a jacobian
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  rowPortIndex    Zero-based index of the row port.
       * @param  columnPortIndex Zero-based index of the column port.
       *
       * @returns The jacobian.
       **/
      double getJacobian(size_t rowPortIndex, size_t columnPortIndex) const;
      #pragma endregion

      #pragma region Modifiers
      /**
       * Solve through
       *
       * @author Rod Leonard
       * @date 4/2/2020
       **/
      void solveThrough();
      #pragma endregion

      #pragma region SimulationBlock
      /**
       * Initializes this 
       *
       * @author Rod Leonard
       * @date 4/2/2020
       **/
      void init() override;
      #pragma endregion
    protected:
      #pragma region Modifiers
      /**
       * Sets an intercept
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  portIndex Zero-based index of the port.
       * @param  value     The value.
       **/
      void setIntercept(size_t portIndex, double value);
      /**
       * Sets a jacobian
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  rowPortIndex    Zero-based index of the row port.
       * @param  columnPortIndex Zero-based index of the column port.
       * @param  value           The value.
       **/
      void setJacobian(size_t rowPortIndex, size_t columnPortIndex, double value);
      /**
       * Sets a reference
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  portIndex Zero-based index of the port.
       **/
      void setReference(size_t portIndex);
      #pragma endregion
    private:
      #pragma region Variables
      /** Number of ports */
      size_t _numPorts;
      /** The ports */
      std::unique_ptr<std::shared_ptr<MnaPort>[]> _ports;
      /** The intercept vector */
      std::unique_ptr<double[]> _interceptVector;
      /** The jacobian matrix */
      std::unique_ptr< std::unique_ptr<double[]>[] > _jacobianMatrix;
      #pragma endregion

      #pragma region Observers
      /**
       * Check port index
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  portIndex Zero-based index of the port.
       **/
      void checkPortIndex(size_t portIndex) const;
      #pragma endregion
    };
  }
}