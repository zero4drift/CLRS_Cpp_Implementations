#ifndef EDGE_GRAPH_H
#define EDGE_GRAPH_H


#include <utility>

namespace CLRS
{
  // T should be class VertexGraph or its derivation
  template <typename T>
  struct EdgeGraph
  {
    std::pair<std::size_t, std::size_t> edge;
  public:
    EdgeGraph(const T &v1,
	      const T &v2):
      edge(std::make_pair(v1.get_index(),
			  v2.get_index())) {}
    std::size_t get_first_vertex() const
    {return edge.first;}
    std::size_t get_second_vertex() const
    {return edge.second;}
    void set_first_vertex(std::size_t i)
    {edge.first = i;}
    void set_second_vertex(std::size_t i)
    {edge.second = i;}
  };
}


#endif
