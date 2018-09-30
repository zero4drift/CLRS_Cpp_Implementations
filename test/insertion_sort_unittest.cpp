#include <gtest/gtest.h>
#include "chapter-2/insertion_sort/insertion_sort.h"

using namespace CLRS;

TEST(InsertionSort, HandleNormalArray1)
{
  int a[4] = {4, 3, 2, 1};
  insertion_sort(a);
  EXPECT_EQ(1, a[0]);
  EXPECT_EQ(2, a[1]);
  EXPECT_EQ(3, a[2]);
  EXPECT_EQ(4, a[3]);
}

TEST(InsertionSort, HandleNormalArray2)
{
  int a[4] = {1, 2, 3, 4};
  insertion_sort(a);
  EXPECT_EQ(1, a[0]);
  EXPECT_EQ(2, a[1]);
  EXPECT_EQ(3, a[2]);
  EXPECT_EQ(4, a[3]);
}

TEST(InsertionSort, HandleNormalArray3)
{
  int a[4] = {2, 4, 3, 1};
  insertion_sort(a);
  EXPECT_EQ(1, a[0]);
  EXPECT_EQ(2, a[1]);
  EXPECT_EQ(3, a[2]);
  EXPECT_EQ(4, a[3]);
}

TEST(InsertionSort, HandleOneElementArray)
{
  int a[1] = {4};
  insertion_sort(a);
  EXPECT_EQ(4, a[0]);
}

