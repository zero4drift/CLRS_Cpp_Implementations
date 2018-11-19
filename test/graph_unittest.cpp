#include <set>
#include <memory>
#include <gtest/gtest.h>
#include "chapter-22/vertex_graph/vertex_graph.h"
#include "chapter-22/edge_graph/edge_graph.h"
#include "chapter-22/base_graph/base_graph.h"
#include "chapter-22/linked_list_graph/linked_list_graph.h"
#include "chapter-22/matrix_graph/matrix_graph.h"

using namespace CLRS;

TEST(Graph, VertexCreate)
{
  auto v1 = std::make_shared<VertexGraph>(1);
  EXPECT_EQ(1, v1->get_index());
}

TEST(Graph, EdgeCreate)
{
  auto v1 = std::make_shared<VertexGraph>(1);
  auto v2 = std::make_shared<VertexGraph>(2);
  auto e1 = std::make_shared<EdgeGraph>(v1, v2);
  EXPECT_EQ(1, e1->get_first_vertex()->get_index());
  EXPECT_EQ(2, e1->get_second_vertex()->get_index());
}

TEST(Graph, EdgeCompare1)
{
  auto v1 = std::make_shared<VertexGraph>(1);
  auto v2 = std::make_shared<VertexGraph>(2);
  auto v3 = std::make_shared<VertexGraph>(3);
  auto v4 = std::make_shared<VertexGraph>(4);
  auto e1 = std::make_shared<EdgeGraph>(v1, v2);
  auto e2 = std::make_shared<EdgeGraph>(v3, v4);
  EXPECT_TRUE(CLRS::compare_edge_graph(e1, e2));
}

TEST(Graph, EdgeCompare2)
{
  auto v1 = std::make_shared<VertexGraph>(1);
  auto v2 = std::make_shared<VertexGraph>(2);
  auto v3 = std::make_shared<VertexGraph>(3);
  auto e1 = std::make_shared<EdgeGraph>(v1, v2);
  auto e2 = std::make_shared<EdgeGraph>(v1, v3);
  EXPECT_TRUE(CLRS::compare_edge_graph(e1, e2));
}

TEST(Graph, VertexCompare)
{
  auto v1 = std::make_shared<VertexGraph>(1);
  auto v2 = std::make_shared<VertexGraph>(2);
  EXPECT_TRUE(CLRS::compare_vertex_graph(v1, v2));
}

TEST(Graph, SetCompativeVertex)
{
  auto v1 = std::make_shared<VertexGraph>(1);
  auto v2 = std::make_shared<VertexGraph>(2);
  auto v3 = std::make_shared<VertexGraph>(1);
  std::set<std::shared_ptr<VertexGraph>,
	   decltype(compare_vertex_graph)*>
    edge_set(compare_vertex_graph);
  // same pair of indexes -> same keyword
  edge_set.insert(v1);
  edge_set.insert(v2);
  edge_set.insert(v3);
  auto cit = edge_set.cbegin();
  EXPECT_EQ(1, (*cit)->get_index());
  ++cit;
  EXPECT_EQ(2, (*cit)->get_index());
  ++cit;
  EXPECT_TRUE(cit == edge_set.cend());
}

TEST(Graph, SetCompativeEdge1)
{
  auto v1 = std::make_shared<VertexGraph>(1);
  auto v2 = std::make_shared<VertexGraph>(2);
  auto v3 = std::make_shared<VertexGraph>(1);
  auto v4 = std::make_shared<VertexGraph>(2);
  auto e1 = std::make_shared<EdgeGraph>(v1, v2);
  auto e2 = std::make_shared<EdgeGraph>(v3, v4);
  std::set<std::shared_ptr<EdgeGraph>,
	   decltype(compare_edge_graph)*>
    edge_set(compare_edge_graph);
  // same pair of indexes -> same keyword
  edge_set.insert(e1);
  edge_set.insert(e2);
  auto cit = edge_set.cbegin();
  EXPECT_EQ(1, (*cit)->get_first_vertex()->get_index());
  ++cit;
  EXPECT_TRUE(cit == edge_set.cend());
}

