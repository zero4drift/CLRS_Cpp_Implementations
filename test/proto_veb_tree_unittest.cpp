#include <gtest/gtest.h>
#include "chapter-20/veb_tree_utilities.h"
#include "chapter-20/proto_veb_tree/proto_veb_tree.h"

using namespace CLRS;

TEST(ProtovEBTree, Utilities1)
{
  unsigned u = 16;
  unsigned x = 5;
  unsigned high = veb_high(x, u);
  unsigned low = veb_low(x, u);
  unsigned i = veb_index(high, low, u);
  EXPECT_EQ(1, high);
  EXPECT_EQ(1, low);
  EXPECT_EQ(5, i);
}

TEST(ProtovEBTree, Utilities2)
{
  unsigned u = 256;
  unsigned x = 123;
  unsigned high = veb_high(x, u);
  unsigned low = veb_low(x, u);
  unsigned i = veb_index(high, low, u);
  EXPECT_EQ(7, high);
  EXPECT_EQ(11, low);
  EXPECT_EQ(123, i);
}

TEST(ProtovEBTree, Create)
{
  unsigned u = 16;
  auto pvebt = ProtovEBTree(u);
}

TEST(ProtovEBTree, Insert)
{
  unsigned u = 16;
  auto pvebt = ProtovEBTree(u);
  proto_veb_insert(pvebt, 2);
  proto_veb_insert(pvebt, 3);
  proto_veb_insert(pvebt, 4);
  proto_veb_insert(pvebt, 5);
  proto_veb_insert(pvebt, 7);
  proto_veb_insert(pvebt, 14);
  proto_veb_insert(pvebt, 15);
  EXPECT_EQ(7, pvebt.get_n());
  auto &summary = *pvebt.get_summary();
  EXPECT_EQ(3, summary.get_n());
  auto &cluster0 = *pvebt.get_cluster()[0];
  EXPECT_EQ(2, cluster0.get_n());
  auto &cluster1 = *pvebt.get_cluster()[1];
  EXPECT_EQ(3, cluster1.get_n());
  auto &cluster2 = *pvebt.get_cluster()[2];
  EXPECT_EQ(0, cluster2.get_n());
  auto &cluster3 = *pvebt.get_cluster()[3];
  EXPECT_EQ(2, cluster3.get_n());
  // deeper layer
  auto &s_summary = *summary.get_summary();
  EXPECT_EQ(2, s_summary.get_n());
  auto &s_cluster0 = *summary.get_cluster()[0];
  EXPECT_EQ(2, s_cluster0.get_n());
  auto &s_cluster1 = *summary.get_cluster()[1];
  EXPECT_EQ(1, s_cluster1.get_n());
  auto &c0_summary = *cluster0.get_summary();
  EXPECT_EQ(1, c0_summary.get_n());
  auto &c0_cluster0 = *cluster0.get_cluster()[0];
  EXPECT_EQ(0, c0_cluster0.get_n());
  auto &c0_cluster1 = *cluster0.get_cluster()[1];
  EXPECT_EQ(2, c0_cluster1.get_n());
  auto &c1_summary = *cluster1.get_summary();
  EXPECT_EQ(2, c1_summary.get_n());
  auto &c1_cluster0 = *cluster1.get_cluster()[0];
  EXPECT_EQ(2, c1_cluster0.get_n());
  auto &c1_cluster1 = *cluster1.get_cluster()[1];
  EXPECT_EQ(1, c1_cluster1.get_n());
  auto &c2_summary = *cluster2.get_summary();
  EXPECT_EQ(0, c2_summary.get_n());
  auto &c2_cluster0 = *cluster2.get_cluster()[0];
  EXPECT_EQ(0, c2_cluster0.get_n());
  auto &c2_cluster1 = *cluster2.get_cluster()[1];
  EXPECT_EQ(0, c2_cluster1.get_n());
  auto &c3_summary = *cluster3.get_summary();
  EXPECT_EQ(1, c3_summary.get_n());
  auto &c3_cluster0 = *cluster3.get_cluster()[0];
  EXPECT_EQ(0, c3_cluster0.get_n());
  auto &c3_cluster1 = *cluster3.get_cluster()[1];
  EXPECT_EQ(2, c3_cluster1.get_n());
}

