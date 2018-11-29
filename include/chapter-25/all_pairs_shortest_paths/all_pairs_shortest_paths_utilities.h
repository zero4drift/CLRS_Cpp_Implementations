#ifndef All_PAIRS_SHORTEST_PATHS_UTILITIES_H
#define All_PAIRS_SHORTEST_PATHS_UTILITIES_H


#include <utility>
#include <vector>
#include "chapter-22/base_graph/base_graph.h"
#include "chapter-22/edge_graph/edge_graph.h"
#include "chapter-22/vertex_graph/vertex_graph.h"

namespace CLRS
{ 
  class APSPMatrixElement
  {
    int weight = 0;
    bool weight_set = false;
  public:
    APSPMatrixElement() = default;
    APSPMatrixElement(int w, bool s):
      weight(w), weight_set(true) {}
    int get_weight() const {return weight;}
    void set_weight(int w) {weight = w;}
    bool is_weight_set() const {return weight_set;}
    void set_weight_set() {weight_set = true;}
    bool operator<(const APSPMatrixElement &e) const;
    APSPMatrixElement operator+(const APSPMatrixElement &e) const;
  };
  
  bool APSPMatrixElement::operator<(const APSPMatrixElement &e) const
  {
    if(weight_set && e.is_weight_set())
      return weight < e.get_weight();
    else if(weight_set && !e.is_weight_set())
      return true;
    else if(!weight_set && e.is_weight_set())
      return false;
    else
      return false;
  }
  
  APSPMatrixElement APSPMatrixElement::
  operator+(const APSPMatrixElement &e) const
  {
    if(weight_set && e.is_weight_set())
      return APSPMatrixElement
	(weight + e.get_weight(), true);
    else
      return APSPMatrixElement();
  }
  
  class APSPWeightEdgeGraph: public EdgeGraph<VertexGraph>
  {
    int weight;
  public:
    APSPWeightEdgeGraph(const VertexGraph &v1,
			const VertexGraph &v2,
			int w):
      EdgeGraph<VertexGraph>(v1, v2), weight(w) {}
    int get_weight() const {return weight;}
  };

  class APSPMatrixGraph:
    public BaseGraph<VertexGraph, APSPWeightEdgeGraph>
  {
  protected:
    // square matrix
    std::vector<std::vector<APSPMatrixElement>> a;
  public:
    APSPMatrixGraph
    (const std::vector<VertexGraph> &vs,
     const std::vector<APSPWeightEdgeGraph> &es);
    bool edge_or_not(const APSPWeightEdgeGraph &e) const override
    {
      std::size_t i1 = e.get_first_vertex();
      std::size_t i2 = e.get_second_vertex();
      return a[i1][i2].is_weight_set();
    }
    bool edge_or_not(std::size_t i1, std::size_t i2) const
    {
      return a[i1][i2].is_weight_set();
    }
    std::vector<std::vector<APSPMatrixElement>> get_matrix() const
    {return a;}
  };

  APSPMatrixGraph::APSPMatrixGraph
  (const std::vector<VertexGraph> &vs,
   const std::vector<APSPWeightEdgeGraph> &es):
    BaseGraph<VertexGraph, APSPWeightEdgeGraph>(vs, es),
    a(vs.size(), std::vector<APSPMatrixElement>(vs.size()))
  {
    for(std::size_t i = 0; i != vs.size(); ++i)
      {
	a[i][i].set_weight(0);
	a[i][i].set_weight_set();
      }
    auto it = es.cbegin();
    while(it != es.cend())
      {
	std::size_t i1 =
	  it->get_first_vertex();
	std::size_t i2 =
	  it->get_second_vertex();
	a[i1][i2].set_weight(it->get_weight());
	a[i1][i2].set_weight_set();
	++it;
      }
  }

}


#endif
