#pragma once
#include "SimulationBlock.h"
#include "MNA/MnaPort.h"
#include <map>

namespace ELCT350
{
  namespace MNA
  {
    class MnaBlock : public virtual SimulationBlock
    {
    public:
      #pragma region Constructor
      MnaBlock(size_t numPorts);
      #pragma endregion

      #pragma region Observers
      size_t getNumPorts() const;
      const MnaPort& getPort(size_t portIndex) const;
      double getIntercept(size_t portIndex) const;
      double getJacobian(size_t rowPortIndex, size_t columnPortIndex) const;
      #pragma endregion

      #pragma region Modifiers
      void solveThrough();
      #pragma endregion

      #pragma region SimulationBlock
      void init() override;
      #pragma endregion
    protected:
      #pragma region Modifiers
      void setIntercept(size_t portIndex, double value);
      void setJacobian(size_t rowPortIndex, size_t columnPortIndex, double value);
      void setReference(size_t portIndex);
      #pragma endregion
    private:
      #pragma region Variables
      size_t _numPorts;
      std::unique_ptr<std::shared_ptr<MnaPort>[]> _ports;
      std::unique_ptr<double[]> _interceptVector;
      std::unique_ptr< std::unique_ptr<double[]>[] > _jacobianMatrix;
      #pragma endregion

      #pragma region Observers
      void checkPortIndex(size_t portIndex) const;
      #pragma endregion
    };
  }
}