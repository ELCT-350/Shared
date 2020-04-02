/**
 * @file C:\Users\leona\source\repos\Shared\include\MNA\MnaNode.h.
 *
 * Declares the mna node class
 **/

#pragma once
#include "MNA/MnaPort.h"
#include <vector>

/** . */
namespace ELCT350
{
/** . */
  namespace MNA
  {
    /**
     * A mna node. This class cannot be inherited..
     *
     * @author Rod Leonard
     * @date 4/2/2020
     **/
    class MnaNode final : public std::enable_shared_from_this<MnaNode>
    {
    public:
      #pragma region Modifiers
      /**
       * Combine node
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param [in,out] node The node.
       **/
      void combineNode(MnaNode& node);
      /**
       * Adds a port
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param [in,out] port The port.
       **/
      void addPort(MnaPort& port);
      /**
       * Sets node index
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  index Zero-based index of the.
       **/
      void setNodeIndex(size_t index);
      /**
       * Sets the across
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  value The value.
       **/
      void setAcross(double value);
      #pragma endregion

      #pragma region Observers
      /**
       * Query if this  is reference
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @returns True if reference, false if not.
       **/
      bool isReference() const;
      /**
       * Gets node index
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @returns The node index.
       **/
      size_t getNodeIndex() const;
      #pragma endregion
    private:
      #pragma region Variables
      /** The ports */
      std::vector< std::weak_ptr<MnaPort> > _ports;
      /** Zero-based index of the node */
      size_t _nodeIndex;
      #pragma endregion
    };
  }
}