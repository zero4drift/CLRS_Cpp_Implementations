#ifndef RADIX_SORT_H
#define RADIX_SORT_H


#include <utility>

namespace CLRS
{
  template <typename T>
  T radix_digit(T a, std::size_t d)
  {
    T return_value;
    for(T i = 1; i <= d; ++i)
      {
	return_value = a % 10;
	a /= 10;
      }
    return return_value;
  }

  template <typename T, std::size_t n>
  void radix_counting_sort(T (&a)[n], T (&b)[n], std::size_t d)
  {
    T c[10];
    for(std::size_t i = 0; i <= 9; ++i)
      c[i] = 0;
    for(std::size_t j = 0; j != n; ++j)
      ++c[radix_digit(a[j], d)];
    for(std::size_t i = 1; i <= 9; ++i)
      c[i] = c[i] + c[i - 1];
    for(long long j = n - 1; j >= 0; --j)
      {
	b[c[radix_digit(a[j], d)] - 1] = a[j];
	--c[radix_digit(a[j], d)];
      }
  }

  template <typename T, std::size_t n>
  void radix_sort(T (&a)[n], T d)
  {
    T b[n];
    for(std::size_t j = 1; j <= d; ++j)
      {
	radix_counting_sort(a, b, j);
	for(std::size_t i = 0; i != n; ++i)
	  a[i] = b[i];
      }
  }
}
  


#endif
