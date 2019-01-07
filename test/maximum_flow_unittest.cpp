#include <gtest/gtest.h>
#include "chapter-22/bfs_graph/bfs_graph.hpp"
#include "chapter-26/maximum_flow_utilities.hpp"
#include "chapter-26/maximum_flow/maximum_flow.hpp"

using namespace CLRS;

TEST(MaximumFlow, Test)
{
  auto v0 = BFSVertexGraph(0);
  auto v1 = BFSVertexGraph(1);
  auto v2 = BFSVertexGraph(2);
  auto v3 = BFSVertexGraph(3);
  auto v4 = BFSVertexGraph(4);
  auto v5 = BFSVertexGraph(5);
  auto e0 = MaximumFlowEdgeGraph(16, v0, v1);
  auto e1 = MaximumFlowEdgeGraph(12, v1, v2);
  auto e2 = MaximumFlowEdgeGraph(20, v2, v3);
  auto e3 = MaximumFlowEdgeGraph(13, v0, v5);
  auto e4 = MaximumFlowEdgeGraph(4, v5, v1);
  auto e5 = MaximumFlowEdgeGraph(9, v2, v5);
  auto e6 = MaximumFlowEdgeGraph(14, v5, v4);
  auto e7 = MaximumFlowEdgeGraph(4, v4, v3);
  auto e8 = MaximumFlowEdgeGraph(7, v4, v2);
  std::vector<BFSVertexGraph> vs = {v0, v1, v2, v3, v4, v5};
  std::vector<MaximumFlowEdgeGraph> es =
    {e0, e1, e2, e3, e4, e5, e6, e7, e8};
  MaximumFlowLinkedListGraph g(vs, es);
  ford_fulkserson(g, 0, 3);
  EXPECT_EQ(19, g.edge(2, 3).get_f());
  EXPECT_EQ(4, g.edge(4, 3).get_f());
  EXPECT_EQ(12, g.edge(1, 2).get_f());
  EXPECT_EQ(0, g.edge(2, 5).get_f());
  EXPECT_EQ(11, g.edge(0, 5).get_f());
}
