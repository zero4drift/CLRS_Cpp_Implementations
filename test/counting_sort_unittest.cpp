#include <gtest/gtest.h>
#include "chapter-8/counting_sort/counting_sort.h"

TEST(CountingSort, NormalArray)
{
  unsigned a[8] = {2, 5, 3, 0, 2, 3, 0, 3};
  unsigned b[8];
  unsigned k = 5;
  counting_sort(a, b, k);
  EXPECT_EQ(0, b[0]);
  EXPECT_EQ(0, b[1]);
  EXPECT_EQ(2, b[2]);
  EXPECT_EQ(2, b[3]);
  EXPECT_EQ(3, b[4]);
  EXPECT_EQ(3, b[5]);
  EXPECT_EQ(3, b[6]);
  EXPECT_EQ(5, b[7]);
}
