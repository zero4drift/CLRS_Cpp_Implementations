#ifndef LINKED_LIST_GRAPH_H
#define LINKED_LIST_GRAPH_H


#include <vector>
#include <utility>
#include "chapter-22/base_graph/base_graph.hpp"

namespace CLRS
{
  template <typename T1, typename T2>
  class LinkedListGraph: public BaseGraph<T1, T2>
  {
  protected:
    std::vector<std::vector<std::size_t>> adj;
  public:
    LinkedListGraph(const std::vector<T1> &vs,
		    const std::vector<T2> &es);
    bool edge_or_not(const T2 &e) const override;
    bool edge_or_not(std::size_t i1,
		     std::size_t i2) const override;
    std::vector<std::size_t> get_adj_vertexes(std::size_t i) const
    {return adj[i];}
  };

  template <typename T1, typename T2>
  bool LinkedListGraph<T1, T2>::
  edge_or_not(const T2 &e) const
  {
    std::size_t i =
      e.get_first_vertex();
    std::size_t j =
      e.get_second_vertex();
    for(const auto &ev : adj[i])
      {
	if(BaseGraph<T1, T2>::edges[ev].
	   get_second_vertex() == j)
	  return true;
      }
    return false;
  }
  template <typename T1, typename T2>
  bool LinkedListGraph<T1, T2>::edge_or_not(std::size_t i,
					    std::size_t j) const
  {
    for(const auto &ev : adj[i])
      {
	if(BaseGraph<T1, T2>::edges[ev].
	   get_second_vertex() == j)
	  return true;
      }
    return false;
  }

  template <typename T1, typename T2>
  LinkedListGraph<T1, T2>::LinkedListGraph
  (const std::vector<T1> &vs,
   const std::vector<T2> &es):
    BaseGraph<T1, T2>(vs, es), adj(vs.size())
  {
    for(std::size_t i = 0;
	i != BaseGraph<T1, T2>::edges.size();
	++i)
      {
	adj[BaseGraph<T1, T2>::edges[i]
	    .get_first_vertex()].push_back(i);
      }
  }
}


#endif
