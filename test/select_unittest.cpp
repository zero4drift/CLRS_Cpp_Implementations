#include <gtest/gtest.h>
#include "chapter-9/select/select.h"

TEST(Select, OrderedArray)
{
  int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  EXPECT_EQ(1, select(a, 0, 7, 1));
  EXPECT_EQ(2, select(a, 0, 7, 2));
  EXPECT_EQ(3, select(a, 0, 7, 3));
  EXPECT_EQ(4, select(a, 0, 7, 4));
  EXPECT_EQ(5, select(a, 0, 7, 5));
  EXPECT_EQ(6, select(a, 0, 7, 6));
  EXPECT_EQ(7, select(a, 0, 7, 7));
  EXPECT_EQ(8, select(a, 0, 7, 8));
}

TEST(Select, UnOrderedArray)
{
  int a[8] = {2, 5, 4, 8, 7, 3, 6, 1};
  EXPECT_EQ(1, select(a, 0, 7, 1));
  EXPECT_EQ(2, select(a, 0, 7, 2));
  EXPECT_EQ(3, select(a, 0, 7, 3));
  EXPECT_EQ(4, select(a, 0, 7, 4));
  EXPECT_EQ(5, select(a, 0, 7, 5));
  EXPECT_EQ(6, select(a, 0, 7, 6));
  EXPECT_EQ(7, select(a, 0, 7, 7));
  EXPECT_EQ(8, select(a, 0, 7, 8));
}
