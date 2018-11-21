#include <queue>
#include <vector>
#include <gtest/gtest.h>
#include "chapter-22/vertex_graph/vertex_graph.h"
#include "chapter-22/edge_graph/edge_graph.h"
#include "chapter-22/base_graph/base_graph.h"
#include "chapter-22/linked_list_graph/linked_list_graph.h"
#include "chapter-22/matrix_graph/matrix_graph.h"
#include "chapter-22/bfs_graph/bfs_graph.h"

using namespace CLRS;

TEST(Graph, VertexCreate)
{
  // vertex index must start from 0
  auto v0 = VertexGraph(0);
  EXPECT_EQ(0, v0.get_index());
}

TEST(Graph, EdgeCreate)
{
  auto v0 = VertexGraph(0);
  auto v1 = VertexGraph(1);
  auto e0 = EdgeGraph<VertexGraph>(v0, v1);
  EXPECT_EQ(0, e0.get_first_vertex());
  EXPECT_EQ(1, e0.get_second_vertex());
}

TEST(Graph, LinkedListGraph)
{
  auto v0 = VertexGraph(0);
  auto v1 = VertexGraph(1);
  auto v2 = VertexGraph(2);
  auto v3 = VertexGraph(3);
  auto v4 = VertexGraph(4);
  auto v5 = VertexGraph(5);
  auto v6 = VertexGraph(6);
  auto e0 = EdgeGraph<VertexGraph>(v0, v1);
  auto e1 = EdgeGraph<VertexGraph>(v1, v2);
  auto e2 = EdgeGraph<VertexGraph>(v1, v4);
  auto e3 = EdgeGraph<VertexGraph>(v2, v5);
  auto e4 = EdgeGraph<VertexGraph>(v4, v2);
  auto e5 = EdgeGraph<VertexGraph>(v5, v4);
  auto e6 = EdgeGraph<VertexGraph>(v3, v5);
  auto e7 = EdgeGraph<VertexGraph>(v3, v6);
  std::vector<VertexGraph> vs =
    {v0, v1, v2, v3, v4, v5, v6};
  std::vector<EdgeGraph<VertexGraph>> es =
    {e0, e1, e2, e3, e4, e5, e6, e7};
  LinkedListGraph<VertexGraph,
		  EdgeGraph<VertexGraph>> llg(vs, es);
  EXPECT_TRUE(llg.edge_or_not(e0));
  EXPECT_TRUE(llg.edge_or_not(e1));
  EXPECT_TRUE(llg.edge_or_not(e2));
  EXPECT_TRUE(llg.edge_or_not(e3));
  EXPECT_TRUE(llg.edge_or_not(e4));
  EXPECT_TRUE(llg.edge_or_not(e5));
  EXPECT_TRUE(llg.edge_or_not(e6));
  EXPECT_TRUE(llg.edge_or_not(e7));
  // case: a edge does not exit
  auto e8= EdgeGraph<VertexGraph>(v4, v3);
  EXPECT_FALSE(llg.edge_or_not(e8));
}

TEST(Graph, MatrixListGraph)
{
  auto v0 = VertexGraph(0);
  auto v1 = VertexGraph(1);
  auto v2 = VertexGraph(2);
  auto v3 = VertexGraph(3);
  auto v4 = VertexGraph(4);
  auto v5 = VertexGraph(5);
  auto v6 = VertexGraph(6);
  auto e0 = EdgeGraph<VertexGraph>(v0, v1);
  auto e1 = EdgeGraph<VertexGraph>(v1, v2);
  auto e2 = EdgeGraph<VertexGraph>(v1, v4);
  auto e3 = EdgeGraph<VertexGraph>(v2, v5);
  auto e4 = EdgeGraph<VertexGraph>(v4, v2);
  auto e5 = EdgeGraph<VertexGraph>(v5, v4);
  auto e6 = EdgeGraph<VertexGraph>(v3, v5);
  auto e7 = EdgeGraph<VertexGraph>(v3, v6);
  std::vector<VertexGraph> vs =
    {v0, v1, v2, v3, v4, v5, v6};
  std::vector<EdgeGraph<VertexGraph>> es =
    {e0, e1, e2, e3, e4, e5, e6, e7};
  MatrixGraph<VertexGraph,
	      EdgeGraph<VertexGraph>> mg(vs, es);
  EXPECT_TRUE(mg.edge_or_not(e0));
  EXPECT_TRUE(mg.edge_or_not(e1));
  EXPECT_TRUE(mg.edge_or_not(e2));
  EXPECT_TRUE(mg.edge_or_not(e3));
  EXPECT_TRUE(mg.edge_or_not(e4));
  EXPECT_TRUE(mg.edge_or_not(e5));
  EXPECT_TRUE(mg.edge_or_not(e6));
  EXPECT_TRUE(mg.edge_or_not(e7));
  // case: a edge does not exit
  auto e8= EdgeGraph<VertexGraph>(v4, v3);
  EXPECT_FALSE(mg.edge_or_not(e8));
}

