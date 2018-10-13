#include <gtest/gtest.h>
#include "chapter-15/cut_rod/dynamic_programming_cut_rod.h"

using namespace CLRS;

constexpr unsigned PRICES[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

TEST(MemoizedCutRod, 4)
{
  EXPECT_EQ(10, memoized_cut_rod(PRICES, 4));
}

TEST(MemoizedCutRod, 10)
{
  EXPECT_EQ(30, memoized_cut_rod(PRICES, 10));
}

TEST(MemoizedCutRod, 30)
{
  EXPECT_EQ(90, memoized_cut_rod(PRICES, 30));
}

TEST(MemoizedCutRod, 40)
{
  EXPECT_EQ(120, memoized_cut_rod(PRICES, 40));
}

TEST(BottomUpCutRod, 4)
{
  EXPECT_EQ(10, bottom_up_cut_rod(PRICES, 4));
}

TEST(BottomUpCutRod, 10)
{
  EXPECT_EQ(30, bottom_up_cut_rod(PRICES, 10));
}

TEST(BottomUpCutRod, 30)
{
  EXPECT_EQ(90, bottom_up_cut_rod(PRICES, 30));
}

TEST(BottomUpCutRod, 40)
{
  EXPECT_EQ(120, bottom_up_cut_rod(PRICES, 40));
}

TEST(ExtendedBottomUpCutRod, 7)
{
  unsigned r[8];
  std::size_t s[8];
  extended_bottom_up_cut_rod(PRICES, 7, r, s);
  EXPECT_EQ(1, s[7]);
  EXPECT_EQ(6, s[6]);
}
