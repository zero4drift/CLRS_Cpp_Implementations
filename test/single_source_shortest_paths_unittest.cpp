#include <vector>
#include <gtest/gtest.h>
#include "chapter-22/linked_list_graph/linked_list_graph.hpp"
#include "chapter-24/single_source_shortest_paths/sssp_utilities.hpp"
#include "chapter-24/single_source_shortest_paths/bellman_ford/bellman_ford.hpp"
#include "chapter-24/single_source_shortest_paths/dag_shortest_paths/dag_shortest_paths.hpp"
#include "chapter-24/single_source_shortest_paths/dijkstra/dijkstra.hpp"

using namespace CLRS;

TEST(SSSP, BellmanFordWithoutNegativeCircle)
{
  auto v0 = SSSPVertexGraph(0);
  auto v1 = SSSPVertexGraph(1);
  auto v2 = SSSPVertexGraph(2);
  auto v3 = SSSPVertexGraph(3);
  auto v4 = SSSPVertexGraph(4);
  auto e0 = SSSPWeightEdgeGraph<SSSPVertexGraph>(v0, v1, 6);
  auto e1 = SSSPWeightEdgeGraph<SSSPVertexGraph>(v1, v2, 5);
  auto e2 = SSSPWeightEdgeGraph<SSSPVertexGraph>(v2, v1, -2);
  auto e3 = SSSPWeightEdgeGraph<SSSPVertexGraph>(v1, v4, -4);
  auto e4 = SSSPWeightEdgeGraph<SSSPVertexGraph>(v1, v3, 8);
  auto e5 = SSSPWeightEdgeGraph<SSSPVertexGraph>(v3, v2, -3);
  auto e6 = SSSPWeightEdgeGraph<SSSPVertexGraph>(v3, v4, 9);
  auto e7 = SSSPWeightEdgeGraph<SSSPVertexGraph>(v4, v0, 2);
  auto e8 = SSSPWeightEdgeGraph<SSSPVertexGraph>(v0, v3, 7);
  auto e9 = SSSPWeightEdgeGraph<SSSPVertexGraph>(v4, v2, 7);
  std::vector<SSSPVertexGraph> vs = {v0, v1, v2, v3, v4};
  std::vector<SSSPWeightEdgeGraph<SSSPVertexGraph>> es =
    {e0, e1, e2, e3, e4, e5, e6, e7, e8, e9};
  LinkedListGraph<SSSPVertexGraph,
		  SSSPWeightEdgeGraph<SSSPVertexGraph>> llg(vs, es);
  EXPECT_TRUE(bellman_ford(llg, 0));
  EXPECT_EQ(0, llg.vertex(3).get_p());
  EXPECT_EQ(7, llg.vertex(3).get_dw());
  EXPECT_EQ(3, llg.vertex(2).get_p());
  EXPECT_EQ(4, llg.vertex(2).get_dw());
  EXPECT_EQ(2, llg.vertex(1).get_p());
  EXPECT_EQ(2, llg.vertex(1).get_dw());
  EXPECT_EQ(1, llg.vertex(4).get_p());
  EXPECT_EQ(-2, llg.vertex(4).get_dw());
}

