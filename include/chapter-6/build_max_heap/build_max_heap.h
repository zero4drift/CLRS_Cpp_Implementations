#ifndef BUILD_MAX_HEAP_H
#define BUILD_MAX_HEAP_H


#include <utility>
#include "../max_heapify/max_heapify.h"

namespace CLRS
{
  template <typename T, std::size_t n>
  void build_max_heap(T (&a)[n])
  {
    for(long i = n / 2 - 1; i >= 0; --i)
      CLRS::max_heapify(a, i);
  }
} 


#endif
