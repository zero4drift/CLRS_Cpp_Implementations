#ifndef MAXIMUM_FLOW_H
#define MAXIMUM_FLOW_H


#include <algorithm>
#include "chapter-22/bfs_graph/bfs_graph.h"
#include "chapter-26/maximum_flow_utilities.h"

namespace CLRS
{
  void ford_fulkserson(MaximumFlowLinkedListGraph &g,
		       std::size_t s, std::size_t t)
  {
    auto gf = g;
    for(auto p = maximum_bfs_graph(gf, s, t);
	p.size() > 1; p = maximum_bfs_graph(gf, s, t))
      {
	std::sort(p.begin(), p.end(),
		  [&gf](const MaximumFlowEdgeGraph &e1,
			const MaximumFlowEdgeGraph &e2)
		  {return get_cf(e1, gf) < get_cf(e2, gf);});
	unsigned min_cf = get_cf(p[0], gf);
	for(const auto &e : p)
	  {
	    std::size_t u = e.get_first_vertex();
	    std::size_t v = e.get_second_vertex();
	    if(!e.get_residual())
	      {
		gf.edge(u, v).incr_f(min_cf);
		g.edge(u, v).incr_f(min_cf);
		gf.reverse_edge_incr_f(v, u, min_cf);
	      }
	    else
	      {
		gf.edge(v, u).decr_f(min_cf);
		g.edge(v, u).decr_f(min_cf);
		gf.edge(u, v).decr_f(min_cf);
	      }
	  }
      }
  }
}


#endif
