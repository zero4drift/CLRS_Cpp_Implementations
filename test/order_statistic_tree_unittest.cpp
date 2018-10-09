#include <gtest/gtest.h>
#include "chapter-14/order_statistic_tree/order_statistic_tree.h"

using namespace CLRS;

TEST(OrderStatisticTree, InsertSearhRankSelect1)
{
  OrderStatisticTree<int> t;
  OrderStatisticTreeNode<int> n1(6);
  OrderStatisticTreeNode<int> n2(5);
  OrderStatisticTreeNode<int> n3(2);
  OrderStatisticTreeNode<int> n4(5);
  OrderStatisticTreeNode<int> n5(7);
  OrderStatisticTreeNode<int> n6(8);
  order_statistic_tree_insert(&t, &n1);
  order_statistic_tree_insert(&t, &n2);
  order_statistic_tree_insert(&t, &n3);
  order_statistic_tree_insert(&t, &n4);
  order_statistic_tree_insert(&t, &n5);
  order_statistic_tree_insert(&t, &n6);
  EXPECT_EQ(6, order_statistic_tree_search(t.get_nil(), t.get_root(), 6)->get_value());
  EXPECT_EQ(2, iterative_order_statistic_tree_search(t.get_nil(), t.get_root(), 2)->get_value());
  EXPECT_EQ(8, order_statistic_tree_search(t.get_nil(), t.get_root(), 8)->get_value());
  EXPECT_EQ(t.get_nil(), order_statistic_tree_search(t.get_nil(), t.get_root(), 4));
  EXPECT_EQ(&n3, order_statistic_select(t.get_root(), 1));
  EXPECT_EQ(&n5, order_statistic_select(t.get_root(), 5));
  EXPECT_EQ(1, order_statistic_rank(&t, &n3));
  EXPECT_EQ(6, order_statistic_rank(&t, &n6));
}

TEST(OrderStatisticTree, InsertSearhRankSelect2)
{
  OrderStatisticTree<int> t;
  OrderStatisticTreeNode<int> n1(11);
  OrderStatisticTreeNode<int> n2(2);
  OrderStatisticTreeNode<int> n3(14);
  OrderStatisticTreeNode<int> n4(1);
  OrderStatisticTreeNode<int> n5(7);
  OrderStatisticTreeNode<int> n6(15);
  OrderStatisticTreeNode<int> n7(5);
  OrderStatisticTreeNode<int> n8(8);
  OrderStatisticTreeNode<int> n9(4);
  order_statistic_tree_insert(&t, &n1);
  order_statistic_tree_insert(&t, &n2);
  order_statistic_tree_insert(&t, &n3);
  order_statistic_tree_insert(&t, &n4);
  order_statistic_tree_insert(&t, &n5);
  order_statistic_tree_insert(&t, &n6);
  order_statistic_tree_insert(&t, &n7);
  order_statistic_tree_insert(&t, &n8);
  order_statistic_tree_insert(&t, &n9);
  EXPECT_EQ(14, order_statistic_tree_search(t.get_nil(), t.get_root(), 14)->get_value());
  EXPECT_EQ(2, iterative_order_statistic_tree_search(t.get_nil(), t.get_root(), 2)->get_value());
  EXPECT_EQ(8, order_statistic_tree_search(t.get_nil(), t.get_root(), 8)->get_value());
  EXPECT_EQ(t.get_nil(), order_statistic_tree_search(t.get_nil(), t.get_root(), 13));
  EXPECT_EQ(&n5, t.get_root());
  EXPECT_EQ(&n4, order_statistic_select(t.get_root(), 1));
  EXPECT_EQ(&n5, order_statistic_select(t.get_root(), 5));
  EXPECT_EQ(8, order_statistic_rank(&t, &n3));
  EXPECT_EQ(5, order_statistic_rank(&t, &n5));

}

TEST(OrderStatisticTree, MinimumMaximum)
{
  OrderStatisticTree<int> t;
  OrderStatisticTreeNode<int> n1(6);
  OrderStatisticTreeNode<int> n2(5);
  OrderStatisticTreeNode<int> n3(2);
  OrderStatisticTreeNode<int> n4(5);
  OrderStatisticTreeNode<int> n5(7);
  OrderStatisticTreeNode<int> n6(8);
  order_statistic_tree_insert(&t, &n1);
  order_statistic_tree_insert(&t, &n2);
  order_statistic_tree_insert(&t, &n3);
  order_statistic_tree_insert(&t, &n4);
  order_statistic_tree_insert(&t, &n5);
  order_statistic_tree_insert(&t, &n6);
  EXPECT_EQ(8, order_statistic_tree_maximum(t.get_nil(), t.get_root())->get_value());
  EXPECT_EQ(2, order_statistic_tree_minimum(t.get_nil(), t.get_root())->get_value());
}

TEST(OrderStatisticTree, SuccessorPredecessor)
{
  OrderStatisticTree<int> t;
  OrderStatisticTreeNode<int> n1(6);
  OrderStatisticTreeNode<int> n2(5);
  OrderStatisticTreeNode<int> n3(2);
  OrderStatisticTreeNode<int> n4(5);
  OrderStatisticTreeNode<int> n5(7);
  OrderStatisticTreeNode<int> n6(8);
  order_statistic_tree_insert(&t, &n1);
  order_statistic_tree_insert(&t, &n2);
  order_statistic_tree_insert(&t, &n3);
  order_statistic_tree_insert(&t, &n4);
  order_statistic_tree_insert(&t, &n5);
  order_statistic_tree_insert(&t, &n6);
  EXPECT_EQ(7, order_statistic_tree_successor(t.get_nil(), &n1)->get_value());
  EXPECT_EQ(5, order_statistic_tree_predecessor(t.get_nil(), &n4)->get_value());
}

TEST(OrderStatisticTree, Delete)
{
  OrderStatisticTree<int> t;
  OrderStatisticTreeNode<int> n1(6);
  OrderStatisticTreeNode<int> n2(5);
  OrderStatisticTreeNode<int> n3(2);
  OrderStatisticTreeNode<int> n4(5);
  OrderStatisticTreeNode<int> n5(7);
  OrderStatisticTreeNode<int> n6(8);
  order_statistic_tree_insert(&t, &n1);
  order_statistic_tree_insert(&t, &n2);
  order_statistic_tree_insert(&t, &n3);
  order_statistic_tree_insert(&t, &n4);
  order_statistic_tree_insert(&t, &n5);
  order_statistic_tree_insert(&t, &n6);
  order_statistic_tree_delete(&t, &n3);
  EXPECT_EQ(t.get_nil(), order_statistic_tree_search(t.get_nil(), t.get_root(), 2));
  EXPECT_EQ(7, order_statistic_tree_successor(t.get_nil(), &n1)->get_value());
  EXPECT_EQ(5, order_statistic_tree_predecessor(t.get_nil(), &n4)->get_value());
  EXPECT_EQ(&n1, order_statistic_select(t.get_root(), 3));
  EXPECT_EQ(&n6, order_statistic_select(t.get_root(), 5));
  EXPECT_EQ(4, order_statistic_rank(&t, &n5));
  EXPECT_EQ(5, order_statistic_rank(&t, &n6));
}
