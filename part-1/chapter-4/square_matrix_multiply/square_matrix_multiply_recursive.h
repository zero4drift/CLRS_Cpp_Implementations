// Only for matrix with dimension 2, 4, 8, 16...
#ifndef SQUARE_MATRIX_MULTIPLY_RECURSIVE_H
#define SQUARE_MATRIX_MULTIPLY_RECURSIVE_H


#include <utility>

template <typename T, std::size_t n>
void divide_matrix_4(T (&a)[n][n],
		     T (&b)[n/2][n/2],
		     T (&c)[n/2][n/2],
		     T (&a00)[n/2][n/2],
		     T (&a01)[n/2][n/2])
{
  for(std::size_t i = 0; i != n / 2; ++i)
    for(std::size_t j = 0; j != n / 2; ++j)
      b[i][j] = a[i][j];
  for(std::size_t i = 0; i != n / 2; ++i)
    for(std::size_t j = n / 2; j != n; ++j)
      c[i][j - n/2] = a[i][j];
  for(std::size_t i = n / 2; i != n; ++i)
    for(std::size_t j = 0; j != n / 2; ++j)
      a00[i - n/2][j] = a[i][j];
  for(std::size_t i = n / 2; i != n; ++i)
    for(std::size_t j = n / 2; j != n; ++j)
      a01[i - n/2][j - n/2] = a[i][j];
}

template <typename T, std::size_t n>
void combine_matrix_4(T (&a)[n][n],
		      T (&b)[n/2][n/2],
		      T (&c)[n/2][n/2],
		      T (&a00)[n/2][n/2],
		      T (&a01)[n/2][n/2])
{
  for(std::size_t i = 0; i != n / 2; ++i)
    for(std::size_t j = 0; j != n / 2; ++j)
      {
	a[i][j] = b[i][j];
	a[i][j + n/2] = c[i][j];
	a[i + n/2][j] = a00[i][j];
	a[i + n/2][j + n/2] = a01[i][j];
      }
}

template <typename T, std::size_t n>
void add_matrix(T (&c)[n][n], T (&a)[n][n], T (&b)[n][n])
{
  for(std::size_t i = 0; i != n; ++i)
    for(std::size_t j = 0; j != n; ++j)
      c[i][j] = a[i][j] + b[i][j];
}

template <typename T>
void square_matrix_multiply_recursive(T (&a)[1][1], T (&b)[1][1], T (&c)[1][1])
// more specific function template for recursive base case when n equals 1.
{
  c[0][0] = a[0][0] * b[0][0];
}

template <typename T, std::size_t n>
void square_matrix_multiply_recursive(T (&a)[n][n], T (&b)[n][n], T (&c)[n][n]) 
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
  T temp1[n/2][n/2];
  T temp2[n/2][n/2];
  square_matrix_multiply_recursive(a00, b00, temp1);
  square_matrix_multiply_recursive(a01, b10, temp2);
  T c00[n/2][n/2];
  add_matrix(c00, temp1, temp2);
  square_matrix_multiply_recursive(a00, b01, temp1);
  square_matrix_multiply_recursive(a01, b11, temp2);
  T c01[n/2][n/2];
  add_matrix(c01, temp1, temp2);
  square_matrix_multiply_recursive(a10, b00, temp1);
  square_matrix_multiply_recursive(a11, b10, temp2);
  T c10[n/2][n/2];
  add_matrix(c10, temp1, temp2);
  square_matrix_multiply_recursive(a10, b01, temp1);
  square_matrix_multiply_recursive(a11, b11, temp2);
  T c11[n/2][n/2];
  add_matrix(c11, temp1, temp2);
  combine_matrix_4(c, c00, c01, c10, c11);
}


#endif