TEST(ProtovEBTree, RepeatInsert)
{
  unsigned u = 16;
  auto pvebt = ProtovEBTree(u);
  proto_veb_insert(pvebt, 2);
  proto_veb_insert(pvebt, 3);
  proto_veb_insert(pvebt, 4);
  proto_veb_insert(pvebt, 5);
  proto_veb_insert(pvebt, 7);
  proto_veb_insert(pvebt, 14);
  proto_veb_insert(pvebt, 15);
  // repeat last operation insert
  proto_veb_insert(pvebt, 15);
  EXPECT_EQ(7, pvebt.get_n());
  auto &summary = *pvebt.get_summary();
  EXPECT_EQ(3, summary.get_n());
  auto &cluster0 = *pvebt.get_cluster()[0];
  EXPECT_EQ(2, cluster0.get_n());
  auto &cluster1 = *pvebt.get_cluster()[1];
  EXPECT_EQ(3, cluster1.get_n());
  auto &cluster2 = *pvebt.get_cluster()[2];
  EXPECT_EQ(0, cluster2.get_n());
  auto &cluster3 = *pvebt.get_cluster()[3];
  EXPECT_EQ(2, cluster3.get_n());
  // deeper layer
  auto &s_summary = *summary.get_summary();
  EXPECT_EQ(2, s_summary.get_n());
  auto &s_cluster0 = *summary.get_cluster()[0];
  EXPECT_EQ(2, s_cluster0.get_n());
  auto &s_cluster1 = *summary.get_cluster()[1];
  EXPECT_EQ(1, s_cluster1.get_n());
  auto &c0_summary = *cluster0.get_summary();
  EXPECT_EQ(1, c0_summary.get_n());
  auto &c0_cluster0 = *cluster0.get_cluster()[0];
  EXPECT_EQ(0, c0_cluster0.get_n());
  auto &c0_cluster1 = *cluster0.get_cluster()[1];
  EXPECT_EQ(2, c0_cluster1.get_n());
  auto &c1_summary = *cluster1.get_summary();
  EXPECT_EQ(2, c1_summary.get_n());
  auto &c1_cluster0 = *cluster1.get_cluster()[0];
  EXPECT_EQ(2, c1_cluster0.get_n());
  auto &c1_cluster1 = *cluster1.get_cluster()[1];
  EXPECT_EQ(1, c1_cluster1.get_n());
  auto &c2_summary = *cluster2.get_summary();
  EXPECT_EQ(0, c2_summary.get_n());
  auto &c2_cluster0 = *cluster2.get_cluster()[0];
  EXPECT_EQ(0, c2_cluster0.get_n());
  auto &c2_cluster1 = *cluster2.get_cluster()[1];
  EXPECT_EQ(0, c2_cluster1.get_n());
  auto &c3_summary = *cluster3.get_summary();
  EXPECT_EQ(1, c3_summary.get_n());
  auto &c3_cluster0 = *cluster3.get_cluster()[0];
  EXPECT_EQ(0, c3_cluster0.get_n());
  auto &c3_cluster1 = *cluster3.get_cluster()[1];
  EXPECT_EQ(2, c3_cluster1.get_n());
}

TEST(ProtovEBTree, Member)
{
  unsigned u = 16;
  auto pvebt = ProtovEBTree(u);
  proto_veb_insert(pvebt, 2);
  proto_veb_insert(pvebt, 3);
  proto_veb_insert(pvebt, 4);
  proto_veb_insert(pvebt, 5);
  proto_veb_insert(pvebt, 7);
  proto_veb_insert(pvebt, 14);
  proto_veb_insert(pvebt, 15);
  EXPECT_TRUE(proto_veb_member(pvebt, 2));
  EXPECT_TRUE(proto_veb_member(pvebt, 3));
  EXPECT_TRUE(proto_veb_member(pvebt, 4));
  EXPECT_TRUE(proto_veb_member(pvebt, 5));
  EXPECT_TRUE(proto_veb_member(pvebt, 7));
  EXPECT_TRUE(proto_veb_member(pvebt, 14));
  EXPECT_TRUE(proto_veb_member(pvebt, 15));
  // does not exist
  EXPECT_FALSE(proto_veb_member(pvebt, 8));
}

TEST(ProtovEBTree, MaximumMinimum)
{
  unsigned u = 16;
  auto pvebt = ProtovEBTree(u);
  proto_veb_insert(pvebt, 2);
  proto_veb_insert(pvebt, 3);
  proto_veb_insert(pvebt, 4);
  proto_veb_insert(pvebt, 5);
  proto_veb_insert(pvebt, 7);
  proto_veb_insert(pvebt, 14);
  proto_veb_insert(pvebt, 15);
  EXPECT_EQ(2, proto_veb_minimum(pvebt));
  EXPECT_EQ(15, proto_veb_maximum(pvebt));
}

