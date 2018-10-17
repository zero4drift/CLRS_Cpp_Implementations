#ifndef HEAPSORT_H
#define HEAPSORT_H


#include <utility>
#include "../build_max_min_heap/build_max_min_heap.h"
#include "../max_min_heapify/max_min_heapify.h"

namespace CLRS
{
  template <typename T, std::size_t n>
  void heapsort(T (&a)[n])
  {
    CLRS::build_max_heap(a);
    for(std::size_t i = n - 1; i >= 1; --i)
      {
	T temp = a[i];
	a[i] = a[0];
	a[0] = temp;
	if(i >= 2)
	  CLRS::max_heapify(a, 0, i);
      }
  }

  /*
   * use minimal heap priority queue
   * result sorted from large to small.
   */
  template <typename T, std::size_t n>
  void min_heapsort(T (&a)[n])
  {
    CLRS::build_min_heap(a);
    for(std::size_t i = n - 1; i >= 1; --i)
      {
	T temp = a[i];
	a[i] = a[0];
	a[0] = temp;
	if(i >= 2)
	  CLRS::min_heapify(a, 0, i);
      }
  }
}


#endif
