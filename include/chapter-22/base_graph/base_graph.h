#ifndef BASE_GRAPH_H
#define BASE_GRAPH_H


#include <set>
#include <algorithm>
#include "chapter-22/vertex_graph/vertex_graph.h"
#include "chapter-22/edge_graph/edge_graph.h"

namespace CLRS
{
  class BaseGraph
  {
  protected:
    std::set<VertexSHR,
	     decltype(CLRS::compare_vertex_graph)*>
    vertexes;
    std::set<EdgeSHR,
	     decltype(CLRS::compare_edge_graph)*>
    edges;
  public:
    /* 
     * when construct, 
     * make sure passed-in vs has every
     * graph node stored in an order of index;
     * and es only stores existing graph edges. 
     */
    BaseGraph(const std::set<VertexSHR,
	      decltype(CLRS::compare_vertex_graph)*> &vs,
	      const std::set<EdgeSHR,
	      decltype(CLRS::compare_edge_graph)*> &es):
      vertexes(vs), edges(es) {}
    // indexes of the passed in object are inside the range
    virtual bool edge_or_not(const EdgeSHR &) const = 0;
    virtual VertexSHR get_vertex(std::size_t) const;
    virtual EdgeSHR get_edge(std::size_t, std::size_t) const;
  };

  // user should make sure i < vertexes.count()
  VertexSHR BaseGraph::get_vertex(std::size_t i) const
  {
    auto cit = vertexes.cbegin();
    while(cit != vertexes.cend())
      {
	if((*cit)->get_index() == i)
	  return *cit;
	++cit;
      }
    return nullptr;
  }

  /* 
   * user should make sure i + j < edges.count()
   * and the object pointed by return shr still 
   * takes i as first index
   */
  EdgeSHR BaseGraph::get_edge(std::size_t i,
			      std::size_t j) const
  {
    auto cit = edges.cbegin();
    while(cit != edges.cend())
      {
	if((*cit)->get_first_vertex()->get_index() == i
	   && (*cit)->get_second_vertex()->get_index() == j)
	  return *cit;
	else
	  ++cit;
      }
    return nullptr;
  }
}


#endif
