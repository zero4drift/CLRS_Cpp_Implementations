#include <gtest/gtest.h>
#include <vector>
#include "max_heapify.h"

using std::vector;

TEST(MaxHeapIfy, IllegalArray1)
{
  int a[10] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
  max_heapify(a, 1);
  EXPECT_EQ(14, a[1]);
  EXPECT_EQ(8, a[3]);
  EXPECT_EQ(4, a[8]);
}

TEST(MaxHeapIfy, IllegalArray2)
{
  vector<int> a = {4, 16, 3, 2, 1, 9, 10, 14, 8, 7};
  max_heapify(a, 0);
  EXPECT_EQ(16, a[0]);
  EXPECT_EQ(4, a[1]);
  EXPECT_EQ(3, a[2]);
}

TEST(MaxHeapIfy, IllegalVector1)
{
  vector<int> a = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
  max_heapify(a, 1);
  EXPECT_EQ(14, a[1]);
  EXPECT_EQ(8, a[3]);
  EXPECT_EQ(4, a[8]);
}

TEST(MaxHeapIfy, IllegalVector2)
{
  int a[10] = {4, 16, 3, 2, 1, 9, 10, 14, 8, 7};
  max_heapify(a, 0);
  EXPECT_EQ(16, a[0]);
  EXPECT_EQ(4, a[1]);
  EXPECT_EQ(3, a[2]);
}
