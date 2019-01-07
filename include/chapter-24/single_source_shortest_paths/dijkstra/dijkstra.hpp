#ifndef DIJKSTRA_H
#define DIJKSTRA_H


#include <vector>
#include <memory>
#include "chapter-19/fibonacci_heap/fibonacci_heap.hpp"
#include "chapter-22/linked_list_graph/linked_list_graph.hpp"
#include "chapter-24/single_source_shortest_paths/sssp_utilities.hpp"
#include "chapter-23/minimum_spanning_tree/mst_utilities.hpp"

namespace CLRS
{
  void dijkstra
  (LinkedListGraph<DijkstraVertexGraph,
   WeightEdgeGraph<DijkstraVertexGraph>> &g,
   std::size_t s)
  {
    initialize_single_source(g, s);
    // fibonacci heap now contains all node of g
    auto fib_h =
      CLRS::make_fib_heap<DijkstraVertexGraph>();
    // have to create a graph node <-> shared_ptr index
    std::vector
      <std::shared_ptr
       <FibHeapTreeNode<DijkstraVertexGraph>>> vshr;
    for(std::size_t i = 0;
	i != g.get_vertexes_size();
	++i)
      {
	auto shr = std::make_shared
	  <FibHeapTreeNode
	   <DijkstraVertexGraph>>(g.vertex(i));
	vshr.push_back(shr);
	fib_heap_insert(fib_h, shr);
      }
    while(fib_h.get_n())
      {
	auto u = fib_heap_extract_min(fib_h);
	for(const auto &ev : g.get_adj_vertexes
	      (u->get_key().get_index()))
	  {
	    auto vr = sssp_relax(g, g.edgesr()[ev]);
	    auto v = vshr[g.edgesr()[ev].get_second_vertex()];
	    if(vr < v->get_key())
	      fib_heap_decrease_key(fib_h, v, vr);
	  }
      }
  }
}


#endif
