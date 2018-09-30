#ifndef HEAP_PRIORITY_QUEUE
#define HEAP_PRIORITY_QUEUE


#include <utility>
#include <vector>
#include <stdexcept>
#include "../common_heap_utility.h"
#include "../max_heapify/max_heapify.h"

namespace CLRS
{
  template <typename T>
  // return reference or copy?
  T heap_maximum(const std::vector<T> &a)
  {
    if(a.size() == 0)
      throw(std::logic_error("this queue is empty"));
    return a[0];
  }

  template <typename T>
  T heap_extract_max(std::vector<T> &a)
  {
    if(a.size() == 0)
      throw(std::underflow_error("heap underflow"));
    T max = a[0];
    a[0] = a.back();
    a.pop_back();
    CLRS::max_heapify(a, 0);
    return max;
  }

  template <typename T>
  void heap_increase_key(std::vector<T> &a, std::size_t i, T key)
  {
    if(key < a[i])
      throw(std::logic_error("new key is smaller than current key"));
    a[i] = key;
    while(i > 0 && a[CLRS::parent(i)] < a[i])
      {
	T temp = a[CLRS::parent(i)];
	a[CLRS::parent(i)] = a[i];
	a[i] = temp;
	i = CLRS::parent(i);
      }
  }

  template <typename T>
  void max_heap_insert(std::vector<T> &a, T key)
  {
    a.push_back(key);
    heap_increase_key(a, a.size() - 1, key);
  }
}


#endif
