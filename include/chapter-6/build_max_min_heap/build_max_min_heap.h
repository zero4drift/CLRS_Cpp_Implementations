#ifndef BUILD_MAX_HEAP_H
#define BUILD_MAX_HEAP_H


#include <utility>
#include "../max_min_heapify/max_min_heapify.h"

namespace CLRS
{
  template <typename T, std::size_t n>
  void build_max_heap(T (&a)[n])
  {
    for(long i = n / 2 - 1; i >= 0; --i)
      CLRS::max_heapify(a, i);
  }

  template <typename T, std::size_t n>
  void build_min_heap(T (&a)[n])
  {
    for(long i = n / 2 - 1; i >= 0; --i)
      CLRS::min_heapify(a, i);
  }
} 


#endif
