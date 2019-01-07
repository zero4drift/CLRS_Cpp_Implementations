#ifndef RANDOMIZED_QUICKSORT_H
#define RANDOMIZED_QUICKSORT_H


#include <utility>
#include <random>
#include <ctime>
#include "chapter-7/quicksort/quicksort.hpp"

namespace CLRS
{
  template <typename T, std::size_t n>
  std::size_t randomized_partition(T (&a)[n], long long p, long long r)
  {
    std::default_random_engine e(std::time(0));
    std::uniform_int_distribution<long long> u(p, r);
    long long i = u(e);
    T temp = a[r];
    a[r] = a[i];
    a[i] = temp;
    return CLRS::partition(a, p, r);
  }

  template <typename T, std::size_t n>
  void randomized_quicksort(T (&a)[n], long long p, long long r)
  {
    if(p < r)
      {
	std::size_t q = randomized_partition(a, p, r);
	randomized_quicksort(a, p, q - 1);
	randomized_quicksort(a, q + 1, r);
      }
  }
}


#endif