TEST(SSSP, BellmanFordWithoutNegativeCircleWithUnconnectedNodes)
{
  auto v0 = SSSPVertexGraph(0);
  auto v1 = SSSPVertexGraph(1);
  auto v2 = SSSPVertexGraph(2);
  auto v3 = SSSPVertexGraph(3);
  auto v4 = SSSPVertexGraph(4);
  auto v5 = SSSPVertexGraph(4);
  auto v6 = SSSPVertexGraph(4);
  auto e0 = SSSPWeightEdgeGraph<SSSPVertexGraph>(v0, v1, 6);
  auto e1 = SSSPWeightEdgeGraph<SSSPVertexGraph>(v1, v2, 5);
  auto e2 = SSSPWeightEdgeGraph<SSSPVertexGraph>(v2, v1, -2);
  auto e3 = SSSPWeightEdgeGraph<SSSPVertexGraph>(v1, v4, -4);
  auto e4 = SSSPWeightEdgeGraph<SSSPVertexGraph>(v1, v3, 8);
  auto e5 = SSSPWeightEdgeGraph<SSSPVertexGraph>(v3, v2, -3);
  auto e6 = SSSPWeightEdgeGraph<SSSPVertexGraph>(v3, v4, 9);
  auto e7 = SSSPWeightEdgeGraph<SSSPVertexGraph>(v4, v0, 2);
  auto e8 = SSSPWeightEdgeGraph<SSSPVertexGraph>(v0, v3, 7);
  auto e9 = SSSPWeightEdgeGraph<SSSPVertexGraph>(v4, v2, 7);
  auto e10 = SSSPWeightEdgeGraph<SSSPVertexGraph>(v5, v6, 2);

  std::vector<SSSPVertexGraph> vs = {v0, v1, v2, v3, v4, v5, v6};
  std::vector<SSSPWeightEdgeGraph<SSSPVertexGraph>> es =
    {e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10};
  LinkedListGraph<SSSPVertexGraph,
		  SSSPWeightEdgeGraph<SSSPVertexGraph>> llg(vs, es);
  EXPECT_TRUE(bellman_ford(llg, 0));
  EXPECT_EQ(0, llg.vertex(3).get_p());
  EXPECT_EQ(7, llg.vertex(3).get_dw());
  EXPECT_EQ(3, llg.vertex(2).get_p());
  EXPECT_EQ(4, llg.vertex(2).get_dw());
  EXPECT_EQ(2, llg.vertex(1).get_p());
  EXPECT_EQ(2, llg.vertex(1).get_dw());
  EXPECT_EQ(1, llg.vertex(4).get_p());
  EXPECT_EQ(-2, llg.vertex(4).get_dw());
  EXPECT_FALSE(llg.vertex(5).is_dw_set());
  EXPECT_FALSE(llg.vertex(6).is_dw_set());
}

TEST(SSSP, BellmanFordWithNegativeCircle)
{
  auto v0 = SSSPVertexGraph(0);
  auto v1 = SSSPVertexGraph(1);
  auto v2 = SSSPVertexGraph(2);
  auto v3 = SSSPVertexGraph(3);
  auto v4 = SSSPVertexGraph(4);
  auto e0 = SSSPWeightEdgeGraph<SSSPVertexGraph>(v0, v1, 6);
  auto e1 = SSSPWeightEdgeGraph<SSSPVertexGraph>(v1, v2, 5);
  auto e2 = SSSPWeightEdgeGraph<SSSPVertexGraph>(v2, v1, -7);
  auto e3 = SSSPWeightEdgeGraph<SSSPVertexGraph>(v1, v4, -4);
  auto e4 = SSSPWeightEdgeGraph<SSSPVertexGraph>(v1, v3, 8);
  auto e5 = SSSPWeightEdgeGraph<SSSPVertexGraph>(v3, v2, -3);
  auto e6 = SSSPWeightEdgeGraph<SSSPVertexGraph>(v3, v4, 9);
  auto e7 = SSSPWeightEdgeGraph<SSSPVertexGraph>(v4, v0, 2);
  auto e8 = SSSPWeightEdgeGraph<SSSPVertexGraph>(v0, v3, 7);
  auto e9 = SSSPWeightEdgeGraph<SSSPVertexGraph>(v4, v2, 7);
  std::vector<SSSPVertexGraph> vs = {v0, v1, v2, v3, v4};
  std::vector<SSSPWeightEdgeGraph<SSSPVertexGraph>> es =
    {e0, e1, e2, e3, e4, e5, e6, e7, e8, e9};
  LinkedListGraph<SSSPVertexGraph,
		  SSSPWeightEdgeGraph<SSSPVertexGraph>> llg(vs, es);
  EXPECT_FALSE(bellman_ford(llg, 0));
}

