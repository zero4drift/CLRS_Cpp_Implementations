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
    virtual std::size_t get_index() const {return index;}
  };

  // compare function below for set compatibility
  bool compare_vertex_graph(const VertexSHR &vp1,
			    const VertexSHR &vp2)
  {
    std::size_t i1 =
      vp1->get_index();
    std::size_t i2 =
      vp2->get_index();
    return i1 < i2;
  }

}


#endif