TEST(Graph, DerivedVertex)
{
  // a derived class with an additional vertex parameter
  class DerivedVertexGraph: public VertexGraph
  {
  private:
    unsigned weight;
  public:
    DerivedVertexGraph(std::size_t i,
		       unsigned w):
      VertexGraph(i), weight(w) {}
    unsigned get_weight() const {return weight;}
  }; 
    
  auto v0 = DerivedVertexGraph(0, 0);
  auto v1 = DerivedVertexGraph(1, 1);
  auto v2 = DerivedVertexGraph(2, 2);
  auto v3 = DerivedVertexGraph(3, 3);
  auto v4 = DerivedVertexGraph(4, 4);
  auto v5 = DerivedVertexGraph(5, 5);
  auto v6 = DerivedVertexGraph(6, 6);
  auto e0 = EdgeGraph<DerivedVertexGraph>(v0, v1);
  auto e1 = EdgeGraph<DerivedVertexGraph>(v1, v2);
  auto e2 = EdgeGraph<DerivedVertexGraph>(v1, v4);
  auto e3 = EdgeGraph<DerivedVertexGraph>(v2, v5);
  auto e4 = EdgeGraph<DerivedVertexGraph>(v4, v2);
  auto e5 = EdgeGraph<DerivedVertexGraph>(v5, v4);
  auto e6 = EdgeGraph<DerivedVertexGraph>(v3, v5);
  auto e7 = EdgeGraph<DerivedVertexGraph>(v3, v6);
  std::vector<DerivedVertexGraph> vs =
    {v0, v1, v2, v3, v4, v5, v6};
  std::vector<EdgeGraph<DerivedVertexGraph>> es =
    {e0, e1, e2, e3, e4, e5, e6, e7};
  // test for MatrixGraph
  MatrixGraph<DerivedVertexGraph,
	      EdgeGraph<DerivedVertexGraph>>
    mg(vs, es);
  EXPECT_EQ(0, mg.vertex(0).get_weight());
  EXPECT_TRUE(mg.edge_or_not(e1));
  // test for LinkedListGraph
  LinkedListGraph<DerivedVertexGraph,
		  EdgeGraph<DerivedVertexGraph>>
    llg(vs, es);
  EXPECT_TRUE(llg.edge_or_not(e1));
  EXPECT_EQ(0, llg.vertex(0).get_weight());
}

TEST(Graph, DerivedEdge)
{
  // a derived class with an additional edge parameter
  class DerivedEdgeGraph: public EdgeGraph<VertexGraph>
  {
  private:
    unsigned weight;
  public:
    DerivedEdgeGraph(const VertexGraph &v1,
		     const VertexGraph &v2,
		     unsigned w):
      EdgeGraph<VertexGraph>(v1, v2), weight(w) {}
    unsigned get_weight() const {return weight;}
  };

  auto v0 = VertexGraph(0);
  auto v1 = VertexGraph(1);
  auto v2 = VertexGraph(2);
  auto v3 = VertexGraph(3);
  auto v4 = VertexGraph(4);
  auto v5 = VertexGraph(5);
  auto v6 = VertexGraph(6);
  auto e0 = DerivedEdgeGraph(v0, v1, 0);
  auto e1 = DerivedEdgeGraph(v1, v2, 1);
  auto e2 = DerivedEdgeGraph(v1, v4, 2);
  auto e3 = DerivedEdgeGraph(v2, v5, 3);
  auto e4 = DerivedEdgeGraph(v4, v2, 4);
  auto e5 = DerivedEdgeGraph(v5, v4, 5);
  auto e6 = DerivedEdgeGraph(v3, v5, 6);
  auto e7 = DerivedEdgeGraph(v3, v6, 7);
  std::vector<VertexGraph> vs =
    {v0, v1, v2, v3, v4, v5, v6};
  std::vector<DerivedEdgeGraph> es =
    {e0, e1, e2, e3, e4, e5, e6, e7};
  // test for MatrixGraph
  MatrixGraph<VertexGraph,
	      DerivedEdgeGraph> mg(vs, es);
  EXPECT_EQ(1, mg.edge(1, 2).get_weight());
  EXPECT_TRUE(mg.edge_or_not(e1));
  // test for LinkedListGraph
  LinkedListGraph<VertexGraph,
		  DerivedEdgeGraph> llg(vs, es);
  EXPECT_TRUE(llg.edge_or_not(e1));
  EXPECT_EQ(1, llg.edge(1, 2).get_weight());
}

