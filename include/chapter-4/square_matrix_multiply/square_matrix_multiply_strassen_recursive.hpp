#ifndef SQUARE_MATRIX_MULTIPLY_STRASSEN_RECURSIVE_H
#define SQUARE_MATRIX_MULTIPLY_STRASSEN_RECURSIVE_H


#include <utility>
#include "square_matrix_multiply_recursive.hpp"

namespace CLRS
{
  template <typename T, std::size_t n>
  void sub_matrix(T (&c)[n][n], T (&a)[n][n], T (&b)[n][n])
  {
    for(std::size_t i = 0; i != n; ++i)
      for(std::size_t j = 0; j != n; ++j)
	c[i][j] = a[i][j] - b[i][j];
  }

  template <typename T>
  void square_matrix_multiply_strassen_recursive(T (&a)[1][1], T (&b)[1][1], T (&c)[1][1])
  // more specific function template for recursive base case when n equals 1.
  {
    c[0][0] = a[0][0] * b[0][0];
  }

  template <typename T, std::size_t n>
  void square_matrix_multiply_strassen_recursive(T (&a)[n][n], T (&b)[n][n], T (&c)[n][n])
  {
    T a00[n/2][n/2];
    T a01[n/2][n/2];
    T a10[n/2][n/2];
    T a11[n/2][n/2];
    divide_matrix_4(a, a00, a01, a10, a11);
    T b00[n/2][n/2];
    T b01[n/2][n/2];
    T b10[n/2][n/2];
    T b11[n/2][n/2];
    divide_matrix_4(b, b00, b01, b10, b11);
    T s0[n/2][n/2];
    T s1[n/2][n/2];
    T s2[n/2][n/2];
    T s3[n/2][n/2];
    T s4[n/2][n/2];
    T s5[n/2][n/2];
    T s6[n/2][n/2];
    T s7[n/2][n/2];
    T s8[n/2][n/2];
    T s9[n/2][n/2];
    sub_matrix(s0, b01, b11);
    add_matrix(s1, a00, a01);
    add_matrix(s2, a10, a11);
    sub_matrix(s3, b10, b00);
    add_matrix(s4, a00, a11);
    add_matrix(s5, b00, b11);
    sub_matrix(s6, a01, a11);
    add_matrix(s7, b10, b11);
    sub_matrix(s8, a00, a10);
    add_matrix(s9, b00, b01);
    T p0[n/2][n/2];
    T p1[n/2][n/2];
    T p2[n/2][n/2];
    T p3[n/2][n/2];
    T p4[n/2][n/2];
    T p5[n/2][n/2];
    T p6[n/2][n/2];
    square_matrix_multiply_strassen_recursive(a00, s0, p0);
    square_matrix_multiply_strassen_recursive(s1, b11, p1);
    square_matrix_multiply_strassen_recursive(s2, b00, p2);
    square_matrix_multiply_strassen_recursive(a11, s3, p3);
    square_matrix_multiply_strassen_recursive(s4, s5, p4);
    square_matrix_multiply_strassen_recursive(s6, s7, p5);
    square_matrix_multiply_strassen_recursive(s8, s9, p6);
    T c00[n/2][n/2];
    T c01[n/2][n/2];
    T c10[n/2][n/2];
    T c11[n/2][n/2];
    T temp1[n/2][n/2];
    T temp2[n/2][n/2];
    add_matrix(temp1, p4, p3);
    sub_matrix(temp2, temp1, p1);
    add_matrix(c00, temp2, p5);
    add_matrix(c01, p0, p1);
    add_matrix(c10, p2, p3);
    add_matrix(temp1, p4, p0);
    sub_matrix(temp2, temp1, p2);
    sub_matrix(c11, temp2, p6);
    combine_matrix_4(c, c00, c01, c10, c11);
  }
}


#endif
