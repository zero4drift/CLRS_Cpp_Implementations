#ifndef VERTEX_GRAPH_H
#define VERTEX_GRAPH_H


#include <memory>
#include <utility>

namespace CLRS
{
  class VertexGraph;
  using VertexSHR = std::shared_ptr<VertexGraph>;

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
