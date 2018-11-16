#include <memory>
#include <gtest/gtest.h>
#include "chapter-21/linked_list_disjoint_set/linked_list_disjoint_set.h"

using namespace CLRS;

TEST(LinkedListDisjointSet, Initialization)
{
  int i1 = 1;
  auto n1 = std::make_shared<LinkedListDisjointSetNode<int>>(i1);
  EXPECT_EQ(i1, n1->get_key());
  EXPECT_EQ(nullptr, n1->get_next());
  EXPECT_EQ(nullptr, n1->get_set_p());
  auto s1 = linked_list_disjoint_make_set(n1);
  EXPECT_EQ(n1, s1->get_head());
  EXPECT_EQ(n1, s1->get_tail());
  EXPECT_EQ(1, s1->get_length());
}

TEST(LinkedListDisjointSet, MakeSets)
{
  int i1 = 1;
  int i2 = 2;
  int i3 = 3;
  int i4 = 4;
  int i5 = 5;
  int i6 = 6;
  // 1
  auto n1 = std::make_shared<LinkedListDisjointSetNode<int>>(i1);
  auto s1 = linked_list_disjoint_make_set(n1);
  EXPECT_EQ(n1, s1->get_head());
  EXPECT_EQ(n1, s1->get_tail());
  EXPECT_EQ(1, s1->get_length());
  // 2
  auto n2 = std::make_shared<LinkedListDisjointSetNode<int>>(i2);
  auto s2 = linked_list_disjoint_make_set(n2);
  EXPECT_EQ(n2, s2->get_head());
  EXPECT_EQ(n2, s2->get_tail());
  EXPECT_EQ(1, s2->get_length());
  // 3
  auto n3 = std::make_shared<LinkedListDisjointSetNode<int>>(i3);
  auto s3 = linked_list_disjoint_make_set(n3);
  EXPECT_EQ(n3, s3->get_head());
  EXPECT_EQ(n3, s3->get_tail());
  EXPECT_EQ(1, s3->get_length());
  // 4
  auto n4 = std::make_shared<LinkedListDisjointSetNode<int>>(i4);
  auto s4 = linked_list_disjoint_make_set(n4);
  EXPECT_EQ(n4, s4->get_head());
  EXPECT_EQ(n4, s4->get_tail());
  EXPECT_EQ(1, s4->get_length());
  // 5
  auto n5 = std::make_shared<LinkedListDisjointSetNode<int>>(i5);
  auto s5 = linked_list_disjoint_make_set(n5);
  EXPECT_EQ(n5, s5->get_head());
  EXPECT_EQ(n5, s5->get_tail());
  EXPECT_EQ(1, s5->get_length());
  // 6
  auto n6 = std::make_shared<LinkedListDisjointSetNode<int>>(i6);
  auto s6 = linked_list_disjoint_make_set(n6);
  EXPECT_EQ(n6, s6->get_head());
  EXPECT_EQ(n6, s6->get_tail());
  EXPECT_EQ(1, s6->get_length());
}

TEST(LinkedListDisjointSet, FindSet)
{
  int i1 = 1;
  int i2 = 2;
  int i3 = 3;
  int i4 = 4;
  int i5 = 5;
  int i6 = 6;
  // 1
  auto n1 = std::make_shared<LinkedListDisjointSetNode<int>>(i1);
  auto s1 = linked_list_disjoint_make_set(n1);
  EXPECT_EQ(1, linked_list_disjoint_find_set(n1));
  // 2
  auto n2 = std::make_shared<LinkedListDisjointSetNode<int>>(i2);
  auto s2 = linked_list_disjoint_make_set(n2);
  EXPECT_EQ(2, linked_list_disjoint_find_set(n2));
  // 3
  auto n3 = std::make_shared<LinkedListDisjointSetNode<int>>(i3);
  auto s3 = linked_list_disjoint_make_set(n3);
  EXPECT_EQ(3, linked_list_disjoint_find_set(n3));
  // 4
  auto n4 = std::make_shared<LinkedListDisjointSetNode<int>>(i4);
  auto s4 = linked_list_disjoint_make_set(n4);
  EXPECT_EQ(4, linked_list_disjoint_find_set(n4));
  // 5
  auto n5 = std::make_shared<LinkedListDisjointSetNode<int>>(i5);
  auto s5 = linked_list_disjoint_make_set(n5);
  EXPECT_EQ(5, linked_list_disjoint_find_set(n5));
  // 6
  auto n6 = std::make_shared<LinkedListDisjointSetNode<int>>(i6);
  auto s6 = linked_list_disjoint_make_set(n6);
  EXPECT_EQ(6, linked_list_disjoint_find_set(n6));
}

