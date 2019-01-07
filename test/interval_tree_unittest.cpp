#include <gtest/gtest.h>
#include "chapter-14/interval_tree/interval_tree.hpp"

using namespace CLRS;

TEST(IntervalTree, InsertSearh)
{
  IntervalTree<int> t;
  IntervalTreeNode<int> n1(16, 21);
  IntervalTreeNode<int> n2(8, 9);
  IntervalTreeNode<int> n3(25, 30);
  IntervalTreeNode<int> n4(5, 8);
  IntervalTreeNode<int> n5(15, 23);
  IntervalTreeNode<int> n6(17, 19);
  IntervalTreeNode<int> n7(26, 26);
  IntervalTreeNode<int> n8(0, 3);
  IntervalTreeNode<int> n9(6, 10);
  IntervalTreeNode<int> n10(19, 20);
  interval_tree_insert(&t, &n1);
  interval_tree_insert(&t, &n2);
  interval_tree_insert(&t, &n3);
  interval_tree_insert(&t, &n4);
  interval_tree_insert(&t, &n5);
  interval_tree_insert(&t, &n6);
  interval_tree_insert(&t, &n7);
  interval_tree_insert(&t, &n8);
  interval_tree_insert(&t, &n9);
  interval_tree_insert(&t, &n10);
  EXPECT_EQ(&n5, interval_tree_search(&t, Interval<int>(22, 25)));
  EXPECT_EQ(t.get_nil(),  interval_tree_search(&t, Interval<int>(11, 14)));
}

TEST(IntervalTree, MinimumMaximum)
{
  IntervalTree<int> t;
  IntervalTreeNode<int> n1(16, 21);
  IntervalTreeNode<int> n2(8, 9);
  IntervalTreeNode<int> n3(25, 30);
  IntervalTreeNode<int> n4(5, 8);
  IntervalTreeNode<int> n5(15, 23);
  IntervalTreeNode<int> n6(17, 19);
  IntervalTreeNode<int> n7(26, 26);
  IntervalTreeNode<int> n8(0, 3);
  IntervalTreeNode<int> n9(6, 10);
  IntervalTreeNode<int> n10(19, 20);
  interval_tree_insert(&t, &n1);
  interval_tree_insert(&t, &n2);
  interval_tree_insert(&t, &n3);
  interval_tree_insert(&t, &n4);
  interval_tree_insert(&t, &n5);
  interval_tree_insert(&t, &n6);
  interval_tree_insert(&t, &n7);
  interval_tree_insert(&t, &n8);
  interval_tree_insert(&t, &n9);
  interval_tree_insert(&t, &n10);
  EXPECT_EQ(26, interval_tree_maximum(t.get_nil(), t.get_root())->get_value());
  EXPECT_EQ(0, interval_tree_minimum(t.get_nil(), t.get_root())->get_value());
}

TEST(IntervalTree, SuccessorPredecessor)
{
  IntervalTree<int> t;
  IntervalTreeNode<int> n1(16, 21);
  IntervalTreeNode<int> n2(8, 9);
  IntervalTreeNode<int> n3(25, 30);
  IntervalTreeNode<int> n4(5, 8);
  IntervalTreeNode<int> n5(15, 23);
  IntervalTreeNode<int> n6(17, 19);
  IntervalTreeNode<int> n7(26, 26);
  IntervalTreeNode<int> n8(0, 3);
  IntervalTreeNode<int> n9(6, 10);
  IntervalTreeNode<int> n10(19, 20);
  interval_tree_insert(&t, &n1);
  interval_tree_insert(&t, &n2);
  interval_tree_insert(&t, &n3);
  interval_tree_insert(&t, &n4);
  interval_tree_insert(&t, &n5);
  interval_tree_insert(&t, &n6);
  interval_tree_insert(&t, &n7);
  interval_tree_insert(&t, &n8);
  interval_tree_insert(&t, &n9);
  interval_tree_insert(&t, &n10);
  EXPECT_EQ(17, interval_tree_successor(t.get_nil(), &n1)->get_value());
  EXPECT_EQ(0, interval_tree_predecessor(t.get_nil(), &n4)->get_value());
}

TEST(IntervalTree, Delete)
{
  IntervalTree<int> t;
  IntervalTreeNode<int> n1(16, 21);
  IntervalTreeNode<int> n2(8, 9);
  IntervalTreeNode<int> n3(25, 30);
  IntervalTreeNode<int> n4(5, 8);
  IntervalTreeNode<int> n5(15, 23);
  IntervalTreeNode<int> n6(17, 19);
  IntervalTreeNode<int> n7(26, 26);
  IntervalTreeNode<int> n8(0, 3);
  IntervalTreeNode<int> n9(6, 10);
  IntervalTreeNode<int> n10(19, 20);
  interval_tree_insert(&t, &n1);
  interval_tree_insert(&t, &n2);
  interval_tree_insert(&t, &n3);
  interval_tree_insert(&t, &n4);
  interval_tree_insert(&t, &n5);
  interval_tree_insert(&t, &n6);
  interval_tree_insert(&t, &n7);
  interval_tree_insert(&t, &n8);
  interval_tree_insert(&t, &n9);
  interval_tree_insert(&t, &n10);
  interval_tree_delete(&t, &n5);
  EXPECT_EQ(&n3,  interval_tree_search(&t, Interval<int>(22, 25)));
  EXPECT_EQ(10, n2.get_max());
}

