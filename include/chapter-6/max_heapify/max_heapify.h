#ifndef MAX_HEAPIFY_H
#define MAX_HEAPIFY_H


#include <utility>
#include <vector>
#include "../common_heap_utility.h"

namespace CLRS
{
  template <typename T, std::size_t n>
  void max_heapify(T (&a)[n], std::size_t i, std::size_t length = n)
  {
    std::size_t l = CLRS::left(i);
    std::size_t r = CLRS::right(i);
    std::size_t largest = i;
    if(l < length && a[l] > a[i])
      largest = l;
    if(r < length && a[r] > a[largest])
      largest = r;
    if(largest != i)
      {
	T temp = a[i];
	a[i] = a[largest];
	a[largest] = temp;
	max_heapify(a, largest, length);
      }
  }

  template <typename T>
  void max_heapify(std::vector<T> &a, std::size_t i)
  {
    std::size_t l = CLRS::left(i);
    std::size_t r = CLRS::right(i);
    std::size_t largest = i;
    if(l < a.size() && a[l] > a[i])
      largest = l;
    if(r < a.size() && a[r] > a[largest])
      largest = r;
    if(largest != i)
      {
	T temp = a[i];
	a[i] = a[largest];
	a[largest] = temp;
	max_heapify(a, largest);
      }
  }
}


#endif
