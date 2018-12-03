#ifndef MAXIMUM_FLOW_UTILITIES_H
#define MAXIMUM_FLOW_UTILITIES_H


#include <vector>
#include <queue>
#include <utility>
#include "chapter-22/linked_list_graph/linked_list_graph.h"
#include "chapter-22/bfs_graph/bfs_graph.h"

namespace CLRS
{
  class MaximumFlowEdgeGraph:
    public EdgeGraph<BFSVertexGraph>
  {
    unsigned f = 0;
    unsigned c;
    bool is_residual = false;
  public:
    MaximumFlowEdgeGraph(unsigned C,
			 const BFSVertexGraph &v1,
			 const BFSVertexGraph &v2):
      EdgeGraph(v1, v2),c(C) {}
    MaximumFlowEdgeGraph(unsigned C,
			 std::size_t i1,
			 std::size_t i2):
      EdgeGraph(i1, i2),c(C) {}
    unsigned get_f() const {return f;}
    unsigned get_c() const {return c;}
    void incr_f(unsigned F) {f += F;}
    void decr_f(unsigned F) {f -= F;}
    bool get_residual() const {return is_residual;}
    void set_residual() {is_residual = true;}
  };

  class MaximumFlowLinkedListGraph:
    public LinkedListGraph<BFSVertexGraph, MaximumFlowEdgeGraph>
  {
  public:
    MaximumFlowLinkedListGraph(const std::vector<BFSVertexGraph> vs,
			       const std::vector<MaximumFlowEdgeGraph> es);
  };

  MaximumFlowLinkedListGraph::
  MaximumFlowLinkedListGraph
  (const std::vector<BFSVertexGraph> vs,
   const std::vector<MaximumFlowEdgeGraph> es):
    LinkedListGraph<BFSVertexGraph, MaximumFlowEdgeGraph>(vs, es)
  {
    for(const auto &e : BaseGraph::edges)
      {
	std::size_t u = e.get_first_vertex();
	std::size_t v = e.get_second_vertex();
	if(!edge_or_not(v, u))
	  {
	    auto e = MaximumFlowEdgeGraph(v, u, 0);
	    e.set_residual();
	    std::size_t index = edges.size();
	    BaseGraph::edges.push_back(e);
	    LinkedListGraph::adj[v].push_back(index);
	  }
      }
  }

  std::vector<MaximumFlowEdgeGraph> maximum_flow_path
  (MaximumFlowLinkedListGraph &g,
   std::size_t s, std::size_t t)
  {
    std::vector<MaximumFlowEdgeGraph> r;
    while(t != s)
      {
	if(g.vertex(t).is_p_set())
	  r.push_back(g.edge(g.vertex(t).get_p(), t));
	else
	  return std::vector<MaximumFlowEdgeGraph>();
	t = g.vertex(t).get_p();
      }
    return r;
  }

  std::vector<MaximumFlowEdgeGraph> maximum_bfs_graph
  (MaximumFlowLinkedListGraph &g,
   std::size_t s, std::size_t t)
  {
    // initialize
    for(std::size_t i = 0; i != g.get_vertexes_size(); ++i)
      {
	g.vertex(i).set_color(BFSVertexColor::white);
	g.vertex(i).set_p(0);
	g.vertex(i).clear_p_b();
	g.vertex(i).set_d(0);
	g.vertex(i).clear_d_b();
      }
    g.vertex(s).set_color(BFSVertexColor::gray);
    g.vertex(s).set_d_b();
    std::queue<std::size_t> q;
    q.push(s);
    while(!q.empty())
      {
	std::size_t u = q.front();
	q.pop();
	for(const auto &ev : g.get_adj_vertexes(u))
	  {
	    auto e = g.get_edges()[ev];
	    if((!e.get_residual() && e.get_f() != e.get_c())
	       || (e.get_residual() && e.get_f() != 0))
	      {
		std::size_t v = e.get_second_vertex();
		if(g.vertex(v).get_color() ==
		   BFSVertexColor::white)
		  {
		    g.vertex(v).set_color
		      (BFSVertexColor::gray);
		    g.vertex(v).set_d(g.vertex(u).get_d() + 1);
		    g.vertex(v).set_d_b();
		    g.vertex(v).set_p(u);
		    g.vertex(v).set_p_b();
		    q.push(v);
		  }
	      }
	  }
	g.vertex(u).set_color(BFSVertexColor::black);
      }
    return maximum_flow_path(g, s, t);
  }

  unsigned get_cf(const MaximumFlowEdgeGraph &e,
		  MaximumFlowLinkedListGraph &g)
  {
    std::size_t u = e.get_first_vertex();
    std::size_t v = e.get_second_vertex();
    if(g.edge_or_not(u, v))
      return e.get_c() - e.get_f();
    else if(g.edge_or_not(v, u))
      return g.edge(v, u).get_f();
    return 0;
  }
}


#endif
