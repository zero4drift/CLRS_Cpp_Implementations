#ifndef DFS_GRAPH_H
#define DFS_GRAPH_H


#include <list>
#include <utility>
#include "chapter-22/edge_graph/edge_graph.hpp"
#include "chapter-22/vertex_graph/vertex_graph.hpp"
#include "chapter-22/linked_list_graph/linked_list_graph.hpp"

namespace CLRS
{
  enum class DFSVertexColor {white, gray, black};

  class DFSVertexGraph: public VertexGraph
  {
  private:
    DFSVertexColor color = DFSVertexColor::white;
    std::size_t p = 0;
    bool p_set = false;
    // visit time
    std::size_t d = 0;
    bool d_set = false;
    // visit completed time 
    std::size_t f = 0;
    bool f_set = false;
  public:
    DFSVertexGraph(std::size_t i): VertexGraph(i) {}
    DFSVertexColor get_color() const {return color;}
    void set_color(DFSVertexColor c) {color = c;}
    std::size_t get_p() const {return p;}
    bool is_p_set() const {return p_set;}
    void set_p_flag() {p_set = true;}
    void set_p(std::size_t i) {p = i;}
    std::size_t get_d() const {return d;}
    bool is_d_set() const {return d_set;}
    void set_d_flag() {d_set = true;}
    void set_d(std::size_t D) {d = D;}
    std::size_t get_f() const {return f;}
    bool is_f_set() const {return f_set;}
    void set_f_flag() {f_set = true;}
    void set_f(std::size_t F) {f = F;}
  };

  template <typename T1, typename T2>
  void dfs_visit_graph
  (LinkedListGraph<T1, T2> &g,
   std::size_t u, std::size_t *t)
  {
    *t = *t + 1;
    g.vertex(u).set_d(*t);
    g.vertex(u).set_d_flag();
    g.vertex(u).set_color(DFSVertexColor::gray);
    for(const auto &ev : g.get_adj_vertexes(u))
      {
	std::size_t v = g.edgesr()[ev].get_second_vertex();
	if(g.vertex(v).get_color() ==
	   DFSVertexColor::white)
	  {
	    g.vertex(v).set_p(u);
	    g.vertex(v).set_p_flag();
	    dfs_visit_graph(g, v, t);
	  }
      }
    g.vertex(u).set_color(DFSVertexColor::black);
    *t = *t + 1;
    g.vertex(u).set_f(*t);
    g.vertex(u).set_f_flag();
  }

  template <typename T1, typename T2>
  void dfs_graph
  (LinkedListGraph<T1, T2> &g)
  {
    std::size_t time = 0;
    std::size_t amount = g.get_vertexes_size();
    for(std::size_t index = 0;
	index < amount;
	++index)
      {
	if(g.vertex(index).get_color() ==
	   DFSVertexColor::white)
	  dfs_visit_graph(g, index, &time);
      }
  }

  // TODO: any better way to implement dfs topo sort?
  template <typename T1, typename T2>
  void topo_dfs_visit_graph
  (LinkedListGraph<T1, T2> &g,
   std::size_t u, std::size_t *t,
   std::list<std::size_t> &l)
  {
    *t = *t + 1;
    g.vertex(u).set_d(*t);
    g.vertex(u).set_d_flag();
    g.vertex(u).set_color(DFSVertexColor::gray);
    for(const auto &ev: g.get_adj_vertexes(u))
      {
	std::size_t v = g.edgesr()[ev].get_second_vertex();
	if(g.vertex(v).get_color() ==
	   DFSVertexColor::white)
	  {
	    g.vertex(v).set_p(u);
	    g.vertex(v).set_p_flag();
	    topo_dfs_visit_graph(g, v, t, l);
	  }
      }
    g.vertex(u).set_color(DFSVertexColor::black);
    l.push_front(u);
    *t = *t + 1;
    g.vertex(u).set_f(*t);
    g.vertex(u).set_f_flag();
  }

  template <typename T1, typename T2>
  void topo_dfs_graph
  (LinkedListGraph<T1, T2> &g,
   std::list<std::size_t> &l)
  {
    std::size_t time = 0;
    std::size_t amount = g.get_vertexes_size();
    for(std::size_t index = 0;
	index < amount;
	++index)
      {
	if(g.vertex(index).get_color() ==
	   DFSVertexColor::white)
	  topo_dfs_visit_graph
	    (g, index, &time, l);
      }
  }
  
  template <typename T1, typename T2>
  std::list<std::size_t> topological_sort_graph
  (LinkedListGraph<T1, T2> &g)
  {
    std::list<std::size_t> l;
    topo_dfs_graph(g, l);
    return l;
  }

  // implement strongly connected components
  template <typename T1, typename T2>
  class SCCLinkedListGraph: public LinkedListGraph<T1, T2>
  {
  public:
    SCCLinkedListGraph(const std::vector<T1> &vs,
		       const std::vector<T2> &es):
      LinkedListGraph<T1, T2>(vs, es) {}
    void tranpose();
  };

  template <typename T1, typename T2>
  void SCCLinkedListGraph<T1, T2>::tranpose()
  {
    for(auto &l: LinkedListGraph<T1, T2>::adj)
      l.clear();
    std::size_t i = 0;
    for(auto &e : BaseGraph<T1, T2>::edges)
      {
	std::size_t i1 = e.get_first_vertex();
	std::size_t i2 = e.get_second_vertex();
	e.set_first_vertex(i2);
	e.set_second_vertex(i1);
	LinkedListGraph<T1, T2>::adj[i2].push_back(i);
	++i;
      }
  }

  template <typename T1, typename T2>
  void scc_dfs_graph
  (SCCLinkedListGraph<T1, T2> &g,
   const std::list<std::size_t> &decr_f)
  {
    std::size_t time = 0;
    for(std::size_t index : decr_f)
      {
	if(g.vertex(index).get_color() ==
	   DFSVertexColor::white)
	  dfs_visit_graph(g, index, &time);
      }
  }

  // return a graph proves scc
  template <typename T1, typename T2>
  SCCLinkedListGraph<T1, T2>
  scc_graph
  (SCCLinkedListGraph<T1, T2> &g)
  {
    auto gt = g;
    gt.tranpose();
    std::list<std::size_t> l;
    topo_dfs_graph(g, l);
    scc_dfs_graph(gt, l);
    return gt;
  }
}


#endif
