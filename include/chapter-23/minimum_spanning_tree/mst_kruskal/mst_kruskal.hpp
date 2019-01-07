#ifndef MST_KRUSKAL_H
#define MST_KRUSKAL_H


#include <vector>
#include <utility>
#include <memory>
#include <algorithm>
#include "chapter-21/tree_disjoint_set/tree_disjoint_set.hpp"
#include "chapter-22/base_graph/base_graph.hpp"
#include "chapter-22/vertex_graph/vertex_graph.hpp"
#include "chapter-23/minimum_spanning_tree/mst_utilities.hpp"

namespace CLRS
{

  std::vector<std::pair<std::size_t, std::size_t>>
  mst_kruskal
  (BaseGraph<VertexGraph,
   WeightEdgeGraph<VertexGraph>> &g)
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
    std::sort(g.edgesr().begin(),
	      g.edgesr().end(),
	      [](const WeightEdgeGraph<VertexGraph> &e1,
		 const WeightEdgeGraph<VertexGraph> &e2)
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
