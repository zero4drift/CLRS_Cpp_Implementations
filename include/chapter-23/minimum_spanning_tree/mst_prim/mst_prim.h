#ifndef MST_PRIM_H
#define MST_PRIM_H


#include <vector>
#include <utility>
#include "chapter-19/fibonacci_heap/fibonacci_heap.h"
#include "chapter-22/linked_list_graph/linked_list_graph.h"
#include "chapter-23/minimum_spanning_tree/mst_utilities.h"


namespace CLRS
{  
  std::vector<
    std::pair<
      std::size_t, std::size_t>>
  mst_prim(const LinkedListGraph<WeightVertexGraph,
	   WeightEdgeGraph<WeightVertexGraph>> &llg,
	   std::size_t r)
  {
    auto g = llg;
    // initialize a vector as return value
    std::vector<
      std::pair<
	std::size_t, std::size_t>> a;
    // set weight for the root node with specified index
    g.vertex(r).set_weight(0);
    g.vertex(r).set_weight_flag();
    // fibonacci heap
    auto fib_h =
      CLRS::make_fib_heap<WeightVertexGraph>();
    // vshr stores the shared_ptr of fib nodes by index of its key
    std::vector
      <std::shared_ptr
       <FibHeapTreeNode<WeightVertexGraph>>> vshr;
    for(std::size_t i = 0;
	i != g.get_vertexes_size();
	++i)
      {
	// vertex would be in fib heap
	g.vertex(i).set_in_fib_h();
	auto shr = std::make_shared<FibHeapTreeNode
				    <WeightVertexGraph>>
	  (g.vertex(i));
	vshr.push_back(shr);
	CLRS::fib_heap_insert(fib_h, shr);
      }
    // if fib_heap is empty, the program ends
    while(fib_h.get_n())
      {
	auto up = fib_heap_extract_min(fib_h);
	auto uv = up->get_key();
	// clear the flag and make it effective
	uv.clear_in_fib_h();
	up->set_key(uv);
	// every one extracted from fib heap makes a safe edge
	// which is member of minimum spanning tree
	std::size_t u = uv.get_index();
	if(uv.get_weight())
	  a.push_back(std::make_pair(uv.get_p(), u));
	// scan through the adjacent nodes
	for(std::size_t vp : g.get_adj_vertexes(u))
	  {
	    auto vv = vshr[vp]->get_key();
	    std::size_t v = vv.get_index();
	    // condition1: handle the node still in fib heap
	    if(vv.get_in_fib_h())
	      {
		// condition2: data member weight unsettled or
		// comes to a smaller weight 
		if((vv.is_weight_set()
		    && g.edge(u, v).get_weight() <
		    vv.get_weight()) || !vv.is_weight_set())
		  {
		    vv.set_p(u);
		    vv.set_p_flag();
		    vv.set_weight
		      (g.edge(u, v).get_weight());
		    vv.set_weight_flag();
		    // the data member weight of vertex
		    // decides the arrangement of fib heap
		    fib_heap_decrease_key(fib_h, vshr[vp], vv);
		  }
	      }
	  }
      }
    return a;
  }
}


#endif
