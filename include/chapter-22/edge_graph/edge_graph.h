#ifndef EDGE_GRAPH_H
#define EDGE_GRAPH_H


#include <memory>
#include <utility>
#include "chapter-22/vertex_graph/vertex_graph.h"

namespace CLRS
{
  struct EdgeGraph;
  using VertexSHRPair =
    std::pair<VertexSHR, VertexSHR>;
  using EdgeSHR = std::shared_ptr<EdgeGraph>;

  
  struct EdgeGraph
  {
    VertexSHRPair edge;
  public:
    EdgeGraph(const VertexSHR &v1,
	      const VertexSHR &v2):
      edge(std::make_pair(v1, v2)) {}
    const VertexSHR &get_first_vertex() const
    {return edge.first;}
    const VertexSHR &get_second_vertex() const
    {return edge.second;}
  };

  // compare function below for set compatibility
  bool compare_edge_graph(const EdgeSHR &ep1,
			  const EdgeSHR &ep2)
  {
    std::size_t i1_1 =
      ep1->get_first_vertex()->get_index();
    std::size_t i1_2 =
      ep1->get_second_vertex()->get_index();
    std::size_t i2_1 =
      ep2->get_first_vertex()->get_index();
    std::size_t i2_2 =
      ep2->get_second_vertex()->get_index();
    if(i1_1 == i2_1)
      return i1_2 < i2_2;
    else
      return i1_1 < i2_1;
  }

}


#endif
