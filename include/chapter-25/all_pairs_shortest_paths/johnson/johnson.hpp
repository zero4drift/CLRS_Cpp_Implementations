#ifndef JOHNSON_H
#define JOHNSON_H


#include <utility>
#include <vector>
#include <stdexcept>
#include "chapter-22/linked_list_graph/linked_list_graph.hpp"
#include "chapter-23/minimum_spanning_tree/mst_utilities.hpp"
#include "chapter-24/single_source_shortest_paths/bellman_ford/bellman_ford.hpp"
#include "chapter-24/single_source_shortest_paths/dijkstra/dijkstra.hpp"

namespace CLRS
{
  /* 
   * TODO: too many initialization work greatly lower efficience.
   * Needs improvement.
   */
  std::vector<std::vector<int>>
  johnson(const LinkedListGraph<SSSPVertexGraph,
	  SSSPWeightEdgeGraph<SSSPVertexGraph>> &g)
  {
    std::size_t n = g.get_vertexes_size();
    auto vn = SSSPVertexGraph(n);
    auto vs = g.get_vertexes();
    vs.push_back(vn);
    auto es = g.get_edges();
    for(std::size_t i = 0; i != n; ++i)
      {
	es.push_back
	  (SSSPWeightEdgeGraph<
	   SSSPVertexGraph>(n, i, 0));
      }
    auto g1 = LinkedListGraph<
      SSSPVertexGraph,
      SSSPWeightEdgeGraph<SSSPVertexGraph>>(vs, es);
    if(bellman_ford(g1, n) == false)
      std::logic_error
	("the input graph contains negative-weight cycle");
    std::vector<int> vh;
    for(std::size_t i = 0; i != n; ++i)
      vh.push_back(g1.vertex(i).get_dw());
    // create a graph suitable for dijkstra algorithm
    std::vector<DijkstraVertexGraph> dvs;
    std::vector<WeightEdgeGraph<DijkstraVertexGraph>> des;
    for(std::size_t i = 0; i != n; ++i)
      dvs.push_back(DijkstraVertexGraph(i));
    for(const auto &e : g.get_edges())
      des.push_back
	(WeightEdgeGraph<DijkstraVertexGraph>
	 (e.get_first_vertex(),
	  e.get_second_vertex(),
	  e.get_weight() +
	  vh[e.get_first_vertex()] -
	  vh[e.get_second_vertex()]));
    LinkedListGraph<DijkstraVertexGraph,
		    WeightEdgeGraph<DijkstraVertexGraph>> g2(dvs, des);
    std::vector<std::vector<int>> D(n, std::vector<int>(n));
    for(std::size_t i = 0; i != n; ++i)
      {
	dijkstra(g2, i);
	for(std::size_t j = 0; j != n; ++j)
	  D[i][j] = g2.vertex(j).get_dw() + vh[j] - vh[i];
      }
    return D;
  }
}


#endif
