#include <gtest/gtest.h>
#include "insertion_sort.h"

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

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
