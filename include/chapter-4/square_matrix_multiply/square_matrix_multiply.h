#ifndef SQUARE_MATRIX_MULTIPLY_H
#define SQUARE_MATRIX_MULTIPLY_H


#include <utility>

template <typename T, std::size_t n>
void square_matrix_multiply(const T (&a)[n][n], const T (&b)[n][n], T (&c)[n][n])
{
  for(std::size_t i = 0; i != n; ++i)
    for(std::size_t j = 0; j != n; ++j)
      {
	c[i][j] = 0;
	for(std::size_t k = 0; k != n; ++k)
	  c[i][j] += a[i][k] * b[k][j];
      }
}


#endif
