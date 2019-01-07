#ifndef MAXIMUM_FLOW_H
#define MAXIMUM_FLOW_H


#include "chapter-22/bfs_graph/bfs_graph.hpp"
#include "chapter-26/maximum_flow_utilities.hpp"

namespace CLRS
{
  void ford_fulkserson(MaximumFlowLinkedListGraph &g,
		       std::size_t s, std::size_t t)
  {
    auto p = maximum_bfs_graph(g, s, t);
    while(p.size())
      {
	unsigned min_cf = -1;
	for(const auto &ev : p)
	  {
	    if(get_cf(g.edge(ev), g) < min_cf)
	      min_cf = get_cf(g.edge(ev), g);
	  }
	for(const auto &ev : p)
	  {
	    auto &e = g.edge(ev);
	    if(!e.get_residual())
	      {
		e.incr_f(min_cf);
		g.edge(e.get_second_vertex(),
		       e.get_first_vertex()).incr_f(min_cf);
	      }
	    else
	      {
		e.decr_f(min_cf);
		g.edge(e.get_second_vertex(),
		       e.get_first_vertex()).decr_f(min_cf);
	      }
	  }
	p = maximum_bfs_graph(g, s, t);
      }
  }
}


#endif
