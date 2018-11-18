#ifndef MATRIX_GRAPH_H
#define MATRIX_GRAPH_H


#include <utility>
#include <vector>
#include <memory>
#include "chapter-22/base_graph/base_graph.h"
#include "chapter-22/vertex_graph/vertex_graph.h"
#include "chapter-22/edge_graph/edge_graph.h"

namespace CLRS
{ 
  class MatrixGraph: public BaseGraph
  {
  protected:
    // square matrix
    std::vector<std::vector<bool>> a;
  public:
    MatrixGraph(const std::vector<VertexSHR> &vs,
		const std::set<EdgeSHR,
		decltype(compare_edge_graph)*> &es);
    bool edge_or_not(const EdgeSHR &e) const override
    {
      std::size_t i1 = e->get_first_vertex()->get_index();
      std::size_t i2 = e->get_second_vertex()->get_index();
      return a[i1][i2];
    }
  };

  MatrixGraph::MatrixGraph
  (const std::vector<VertexSHR> &vs,
   const std::set<EdgeSHR,
   decltype(compare_edge_graph)*> &es):
    BaseGraph(vs, es),
    a(vs.size(), std::vector<bool>(vs.size()))
  {
    std::set<EdgeSHR>::const_iterator it = es.cbegin();
    while(it != es.cend())
      {
	std::size_t i1 =
	  (*it)->get_first_vertex()->get_index();
	std::size_t i2 =
	  (*it)->get_second_vertex()->get_index();
	a[i1][i2] = true;
	++it;
      }
  }

}


#endif
