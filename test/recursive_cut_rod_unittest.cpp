#include <gtest/gtest.h>
#include "chapter-15/cut_rod/recursive_cut_rod.hpp"

using namespace CLRS;

constexpr unsigned RECURSIVE_CUT_ROD_PRICES[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

TEST(RecursiveCutRod, 4)
{
  EXPECT_EQ(10, recursive_cut_rod(RECURSIVE_CUT_ROD_PRICES, 4));
}

TEST(RecursiveCutRod, 10)
{
  EXPECT_EQ(30, recursive_cut_rod(RECURSIVE_CUT_ROD_PRICES, 10));
}

TEST(RecursiveCutRod, 30)
{
  EXPECT_EQ(90, recursive_cut_rod(RECURSIVE_CUT_ROD_PRICES, 30));
}
