#ifndef LINKED_LIST_GRAPH_H
#define LINKED_LIST_GRAPH_H


#include <list>
#include <vector>
#include <utility>
#include "chapter-22/base_graph/base_graph.h"

namespace CLRS
{
  template <typename T1, typename T2>
  class LinkedListGraph: public BaseGraph<T1, T2>
  {
  protected:
    std::vector<std::list<std::size_t>> adj;
  public:
    LinkedListGraph(const std::vector<T1> &vs,
		    const std::vector<T2> &es);
    bool edge_or_not(const T2 &e) const override;
    std::list<size_t> get_list(std::size_t i) const
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
    for(auto cit = adj[i].cbegin();
	cit != adj[i].cend();
	++cit)
      {
	if(*cit == j)
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
    auto it = es.cbegin();
    while(it != es.cend())
      {
	std::size_t i1 =
	  (*it).get_first_vertex();
	std::size_t i2 =
	  (*it).get_second_vertex();
	adj[i1].push_back(i2);
	++it;
      }
  }
}


#endif
