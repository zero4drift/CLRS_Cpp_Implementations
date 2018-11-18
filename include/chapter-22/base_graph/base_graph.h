#ifndef BASE_GRAPH_H
#define BASE_GRAPH_H


#include <set>
#include <vector>
#include <algorithm>
#include "chapter-22/vertex_graph/vertex_graph.h"
#include "chapter-22/edge_graph/edge_graph.h"

namespace CLRS
{
  class BaseGraph
  {
  protected:
    std::vector<VertexSHR> vertexes;
    std::set<EdgeSHR,
	     decltype(compare_edge_graph)*> edges;
  public:
      /* 
       * when construct, 
       * make sure passed-in vs has every
       * graph node stored in an order of index;
       * and es only stores existing graph edges. 
       */
    BaseGraph(const std::vector<VertexSHR> &vs,
	      const std::set<EdgeSHR,
	      decltype(compare_edge_graph)*> &es):
      vertexes(vs), edges(es) {}
    virtual bool edge_or_not(const EdgeSHR &) const = 0;
  };
}


#endif
