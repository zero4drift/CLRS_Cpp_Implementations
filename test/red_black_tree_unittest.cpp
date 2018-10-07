#include <gtest/gtest.h>
#include "chapter-13/red_black_tree/red_black_tree.h"

using namespace CLRS;

TEST(RedBlackRedBlackTree, InsertSearh1)
{
  RedBlackTree<int> t;
  RedBlackTreeNode<int> n1(6);
  RedBlackTreeNode<int> n2(5);
  RedBlackTreeNode<int> n3(2);
  RedBlackTreeNode<int> n4(5);
  RedBlackTreeNode<int> n5(7);
  RedBlackTreeNode<int> n6(8);
  red_black_tree_insert(&t, &n1);
  red_black_tree_insert(&t, &n2);
  red_black_tree_insert(&t, &n3);
  red_black_tree_insert(&t, &n4);
  red_black_tree_insert(&t, &n5);
  red_black_tree_insert(&t, &n6);
  EXPECT_EQ(6, red_black_tree_search(t.get_nil(), t.get_root(), 6)->get_value());
  EXPECT_EQ(2, iterative_red_black_tree_search(t.get_nil(), t.get_root(), 2)->get_value());
  EXPECT_EQ(8, red_black_tree_search(t.get_nil(), t.get_root(), 8)->get_value());
  EXPECT_EQ(t.get_nil(), red_black_tree_search(t.get_nil(), t.get_root(), 4));
}

TEST(RedBlackRedBlackTree, InsertSearh2)
{
  RedBlackTree<int> t;
  RedBlackTreeNode<int> n1(11);
  RedBlackTreeNode<int> n2(2);
  RedBlackTreeNode<int> n3(14);
  RedBlackTreeNode<int> n4(1);
  RedBlackTreeNode<int> n5(7);
  RedBlackTreeNode<int> n6(15);
  RedBlackTreeNode<int> n7(5);
  RedBlackTreeNode<int> n8(8);
  RedBlackTreeNode<int> n9(4);
  red_black_tree_insert(&t, &n1);
  red_black_tree_insert(&t, &n2);
  red_black_tree_insert(&t, &n3);
  red_black_tree_insert(&t, &n4);
  red_black_tree_insert(&t, &n5);
  red_black_tree_insert(&t, &n6);
  red_black_tree_insert(&t, &n7);
  red_black_tree_insert(&t, &n8);
  red_black_tree_insert(&t, &n9);
  EXPECT_EQ(14, red_black_tree_search(t.get_nil(), t.get_root(), 14)->get_value());
  EXPECT_EQ(2, iterative_red_black_tree_search(t.get_nil(), t.get_root(), 2)->get_value());
  EXPECT_EQ(8, red_black_tree_search(t.get_nil(), t.get_root(), 8)->get_value());
  EXPECT_EQ(t.get_nil(), red_black_tree_search(t.get_nil(), t.get_root(), 13));
  EXPECT_EQ(&n5, t.get_root());
}

TEST(RedBlackRedBlackTree, MinimumMaximum)
{
  RedBlackTree<int> t;
  RedBlackTreeNode<int> n1(6);
  RedBlackTreeNode<int> n2(5);
  RedBlackTreeNode<int> n3(2);
  RedBlackTreeNode<int> n4(5);
  RedBlackTreeNode<int> n5(7);
  RedBlackTreeNode<int> n6(8);
  red_black_tree_insert(&t, &n1);
  red_black_tree_insert(&t, &n2);
  red_black_tree_insert(&t, &n3);
  red_black_tree_insert(&t, &n4);
  red_black_tree_insert(&t, &n5);
  red_black_tree_insert(&t, &n6);
  EXPECT_EQ(8, red_black_tree_maximum(t.get_nil(), t.get_root())->get_value());
  EXPECT_EQ(2, red_black_tree_minimum(t.get_nil(), t.get_root())->get_value());
}

TEST(RedBlackRedBlackTree, SuccessorPredecessor)
{
  RedBlackTree<int> t;
  RedBlackTreeNode<int> n1(6);
  RedBlackTreeNode<int> n2(5);
  RedBlackTreeNode<int> n3(2);
  RedBlackTreeNode<int> n4(5);
  RedBlackTreeNode<int> n5(7);
  RedBlackTreeNode<int> n6(8);
  red_black_tree_insert(&t, &n1);
  red_black_tree_insert(&t, &n2);
  red_black_tree_insert(&t, &n3);
  red_black_tree_insert(&t, &n4);
  red_black_tree_insert(&t, &n5);
  red_black_tree_insert(&t, &n6);
  EXPECT_EQ(7, red_black_tree_successor(t.get_nil(), &n1)->get_value());
  EXPECT_EQ(5, red_black_tree_predecessor(t.get_nil(), &n4)->get_value());
}

TEST(RedBlackRedBlackTree, Delete)
{
  RedBlackTree<int> t;
  RedBlackTreeNode<int> n1(6);
  RedBlackTreeNode<int> n2(5);
  RedBlackTreeNode<int> n3(2);
  RedBlackTreeNode<int> n4(5);
  RedBlackTreeNode<int> n5(7);
  RedBlackTreeNode<int> n6(8);
  red_black_tree_insert(&t, &n1);
  red_black_tree_insert(&t, &n2);
  red_black_tree_insert(&t, &n3);
  red_black_tree_insert(&t, &n4);
  red_black_tree_insert(&t, &n5);
  red_black_tree_insert(&t, &n6);
  EXPECT_EQ(7, red_black_tree_successor(t.get_nil(), &n1)->get_value());
  EXPECT_EQ(5, red_black_tree_predecessor(t.get_nil(), &n4)->get_value());
  red_black_tree_delete(&t, &n3);
  EXPECT_EQ(t.get_nil(), red_black_tree_search(t.get_nil(), t.get_root(), 2));
  EXPECT_EQ(7, red_black_tree_successor(t.get_nil(), &n1)->get_value());
  EXPECT_EQ(5, red_black_tree_predecessor(t.get_nil(), &n4)->get_value());
}
