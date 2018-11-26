#ifndef SSSP_UTILITIES_H
#define SSSP_UTILITIES_H


#include <utility>
#include "chapter-22/vertex_graph/vertex_graph.h"
#include "chapter-22/edge_graph/edge_graph.h"
#include "chapter-22/linked_list_graph/linked_list_graph.h"
#include "chapter-22/dfs_graph/dfs_graph.h"

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
    int dw = 0;
    bool dw_set = false;
    std::size_t p = 0;
    bool p_set = false;
  public:
    SSSPVertexGraph(std::size_t i):
      VertexGraph(i) {}
    int get_dw() const {return dw;}
    void set_dw(int D) {dw = D;}
    bool is_dw_set() const {return dw_set;}
    void set_dw_flag() {dw_set = true;}
    std::size_t get_p() const {return p;}
    void set_p(std::size_t P) {p = P;}
    bool is_p_set() const {return p_set;}
    void set_p_flag() {p_set = true;}
  };

  // another class supports SSSP and also dfs
  class SSSPDFSVertexGraph: public DFSVertexGraph
  {
    int dw = 0;
    bool dw_set = false;
  public:
    SSSPDFSVertexGraph(std::size_t i):
      DFSVertexGraph(i) {}
    int get_dw() const {return dw;}
    void set_dw(int D) {dw = D;}
    bool is_dw_set() const {return dw_set;}
    void set_dw_flag() {dw_set = true;}
  };

  /*
   * textbook assumes algorithms in
   * this chpater are based on linked list graph
   */
  template <typename T1, typename T2>
  void initialize_single_source
  (LinkedListGraph<T1, T2> &g,
   std::size_t s)
  {
    g.vertex(s).set_dw(0);
    g.vertex(s).set_dw_flag();
  }

  template <typename T>
  inline void sssp_relax_helper
  (T &u, T&v,
   std::size_t w)
  {
    v.set_dw(u.get_dw() + w);
    v.set_dw_flag();
    v.set_p(u.get_index());
    v.set_p_flag();
  }

  template <typename T1, typename T2>
  void sssp_relax
  (LinkedListGraph<T1, T2> &g, const T2 &e)
  {
    std::size_t ui = e.get_first_vertex();
    std::size_t vi = e.get_second_vertex();
    auto &u = g.vertex(ui);
    auto &v = g.vertex(vi);
    if(v.is_dw_set() && u.is_dw_set())
      {
	if(v.get_dw() > (u.get_dw() + e.get_weight()))
	  sssp_relax_helper(u, v, e.get_weight());
      }
    else if(!v.is_dw_set() && u.is_dw_set())
      sssp_relax_helper(u, v, e.get_weight());
  }
}


#endif
