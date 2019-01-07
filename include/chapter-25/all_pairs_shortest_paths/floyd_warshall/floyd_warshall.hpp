#ifndef FLOYD_WARSHALL_H
#define FLOYD_WARSHALL_H


#include <utility>
#include <vector>
#include "chapter-22/vertex_graph/vertex_graph.hpp"
#include "chapter-25/all_pairs_shortest_paths/all_pairs_shortest_paths_utilities.hpp"

namespace CLRS
{
  std::vector<std::vector<APSPMatrixElement>>
  floyd_warshall
  (const std::vector<std::vector<APSPMatrixElement>> &w)
  {
    std::size_t n = w.size();
    auto D = w;
    auto d = D;
    APSPMatrixElement temp;
    for(std::size_t k = 0; k != n; ++k)
      {
	d = D;
	for(std::size_t i = 0; i != n; ++i)
	  for(std::size_t j = 0; j != n; ++j)
	    {
	      temp = d[i][k] + d[k][j];
	      if(temp < d[i][j])
		D[i][j] = temp;
	      else if(d[i][j] < temp)
		D[i][j] = d[i][j];
	    } 
      }
    return D;
  }

  std::vector<std::vector<bool>>
  transitive_closure
  (const APSPMatrixGraph &g)
  {
    std::size_t n = g.get_vertexes_size();
    std::vector<std::vector<bool>>
      T(n, std::vector<bool>(n));
    for(std::size_t i = 0; i != n; ++i)
      for(std::size_t j = 0; j != n; ++j)
	{
	  if(i == j || g.edge_or_not(i, j))
	    T[i][j] = true;
	  else
	    T[i][j] = false;
	}
    auto t = T;
    for(std::size_t k = 0; k != n; ++k)
      {
	t = T;
	for(std::size_t i = 0; i != n; ++i)
	  for(std::size_t j = 0; j != n; ++j)
	    T[i][j] = t[i][j] || (t[i][k] && t[k][j]);
      }
    return T;
  }
}


#endif
