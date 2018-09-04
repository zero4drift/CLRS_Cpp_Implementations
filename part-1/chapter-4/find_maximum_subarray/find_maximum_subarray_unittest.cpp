#include <gtest/gtest.h>
#include "find_maximum_subarray.h"

TEST(FindMaximumSubarray, NormalArray)
{
  int array[] = {13, -3, -25, 20, -3, -16, -23, 18, 20,
		 -7, 12, -5, -22, 15, -4, 7};
  auto r = find_maximum_subarray(array, 0, 15);
  EXPECT_EQ(r.first.first, 7);
  EXPECT_EQ(r.first.second, 10);
  EXPECT_EQ(r.second, 43);
}
