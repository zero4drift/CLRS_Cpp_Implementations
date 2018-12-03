#ifndef MAXIMUM_FLOW_H
#define MAXIMUM_FLOW_H


#include "chapter-22/bfs_graph/bfs_graph.h"
#include "chapter-26/maximum_flow_utilities.h"

namespace CLRS
{
  void ford_fulkserson(MaximumFlowLinkedListGraph &g,
		       std::size_t s, std::size_t t)
  {
    auto gf = MaximumFlowLinkedListGraph
      (g.get_vertexes(), g.get_edges());
    auto p = maximum_bfs_graph(gf, s, t);
    std::size_t i = 2;
    while(p.size())
      {
	unsigned min_cf = -1;
	for(const auto &e : p)
	  {
	    if(get_cf(e, g) < min_cf)
	      min_cf = get_cf(e, g);
	  }
	for(const auto &e : p)
	  {
	    std::size_t u = e.get_first_vertex();
	    std::size_t v = e.get_second_vertex();
	    if(!e.get_residual())
	      {
		gf.edge(u, v).incr_f(min_cf);
		g.edge(u, v).incr_f(min_cf);
		gf.edge(v, u).incr_f(min_cf);
	      }
	    else
	      {
		gf.edge(v, u).decr_f(min_cf);
		g.edge(v, u).decr_f(min_cf);
		gf.edge(u, v).decr_f(min_cf);
	      }
	  }
	p = maximum_bfs_graph(gf, s, t);
      }
  }
}


#endif
