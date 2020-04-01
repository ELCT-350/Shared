#pragma once
#include "Math/Matrix.h"
#include "MNA/MnaBlock.h"
#include "MNA/MnaNode.h"
#include <vector>

namespace ELCT350
{
  namespace MNA
  {
    class MnaSolver final
    {
    public:
      #pragma region Modifiers
      void connect(const MnaPort& port1, const MnaPort& port2);
      void init();
      void step(double time, double timeStep);
      #pragma endregion
    private:
      #pragma region Constants
      static const double MAX_ERROR;
      static const size_t MAX_ITERATIONS;
      #pragma endregion

      #pragma region Variables
      std::vector< std::shared_ptr<MnaNode> > _nodes;
      std::vector< std::shared_ptr<MnaNode> > _nonReferenceNodes;
      std::vector< MnaBlock* > _engines;
      Math::Matrix _jacobianMatrix;
      Math::Vector _interceptVector;
      Math::Vector _acrossVector;
      #pragma endregion

      #pragma region Modifiers
      void addEngine(MnaBlock& engine);
      void initEngines();
      void stepEngines(double time, double timeStep);
      void copyJacobian();
      void copyIntercept();
      void solve();
      bool newtonRaphson();
      void propagateSolution();
      #pragma endregion
    };
  }
}