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

class SSSPBaseVertexGraph: public VertexGraph
  {
    std::size_t p = 0;
    bool p_set = false;
  public:
    SSSPBaseVertexGraph(std::size_t i):
      VertexGraph(i) {}
    std::size_t get_p() const {return p;}
    void set_p(std::size_t P) {p = P;}
    bool is_p_set() const {return p_set;}
    void set_p_flag() {p_set = true;}
  };

  class SSSPVertexGraph: public SSSPBaseVertexGraph
  {
    int dw = 0;
    bool dw_set = false;
  public:
    SSSPVertexGraph(std::size_t i):
      SSSPBaseVertexGraph(i) {}
    int get_dw() const {return dw;}
    void set_dw(int D) {dw = D;}
    bool is_dw_set() const {return dw_set;}
    void set_dw_flag() {dw_set = true;}
    void clear_dw_flag() {dw_set = false;}
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
    void clear_dw_flag() {dw_set = false;}
  };

  // another class supports dijkstra and fibonacci heap
  class DijkstraVertexGraph: public SSSPBaseVertexGraph
  {
    unsigned dw = 0;
    bool dw_set = false;
  public:
    DijkstraVertexGraph(std::size_t i):
      SSSPBaseVertexGraph(i) {}
    unsigned get_dw() const {return dw;}
    void set_dw(unsigned d) {dw = d;}
    bool is_dw_set() const {return dw_set;}
    void set_dw_flag() {dw_set = true;}
    void clear_dw_flag() {dw_set = false;}
    bool operator<(const DijkstraVertexGraph &v) const;
  };

  bool DijkstraVertexGraph::operator<
  (const DijkstraVertexGraph &v) const
  {
    if(dw_set && v.is_dw_set())
      return dw < v.get_dw();
    else if(dw_set && !v.is_dw_set())
      return true;
    else if(!dw_set && v.is_dw_set())
      return false;
    else
      return false;
  }

  /*
   * textbook assumes algorithms in
   * this chpater are based on linked list graph
   */
  template <typename T1, typename T2>
  void initialize_single_source
  (LinkedListGraph<T1, T2> &g,
   std::size_t s)
  {
    for(std::size_t i = 0;
	i != g.get_vertexes_size();
	++i)
      {
	g.vertex(i).set_dw(0);
	g.vertex(i).clear_dw_flag();
      }
    g.vertex(s).set_dw(0);
    g.vertex(s).set_dw_flag();
  }

  template <typename T1, typename T2>
  inline void sssp_relax_helper
  (const T1 &u, T1 &v, const T2 &e)
  {
    v.set_dw(u.get_dw() + e.get_weight());
    v.set_dw_flag();
    v.set_p(u.get_index());
    v.set_p_flag();
  }

  template <typename T1, typename T2>
  T1 sssp_relax
  (LinkedListGraph<T1, T2> &g, const T2 &e)
  {
    std::size_t ui = e.get_first_vertex();
    std::size_t vi = e.get_second_vertex();
    auto &u = g.vertex(ui);
    auto &v = g.vertex(vi);
    if(v.is_dw_set() && u.is_dw_set())
      {
	if(v.get_dw() > (u.get_dw() + e.get_weight()))
	  sssp_relax_helper(u, v, e);
      }
    else if(!v.is_dw_set() && u.is_dw_set())
      sssp_relax_helper(u, v, e);
    return v;
  }
}


#endif
