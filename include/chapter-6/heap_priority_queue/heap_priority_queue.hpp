#ifndef HEAP_PRIORITY_QUEUE
#define HEAP_PRIORITY_QUEUE


#include <utility>
#include <vector>
#include <stdexcept>
#include "../common_heap_utility.hpp"
#include "../max_min_heapify/max_min_heapify.hpp"

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
  void max_heap_increase_key(std::vector<T> &a, std::size_t i, T key)
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
    max_heap_increase_key(a, a.size() - 1, key);
  }

  // for minimum heap priority queue
  template <typename T>
  // return reference or copy?
  T heap_minimum(const std::vector<T> &a)
  {
    if(a.size() == 0)
      throw(std::logic_error("this queue is empty"));
    return a[0];
  }

  template <typename T>
  T heap_extract_min(std::vector<T> &a)
  {
    if(a.size() == 0)
      throw(std::underflow_error("heap underflow"));
    T min = a[0];
    a[0] = a.back();
    a.pop_back();
    CLRS::min_heapify(a, 0);
    return min;
  }

  template <typename T>
  void min_heap_increase_key(std::vector<T> &a, std::size_t i, T key)
  {
    if(key > a[i])
      throw(std::logic_error("new key is larger than current key"));
    a[i] = key;
    while(i > 0 && a[CLRS::parent(i)] > a[i])
      {
	T temp = a[CLRS::parent(i)];
	a[CLRS::parent(i)] = a[i];
	a[i] = temp;
	i = CLRS::parent(i);
      }
  }

  template <typename T>
  void min_heap_insert(std::vector<T> &a, T key)
  {
    a.push_back(key);
    min_heap_increase_key(a, a.size() - 1, key);
  }
}


#endif
