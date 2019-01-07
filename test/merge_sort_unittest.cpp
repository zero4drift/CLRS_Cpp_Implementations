#include <gtest/gtest.h>
#include "chapter-2/merge_sort/merge_sort.hpp"

using namespace CLRS;

TEST(MergeSort, HandleEvenArray1)
{
  int a[4] = {4, 3, 2, 1};
  merge_sort(a, 0, 3);
  EXPECT_EQ(1, a[0]);
  EXPECT_EQ(2, a[1]);
  EXPECT_EQ(3, a[2]);
  EXPECT_EQ(4, a[3]);
}

TEST(MergeSort, HandleEvenArray2)
{
  int a[4] = {1, 2, 3, 4};
  merge_sort(a, 0, 3);
  EXPECT_EQ(1, a[0]);
  EXPECT_EQ(2, a[1]);
  EXPECT_EQ(3, a[2]);
  EXPECT_EQ(4, a[3]);
}

TEST(MergeSort, HandleEvenArray3)
{
  int a[4] = {2, 4, 3, 1};
  merge_sort(a, 0, 3);
  EXPECT_EQ(1, a[0]);
  EXPECT_EQ(2, a[1]);
  EXPECT_EQ(3, a[2]);
  EXPECT_EQ(4, a[3]);
}

TEST(MergeSort, HandleOddArray1)
{
  int a[5] = {4, 3, 2, 1, 0};
  merge_sort(a, 0, 4);
  EXPECT_EQ(0, a[0]);
  EXPECT_EQ(1, a[1]);
  EXPECT_EQ(2, a[2]);
  EXPECT_EQ(3, a[3]);
  EXPECT_EQ(4, a[4]);
}

TEST(MergeSort, HandleOddArray2)
{
  int a[5] = {0, 1, 2, 3, 4};
  merge_sort(a, 0, 4);
  EXPECT_EQ(0, a[0]);
  EXPECT_EQ(1, a[1]);
  EXPECT_EQ(2, a[2]);
  EXPECT_EQ(3, a[3]);
  EXPECT_EQ(4, a[4]);
}

TEST(MergeSort, HandleOddArray3)
{
  int a[5] = {2, 4, 0, 3, 1};
  merge_sort(a, 0, 4);
  EXPECT_EQ(0, a[0]);
  EXPECT_EQ(1, a[1]);
  EXPECT_EQ(2, a[2]);
  EXPECT_EQ(3, a[3]);
  EXPECT_EQ(4, a[4]);

}

TEST(MergeSort, HandleOneElementArray)
{
  int a[1] = {4};
  merge_sort(a, 0, 0);
  EXPECT_EQ(4, a[0]);
}

