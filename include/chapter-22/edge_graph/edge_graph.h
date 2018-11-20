#ifndef EDGE_GRAPH_H
#define EDGE_GRAPH_H


#include <utility>
#include "chapter-22/vertex_graph/vertex_graph.h"

namespace CLRS
{
  // T should be class VertexGraph or its derivation
  template <typename T>
  struct EdgeGraph
  {
    std::pair<T, T> edge;
  public:
    EdgeGraph(const T &v1,
	      const T &v2):
      edge(std::make_pair(v1, v2)) {}
    T get_first_vertex() const
    {return edge.first;}
    T get_second_vertex() const
    {return edge.second;}
  };
}


#endif