TEST(ProtovEBTree, EmptyTreeMaximumMinimum)
{
  unsigned u = 16;
  auto pvebt = ProtovEBTree(u);
  EXPECT_EQ(16, proto_veb_minimum(pvebt));
  EXPECT_EQ(16, proto_veb_maximum(pvebt));
}

TEST(ProtovEBTree, SuccessorPredecessor)
{
  unsigned u = 16;
  auto pvebt = ProtovEBTree(u);
  proto_veb_insert(pvebt, 2);
  proto_veb_insert(pvebt, 3);
  proto_veb_insert(pvebt, 4);
  proto_veb_insert(pvebt, 5);
  proto_veb_insert(pvebt, 7);
  proto_veb_insert(pvebt, 14);
  proto_veb_insert(pvebt, 15);
  // successor
  EXPECT_EQ(3, proto_veb_successor(pvebt, 2));
  EXPECT_EQ(4, proto_veb_successor(pvebt, 3));
  EXPECT_EQ(5, proto_veb_successor(pvebt, 4));
  EXPECT_EQ(7, proto_veb_successor(pvebt, 5));
  EXPECT_EQ(14, proto_veb_successor(pvebt, 7));
  EXPECT_EQ(15, proto_veb_successor(pvebt, 14));
  // successor of which does not belong to this tree
  EXPECT_EQ(14, proto_veb_successor(pvebt, 8));
  // predecessor
  EXPECT_EQ(14, proto_veb_predecessor(pvebt, 15));
  EXPECT_EQ(7, proto_veb_predecessor(pvebt, 14));
  EXPECT_EQ(5, proto_veb_predecessor(pvebt, 7));
  EXPECT_EQ(4, proto_veb_predecessor(pvebt, 5));
  EXPECT_EQ(3, proto_veb_predecessor(pvebt, 4));
  EXPECT_EQ(2, proto_veb_predecessor(pvebt, 3));
  // predecessor of which does not belong to this tree
  EXPECT_EQ(7, proto_veb_predecessor(pvebt, 8));
}

TEST(ProtovEBTree, EmptyTreeSuccessorPredecessor)
{
  unsigned u = 16;
  auto pvebt = ProtovEBTree(u);
  EXPECT_EQ(16, proto_veb_successor(pvebt, 2));
  EXPECT_EQ(16, proto_veb_predecessor(pvebt, 2));
}

