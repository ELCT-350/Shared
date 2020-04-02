/**
 * @file C:\Users\leona\source\repos\Shared\include\MNA\MnaPort.h.
 *
 * Declares the mna port class
 **/

#pragma once
#include <memory>

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
    class MnaBlock;
    /**
     * A mna node.
     *
     * @author Rod Leonard
     * @date 4/2/2020
     **/
    class MnaNode;
    /**
     * A mna port. This class cannot be inherited..
     *
     * @author Rod Leonard
     * @date 4/2/2020
     **/
    class MnaPort final : public std::enable_shared_from_this<MnaPort>
    {
    public:
      #pragma region Constructors
      /**
       * Default constructor
       *
       * @author Rod Leonard
       * @date 4/2/2020
       **/
      MnaPort();
      #pragma endregion

      #pragma region Observers
      /**
       * Query if this  has assigned node
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @returns True if assigned node, false if not.
       **/
      bool hasAssignedNode() const;
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
       * Gets the across
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @returns The across.
       **/
      double getAcross() const;
      /**
       * Gets the through
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @returns The through.
       **/
      double getThrough() const;
      #pragma endregion

      #pragma region Modifers
      /**
       * Gets the node
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @returns The node.
       **/
      MnaNode& getNode();
      /**
       * Sets a node
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param [in,out] node The node.
       **/
      void setNode(MnaNode& node);
      /**
       * Gets the engine
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @returns The engine.
       **/
      MnaBlock& getEngine();
      /**
       * Sets an engine
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param [in,out] engine The engine.
       **/
      void setEngine(MnaBlock& engine);
      /**
       * Sets the across
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  value The value.
       **/
      void setAcross(double value);
      /**
       * Sets a through
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  value The value.
       **/
      void setThrough(double value);
      /**
       * Sets the reference
       *
       * @author Rod Leonard
       * @date 4/2/2020
       **/
      void setReference();
      #pragma endregion
    private:
      #pragma region Variables
      /** True to reference */
      bool _reference;
      /** The engine */
      MnaBlock* _engine;
      /** The across */
      double _across;
      /** The through */
      double _through;
      /** The containing node */
      std::weak_ptr<MnaNode> _containingNode;
      #pragma endregion
    };
  }
}