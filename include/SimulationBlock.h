/**
 * @file C:\Users\leona\source\repos\Shared\include\SimulationBlock.h.
 *
 * Declares the simulation block class
 **/

#pragma once
#include <memory>

/** . */
namespace ELCT350
{
  /**
   * A simulation block.
   *
   * @author Rod Leonard
   * @date 4/2/2020
   **/
  class SimulationBlock
  {
  public:
    #pragma region Destructor
    /**
     * Destructor
     *
     * @author Rod Leonard
     * @date 4/2/2020
     **/
    virtual ~SimulationBlock() {};
    #pragma endregion

    #pragma region Modifiers
    /**
     * Sets a parameter
     *
     * @author Rod Leonard
     * @date 4/2/2020
     *
     * @param  parameterIndex Zero-based index of the parameter.
     * @param  parameter      The parameter.
     **/
    void setParameter(size_t parameterIndex, double parameter);
    /**
     * Initializes this 
     *
     * @author Rod Leonard
     * @date 4/2/2020
     **/
    virtual void init() = 0;
    /**
     * Steps
     *
     * @author Rod Leonard
     * @date 4/2/2020
     *
     * @param  time     The time.
     * @param  timeStep The time step.
     **/
    virtual void step(double time, double timeStep) = 0;
    #pragma endregion

    #pragma region Observers
    /**
     * Gets a parameter
     *
     * @author Rod Leonard
     * @date 4/2/2020
     *
     * @param  parameterIndex Zero-based index of the parameter.
     *
     * @returns The parameter.
     **/
    double getParameter(size_t parameterIndex) const;
    #pragma endregion
  protected:
    #pragma region Constructor
    /**
     * Constructor
     *
     * @author Rod Leonard
     * @date 4/2/2020
     *
     * @param  numParameters Number of parameters.
     **/
    SimulationBlock(size_t numParameters);
    #pragma endregion
  private:
    #pragma region Variables
    /** Number of parameters */
    size_t _numParameters;
    /** Options for controlling the operation */
    std::unique_ptr<double[]> _parameters;
    #pragma endregion
  };
}