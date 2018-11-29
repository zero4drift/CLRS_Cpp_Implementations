#include <iostream>
#include <gtest/gtest.h>
#include "chapter-25/all_pairs_shortest_paths/all_pairs_shortest_paths_utilities.h"
#include "chapter-25/all_pairs_shortest_paths/matrix_all_pairs_shortest_paths/matrix_all_pairs_shortest_paths.h"
#include "chapter-25/all_pairs_shortest_paths/floyd_warshall/floyd_warshall.h"

using namespace CLRS;

TEST(AllPairsShortestPaths, Matrix)
{
  auto v0 = VertexGraph(0);
  auto v1 = VertexGraph(1);
  auto v2 = VertexGraph(2);
  auto v3 = VertexGraph(3);
  auto v4 = VertexGraph(4);
  auto e0 = APSPWeightEdgeGraph(v0, v1, 3);
  auto e1 = APSPWeightEdgeGraph(v2, v1, 4);
  auto e2 = APSPWeightEdgeGraph(v0, v2, 8);
  auto e3 = APSPWeightEdgeGraph(v1, v4, 7);
  auto e4 = APSPWeightEdgeGraph(v1, v3, 1);
  auto e5 = APSPWeightEdgeGraph(v3, v0, 2);
  auto e6 = APSPWeightEdgeGraph(v0, v4, -4);
  auto e7 = APSPWeightEdgeGraph(v4, v3, 6);
  auto e8 = APSPWeightEdgeGraph(v3, v2, -5);
  std::vector<VertexGraph> vs = {v0, v1, v2, v3, v4};
  std::vector<APSPWeightEdgeGraph> es =
    {e0, e1, e2, e3, e4, e5, e6, e7, e8};
  APSPMatrixGraph mg(vs, es);
  auto l = faster_all_pairs_shortest_paths(mg.get_matrix());
  EXPECT_EQ(0, l[0][0].get_weight());
  EXPECT_EQ(1, l[0][1].get_weight());
  EXPECT_EQ(1, l[1][3].get_weight());
  EXPECT_EQ(3, l[2][4].get_weight());
  EXPECT_EQ(-5, l[3][2].get_weight());
  EXPECT_EQ(6, l[4][3].get_weight());
}

TEST(AllPairsShortestPaths, FloydWarshall)
{
  auto v0 = VertexGraph(0);
  auto v1 = VertexGraph(1);
  auto v2 = VertexGraph(2);
  auto v3 = VertexGraph(3);
  auto v4 = VertexGraph(4);
  auto e0 = APSPWeightEdgeGraph(v0, v1, 3);
  auto e1 = APSPWeightEdgeGraph(v2, v1, 4);
  auto e2 = APSPWeightEdgeGraph(v0, v2, 8);
  auto e3 = APSPWeightEdgeGraph(v1, v4, 7);
  auto e4 = APSPWeightEdgeGraph(v1, v3, 1);
  auto e5 = APSPWeightEdgeGraph(v3, v0, 2);
  auto e6 = APSPWeightEdgeGraph(v0, v4, -4);
  auto e7 = APSPWeightEdgeGraph(v4, v3, 6);
  auto e8 = APSPWeightEdgeGraph(v3, v2, -5);
  std::vector<VertexGraph> vs = {v0, v1, v2, v3, v4};
  std::vector<APSPWeightEdgeGraph> es =
    {e0, e1, e2, e3, e4, e5, e6, e7, e8};
  APSPMatrixGraph mg(vs, es);
  auto l = floyd_warshall(mg.get_matrix());
  EXPECT_EQ(0, l[0][0].get_weight());
  EXPECT_EQ(1, l[0][1].get_weight());
  EXPECT_EQ(1, l[1][3].get_weight());
  EXPECT_EQ(3, l[2][4].get_weight());
  EXPECT_EQ(-5, l[3][2].get_weight());
  EXPECT_EQ(6, l[4][3].get_weight());
}

TEST(AllPairsShortestPaths, TransitiveClosure)
{
  auto v0 = VertexGraph(0);
  auto v1 = VertexGraph(1);
  auto v2 = VertexGraph(2);
  auto v3 = VertexGraph(3);
  auto e0 = APSPWeightEdgeGraph(v3, v0, 3);
  auto e1 = APSPWeightEdgeGraph(v3, v2, 4);
  auto e2 = APSPWeightEdgeGraph(v1, v3, 8);
  auto e3 = APSPWeightEdgeGraph(v1, v2, 7);
  auto e4 = APSPWeightEdgeGraph(v2, v1, 1);
  std::vector<VertexGraph> vs = {v0, v1, v2, v3};
  std::vector<APSPWeightEdgeGraph> es =
    {e0, e1, e2, e3, e4};
  APSPMatrixGraph mg(vs, es);
  auto t = transitive_closure(mg);
  EXPECT_TRUE(t[0][0]);
  EXPECT_FALSE(t[0][1]);
  EXPECT_FALSE(t[0][2]);
  EXPECT_FALSE(t[0][3]);
  for(std::size_t i = 1; i != 4; ++i)
    for(std::size_t j = 0; j != 4; ++j)
      EXPECT_TRUE(t[i][j]);
}
