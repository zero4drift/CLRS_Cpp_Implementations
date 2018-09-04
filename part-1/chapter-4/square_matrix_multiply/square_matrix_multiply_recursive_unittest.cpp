#include <gtest/gtest.h>
#include "square_matrix_multiply_recursive.h"

TEST(SquareMatrixMultiply, NormalMatrix)
{
  int a[2][2] = {{1, 2}, {3, 4}};
  int b[2][2] = {{5, 6}, {7, 8}};
  int c[2][2];
  square_matrix_multiply_recursive(a, b, c);
  EXPECT_EQ(c[0][0], 19);
}
