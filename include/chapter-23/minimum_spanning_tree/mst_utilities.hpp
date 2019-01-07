#ifndef MST_UTILITIES_H
#define MST_UTILITIES_H


#include "chapter-22/edge_graph/edge_graph.hpp"
#include "chapter-22/vertex_graph/vertex_graph.hpp"

namespace CLRS
{
  template <typename T>
  class WeightEdgeGraph: public EdgeGraph<T>
  {
    unsigned weight;
  public:
    WeightEdgeGraph(const T &v1,
		    const T &v2,
		    unsigned w):
      EdgeGraph<T>(v1, v2), weight(w) {}
    WeightEdgeGraph(std::size_t i1,
		    std::size_t i2,
		    unsigned w):
      EdgeGraph<T>(i1, i2), weight(w) {}
    unsigned get_weight() const {return weight;}
  };

  class WeightVertexGraph: public VertexGraph
  {
    unsigned weight = 0;
    std::size_t p;
    bool weight_set = false;
    bool p_set = false;
    bool in_fib_h = false;
  public:
    WeightVertexGraph(std::size_t i):
      VertexGraph(i) {}
    unsigned get_weight() const {return weight;}
    void set_weight(unsigned w) {weight = w;}
    bool is_weight_set() const {return weight_set;}
    void set_weight_flag() {weight_set = true;}
    std::size_t get_p() const {return p;}
    void set_p(std::size_t P) {p = P;}
    bool is_p_set() const {return p_set;}
    void set_p_flag() {p_set = true;}
    bool get_in_fib_h() const {return in_fib_h;}
    void set_in_fib_h() {in_fib_h = true;}
    void clear_in_fib_h() {in_fib_h = false;}
    bool operator<(const WeightVertexGraph &v) const;
  };

  bool WeightVertexGraph::operator<
  (const WeightVertexGraph &v) const
  {
    if(weight_set && v.is_weight_set())
      return weight < v.get_weight();
    else if(weight_set && !v.is_weight_set())
      return true;
    else if(!weight_set && v.is_weight_set())
      return false;
    else
      return true;
  }
}


#endif
