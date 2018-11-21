#ifndef BFS_GRAPH_H
#define BFS_GRAPH_H


#include <queue>
#include <utility>
#include "chapter-22/edge_graph/edge_graph.h"
#include "chapter-22/vertex_graph/vertex_graph.h"
#include "chapter-22/linked_list_graph/linked_list_graph.h"

namespace CLRS
{
  enum class BFSVertexColor {white, gray, black};

  class BFSVertexGraph: public VertexGraph
  {
  private:
    BFSVertexColor color = BFSVertexColor::white;
    std::size_t p_index = 0;
    bool p_set = false;
    std::size_t d = 0;
    bool d_set = false;
  public:
    BFSVertexGraph(std::size_t i): VertexGraph(i) {}
    BFSVertexColor get_color() const {return color;}
    void set_color(BFSVertexColor c) {color = c;}
    std::size_t get_p_() const {return p_index;}
    bool is_p_set() const {return p_set;}
    void set_p_b() {p_set = true;}
    void set_p(std::size_t i) {p_index = i;}
    std::size_t get_d() const {return d;}
    bool is_d_set() const {return d_set;}
    void set_d_b() {d_set = true;}
    void set_d(std::size_t D) {d = D;}
  };

  void bfs_graph
  (LinkedListGraph<BFSVertexGraph,
   EdgeGraph<BFSVertexGraph>> &g,
   std::size_t i)
  {
    g.vertex(i).set_color(BFSVertexColor::gray);
    g.vertex(i).set_d_b();
    std::queue<std::size_t> q;
    q.push(i);
    while(!q.empty())
      {
	std::size_t u = q.front();
	q.pop();
	for(std::size_t v : g.get_list(u))
	  {
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
	// g
	  .vertex(u).set_color(BFSVertexColor::black);
      }
  }
}


#endif
