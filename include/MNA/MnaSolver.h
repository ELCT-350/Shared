/**
 * @file C:\Users\leona\source\repos\Shared\include\MNA\MnaSolver.h.
 *
 * Declares the mna solver class
 **/

#pragma once
#include "Math/Matrix.h"
#include "MNA/MnaBlock.h"
#include "MNA/MnaNode.h"
#include <vector>

/** . */
namespace ELCT350
{
/** . */
  namespace MNA
  {
    /**
     * A mna solver. This class cannot be inherited..
     *
     * @author Rod Leonard
     * @date 4/2/2020
     **/
    class MnaSolver final
    {
    public:
      #pragma region Modifiers
      /**
       * Connects
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  port1 The first port.
       * @param  port2 The second port.
       **/
      void connect(const MnaPort& port1, const MnaPort& port2);
      /**
       * Initializes this 
       *
       * @author Rod Leonard
       * @date 4/2/2020
       **/
      void init();
      /**
       * Steps
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  time     The time.
       * @param  timeStep The time step.
       **/
      void step(double time, double timeStep);
      #pragma endregion
    private:
      #pragma region Constants
      /** The maximum error */
      static const double MAX_ERROR;
      /** The maximum iterations */
      static const size_t MAX_ITERATIONS;
      #pragma endregion

      #pragma region Variables
      /** The nodes */
      std::vector< std::shared_ptr<MnaNode> > _nodes;
      /** The non reference nodes */
      std::vector< std::shared_ptr<MnaNode> > _nonReferenceNodes;
      /** The engines */
      std::vector< MnaBlock* > _engines;
      /** The jacobian matrix */
      Math::Matrix _jacobianMatrix;
      /** The intercept vector */
      Math::Vector _interceptVector;
      /** The across vector */
      Math::Vector _acrossVector;
      #pragma endregion

      #pragma region Modifiers
      /**
       * Adds an engine
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param [in,out] engine The engine.
       **/
      void addEngine(MnaBlock& engine);
      /**
       * Initializes the engines
       *
       * @author Rod Leonard
       * @date 4/2/2020
       **/
      void initEngines();
      /**
       * Step engines
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  time     The time.
       * @param  timeStep The time step.
       **/
      void stepEngines(double time, double timeStep);
      /**
       * Copies the jacobian
       *
       * @author Rod Leonard
       * @date 4/2/2020
       **/
      void copyJacobian();
      /**
       * Copies the intercept
       *
       * @author Rod Leonard
       * @date 4/2/2020
       **/
      void copyIntercept();
      /**
       * Solves this 
       *
       * @author Rod Leonard
       * @date 4/2/2020
       **/
      void solve();
      /**
       * Determines if we can newton raphson
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @returns True if it succeeds, false if it fails.
       **/
      bool newtonRaphson();
      /**
       * Propagate solution
       *
       * @author Rod Leonard
       * @date 4/2/2020
       **/
      void propagateSolution();
      #pragma endregion
    };
  }
}