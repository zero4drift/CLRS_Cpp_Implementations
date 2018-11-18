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
  EXPECT_TRUE(compare_edge_graph(e1, e2));
}

TEST(Graph, EdgeCompare2)
{
  auto v1 = std::make_shared<VertexGraph>(1);
  auto v2 = std::make_shared<VertexGraph>(2);
  auto v3 = std::make_shared<VertexGraph>(3);
  auto e1 = std::make_shared<EdgeGraph>(v1, v2);
  auto e2 = std::make_shared<EdgeGraph>(v1, v3);
  EXPECT_TRUE(compare_edge_graph(e1, e2));
}

TEST(Graph, SetCompativeEdge)
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
