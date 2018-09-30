#ifndef MERGE_SORT_H
#define MERGE_SORT_H


#include <utility>
#include <iostream>

using std::cout;
using std::endl;

namespace CLRS
{
  template <typename T>
  void merge(T *array, std::size_t p, std::size_t q, std::size_t r)
  {
    std::size_t n1 = q - p + 1;
    std::size_t n2 = r - q;

    T larray[n1], rarray[n2];
    for(std::size_t i = 0; i < n1; ++i)
      larray[i] = array[p + i];
    for(std::size_t j = 0; j < n2; ++j)
      rarray[j] = array[q + j + 1];
  
    std::size_t i = 0, j = 0, k = p;
    while(k <= r)
      {
	if(i < n1 && j == n2)
	  {
	    array[k] = larray[i];
	    ++i;
	  }
	else if(i == n1 && j < n2)
	  {
	    array[k] = rarray[j];
	    ++j;
	  }
	else if(larray[i] <= rarray[j])
	  {
	    array[k] = larray[i];
	    ++i;
	  }
	else
	  {
	    array[k] = rarray[j];
	    ++j;
	  }
	++k;
      }
  }

  template <typename T>
  void merge_sort(T *array, std::size_t p, std::size_t r)
  {
    if(p < r)
      {
	std::size_t q = (p + r) / 2;
	merge_sort(array, p, q);
	merge_sort(array, q + 1, r);
	merge(array, p, q, r);
      }
  }
}


#endif
