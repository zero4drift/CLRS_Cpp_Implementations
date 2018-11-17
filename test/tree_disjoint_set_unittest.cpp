#include <memory>
#include <gtest/gtest.h>
#include "chapter-21/tree_disjoint_set/tree_disjoint_set.h"

using namespace CLRS;

TEST(TreeDisjointSet, MakeSet)
{
  int i1 = 1;
  auto n1 =
    std::make_shared<TreeDisjointSetNode<int>>(i1);
  tree_disjoint_make_set(n1);
  EXPECT_EQ(1, n1->get_key());
  EXPECT_EQ(n1, n1->get_p());
  EXPECT_EQ(0, n1->get_rank());
}

TEST(TreeDisjointSet, FindSet)
{
  int i1 = 1;
  int i2 = 2;
  int i3 = 3;
  int i4 = 4;
  int i5 = 5;
  int i6 = 6;
  // 1
  auto n1 = std::make_shared<TreeDisjointSetNode<int>>(i1);
  tree_disjoint_make_set(n1);
  EXPECT_EQ(n1, tree_disjoint_find_set(n1));
  // 2
  auto n2 = std::make_shared<TreeDisjointSetNode<int>>(i2);
  tree_disjoint_make_set(n2);
  EXPECT_EQ(n2, tree_disjoint_find_set(n2));
  // 3
  auto n3 = std::make_shared<TreeDisjointSetNode<int>>(i3);
  tree_disjoint_make_set(n3);
  EXPECT_EQ(n3, tree_disjoint_find_set(n3));
  // 4
  auto n4 = std::make_shared<TreeDisjointSetNode<int>>(i4);
  tree_disjoint_make_set(n4);
  EXPECT_EQ(n4, tree_disjoint_find_set(n4));
  // 5
  auto n5 = std::make_shared<TreeDisjointSetNode<int>>(i5);
  tree_disjoint_make_set(n5);
  EXPECT_EQ(n5, tree_disjoint_find_set(n5));
  // 6
  auto n6 = std::make_shared<TreeDisjointSetNode<int>>(i6);
  tree_disjoint_make_set(n6);
  EXPECT_EQ(n6, tree_disjoint_find_set(n6));
}

TEST(TreeDisjointSet, Union1)
{
  int i1 = 1;
  int i2 = 2;
  int i3 = 3;
  int i4 = 4;
  int i5 = 5;
  int i6 = 6;
  // 1
  auto n1 = std::make_shared<TreeDisjointSetNode<int>>(i1);
  tree_disjoint_make_set(n1);
  // 2
  auto n2 = std::make_shared<TreeDisjointSetNode<int>>(i2);
  tree_disjoint_make_set(n2);
  // 3
  auto n3 = std::make_shared<TreeDisjointSetNode<int>>(i3);
  tree_disjoint_make_set(n3);
  // 4
  auto n4 = std::make_shared<TreeDisjointSetNode<int>>(i4);
  tree_disjoint_make_set(n4);
  // 5
  auto n5 = std::make_shared<TreeDisjointSetNode<int>>(i5);
  tree_disjoint_make_set(n5);
  // 6
  auto n6 = std::make_shared<TreeDisjointSetNode<int>>(i6);
  tree_disjoint_make_set(n6);
  // 1st union
  tree_disjoint_union(n1, n2);
  EXPECT_EQ(n2, tree_disjoint_find_set(n1));
  EXPECT_EQ(1, n2->get_rank());
  // 2nd union
  tree_disjoint_union(n1, n3);
  EXPECT_EQ(n2, tree_disjoint_find_set(n3));
  EXPECT_EQ(1, n2->get_rank());
  // 3rd union
  tree_disjoint_union(n3, n4);
  EXPECT_EQ(n2, tree_disjoint_find_set(n4));
  EXPECT_EQ(1, n2->get_rank());
  // 4th union
  tree_disjoint_union(n4, n5);
  EXPECT_EQ(n2, tree_disjoint_find_set(n5));
  EXPECT_EQ(1, n2->get_rank());
  // 5th union
  tree_disjoint_union(n5, n6);
  EXPECT_EQ(n2, tree_disjoint_find_set(n6));
  EXPECT_EQ(1, n2->get_rank());
}

TEST(TreeDisjointSet, Union2)
{
  int i1 = 1;
  int i2 = 2;
  int i3 = 3;
  int i4 = 4;
  int i5 = 5;
  int i6 = 6;
  int i7 = 7;
  // 1
  auto n1 = std::make_shared<TreeDisjointSetNode<int>>(i1);
  tree_disjoint_make_set(n1);
  // 2
  auto n2 = std::make_shared<TreeDisjointSetNode<int>>(i2);
  tree_disjoint_make_set(n2);
  // 3
  auto n3 = std::make_shared<TreeDisjointSetNode<int>>(i3);
  tree_disjoint_make_set(n3);
  // 4
  auto n4 = std::make_shared<TreeDisjointSetNode<int>>(i4);
  tree_disjoint_make_set(n4);
  // 5
  auto n5 = std::make_shared<TreeDisjointSetNode<int>>(i5);
  tree_disjoint_make_set(n5);
  // 6
  auto n6 = std::make_shared<TreeDisjointSetNode<int>>(i6);
  tree_disjoint_make_set(n6);
  // 7
  auto n7 = std::make_shared<TreeDisjointSetNode<int>>(i7);
  tree_disjoint_make_set(n7);
  // 1st union
  tree_disjoint_union(n1, n2);
  // 2nd union
  tree_disjoint_union(n3, n4);
  // 3rd union
  tree_disjoint_union(n1, n3);
  EXPECT_EQ(n4, tree_disjoint_find_set(n3));
  EXPECT_EQ(2, n4->get_rank());
  // 4th union
  tree_disjoint_union(n5, n6);
  // 5th union
  tree_disjoint_union(n5, n7);
  // 6th union
  tree_disjoint_union(n2, n6);
  EXPECT_EQ(n4, tree_disjoint_find_set(n3));
  EXPECT_EQ(n4, tree_disjoint_find_set(n5));
  EXPECT_EQ(2, n4->get_rank());
}
