#ifndef SSSP_UTILITIES_H
#define SSSP_UTILITIES_H


#include <utility>
#include "chapter-22/vertex_graph/vertex_graph.h"
#include "chapter-22/edge_graph/edge_graph.h"
#include "chapter-22/linked_list_graph/linked_list_graph.h"

namespace CLRS
{
  template <typename T>
  class SSSPWeightEdgeGraph: public EdgeGraph<T>
  {
    int weight;
  public:
    SSSPWeightEdgeGraph(const T &v1,
			const T &v2,
			int w):
      EdgeGraph<T>(v1, v2), weight(w) {}
    int get_weight() const {return weight;}
  };

  class SSSPVertexGraph: public VertexGraph
  {
    int d = 0;
    bool d_set = false;
    std::size_t p = 0;
    bool p_set = false;
  public:
    SSSPVertexGraph(std::size_t i):
      VertexGraph(i) {}
    int get_d() const {return d;}
    void set_d(int D) {d = D;}
    bool is_d_set() const {return d_set;}
    void set_d_flag() {d_set = true;}
    std::size_t get_p() const {return p;}
    void set_p(std::size_t P) {p = P;}
    bool is_p_set() const {return p_set;}
    void set_p_flag() {p_set = true;}
  };

  /*
   * textbook assumes algorithms in
   * this chpater are based on linked list graph
   */
  void initialize_single_source
  (LinkedListGraph<SSSPVertexGraph,
   SSSPWeightEdgeGraph<SSSPVertexGraph>> &g,
   std::size_t s)
  {
    g.vertex(s).set_d(0);
    g.vertex(s).set_d_flag();
  }

  inline void sssp_relax_helper
  (SSSPVertexGraph &u,
   SSSPVertexGraph &v,
   std::size_t w)
  {
    v.set_d(u.get_d() + w);
    v.set_d_flag();
    v.set_p(u.get_index());
    v.set_p_flag();
  }

  void sssp_relax
  (LinkedListGraph<SSSPVertexGraph,
   SSSPWeightEdgeGraph<SSSPVertexGraph>> &g,
   const SSSPWeightEdgeGraph<SSSPVertexGraph> &e)
  {
    std::size_t ui = e.get_first_vertex();
    std::size_t vi = e.get_second_vertex();
    auto &u = g.vertex(ui);
    auto &v = g.vertex(vi);
    if(v.is_d_set() && u.is_d_set())
      {
	if(v.get_d() > (u.get_d() + e.get_weight()))
	  sssp_relax_helper(u, v, e.get_weight());
      }
    else if(!v.is_d_set() && u.is_d_set())
      sssp_relax_helper(u, v, e.get_weight());
  }
}


#endif
