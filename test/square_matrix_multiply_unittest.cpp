#include <gtest/gtest.h>
#include "../include/chapter-4/square_matrix_multiply/square_matrix_multiply.h"

TEST(SquareMatrixMultiply, NormalMatrix)
{
  int a[2][2] = {{1, 2}, {3, 4}};
  int b[2][2] = {{5, 6}, {7, 8}};
  int c[2][2];
  square_matrix_multiply(a, b, c);
  EXPECT_EQ(c[0][0], 19);
}
