#include <gtest/gtest.h>
#include "chapter-15/lcs/lcs.h"

using namespace CLRS;

TEST(Lcs, CharArray)
{
  char x[7] = {'a', 'b', 'c', 'b', 'd', 'a', 'b'};
  char y[6] = {'b', 'd', 'c', 'a', 'b', 'a'};
  char b[8][7], c[8][7];
  lcs_length(x, y, b, c);
  EXPECT_EQ(c[7][6], 4);
  // print_lcs(b, x, 7, 6);
}
