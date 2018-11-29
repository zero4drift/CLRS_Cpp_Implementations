#ifndef MATRIX_ALL_PAIRS_SHORTEST_PATHS_H
#define MATRIX_ALL_PAIRS_SHORTEST_PATHS_H


#include <utility>
#include <vector>
#include "chapter-22/vertex_graph/vertex_graph.h"
#include "chapter-25/all_pairs_shortest_paths/all_pairs_shortest_paths_utilities.h"

namespace CLRS
{
  std::vector<std::vector<APSPMatrixElement>>
  extend_shortest_paths
  (const std::vector<std::vector<APSPMatrixElement>> &l,
   const std::vector<std::vector<APSPMatrixElement>> &w)
  {
    std::size_t n = l.size();
    auto lr = l;
    APSPMatrixElement temp;
    for(std::size_t i = 0; i != n; ++i)
      for(std::size_t j = 0; j != n; ++j)
	for(std::size_t k = 0; k != n; ++k)
	  {
	    temp = l[i][k] + w[k][j];
	    if(temp < lr[i][j])
	      lr[i][j] = temp;
	  }
    return lr;
  }

  std::vector<std::vector<APSPMatrixElement>>
  faster_all_pairs_shortest_paths
  (const std::vector<std::vector<APSPMatrixElement>> &w)
  {
    std::size_t n = w.size();
    auto l = w;
    std::size_t m = 1;
    while(m < n - 1)
      {
	l = extend_shortest_paths(l, l);
	m *= 2;
      }
    return l;
  }
}


#endif
