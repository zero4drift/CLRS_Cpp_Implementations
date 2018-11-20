#ifndef BASE_GRAPH_H
#define BASE_GRAPH_H


#include <vector>
#include "chapter-22/vertex_graph/vertex_graph.h"
#include "chapter-22/edge_graph/edge_graph.h"

namespace CLRS
{
  /*
   * T1 should be class VertexGraph or its derivation
   * T2 should be class EdgeGraph or its derivation
   */
  template <typename T1, typename T2>
  class BaseGraph
  {
  protected:
    std::vector<T1> vertexes;
    std::vector<T2> edges;
  public:
    /* 
     * when construct, 
     * make sure passed-in vs has every
     * graph node stored in an order of index;
     * and es only stores existing graph edges. 
     */
    BaseGraph(const std::vector<T1> &vs,
	      const std::vector<T2> &es):
      vertexes(vs), edges(es) {}
    
    // indexes of the passed in object are inside the range
    virtual bool edge_or_not (const T2 &) const = 0;

    T1 get_vertex(std::size_t) const;

    T2 get_edge(std::size_t, std::size_t) const;

    std::vector<T1> get_vertexes() const
    {return vertexes;}

    std::vector<T2> get_edges() const
    {return edges;}
  };

  // user should make sure i < vertexes.size()
  template <typename T1, typename T2>
  T1
  BaseGraph<T1, T2>::get_vertex(std::size_t i) const
  {
    auto cit = vertexes.cbegin();
    while(cit != vertexes.cend())
      {
	if((*cit).get_index() == i)
	  return *cit;
	++cit;
      }
  }

  /* 
   * user should make sure i + j < edges.count()
   * and the object pointed by return shr still 
   * takes i as first index
   */
  template <typename T1, typename T2>
  T2
  BaseGraph<T1, T2>::get_edge(std::size_t i,
			      std::size_t j) const
  {
    auto cit = edges.cbegin();
    while(cit != edges.cend())
      {
	if((*cit).get_first_vertex().get_index() == i
	   && (*cit).get_second_vertex().get_index() == j)
	  return *cit;
	else
	  ++cit;
      }
  }
}


#endif
