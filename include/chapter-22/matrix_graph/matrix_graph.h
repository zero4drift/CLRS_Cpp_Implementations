#ifndef MATRIX_GRAPH_H
#define MATRIX_GRAPH_H


#include <utility>
#include <vector>
#include "chapter-22/base_graph/base_graph.h"

namespace CLRS
{ 
  template <typename T1, typename T2>
  class MatrixGraph: public BaseGraph<T1, T2>
  {
  protected:
    // square matrix
    std::vector<std::vector<bool>> a;
  public:
    MatrixGraph(const std::vector<T1> &vs,
		const std::vector<T2> &es);
    bool edge_or_not(const T2 &e) const override
    {
      std::size_t i1 = e.get_first_vertex();
      std::size_t i2 = e.get_second_vertex();
      return a[i1][i2];
    }
  };

  template <typename T1, typename T2>
  MatrixGraph<T1, T2>::MatrixGraph
  (const std::vector<T1> &vs,
   const std::vector<T2> &es):
    BaseGraph<T1, T2>(vs, es),
    a(vs.size(), std::vector<bool>(vs.size()))
  {
    auto it = es.cbegin();
    while(it != es.cend())
      {
	std::size_t i1 =
	  (*it).get_first_vertex();
	std::size_t i2 =
	  (*it).get_second_vertex();
	a[i1][i2] = true;
	++it;
      }
  }

}


#endif