TEST(LinkedListDisjointSet, Union1)
{
  int i1 = 1;
  int i2 = 2;
  int i3 = 3;
  int i4 = 4;
  int i5 = 5;
  int i6 = 6;
  // 1
  auto n1 = std::make_shared<LinkedListDisjointSetNode<int>>(i1);
  auto s1 = linked_list_disjoint_make_set(n1);
  // 2
  auto n2 = std::make_shared<LinkedListDisjointSetNode<int>>(i2);
  auto s2 = linked_list_disjoint_make_set(n2);
  // 3
  auto n3 = std::make_shared<LinkedListDisjointSetNode<int>>(i3);
  auto s3 = linked_list_disjoint_make_set(n3);
  // 4
  auto n4 = std::make_shared<LinkedListDisjointSetNode<int>>(i4);
  auto s4 = linked_list_disjoint_make_set(n4);
  // 5
  auto n5 = std::make_shared<LinkedListDisjointSetNode<int>>(i5);
  auto s5 = linked_list_disjoint_make_set(n5);
  // 6
  auto n6 = std::make_shared<LinkedListDisjointSetNode<int>>(i6);
  auto s6 = linked_list_disjoint_make_set(n6);
  // 1st union
  linked_list_disjoint_union(n1, n2);
  EXPECT_EQ(2, n1->get_set_p()->get_length());
  EXPECT_EQ(2, linked_list_disjoint_find_set(n1));
  // 2nd union
  linked_list_disjoint_union(n1, n3);
  EXPECT_EQ(3, n3->get_set_p()->get_length());
  EXPECT_EQ(2, linked_list_disjoint_find_set(n3));
  // 3rd union
  linked_list_disjoint_union(n3, n4);
  EXPECT_EQ(4, n4->get_set_p()->get_length());
  EXPECT_EQ(2, linked_list_disjoint_find_set(n4));
  // 4th union
  linked_list_disjoint_union(n4, n5);
  EXPECT_EQ(5, n5->get_set_p()->get_length());
  EXPECT_EQ(2, linked_list_disjoint_find_set(n5));
  // 5th union
  linked_list_disjoint_union(n5, n6);
  EXPECT_EQ(6, n6->get_set_p()->get_length());
  EXPECT_EQ(2, linked_list_disjoint_find_set(n6));
}

TEST(LinkedListDisjointSet, Union2)
{
  int i1 = 1;
  int i2 = 2;
  int i3 = 3;
  int i4 = 4;
  int i5 = 5;
  int i6 = 6;
  int i7 = 7;
  // 1
  auto n1 = std::make_shared<LinkedListDisjointSetNode<int>>(i1);
  auto s1 = linked_list_disjoint_make_set(n1);
  // 2
  auto n2 = std::make_shared<LinkedListDisjointSetNode<int>>(i2);
  auto s2 = linked_list_disjoint_make_set(n2);
  // 3
  auto n3 = std::make_shared<LinkedListDisjointSetNode<int>>(i3);
  auto s3 = linked_list_disjoint_make_set(n3);
  // 4
  auto n4 = std::make_shared<LinkedListDisjointSetNode<int>>(i4);
  auto s4 = linked_list_disjoint_make_set(n4);
  // 5
  auto n5 = std::make_shared<LinkedListDisjointSetNode<int>>(i5);
  auto s5 = linked_list_disjoint_make_set(n5);
  // 6
  auto n6 = std::make_shared<LinkedListDisjointSetNode<int>>(i6);
  auto s6 = linked_list_disjoint_make_set(n6);
  // 7
  auto n7 = std::make_shared<LinkedListDisjointSetNode<int>>(i7);
  auto s7 = linked_list_disjoint_make_set(n7);
  // 1st union
  linked_list_disjoint_union(n1, n2);
  // 2nd union
  linked_list_disjoint_union(n3, n4);
  // 3rd union
  linked_list_disjoint_union(n1, n3);
  EXPECT_EQ(4, n4->get_set_p()->get_length());
  EXPECT_EQ(4, linked_list_disjoint_find_set(n4));
  // 4th union
  linked_list_disjoint_union(n5, n6);
  // 5th union
  linked_list_disjoint_union(n5, n7);
  // 6th union
  linked_list_disjoint_union(n2, n6);
  EXPECT_EQ(7, n4->get_set_p()->get_length());
  EXPECT_EQ(4, linked_list_disjoint_find_set(n4));
}
