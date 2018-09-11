#ifndef PERMUTE_BY_SORTING_H
#define PERMUTE_BY_SORTING_H


#include <ctime>
#include <random>
#include <utility>
#include "../../chapter-2/merge_sort/merge_sort.h"

template <typename T>
bool operator<=(std::pair<T, unsigned> p1, std::pair<T, unsigned> p2)
{
  return p1.second <= p2.second;
}

template <typename T, std::size_t n>
  void permute_by_sorting(T (&array)[n])
{
  std::default_random_engine e(std::time(0));
  std::uniform_int_distribution<unsigned> u(0, (n-1)*(n-1)*(n-1));
  std::pair<T, unsigned> parray[n];
  for(std::size_t i = 0; i != n; ++i)
    parray[i] = std::pair<T, unsigned>(array[i], u(e));
  merge_sort(parray, 0, n - 1);
  for(std::size_t i = 0; i != n; ++i)
    array[i] = parray[i].first;
}


#endif
