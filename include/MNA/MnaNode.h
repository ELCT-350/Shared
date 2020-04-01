#pragma once
#include "MNA/MnaPort.h"
#include <vector>

namespace ELCT350
{
  namespace MNA
  {
    class MnaNode final : public std::enable_shared_from_this<MnaNode>
    {
    public:
      #pragma region Modifiers
      void combineNode(MnaNode& node);
      void addPort(MnaPort& port);
      void setNodeIndex(size_t index);
      void setAcross(double value);
      #pragma endregion

      #pragma region Observers
      bool isReference() const;
      size_t getNodeIndex() const;
      #pragma endregion
    private:
      #pragma region Variables
      std::vector< std::weak_ptr<MnaPort> > _ports;
      size_t _nodeIndex;
      #pragma endregion
    };
  }
}