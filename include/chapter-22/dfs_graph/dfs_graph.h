#ifndef DFS_GRAPH_H
#define DFS_GRAPH_H


#include <utility>
#include "chapter-22/edge_graph/edge_graph.h"
#include "chapter-22/vertex_graph/vertex_graph.h"
#include "chapter-22/linked_list_graph/linked_list_graph.h"

namespace CLRS
{
  enum class DFSVertexColor {white, gray, black};

  class DFSVertexGraph: public VertexGraph
  {
  private:
    DFSVertexColor color = DFSVertexColor::white;
    std::size_t p_index = 0;
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
    std::size_t get_p() const {return p_index;}
    bool is_p_set() const {return p_set;}
    void set_p_b() {p_set = true;}
    void set_p(std::size_t i) {p_index = i;}
    std::size_t get_d() const {return d;}
    bool is_d_set() const {return d_set;}
    void set_d_b() {d_set = true;}
    void set_d(std::size_t D) {d = D;}
    std::size_t get_f() const {return f;}
    bool is_f_set() const {return f_set;}
    void set_f_b() {f_set = true;}
    void set_f(std::size_t F) {f = F;}
  };

  void dfs_visit_graph
  (LinkedListGraph<DFSVertexGraph,
   EdgeGraph<DFSVertexGraph>> &g,
   std::size_t u, std::size_t *t)
  {
    *t = *t + 1;
    g.vertex(u).set_d(*t);
    g.vertex(u).set_f_b();
    g.vertex(u).set_color(DFSVertexColor::gray);
    for(std::size_t v : g.get_list(u))
      {
	if(g.vertex(v).get_color() ==
	   DFSVertexColor::white)
	  {
	    g.vertex(v).set_p(u);
	    g.vertex(v).set_p_b();
	    dfs_visit_graph(g, v, t);
	  }
      }
    g.vertex(u).set_color(DFSVertexColor::black);
    *t = *t + 1;
    g.vertex(u).set_f(*t);
    g.vertex(u).set_f_b();
  }

  void dfs_graph
  (LinkedListGraph<DFSVertexGraph,
   EdgeGraph<DFSVertexGraph>> &g)
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
}


#endif