TEST(Graph, SetCompativeEdge2)
{
  auto v1 = std::make_shared<VertexGraph>(1);
  auto v2 = std::make_shared<VertexGraph>(2);
  auto v3 = std::make_shared<VertexGraph>(3);
  auto v4 = std::make_shared<VertexGraph>(4);
  auto v5 = std::make_shared<VertexGraph>(5);
  auto v6 = std::make_shared<VertexGraph>(6);
  auto v7 = std::make_shared<VertexGraph>(7);
  auto e1 = std::make_shared<EdgeGraph>(v1, v2);
  auto e2 = std::make_shared<EdgeGraph>(v3, v4);
  auto e3 = std::make_shared<EdgeGraph>(v3, v5);
  auto e4 = std::make_shared<EdgeGraph>(v5, v6);
  auto e5 = std::make_shared<EdgeGraph>(v5, v7);
  std::set<std::shared_ptr<EdgeGraph>,
	   decltype(compare_edge_graph)*>
    edge_set(compare_edge_graph);
  edge_set.insert(e2);
  edge_set.insert(e3);
  edge_set.insert(e5);
  edge_set.insert(e4);
  edge_set.insert(e1);
  auto cit = edge_set.cbegin();
  EXPECT_EQ(1, (*cit)->get_first_vertex()->get_index());
  ++cit;
  EXPECT_EQ(3, (*cit)->get_first_vertex()->get_index());
  EXPECT_EQ(4, (*cit)->get_second_vertex()->get_index());
  ++cit;
  EXPECT_EQ(3, (*cit)->get_first_vertex()->get_index());
  EXPECT_EQ(5, (*cit)->get_second_vertex()->get_index());
  ++cit;
  EXPECT_EQ(5, (*cit)->get_first_vertex()->get_index());
  EXPECT_EQ(6, (*cit)->get_second_vertex()->get_index());
  ++cit;
  EXPECT_EQ(5, (*cit)->get_first_vertex()->get_index());
  EXPECT_EQ(7, (*cit)->get_second_vertex()->get_index());
}

TEST(Graph, LinkedListGraph)
{
  std::set<VertexSHR,
	   decltype(CLRS::compare_vertex_graph)*>
    vs(CLRS::compare_vertex_graph);
  std::set<EdgeSHR,
	   decltype(CLRS::compare_edge_graph)*>
    es(CLRS::compare_edge_graph);
  auto v1 = std::make_shared<VertexGraph>(1);
  auto v2 = std::make_shared<VertexGraph>(2);
  auto v3 = std::make_shared<VertexGraph>(3);
  auto v4 = std::make_shared<VertexGraph>(4);
  auto v5 = std::make_shared<VertexGraph>(5);
  auto v6 = std::make_shared<VertexGraph>(6);
  auto e1 = std::make_shared<EdgeGraph>(v1, v2);
  auto e2 = std::make_shared<EdgeGraph>(v1, v4);
  auto e3 = std::make_shared<EdgeGraph>(v2, v5);
  auto e4 = std::make_shared<EdgeGraph>(v4, v2);
  auto e5 = std::make_shared<EdgeGraph>(v5, v4);
  auto e6 = std::make_shared<EdgeGraph>(v3, v5);
  auto e7 = std::make_shared<EdgeGraph>(v3, v6);
  vs.insert({v1, v2, v3, v4, v5, v6});
  es.insert({e1, e2, e3, e4, e5, e6, e7});
  LinkedListGraph<LinkedListNodeGraph> llg(vs, es);
  EXPECT_TRUE(llg.edge_or_not(e1));
  EXPECT_TRUE(llg.edge_or_not(e2));
  EXPECT_TRUE(llg.edge_or_not(e3));
  EXPECT_TRUE(llg.edge_or_not(e4));
  EXPECT_TRUE(llg.edge_or_not(e5));
  EXPECT_TRUE(llg.edge_or_not(e6));
  EXPECT_TRUE(llg.edge_or_not(e7));
  // case: a edge does not exit
  auto e8= std::make_shared<EdgeGraph>(v4, v3);
  EXPECT_FALSE(llg.edge_or_not(e8));
}

