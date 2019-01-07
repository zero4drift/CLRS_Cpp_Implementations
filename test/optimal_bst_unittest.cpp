#include <utility>
#include <gtest/gtest.h>
#include "chapter-15/optimal_binary_search_tree/optimal_bst.hpp"

using namespace CLRS;

TEST(OptimalBST, Normal)
{
  double p[6] = {0, 0.15, 0.10, 0.05, 0.10, 0.20};
  double q[6] = {0.05, 0.10, 0.05, 0.05, 0.05, 0.10};
  double e[7][6];
  std::size_t root[6][6];
  optimal_bst(p, q, e, root);
  EXPECT_EQ(e[1][5], 2.75);
  EXPECT_EQ(root[1][5], 2);
}
