#ifndef MST_KRUSKAL_H
#define MST_KRUSKAL_H


#include <vector>
#include <utility>
#include <memory>
#include <algorithm>
#include "chapter-21/tree_disjoint_set/tree_disjoint_set.h"
#include "chapter-22/base_graph/base_graph.h"
#include "chapter-22/vertex_graph/vertex_graph.h"
#include "chapter-22/edge_graph/edge_graph.h"

namespace CLRS
{
  class WeightEdgeGraph: public EdgeGraph<VertexGraph>
  {
  private:
    unsigned weight;
  public:
    WeightEdgeGraph(const VertexGraph &v1,
		    const VertexGraph &v2,
		    unsigned w):
      EdgeGraph<VertexGraph>(v1, v2), weight(w) {}
    unsigned get_weight() const {return weight;}
  };

  std::vector<std::pair<std::size_t, std::size_t>>
  mst_kruskal
  (BaseGraph<VertexGraph, WeightEdgeGraph> &g)
  {
    std::vector
      <std::pair<std::size_t, std::size_t>> a;
    std::vector
      <std::shared_ptr
       <TreeDisjointSetNode<std::size_t>>> vp;
    std::size_t s = g.get_vertexes_size();
    for (std::size_t i = 0; i != s; ++i)
      {
	auto p = std::make_shared
	  <TreeDisjointSetNode<std::size_t>>(i);
	vp.push_back(p);
	CLRS::tree_disjoint_make_set(p);
      }
    std::sort(g.get_edges().begin(),
	      g.get_edges().end(),
	      [](const WeightEdgeGraph &e1,
		 const WeightEdgeGraph &e2)
	      {return e1.get_weight() < e2.get_weight();});
    for(const auto &e : g.get_edges())
      {
	std::size_t i1 = e.get_first_vertex();
	std::size_t i2 = e.get_second_vertex();
	if(CLRS::tree_disjoint_find_set(vp[i1]) !=
	   CLRS::tree_disjoint_find_set(vp[i2]))
	  {
	    a.push_back(std::make_pair(i1, i2));
	    CLRS::tree_disjoint_union(vp[i1], vp[i2]);
	  }
      } 
    return a;
  }
}


#endif
