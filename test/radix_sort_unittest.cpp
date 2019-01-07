#include <gtest/gtest.h>
#include "chapter-8/radix_sort/radix_sort.hpp"

using namespace CLRS;

TEST(RadixDigit, OneDigit)
{
  int i = 8;
  EXPECT_EQ(8, radix_digit(i, 1));
}

TEST(RadixDigit, TwoDigits)
{
  int i = 15;
  EXPECT_EQ(5, radix_digit(i, 1));
  EXPECT_EQ(1, radix_digit(i, 2));
}

TEST(RadixDigit, ThreeDigits)
{
  int i = 137;
  EXPECT_EQ(7, radix_digit(i, 1));
  EXPECT_EQ(3, radix_digit(i, 2));
  EXPECT_EQ(1, radix_digit(i, 3));
}

TEST(RadixCountingSort, NormalArray)
{
  int a[7] = {329, 457, 657, 839, 436, 720, 355};
  int b[7];
  radix_counting_sort(a, b, 1);
  EXPECT_EQ(720, b[0]);
  EXPECT_EQ(355, b[1]);
  EXPECT_EQ(436, b[2]);
  EXPECT_EQ(457, b[3]);
  EXPECT_EQ(657, b[4]);
  EXPECT_EQ(329, b[5]);
  EXPECT_EQ(839, b[6]);
  radix_counting_sort(b, a, 2);
  radix_counting_sort(a, b, 3);
  EXPECT_EQ(329, b[0]);
  EXPECT_EQ(355, b[1]);
  EXPECT_EQ(436, b[2]);
  EXPECT_EQ(457, b[3]);
  EXPECT_EQ(657, b[4]);
  EXPECT_EQ(720, b[5]);
  EXPECT_EQ(839, b[6]);
}

TEST(RadixSort, NormalArray)
{
  int a[7] = {329, 457, 657, 839, 436, 720, 355};
  radix_sort(a, 3);
  EXPECT_EQ(329, a[0]);
  EXPECT_EQ(355, a[1]);
  EXPECT_EQ(436, a[2]);
  EXPECT_EQ(457, a[3]);
  EXPECT_EQ(657, a[4]);
  EXPECT_EQ(720, a[5]);
  EXPECT_EQ(839, a[6]);
}
