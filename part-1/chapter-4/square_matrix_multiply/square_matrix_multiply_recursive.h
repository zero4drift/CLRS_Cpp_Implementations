// Only for matrix with dimension 2, 4, 8, 16...
#ifndef SQUARE_MATRIX_MULTIPLY_RECURSIVE_H
#define SQUARE_MATRIX_MULTIPLY_RECURSIVE_H


#include <utility>

template <typename T, std::size_t n>
void divide_matrix_4(T (&a)[n][n],
		     T (&b)[n/2][n/2],
		     T (&c)[n/2][n/2],
		     T (&d)[n/2][n/2],
		     T (&e)[n/2][n/2])
{
  for(std::size_t i = 0; i != n / 2; ++i)
    for(std::size_t j = 0; j != n / 2; ++j)
      b[i][j] = a[i][j];
  for(std::size_t i = 0; i != n / 2; ++i)
    for(std::size_t j = n / 2; j != n; ++j)
      c[i][j - n/2] = a[i][j];
  for(std::size_t i = n / 2; i != n; ++i)
    for(std::size_t j = 0; j != n / 2; ++j)
      d[i - n/2][j] = a[i][j];
  for(std::size_t i = n / 2; i != n; ++i)
    for(std::size_t j = n / 2; j != n; ++j)
      e[i - n/2][j - n/2] = a[i][j];
}

template <typename T, std::size_t n>
void combine_matrix_4(T (&a)[n][n],
		      T (&b)[n/2][n/2],
		      T (&c)[n/2][n/2],
		      T (&d)[n/2][n/2],
		      T (&e)[n/2][n/2])
{
  for(std::size_t i = 0; i != n / 2; ++i)
    for(std::size_t j = 0; j != n / 2; ++j)
      {
	a[i][j] = b[i][j];
	a[i][j + n/2] = c[i][j];
	a[i + n/2][j] = d[i][j];
	a[i + n/2][j + n/2] = e[i][j];
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
  T d[n/2][n/2];
  T e[n/2][n/2];
  T f[n/2][n/2];
  T g[n/2][n/2];
  divide_matrix_4(a, d, e, f, g);
  T h[n/2][n/2];
  T i[n/2][n/2];
  T j[n/2][n/2];
  T k[n/2][n/2];
  divide_matrix_4(b, h, i, j, k);
  T c1[n/2][n/2];
  T c2[n/2][n/2];
  square_matrix_multiply_recursive(d, h, c1);
  square_matrix_multiply_recursive(e, j, c2);
  T c3[n/2][n/2];
  add_matrix(c3, c1, c2);
  square_matrix_multiply_recursive(d, i, c1);
  square_matrix_multiply_recursive(e, k, c2);
  T c4[n/2][n/2];
  add_matrix(c4, c1, c2);
  square_matrix_multiply_recursive(f, h, c1);
  square_matrix_multiply_recursive(g, j, c2);
  T c5[n/2][n/2];
  add_matrix(c5, c1, c2);
  square_matrix_multiply_recursive(f, i, c1);
  square_matrix_multiply_recursive(g, k, c2);
  T c6[n/2][n/2];
  add_matrix(c6, c1, c2);
  combine_matrix_4(c, c3, c4, c5, c6);
}


#endif
