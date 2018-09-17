#ifndef RANDOMIZED_SELECT_H
#define RANDOMIZED_SELECT_H


#include <utility>
#include "chapter-7/randomized_quicksort/randomized_quicksort.h"

template <typename T, std::size_t n>
T randomized_select(T (&a)[n], std::size_t p, std::size_t r, std::size_t i)
{
  if(p == r)
    return a[p];
  std::size_t q = randomized_partition(a, p, r);
  std::size_t k = q - p + 1;
  if(i == k)
    return a[q];
  else if(i < k)
    return randomized_select(a, p, q - 1, i);
  else
    return randomized_select(a, q + 1, r, i - k);
}


#endif