TEST(Graph, BFS)
{
  auto v0 = BFSVertexGraph(0);
  auto v1 = BFSVertexGraph(1);
  auto v2 = BFSVertexGraph(2);
  auto v3 = BFSVertexGraph(3);
  auto v4 = BFSVertexGraph(4);
  auto v5 = BFSVertexGraph(5);
  auto v6 = BFSVertexGraph(6);
  auto v7 = BFSVertexGraph(7);
  auto e0 = EdgeGraph<BFSVertexGraph>(v0, v1);
  auto e1 = EdgeGraph<BFSVertexGraph>(v1, v0);
  auto e2 = EdgeGraph<BFSVertexGraph>(v1, v2);
  auto e3 = EdgeGraph<BFSVertexGraph>(v2, v1);
  auto e4 = EdgeGraph<BFSVertexGraph>(v2, v3);
  auto e5 = EdgeGraph<BFSVertexGraph>(v3, v2);
  auto e6 = EdgeGraph<BFSVertexGraph>(v3, v4);
  auto e7 = EdgeGraph<BFSVertexGraph>(v4, v3);
  auto e8 = EdgeGraph<BFSVertexGraph>(v3, v5);
  auto e9 = EdgeGraph<BFSVertexGraph>(v5, v3);
  auto e10 = EdgeGraph<BFSVertexGraph>(v4, v5);
  auto e11 = EdgeGraph<BFSVertexGraph>(v5, v4);
  auto e12 = EdgeGraph<BFSVertexGraph>(v5, v6);
  auto e13 = EdgeGraph<BFSVertexGraph>(v6, v5);
  auto e14 = EdgeGraph<BFSVertexGraph>(v4, v6);
  auto e15 = EdgeGraph<BFSVertexGraph>(v6, v4);
  auto e16 = EdgeGraph<BFSVertexGraph>(v4, v7);
  auto e17 = EdgeGraph<BFSVertexGraph>(v7, v4);
  auto e18 = EdgeGraph<BFSVertexGraph>(v6, v7);
  auto e19 = EdgeGraph<BFSVertexGraph>(v7, v6);
  std::vector<BFSVertexGraph> vs =
    {v0, v1, v2, v3, v4, v5, v6, v7};
  std::vector<EdgeGraph<BFSVertexGraph>> es =
    {e0, e1, e2, e3, e4, e5, e6, e7, e8,
     e9, e10, e11, e12, e13, e14, e15,
     e16, e17, e18, e19};
  LinkedListGraph<BFSVertexGraph,
		  EdgeGraph<BFSVertexGraph>> llg(vs, es);
  bfs_graph(llg, 2);
  // color test, all vertex should be marked with black
  for(std::size_t i = 0; i <= 7; ++i)
    for(std::size_t u : llg.get_list(i))
      EXPECT_EQ(BFSVertexColor::black, llg.vertex(u).get_color());
  // diatance test
  EXPECT_EQ(2, llg.vertex(0).get_d());
  EXPECT_EQ(1, llg.vertex(3).get_d());
  EXPECT_EQ(2, llg.vertex(5).get_d());
  EXPECT_EQ(3, llg.vertex(7).get_d());
}
