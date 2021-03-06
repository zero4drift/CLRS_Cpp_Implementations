#ifndef DAG_SHORTEST_PATHS
#define DAG_SHORTEST_PATHS


#include "chapter-22/dfs_graph/dfs_graph.hpp"
#include "chapter-22/linked_list_graph/linked_list_graph.hpp"
#include "chapter-24/single_source_shortest_paths/sssp_utilities.hpp"

namespace CLRS
{
  void dag_shortest_paths
  (LinkedListGraph<SSSPDFSVertexGraph,
   SSSPWeightEdgeGraph<SSSPDFSVertexGraph>> &g,
   std::size_t s)
  {
    auto l = topological_sort_graph(g);
    initialize_single_source(g, s);
    for(std::size_t u : l)
      {
	for(const auto &ev : g.get_adj_vertexes(u))
	  sssp_relax(g, g.edgesr()[ev]);
      }
  }
}


#endif
