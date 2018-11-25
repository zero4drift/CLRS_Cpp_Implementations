#include <vector>
#include <gtest/gtest.h>
#include "chapter-22/linked_list_graph/linked_list_graph.h"
#include "chapter-24/single_source_shortest_paths/sssp_utilities.h"
#include "chapter-24/single_source_shortest_paths/bellman_ford/bellman_ford.h"

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
  EXPECT_EQ(7, llg.vertex(3).get_d());
  EXPECT_EQ(3, llg.vertex(2).get_p());
  EXPECT_EQ(4, llg.vertex(2).get_d());
  EXPECT_EQ(2, llg.vertex(1).get_p());
  EXPECT_EQ(2, llg.vertex(1).get_d());
  EXPECT_EQ(1, llg.vertex(4).get_p());
  EXPECT_EQ(-2, llg.vertex(4).get_d());
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
  EXPECT_EQ(7, llg.vertex(3).get_d());
  EXPECT_EQ(3, llg.vertex(2).get_p());
  EXPECT_EQ(4, llg.vertex(2).get_d());
  EXPECT_EQ(2, llg.vertex(1).get_p());
  EXPECT_EQ(2, llg.vertex(1).get_d());
  EXPECT_EQ(1, llg.vertex(4).get_p());
  EXPECT_EQ(-2, llg.vertex(4).get_d());
  EXPECT_FALSE(llg.vertex(5).is_d_set());
  EXPECT_FALSE(llg.vertex(6).is_d_set());
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