TEST(SSSP, Dag)
{
  auto v0 = SSSPDFSVertexGraph(0);
  auto v1 = SSSPDFSVertexGraph(1);
  auto v2 = SSSPDFSVertexGraph(2);
  auto v3 = SSSPDFSVertexGraph(3);
  auto v4 = SSSPDFSVertexGraph(4);
  auto v5 = SSSPDFSVertexGraph(5);
  auto e0 = SSSPWeightEdgeGraph<SSSPDFSVertexGraph>(v0, v1, 5);
  auto e1 = SSSPWeightEdgeGraph<SSSPDFSVertexGraph>(v0, v2, 3);
  auto e2 = SSSPWeightEdgeGraph<SSSPDFSVertexGraph>(v1, v2, 2);
  auto e3 = SSSPWeightEdgeGraph<SSSPDFSVertexGraph>(v1, v3, 6);
  auto e4 = SSSPWeightEdgeGraph<SSSPDFSVertexGraph>(v2, v3, 7);
  auto e5 = SSSPWeightEdgeGraph<SSSPDFSVertexGraph>(v2, v4, 4);
  auto e6 = SSSPWeightEdgeGraph<SSSPDFSVertexGraph>(v2, v5, 2);
  auto e7 = SSSPWeightEdgeGraph<SSSPDFSVertexGraph>(v3, v4, -1);
  auto e8 = SSSPWeightEdgeGraph<SSSPDFSVertexGraph>(v3, v5, 1);
  auto e9 = SSSPWeightEdgeGraph<SSSPDFSVertexGraph>(v4, v5, -2);
  std::vector<SSSPDFSVertexGraph> vs = {v0, v1, v2, v3, v4, v5};
  std::vector<SSSPWeightEdgeGraph<SSSPDFSVertexGraph>> es =
    {e0, e1, e2, e3, e4, e5, e6, e7, e8, e9};
  LinkedListGraph<SSSPDFSVertexGraph,
		  SSSPWeightEdgeGraph<SSSPDFSVertexGraph>> llg(vs, es);
  dag_shortest_paths(llg, 1);
  EXPECT_FALSE(llg.vertex(0).is_dw_set());
  EXPECT_FALSE(llg.vertex(0).is_p_set());
  // data p of source node is effective due to topo sort
  EXPECT_EQ(0, llg.vertex(1).get_p());
  EXPECT_EQ(0, llg.vertex(1).get_dw());
  EXPECT_EQ(1, llg.vertex(2).get_p());
  EXPECT_EQ(2, llg.vertex(2).get_dw());
  EXPECT_EQ(1, llg.vertex(3).get_p());
  EXPECT_EQ(6, llg.vertex(3).get_dw());
  EXPECT_EQ(3, llg.vertex(4).get_p());
  EXPECT_EQ(5, llg.vertex(4).get_dw());
  EXPECT_EQ(4, llg.vertex(5).get_p());
  EXPECT_EQ(3, llg.vertex(5).get_dw());
}

TEST(SSSP, Dijkstra)
{
  auto v0 = DijkstraVertexGraph(0);
  auto v1 = DijkstraVertexGraph(1);
  auto v2 = DijkstraVertexGraph(2);
  auto v3 = DijkstraVertexGraph(3);
  auto v4 = DijkstraVertexGraph(4);
  auto e0 = WeightEdgeGraph<DijkstraVertexGraph>(v0, v1, 10);
  auto e1 = WeightEdgeGraph<DijkstraVertexGraph>(v1, v2, 1);
  auto e2 = WeightEdgeGraph<DijkstraVertexGraph>(v2, v3, 4);
  auto e3 = WeightEdgeGraph<DijkstraVertexGraph>(v3, v2, 6);
  auto e4 = WeightEdgeGraph<DijkstraVertexGraph>(v4, v3, 2);
  auto e5 = WeightEdgeGraph<DijkstraVertexGraph>(v0, v4, 5);
  auto e6 = WeightEdgeGraph<DijkstraVertexGraph>(v1, v4, 2);
  auto e7 = WeightEdgeGraph<DijkstraVertexGraph>(v4, v1, 3);
  auto e8 = WeightEdgeGraph<DijkstraVertexGraph>(v4, v2, 9);
  auto e9 = WeightEdgeGraph<DijkstraVertexGraph>(v3, v0, 7);
  std::vector<DijkstraVertexGraph> vs = {v0, v1, v2, v3, v4};
  std::vector<WeightEdgeGraph<DijkstraVertexGraph>> es =
    {e0, e1, e2, e3, e4, e5, e6, e7, e8, e9};
  LinkedListGraph<DijkstraVertexGraph,
		  WeightEdgeGraph<DijkstraVertexGraph>> llg(vs, es);
  dijkstra(llg, 0);
  EXPECT_EQ(0, llg.vertex(4).get_p());
  EXPECT_EQ(5, llg.vertex(4).get_dw());
  EXPECT_EQ(4, llg.vertex(3).get_p());
  EXPECT_EQ(7, llg.vertex(3).get_dw());
  EXPECT_EQ(4, llg.vertex(1).get_p());
  EXPECT_EQ(8, llg.vertex(1).get_dw());
  EXPECT_EQ(1, llg.vertex(2).get_p());
  EXPECT_EQ(9, llg.vertex(2).get_dw());
}