TEST(Graph, MatrixListGraph)
{
  std::set<VertexSHR,
	   decltype(CLRS::compare_vertex_graph)*>
    vs(CLRS::compare_vertex_graph);
  std::set<EdgeSHR,
	   decltype(CLRS::compare_edge_graph)*>
    es(CLRS::compare_edge_graph);
  auto v1 = std::make_shared<VertexGraph>(1);
  auto v2 = std::make_shared<VertexGraph>(2);
  auto v3 = std::make_shared<VertexGraph>(3);
  auto v4 = std::make_shared<VertexGraph>(4);
  auto v5 = std::make_shared<VertexGraph>(5);
  auto v6 = std::make_shared<VertexGraph>(6);
  auto e1 = std::make_shared<EdgeGraph>(v1, v2);
  auto e2 = std::make_shared<EdgeGraph>(v1, v4);
  auto e3 = std::make_shared<EdgeGraph>(v2, v5);
  auto e4 = std::make_shared<EdgeGraph>(v4, v2);
  auto e5 = std::make_shared<EdgeGraph>(v5, v4);
  auto e6 = std::make_shared<EdgeGraph>(v3, v5);
  auto e7 = std::make_shared<EdgeGraph>(v3, v6);
  vs.insert({v1, v2, v3, v4, v5, v6});
  es.insert({e1, e2, e3, e4, e5, e6, e7});
  MatrixGraph mg(vs, es);
  EXPECT_TRUE(mg.edge_or_not(e1));
  EXPECT_TRUE(mg.edge_or_not(e2));
  EXPECT_TRUE(mg.edge_or_not(e3));
  EXPECT_TRUE(mg.edge_or_not(e4));
  EXPECT_TRUE(mg.edge_or_not(e5));
  EXPECT_TRUE(mg.edge_or_not(e6));
  EXPECT_TRUE(mg.edge_or_not(e7));
  // case: a edge does not exit
  auto e8= std::make_shared<EdgeGraph>(v4, v3);
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
    
  std::set<VertexSHR,
	   decltype(CLRS::compare_vertex_graph)*>
    vs(CLRS::compare_vertex_graph);
  std::set<EdgeSHR,
	   decltype(CLRS::compare_edge_graph)*>
    es(CLRS::compare_edge_graph);
  auto v1 = std::shared_ptr<VertexGraph>
    (new DerivedVertexGraph(1, 1));
  auto v2 = std::shared_ptr<VertexGraph>
    (new DerivedVertexGraph(2, 2));
  auto v3 = std::shared_ptr<VertexGraph>
    (new DerivedVertexGraph(3, 3));
  auto v4 = std::shared_ptr<VertexGraph>
    (new DerivedVertexGraph(4, 4));
  auto v5 = std::shared_ptr<VertexGraph>
    (new DerivedVertexGraph(5, 5));
  auto v6 = std::shared_ptr<VertexGraph>
    (new DerivedVertexGraph(6, 6));
  auto e1 = std::make_shared<EdgeGraph>(v1, v2);
  auto e2 = std::make_shared<EdgeGraph>(v1, v4);
  auto e3 = std::make_shared<EdgeGraph>(v2, v5);
  auto e4 = std::make_shared<EdgeGraph>(v4, v2);
  auto e5 = std::make_shared<EdgeGraph>(v5, v4);
  auto e6 = std::make_shared<EdgeGraph>(v3, v5);
  auto e7 = std::make_shared<EdgeGraph>(v3, v6);
  vs.insert({v1, v2, v3, v4, v5, v6});
  es.insert({e1, e2, e3, e4, e5, e6, e7});
  // test for MatrixGraph
  MatrixGraph mg(vs, es);
  EXPECT_TRUE(mg.edge_or_not(e1));
  // test for LinkedListGraph
  LinkedListGraph<LinkedListNodeGraph> llg(vs, es);
  EXPECT_TRUE(llg.edge_or_not(e1));
  // test for the additional parameter
  auto v = mg.get_vertex(1);
  // first try of dynamic_cast,
  // be alert that only suits class with virtual function
  DerivedVertexGraph &w =
    dynamic_cast<DerivedVertexGraph&>(*v);
  EXPECT_EQ(1, w.get_weight());
}

