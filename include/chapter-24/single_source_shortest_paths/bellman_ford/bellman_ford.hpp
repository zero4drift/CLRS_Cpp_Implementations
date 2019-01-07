#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H


#include <utility>
#include "chapter-22/linked_list_graph/linked_list_graph.hpp"
#include "chapter-24/single_source_shortest_paths/sssp_utilities.hpp"

namespace CLRS
{
  bool bellman_ford
  (LinkedListGraph<SSSPVertexGraph,
   SSSPWeightEdgeGraph<SSSPVertexGraph>> &g,
   std::size_t s)
  {
    initialize_single_source(g, s);
    for(std::size_t i = 0;
	i != g.get_vertexes_size() - 1;
	++i)
      {
	for(const auto &e : g.get_edges())
	  sssp_relax(g, e);
      }
    for(const auto &e : g.get_edges())
      {
	std::size_t ui = e.get_first_vertex();
	std::size_t vi = e.get_second_vertex();
	auto u = g.vertex(ui);
	auto v = g.vertex(vi);
	if(v.is_dw_set() && u.is_dw_set())
	  {
	    if(v.get_dw() > (u.get_dw() + e.get_weight()))
	      return false;
	  }
      }
    return true;
  }
 
}


#endif
