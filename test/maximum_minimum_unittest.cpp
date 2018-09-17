#include <gtest/gtest.h>
#include "chapter-9/maximum_minimum/maximum_minimum.h"
#include "chapter-9/maximum_minimum/minimum.h"

TEST(Minimum, NormalArray)
{
  int a[8] = {1, 2, 3, 4, 5, 6, 7, 8}; 
  auto result = minimum(a);
  EXPECT_EQ(1, result);
}

TEST(MaximumMinimum, EvenArray)
{
  int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  auto result = maximum_minimum(a);
  EXPECT_EQ(8, result.first);
  EXPECT_EQ(1, result.second);
}

TEST(MaximumMinimum, OddArray)
{
  int a[7] = {1, 2, 3, 4, 5, 6, 7};
  auto result = maximum_minimum(a);
  EXPECT_EQ(7, result.first);
  EXPECT_EQ(1, result.second);
}
