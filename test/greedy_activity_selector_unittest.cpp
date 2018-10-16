#include <vector>
#include <gtest/gtest.h>
#include "chapter-16/greedy_activity_selector/greedy_activity_selector.h"


using namespace CLRS;

TEST(RecursiveGreedySelector, Normal)
{
  unsigned s[12] = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
  unsigned f[12] = {0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
  std::vector<unsigned> r;
  recursive_activity_selector(s, f, 0, 11, r);
  EXPECT_EQ(std::vector<unsigned>({1, 4, 8, 11}), r);
}

TEST(IterativeGreedySelector, Normal)
{
  unsigned s[12] = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
  unsigned f[12] = {0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
  EXPECT_EQ(std::vector<unsigned>({1, 4, 8, 11}),
	    greedy_activity_selector(s, f));
}

