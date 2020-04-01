#pragma once
#include <memory>

namespace ELCT350
{
  namespace MNA
  {
    class MnaBlock;
    class MnaNode;
    class MnaPort final : public std::enable_shared_from_this<MnaPort>
    {
    public:
      #pragma region Constructors
      MnaPort();
      #pragma endregion

      #pragma region Observers
      bool hasAssignedNode() const;
      bool isReference() const;
      double getAcross() const;
      double getThrough() const;
      #pragma endregion

      #pragma region Modifers
      MnaNode& getNode();
      void setNode(MnaNode& node);
      MnaBlock& getEngine();
      void setEngine(MnaBlock& engine);
      void setAcross(double value);
      void setThrough(double value);
      void setReference();
      #pragma endregion
    private:
      #pragma region Variables
      bool _reference;
      MnaBlock* _engine;
      double _across;
      double _through;
      std::weak_ptr<MnaNode> _containingNode;
      #pragma endregion
    };
  }
}