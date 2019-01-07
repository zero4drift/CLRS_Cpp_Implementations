#include <gtest/gtest.h>
#include "chapter-4/square_matrix_multiply/square_matrix_multiply_strassen_recursive.hpp"

using namespace CLRS;

TEST(SquareMatrixMultiplyStrassen, D1Matrix)
{
  int a[1][1] = {1};
  int b[1][1] = {2};
  int c[1][1];
  square_matrix_multiply_strassen_recursive(a, b, c);
  EXPECT_EQ(c[0][0], 2);
}

TEST(SquareMatrixMultiplyStrassen, D2Matrix)
{
  int a[2][2] = {{1, 2}, {3, 4}};
  int b[2][2] = {{5, 6}, {7, 8}};
  int c[2][2];
  square_matrix_multiply_strassen_recursive(a, b, c);
  EXPECT_EQ(c[0][0], 19);
  EXPECT_EQ(c[0][1], 22);
  EXPECT_EQ(c[1][0], 43);
  EXPECT_EQ(c[1][1], 50);
}

TEST(SquareMatrixMultiplyStrassen, D4Matrix)
{
  int a[4][4] = {{1, 2, 3, 4}, {3, 4, 5, 6}, {5, 6, 7, 8}, {7, 8, 9, 10}};
  int b[4][4] = {{9, 10, 11, 12}, {11, 12, 13, 14}, {13, 14, 15, 16}, {15, 16, 17, 18}};
  int c[4][4];
  square_matrix_multiply_strassen_recursive(a, b, c);
  EXPECT_EQ(c[1][1], 244);
}
