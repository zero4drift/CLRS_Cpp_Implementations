#include <gtest/gtest.h>
#include "chapter-10/list/list.h"

TEST(ListTest, InsertSearch)
{
  List<int> l;
  ListNode<int> n1(1);
  ListNode<int> n2(2);
  ListNode<int> n3(3);
  ListNode<int> n4(4);
  list_insert(l, n1);
  list_insert(l, n2);
  list_insert(l, n3);
  list_insert(l, n4);
  EXPECT_EQ(1, list_search(l, 1)->get_value());
  EXPECT_EQ(2, list_search(l, 2)->get_value());
  EXPECT_EQ(3, list_search(l, 3)->get_value());
  EXPECT_EQ(4, list_search(l, 4)->get_value());
}

TEST(ListTest, InsertDelete)
{
  List<int> l;
  ListNode<int> n1(1);
  ListNode<int> n2(2);
  ListNode<int> n3(3);
  ListNode<int> n4(4);
  list_insert(l, n1);
  list_insert(l, n2);
  list_insert(l, n3);
  list_insert(l, n4);
  list_delete(l, n1);
  EXPECT_EQ(nullptr, list_search(l, 1));
  list_delete(l, n2);
  EXPECT_EQ(nullptr, list_search(l, 2));
  list_delete(l, n3);
  EXPECT_EQ(nullptr, list_search(l, 3));
  list_delete(l, n4);
  EXPECT_EQ(nullptr, list_search(l, 4));
}
