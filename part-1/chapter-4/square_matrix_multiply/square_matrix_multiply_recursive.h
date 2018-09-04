#ifndef SQUARE_MATRIX_MULTIPLY_RECURSIVE_H
#define SQUARE_MATRIX_MULTIPLY_RECURSIVE_H


#include <utility>

template <typename T, std::size_t n>
  void square_matrix_multiply_recursive(T a[n][n], T b[n][n], T c[n][n])
{
  if(n == 1)
    c[0][0] = a[0][0] * b[0][0];
  else
    {
    }
}


#endif
