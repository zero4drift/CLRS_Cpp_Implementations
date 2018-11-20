#include <vector>
#include <gtest/gtest.h>
#include "chapter-22/vertex_graph/vertex_graph.h"
#include "chapter-22/edge_graph/edge_graph.h"
#include "chapter-22/base_graph/base_graph.h"
#include "chapter-22/linked_list_graph/linked_list_graph.h"
#include "chapter-22/matrix_graph/matrix_graph.h"

using namespace CLRS;

TEST(Graph, VertexCreate)
{
  // vertex index must start from 0
  // too lazy to fix these...
  auto v1 = VertexGraph(1);
  EXPECT_EQ(1, v1.get_index());
}

TEST(Graph, EdgeCreate)
{
  auto v1 = VertexGraph(1);
  auto v2 = VertexGraph(2);
  auto e1 = EdgeGraph<VertexGraph>(v1, v2);
  EXPECT_EQ(1, e1.get_first_vertex().get_index());
  EXPECT_EQ(2, e1.get_second_vertex().get_index());
}

TEST(Graph, LinkedListGraph)
{
  auto v1 = VertexGraph(1);
  auto v2 = VertexGraph(2);
  auto v3 = VertexGraph(3);
  auto v4 = VertexGraph(4);
  auto v5 = VertexGraph(5);
  auto v6 = VertexGraph(6);
  auto e1 = EdgeGraph<VertexGraph>(v1, v2);
  auto e2 = EdgeGraph<VertexGraph>(v1, v4);
  auto e3 = EdgeGraph<VertexGraph>(v2, v5);
  auto e4 = EdgeGraph<VertexGraph>(v4, v2);
  auto e5 = EdgeGraph<VertexGraph>(v5, v4);
  auto e6 = EdgeGraph<VertexGraph>(v3, v5);
  auto e7 = EdgeGraph<VertexGraph>(v3, v6);
  std::vector<VertexGraph> vs = {v1, v2, v3, v4, v5, v6};
  std::vector<EdgeGraph<VertexGraph>> es = {e1, e2, e3, e4, e5, e6, e7};
  LinkedListGraph<VertexGraph,
		  EdgeGraph<VertexGraph>> llg(vs, es);
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
  auto v1 =  VertexGraph(1);
  auto v2 = VertexGraph(2);
  auto v3 = VertexGraph(3);
  auto v4 = VertexGraph(4);
  auto v5 = VertexGraph(5);
  auto v6 = VertexGraph(6);
  auto e1 = EdgeGraph<VertexGraph>(v1, v2);
  auto e2 = EdgeGraph<VertexGraph>(v1, v4);
  auto e3 = EdgeGraph<VertexGraph>(v2, v5);
  auto e4 = EdgeGraph<VertexGraph>(v4, v2);
  auto e5 = EdgeGraph<VertexGraph>(v5, v4);
  auto e6 = EdgeGraph<VertexGraph>(v3, v5);
  auto e7 = EdgeGraph<VertexGraph>(v3, v6);
  std::vector<VertexGraph> vs = {v1, v2, v3, v4, v5, v6};
  std::vector<EdgeGraph<VertexGraph>> es = {e1, e2, e3, e4, e5, e6, e7};
  MatrixGraph<VertexGraph,
	      EdgeGraph<VertexGraph>> mg(vs, es);
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
    
  auto v1 = DerivedVertexGraph(1, 1);
  auto v2 = DerivedVertexGraph(2, 2);
  auto v3 = DerivedVertexGraph(3, 3);
  auto v4 = DerivedVertexGraph(4, 4);
  auto v5 = DerivedVertexGraph(5, 5);
  auto v6 = DerivedVertexGraph(6, 6);
  auto e1 = EdgeGraph<DerivedVertexGraph>(v1, v2);
  auto e2 = EdgeGraph<DerivedVertexGraph>(v1, v4);
  auto e3 = EdgeGraph<DerivedVertexGraph>(v2, v5);
  auto e4 = EdgeGraph<DerivedVertexGraph>(v4, v2);
  auto e5 = EdgeGraph<DerivedVertexGraph>(v5, v4);
  auto e6 = EdgeGraph<DerivedVertexGraph>(v3, v5);
  auto e7 = EdgeGraph<DerivedVertexGraph>(v3, v6);
  std::vector<DerivedVertexGraph> vs =
    {v1, v2, v3, v4, v5, v6};
  std::vector<EdgeGraph<DerivedVertexGraph>> es =
    {e1, e2, e3, e4, e5, e6, e7};
  // test for MatrixGraph
  MatrixGraph<DerivedVertexGraph,
	      EdgeGraph<DerivedVertexGraph>>
    mg(vs, es);
  EXPECT_EQ(1, mg.get_vertexes()[0].get_weight());
  EXPECT_TRUE(mg.edge_or_not(e1));
  // test for LinkedListGraph
  LinkedListGraph<DerivedVertexGraph,
		  EdgeGraph<DerivedVertexGraph>>
    llg(vs, es);
  EXPECT_TRUE(llg.edge_or_not(e1));
  EXPECT_EQ(2, (*llg.get_ll_cbeg_it(1)).get_weight());
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

  auto v1 = VertexGraph(1);
  auto v2 = VertexGraph(2);
  auto v3 = VertexGraph(3);
  auto v4 = VertexGraph(4);
  auto v5 = VertexGraph(5);
  auto v6 = VertexGraph(6);
  auto e1 = DerivedEdgeGraph(v1, v2, 1);
  auto e2 = DerivedEdgeGraph(v1, v4, 2);
  auto e3 = DerivedEdgeGraph(v2, v5, 3);
  auto e4 = DerivedEdgeGraph(v4, v2, 4);
  auto e5 = DerivedEdgeGraph(v5, v4, 5);
  auto e6 = DerivedEdgeGraph(v3, v5, 6);
  auto e7 = DerivedEdgeGraph(v3, v6, 7);
  std::vector<VertexGraph> vs =
    {v1, v2, v3, v4, v5, v6};
  std::vector<DerivedEdgeGraph> es =
    {e1, e2, e3, e4, e5, e6, e7};
  // test for MatrixGraph
  MatrixGraph<VertexGraph,
	      DerivedEdgeGraph> mg(vs, es);
  EXPECT_EQ(1, mg.get_edges()[0].get_weight());
  EXPECT_TRUE(mg.edge_or_not(e1));
  // test for LinkedListGraph
  LinkedListGraph<VertexGraph,
		  DerivedEdgeGraph> llg(vs, es);
  EXPECT_TRUE(llg.edge_or_not(e1));
  EXPECT_EQ(1, llg.get_edges()[0].get_weight());
}
