#include <gtest/gtest.h>
#include "chapter-9/randomized_select/randomized_select.h"

TEST(RandomizedSelect, NormalArray)
{
  int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  EXPECT_EQ(1, randomized_select(a, 0, 7, 1));
  EXPECT_EQ(2, randomized_select(a, 0, 7, 2));
  EXPECT_EQ(3, randomized_select(a, 0, 7, 3));
  EXPECT_EQ(4, randomized_select(a, 0, 7, 4));
  EXPECT_EQ(5, randomized_select(a, 0, 7, 5));
  EXPECT_EQ(6, randomized_select(a, 0, 7, 6));
  EXPECT_EQ(7, randomized_select(a, 0, 7, 7));
  EXPECT_EQ(8, randomized_select(a, 0, 7, 8));
}
