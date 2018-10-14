#include <gtest/gtest.h>
#include "chapter-15/matrix_chain_order/matrix_chain_order.h"

using namespace CLRS;

TEST(BottomUPMatrixChainOrder, 6)
{
  unsigned p[7] = {30, 35, 15, 5, 10, 20, 25};
  unsigned m[7][7];
  std::size_t s[7][7];
  matrix_chain_order(p, m, s);
  EXPECT_EQ(7125, m[2][5]);
  EXPECT_EQ(15125, m[1][6]);
}

TEST(MemoizedMatrixChainOrder, 6)
{
  unsigned p[7] = {30, 35, 15, 5, 10, 20, 25};
  EXPECT_EQ(15125, memoized_matrix_chain(p));
}
