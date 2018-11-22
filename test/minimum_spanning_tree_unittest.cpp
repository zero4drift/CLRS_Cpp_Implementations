#include <utility>
#include <gtest/gtest.h>
#include "chapter-21/tree_disjoint_set/tree_disjoint_set.h"
#include "chapter-22/base_graph/base_graph.h"
#include "chapter-22/vertex_graph/vertex_graph.h"
#include "chapter-22/edge_graph/edge_graph.h"
#include "chapter-22/linked_list_graph/linked_list_graph.h"
#include "chapter-23/minimum_spanning_tree/mst_kruskal/mst_kruskal.h"


using namespace CLRS;

TEST(MST, Kruskal)
{
  auto v0 = VertexGraph(0);
  auto v1 = VertexGraph(1);
  auto v2 = VertexGraph(2);
  auto v3 = VertexGraph(3);
  auto v4 = VertexGraph(4);
  auto v5 = VertexGraph(5);
  auto v6 = VertexGraph(6);
  auto v7 = VertexGraph(7);
  auto v8 = VertexGraph(8);
  auto e0 = WeightEdgeGraph(v0, v1, 4);
  auto e1 = WeightEdgeGraph(v1, v2, 8);
  auto e2 = WeightEdgeGraph(v2, v3, 7);
  auto e3 = WeightEdgeGraph(v3, v4, 9);
  auto e4 = WeightEdgeGraph(v4, v5, 10);
  auto e5 = WeightEdgeGraph(v5, v6, 2);
  auto e6 = WeightEdgeGraph(v6, v7, 1);
  auto e7 = WeightEdgeGraph(v7, v8, 7);
  auto e8 = WeightEdgeGraph(v8, v2, 2);
  auto e9 = WeightEdgeGraph(v8, v6, 6);
  auto e10 = WeightEdgeGraph(v2, v5, 4);
  auto e11 = WeightEdgeGraph(v3, v5, 14);
  auto e12 = WeightEdgeGraph(v1, v7, 11);
  auto e13 = WeightEdgeGraph(v0, v7, 8);
  auto e14 = WeightEdgeGraph(v1, v0, 4);
  auto e15 = WeightEdgeGraph(v2, v1, 8);
  auto e16 = WeightEdgeGraph(v3, v2, 7);
  auto e17 = WeightEdgeGraph(v4, v3, 9);
  auto e18 = WeightEdgeGraph(v5, v4, 10);
  auto e19 = WeightEdgeGraph(v6, v5, 2);
  auto e20 = WeightEdgeGraph(v7, v6, 1);
  auto e21 = WeightEdgeGraph(v8, v7, 7);
  auto e22 = WeightEdgeGraph(v2, v8, 2);
  auto e23 = WeightEdgeGraph(v6, v8, 6);
  auto e24 = WeightEdgeGraph(v5, v2, 4);
  auto e25 = WeightEdgeGraph(v5, v3, 14);
  auto e26 = WeightEdgeGraph(v7, v1, 11);
  auto e27 = WeightEdgeGraph(v7, v0, 8);
  std::vector<VertexGraph> vs =
    {v0, v1, v2, v3, v4, v5, v6, v7, v8};
  std::vector<WeightEdgeGraph> es =
    {e0, e1, e2, e3, e4, e5, e6, e7, e8, e9,
     e10, e11, e12, e13, e14, e15, e16, e17,
     e18, e19, e20, e21, e22, e23, e24, e25,
     e26, e27}; 
  CLRS::LinkedListGraph<VertexGraph,
			WeightEdgeGraph> llg(vs, es);
  auto a = mst_kruskal(llg);
  std::size_t sum = 0;
  for(const auto &p : a)
    sum += llg.edge(p.first, p.second).get_weight();
  EXPECT_EQ(37, sum);
}
