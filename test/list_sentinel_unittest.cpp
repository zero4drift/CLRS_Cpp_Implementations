#include <gtest/gtest.h>
#include "chapter-10/list/list_sentinel.h"

using namespace CLRS;

TEST(ListSentinelTest, InsertSearch)
{
  ListSentinel<int> l;
  ListSentinelNode<int> n1(1);
  ListSentinelNode<int> n2(2);
  ListSentinelNode<int> n3(3);
  ListSentinelNode<int> n4(4);
  list_sentinel_insert(l, n1);
  list_sentinel_insert(l, n2);
  list_sentinel_insert(l, n3);
  list_sentinel_insert(l, n4);
  EXPECT_EQ(1, list_sentinel_search(l, 1)->get_value());
  EXPECT_EQ(2, list_sentinel_search(l, 2)->get_value());
  EXPECT_EQ(3, list_sentinel_search(l, 3)->get_value());
  EXPECT_EQ(4, list_sentinel_search(l, 4)->get_value());
}

TEST(ListSentinelTest, InsertDelete)
{
  ListSentinel<int> l;
  ListSentinelNode<int> n1(1);
  ListSentinelNode<int> n2(2);
  ListSentinelNode<int> n3(3);
  ListSentinelNode<int> n4(4);
  list_sentinel_insert(l, n1);
  list_sentinel_insert(l, n2);
  list_sentinel_insert(l, n3);
  list_sentinel_insert(l, n4);
  list_sentinel_delete(l, n1);
  EXPECT_EQ(nullptr, list_sentinel_search(l, 1));
  list_sentinel_delete(l, n2);
  EXPECT_EQ(nullptr, list_sentinel_search(l, 2));
  list_sentinel_delete(l, n3);
  EXPECT_EQ(nullptr, list_sentinel_search(l, 3));
  list_sentinel_delete(l, n4);
  EXPECT_EQ(nullptr, list_sentinel_search(l, 4));
}