TEST(Graph, DerivedEdge)
{
  // a derived class with an additional edge parameter
  class DerivedEdgeGraph: public EdgeGraph
  {
  private:
    unsigned weight;
  public:
    DerivedEdgeGraph(const VertexSHR &v1,
		     const VertexSHR &v2,
		     unsigned w):
      EdgeGraph(v1, v2), weight(w) {}
    unsigned get_weight() const {return weight;}
  };

  std::set<VertexSHR,
	   decltype(CLRS::compare_vertex_graph)*>
    vs(CLRS::compare_vertex_graph);
  std::set<EdgeSHR,
	   decltype(CLRS::compare_edge_graph)*>
    es(CLRS::compare_edge_graph);
  auto v1 = std::make_shared<VertexGraph>(1);
  auto v2 = std::make_shared<VertexGraph>(2);
  auto v3 = std::make_shared<VertexGraph>(3);
  auto v4 = std::make_shared<VertexGraph>(4);
  auto v5 = std::make_shared<VertexGraph>(5);
  auto v6 = std::make_shared<VertexGraph>(6);
  auto e1 = std::shared_ptr<EdgeGraph>
    (new DerivedEdgeGraph(v1, v2, 1));
  auto e2 = std::shared_ptr<EdgeGraph>
    (new DerivedEdgeGraph(v1, v4, 2));
  auto e3 = std::shared_ptr<EdgeGraph>
    (new DerivedEdgeGraph(v2, v5, 3));
  auto e4 = std::shared_ptr<EdgeGraph>
    (new DerivedEdgeGraph(v4, v2, 4));
  auto e5 = std::shared_ptr<EdgeGraph>
    (new DerivedEdgeGraph(v5, v4, 5));
  auto e6 = std::shared_ptr<EdgeGraph>
    (new DerivedEdgeGraph(v3, v5, 6));
  auto e7 = std::shared_ptr<EdgeGraph>
    (new DerivedEdgeGraph(v3, v6, 7));
  vs.insert({v1, v2, v3, v4, v5, v6});
  es.insert({e1, e2, e3, e4, e5, e6, e7});
  // test for MatrixGraph
  MatrixGraph mg(vs, es);
  EXPECT_TRUE(mg.edge_or_not(e1));
  // test for LinkedListGraph
  LinkedListGraph<LinkedListNodeGraph> llg(vs, es);
  EXPECT_TRUE(llg.edge_or_not(e1));
  // test for the additional parameter
  auto e = mg.get_edge(1, 2);
  // first try of dynamic_cast,
  // be alert that only suits class with virtual function
  DerivedEdgeGraph &w =
    dynamic_cast<DerivedEdgeGraph&>(*e);
  EXPECT_EQ(1, w.get_weight());
}

TEST(Graph, DerivedLinkedListNodeGraph)
{
  // a derived class with an additional edge parameter
  // this time edge paremeter stored in linked list node
  class DerivedNodeGraph
  {
  private:
    std::size_t index;
    unsigned weight;
    std::shared_ptr<DerivedNodeGraph> next;
  public:
    DerivedNodeGraph(const EdgeSHR &e):
      index(e->get_second_vertex()->get_index()),
      weight(index + e->get_first_vertex()->get_index()) {}
    std::size_t get_index() const {return index;}
    unsigned get_weight() const {return weight;}
    std::shared_ptr<DerivedNodeGraph>
    get_next() const {return next;}
    void set_next(const
		  std::shared_ptr<DerivedNodeGraph>
		  &np) {next = np;}
  };
 
  std::set<VertexSHR,
	   decltype(CLRS::compare_vertex_graph)*>
    vs(CLRS::compare_vertex_graph);
  std::set<EdgeSHR,
	   decltype(CLRS::compare_edge_graph)*>
    es(CLRS::compare_edge_graph);
  auto v1 = std::make_shared<VertexGraph>(1);
  auto v2 = std::make_shared<VertexGraph>(2);
  auto v3 = std::make_shared<VertexGraph>(3);
  auto v4 = std::make_shared<VertexGraph>(4);
  auto v5 = std::make_shared<VertexGraph>(5);
  auto v6 = std::make_shared<VertexGraph>(6);
  auto e1 = std::make_shared<EdgeGraph>(v1, v2);
  auto e2 = std::make_shared<EdgeGraph>(v1, v4);
  auto e3 = std::make_shared<EdgeGraph>(v2, v5);
  auto e4 = std::make_shared<EdgeGraph>(v4, v2);
  auto e5 = std::make_shared<EdgeGraph>(v5, v4);
  auto e6 = std::make_shared<EdgeGraph>(v3, v5);
  auto e7 = std::make_shared<EdgeGraph>(v3, v6);
  vs.insert({v1, v2, v3, v4, v5, v6});
  es.insert({e1, e2, e3, e4, e5, e6, e7});
  LinkedListGraph<DerivedNodeGraph> llg(vs, es);
  EXPECT_TRUE(llg.edge_or_not(e1));
  EXPECT_TRUE(llg.edge_or_not(e2));
  EXPECT_TRUE(llg.edge_or_not(e3));
  EXPECT_TRUE(llg.edge_or_not(e4));
  EXPECT_TRUE(llg.edge_or_not(e5));
  EXPECT_TRUE(llg.edge_or_not(e6));
  EXPECT_TRUE(llg.edge_or_not(e7));
  // edge parameter check
  EXPECT_EQ(3, llg.get_node(e1).get_weight());
}