TEST(ProtovEBTree, Delete)
{
  unsigned u = 16;
  auto pvebt = ProtovEBTree(u);
  proto_veb_insert(pvebt, 2);
  proto_veb_insert(pvebt, 3);
  proto_veb_insert(pvebt, 4);
  proto_veb_insert(pvebt, 5);
  proto_veb_insert(pvebt, 7);
  // a slight difference: add 8
  proto_veb_insert(pvebt, 8);
  proto_veb_insert(pvebt, 14);
  proto_veb_insert(pvebt, 15);
  EXPECT_EQ(8, pvebt.get_n());
  auto &summary = *pvebt.get_summary();
  EXPECT_EQ(4, summary.get_n());
  auto &cluster0 = *pvebt.get_cluster()[0];
  EXPECT_EQ(2, cluster0.get_n());
  auto &cluster1 = *pvebt.get_cluster()[1];
  EXPECT_EQ(3, cluster1.get_n());
  auto &cluster2 = *pvebt.get_cluster()[2];
  EXPECT_EQ(1, cluster2.get_n());
  auto &cluster3 = *pvebt.get_cluster()[3];
  EXPECT_EQ(2, cluster3.get_n());
  // deeper layer
  auto &s_summary = *summary.get_summary();
  EXPECT_EQ(2, s_summary.get_n());
  auto &s_cluster0 = *summary.get_cluster()[0];
  EXPECT_EQ(2, s_cluster0.get_n());
  auto &s_cluster1 = *summary.get_cluster()[1];
  EXPECT_EQ(2, s_cluster1.get_n());
  auto &c0_summary = *cluster0.get_summary();
  EXPECT_EQ(1, c0_summary.get_n());
  auto &c0_cluster0 = *cluster0.get_cluster()[0];
  EXPECT_EQ(0, c0_cluster0.get_n());
  auto &c0_cluster1 = *cluster0.get_cluster()[1];
  EXPECT_EQ(2, c0_cluster1.get_n());
  auto &c1_summary = *cluster1.get_summary();
  EXPECT_EQ(2, c1_summary.get_n());
  auto &c1_cluster0 = *cluster1.get_cluster()[0];
  EXPECT_EQ(2, c1_cluster0.get_n());
  auto &c1_cluster1 = *cluster1.get_cluster()[1];
  EXPECT_EQ(1, c1_cluster1.get_n());
  auto &c2_summary = *cluster2.get_summary();
  EXPECT_EQ(1, c2_summary.get_n());
  auto &c2_cluster0 = *cluster2.get_cluster()[0];
  EXPECT_EQ(1, c2_cluster0.get_n());
  auto &c2_cluster1 = *cluster2.get_cluster()[1];
  EXPECT_EQ(0, c2_cluster1.get_n());
  auto &c3_summary = *cluster3.get_summary();
  EXPECT_EQ(1, c3_summary.get_n());
  auto &c3_cluster0 = *cluster3.get_cluster()[0];
  EXPECT_EQ(0, c3_cluster0.get_n());
  auto &c3_cluster1 = *cluster3.get_cluster()[1];
  EXPECT_EQ(2, c3_cluster1.get_n());
  // now delete 2
  proto_veb_delete(pvebt, 2);
  EXPECT_EQ(7, pvebt.get_n());
  EXPECT_EQ(4, summary.get_n());
  EXPECT_EQ(1, cluster0.get_n());
  EXPECT_EQ(3, cluster1.get_n());
  EXPECT_EQ(1, cluster2.get_n());
  EXPECT_EQ(2, cluster3.get_n());
  // deeper layer
  EXPECT_EQ(2, s_summary.get_n());
  EXPECT_EQ(2, s_cluster0.get_n());
  EXPECT_EQ(2, s_cluster1.get_n());
  EXPECT_EQ(1, c0_summary.get_n());
  EXPECT_EQ(0, c0_cluster0.get_n());
  EXPECT_EQ(1, c0_cluster1.get_n());
  EXPECT_EQ(2, c1_summary.get_n());
  EXPECT_EQ(2, c1_cluster0.get_n());
  EXPECT_EQ(1, c1_cluster1.get_n());
  EXPECT_EQ(1, c2_summary.get_n());
  EXPECT_EQ(1, c2_cluster0.get_n());
  EXPECT_EQ(0, c2_cluster1.get_n());
  EXPECT_EQ(1, c3_summary.get_n());
  EXPECT_EQ(0, c3_cluster0.get_n());
  EXPECT_EQ(2, c3_cluster1.get_n());
  // member ?
  EXPECT_FALSE(proto_veb_member(pvebt, 2));
  // now delete 8
  proto_veb_delete(pvebt, 8);
  EXPECT_EQ(6, pvebt.get_n());
  EXPECT_EQ(3, summary.get_n());
  EXPECT_EQ(1, cluster0.get_n());
  EXPECT_EQ(3, cluster1.get_n());
  EXPECT_EQ(0, cluster2.get_n());
  EXPECT_EQ(2, cluster3.get_n());
  // deeper layer
  EXPECT_EQ(2, s_summary.get_n());
  EXPECT_EQ(2, s_cluster0.get_n());
  EXPECT_EQ(1, s_cluster1.get_n());
  EXPECT_EQ(1, c0_summary.get_n());
  EXPECT_EQ(0, c0_cluster0.get_n());
  EXPECT_EQ(1, c0_cluster1.get_n());
  EXPECT_EQ(2, c1_summary.get_n());
  EXPECT_EQ(2, c1_cluster0.get_n());
  EXPECT_EQ(1, c1_cluster1.get_n());
  EXPECT_EQ(0, c2_summary.get_n());
  EXPECT_EQ(0, c2_cluster0.get_n());
  EXPECT_EQ(0, c2_cluster1.get_n());
  EXPECT_EQ(1, c3_summary.get_n());
  EXPECT_EQ(0, c3_cluster0.get_n());
  EXPECT_EQ(2, c3_cluster1.get_n());
  // member ?
  EXPECT_FALSE(proto_veb_member(pvebt, 8));
}

TEST(ProtovEBTree, EmptyDelete)
{
  unsigned u = 16;
  auto pvebt = ProtovEBTree(u);
  proto_veb_delete(pvebt, 2);
  EXPECT_EQ(0, pvebt.get_n());
}
