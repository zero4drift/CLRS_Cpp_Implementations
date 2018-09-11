#ifndef HEAPSORT_H
#define HEAPSORT_H


#include <utility>
#include "../build_max_heap/build_max_heap.h"

template <typename T, std::size_t n>
  void heapsort(T (&a)[n])
{
  build_max_heap(a);
  for(std::size_t i = n - 1; i >= 1; --i)
    {
      T temp = a[i];
      a[i] = a[0];
      a[0] = temp;
      if(i >= 2)
	max_heapify(a, 0, i);
    }
}


#endif
