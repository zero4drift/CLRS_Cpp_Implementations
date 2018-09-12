#ifndef COUNTING_SORTING_H
#define COUNTING_SORTING_H


#include <utility>

// specified for array with unsigned elements
template <typename T, std::size_t n>
void counting_sort(T (&a)[n], T (&b)[n], std::size_t k)
{
  T c[k + 1];
  for(std::size_t i = 0; i <= k; ++i)
    c[i] = 0;
  for(std::size_t j = 0; j != n; ++j)
    ++c[a[j]];
  for(std::size_t i = 1; i <= k; ++i)
    c[i] = c[i] + c[i - 1];
  for(long long j = n - 1; j >= 0; --j)
    {
      // be careful that the index starts from 0
      // and the minimum element should be placed in index 0.
      b[c[a[j]] - 1] = a[j];
      --c[a[j]];
    }
}


#endif
