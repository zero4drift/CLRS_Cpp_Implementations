#ifndef VERTEX_GRAPH_H
#define VERTEX_GRAPH_H


#include <utility>

namespace CLRS
{
  // vertex index must start from 0
  class VertexGraph
  {
    // In every occasion a vertex should have a index
    std::size_t index = 0;
  public:
    VertexGraph(std::size_t i): index(i) {}
    std::size_t get_index() const {return index;}
  };
}


#endif
