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
