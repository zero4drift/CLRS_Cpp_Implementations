#ifndef LINKED_LIST_GRAPH_H
#define LINKED_LIST_GRAPH_H


#include <utility>
#include <vector>
#include <memory>
#include "chapter-22/base_graph/base_graph.h"
#include "chapter-22/vertex_graph/vertex_graph.h"
#include "chapter-22/edge_graph/edge_graph.h"

namespace CLRS
{
  class LinkedListNodeGraph
  {
  protected:
    std::size_t index;
    std::shared_ptr<LinkedListNodeGraph> next;
  public:
    LinkedListNodeGraph(const EdgeSHR &e):
      index(e->get_second_vertex()->get_index()) {}
    std::size_t get_index() const {return index;}
    std::shared_ptr<LinkedListNodeGraph>
    get_next() const {return next;}
    void set_next(const
		  std::shared_ptr<LinkedListNodeGraph>
		  &np) {next = np;}
  };
  
  template <typename T>
  class LinkedListGraph: public BaseGraph
  {
  protected:
    std::vector
    <std::shared_ptr<T>> adj;
  public:
    LinkedListGraph(const std::set<VertexSHR,
		    decltype(CLRS::compare_vertex_graph)*> &vs,
		    const std::set<EdgeSHR,
		    decltype(CLRS::compare_edge_graph)*> &es);
    bool edge_or_not(const EdgeSHR &e) const override;
    T get_node(const EdgeSHR &e) const;
  };

  template <typename T>
  bool LinkedListGraph<T>::edge_or_not(const EdgeSHR &e) const
  {
    std::size_t i =
      e->get_first_vertex()->get_index();
    std::size_t j =
      e->get_second_vertex()->get_index();
    for(auto n = adj[i];
	n != nullptr;
	n = n->get_next())
      {
	if(n->get_index() == j)
	  return true;
      }
    return false;
  }

  template <typename T>
  T LinkedListGraph<T>::get_node(const EdgeSHR &e) const
  {
    std::size_t i =
      e->get_first_vertex()->get_index();
    std::size_t j =
      e->get_second_vertex()->get_index();
    for(auto n = adj[i];
	n != nullptr;
	n = n->get_next())
      if(n->get_index() == j)
	return *n;
  }

  template <typename T>
  LinkedListGraph<T>::LinkedListGraph
  (const std::set<VertexSHR,
   decltype(CLRS::compare_vertex_graph)*> &vs,
   const std::set<EdgeSHR,
   decltype(CLRS::compare_edge_graph)*> &es):
    BaseGraph(vs, es), adj(vs.size())
  {
    std::set<EdgeSHR>::const_iterator it = es.cbegin();
    while(it != es.cend())
      {
	std::size_t i1 =
	  (*it)->get_first_vertex()->get_index();
	std::size_t i2 =
	  (*it)->get_second_vertex()->get_index();
	if(adj[i1] == nullptr)
	  adj[i1] =
	    std::make_shared<T>(*it);
	else
	  {
	    auto p = adj[i1];
	    decltype(p) temp;
	    while(p != nullptr)
	      {
		temp = p;
		p = p->get_next();
	      }
	    temp->set_next
	      (std::make_shared
	       <T>(*it));
	  }
	++it;
      }
  }
}


#endif
