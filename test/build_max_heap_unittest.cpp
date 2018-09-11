#include <gtest/gtest.h>
#include "chapter-6/build_max_heap/build_max_heap.h"

TEST(BuildMaxHeap, UnsortedArray)
{
  int a[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
  build_max_heap(a);
  EXPECT_EQ(16, a[0]);
  EXPECT_EQ(14, a[1]);
  EXPECT_EQ(10, a[2]);
  EXPECT_EQ(8, a[3]);
  EXPECT_EQ(7, a[4]);
  EXPECT_EQ(9, a[5]);
  EXPECT_EQ(3, a[6]);
  EXPECT_EQ(2, a[7]);
  EXPECT_EQ(4, a[8]);
  EXPECT_EQ(1, a[9]);
}
