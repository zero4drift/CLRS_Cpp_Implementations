#include <gtest/gtest.h>
#include "chapter-7/randomized_quicksort/randomized_quicksort.h"

using namespace CLRS;

TEST(RandomizedQuickSort, NormalArray)
{
  int a[8] = {2, 8, 7, 1, 3, 5, 6, 4};
  randomized_quicksort(a, 0, 7);
  EXPECT_EQ(1, a[0]);
  EXPECT_EQ(2, a[1]);
  EXPECT_EQ(3, a[2]);
  EXPECT_EQ(4, a[3]);
  EXPECT_EQ(5, a[4]);
  EXPECT_EQ(6, a[5]);
  EXPECT_EQ(7, a[6]);
  EXPECT_EQ(8, a[7]);
}
