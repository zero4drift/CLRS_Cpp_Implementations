#ifndef LINKED_LIST_GRAPH_H
#define LINKED_LIST_GRAPH_H


#include <list>
#include <vector>
#include <utility>
#include "chapter-22/base_graph/base_graph.h"
#include "chapter-22/vertex_graph/vertex_graph.h"
#include "chapter-22/edge_graph/edge_graph.h"

namespace CLRS
{
  template <typename T1, typename T2>
  class LinkedListGraph: public BaseGraph<T1, T2>
  {
  protected:
    std::vector<std::list<T1>> adj;
  public:
    LinkedListGraph(const std::vector<T1> &vs,
		    const std::vector<T2> &es);
    bool edge_or_not(const T2 &e) const override;
    typename std::list<T1>::const_iterator get_ll_cbeg_it
    (std::size_t i) const {return adj[i].cbegin();}
  };

  template <typename T1, typename T2>
  bool LinkedListGraph<T1, T2>::
  edge_or_not(const T2 &e) const
  {
    std::size_t i =
      e.get_first_vertex().get_index();
    std::size_t j =
      e.get_second_vertex().get_index();
    for(auto it = adj[i].cbegin();
	it != adj[i].cend();
	++it)
      {
	if((*it).get_index() == j)
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
	  (*it).get_first_vertex().get_index();
	std::size_t i2 =
	  (*it).get_second_vertex().get_index();
	adj[i1].push_back
	  ((*it).get_second_vertex());
	++it;
      }
  }
}


#endif
