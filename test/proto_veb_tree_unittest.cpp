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
  EXPECT_EQ(2, (*pvebt.get_cluster()[0]).get_n());
}
