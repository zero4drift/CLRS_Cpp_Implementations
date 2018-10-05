#include <gtest/gtest.h>
#include "chapter-10/tree/tree.h"
#include "chapter-12/binary_search_tree/binary_search_tree.h"

using namespace CLRS;

TEST(BinarySearchTree, InsertSearh)
{
  Tree<int> t;
  TreeNode<int> n1(6);
  TreeNode<int> n2(5);
  TreeNode<int> n3(2);
  TreeNode<int> n4(5);
  TreeNode<int> n5(7);
  TreeNode<int> n6(8);
  tree_insert(&t, &n1);
  tree_insert(&t, &n2);
  tree_insert(&t, &n3);
  tree_insert(&t, &n4);
  tree_insert(&t, &n5);
  tree_insert(&t, &n6);
  EXPECT_EQ(6, tree_search(t.get_root(), 6)->get_value());
  EXPECT_EQ(2, iterative_tree_search(t.get_root(), 2)->get_value());
  EXPECT_EQ(8, tree_search(t.get_root(), 8)->get_value());
  EXPECT_EQ(nullptr, tree_search(t.get_root(), 4));
}

TEST(BinarySearchTree, MinimumMaximum)
{
  Tree<int> t;
  TreeNode<int> n1(6);
  TreeNode<int> n2(5);
  TreeNode<int> n3(2);
  TreeNode<int> n4(5);
  TreeNode<int> n5(7);
  TreeNode<int> n6(8);
  tree_insert(&t, &n1);
  tree_insert(&t, &n2);
  tree_insert(&t, &n3);
  tree_insert(&t, &n4);
  tree_insert(&t, &n5);
  tree_insert(&t, &n6);
  EXPECT_EQ(8, tree_maximum(t.get_root())->get_value());
  EXPECT_EQ(2, tree_minimum(t.get_root())->get_value());
}

TEST(BinarySearchTree, SuccessorPredecessor)
{
  Tree<int> t;
  TreeNode<int> n1(6);
  TreeNode<int> n2(5);
  TreeNode<int> n3(2);
  TreeNode<int> n4(5);
  TreeNode<int> n5(7);
  TreeNode<int> n6(8);
  tree_insert(&t, &n1);
  tree_insert(&t, &n2);
  tree_insert(&t, &n3);
  tree_insert(&t, &n4);
  tree_insert(&t, &n5);
  tree_insert(&t, &n6);
  EXPECT_EQ(7, tree_successor(&n1)->get_value());
  EXPECT_EQ(5, tree_predecessor(&n4)->get_value());
}

TEST(BinarySearchTree, Delete)
{
  Tree<int> t;
  TreeNode<int> n1(6);
  TreeNode<int> n2(5);
  TreeNode<int> n3(2);
  TreeNode<int> n4(5);
  TreeNode<int> n5(7);
  TreeNode<int> n6(8);
  tree_insert(&t, &n1);
  tree_insert(&t, &n2);
  tree_insert(&t, &n3);
  tree_insert(&t, &n4);
  tree_insert(&t, &n5);
  tree_insert(&t, &n6);
  EXPECT_EQ(7, tree_successor(&n1)->get_value());
  EXPECT_EQ(5, tree_predecessor(&n4)->get_value());
  tree_delete(&t, &n3);
  EXPECT_EQ(nullptr, tree_search(t.get_root(), 2));
  EXPECT_EQ(7, tree_successor(&n1)->get_value());
  EXPECT_EQ(5, tree_predecessor(&n4)->get_value());
}
