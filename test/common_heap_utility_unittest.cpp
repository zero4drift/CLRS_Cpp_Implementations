#include <gtest/gtest.h>
#include "chapter-6/common_heap_utility.h"

using namespace CLRS;

TEST(CommonUtilityParent, BelowRoot)
{
  EXPECT_EQ(0, parent(1));
  EXPECT_EQ(0, parent(2));
}

TEST(CommonUtilityParent, Normal)
{
  EXPECT_EQ(1, parent(3));
  EXPECT_EQ(1, parent(4));
  EXPECT_EQ(2, parent(5));
  EXPECT_EQ(2, parent(6));
}

TEST(CommonUtilityLeftRight, Root)
{
  EXPECT_EQ(1, left(0));
  EXPECT_EQ(2, right(0));
}

TEST(CommonUtilityLeftRight, Normal)
{
  EXPECT_EQ(3, left(1));
  EXPECT_EQ(4, right(1));
  EXPECT_EQ(5, left(2));
  EXPECT_EQ(6, right(2));
}
