#ifndef SORT_RANDOMIZED_HIRE_ASSISTANT_H
#define SORT_RANDOMIZED_HIRE_ASSISTANT_H


#include <utility>
#include "permute_by_sorting.hpp"

namespace CLRS
{
  template <typename T, std::size_t n>
  void sort_randomized_hire_assistant(T (&a)[n], T *choose)
  {
    CLRS::permute_by_sorting(a);
    *choose = 0;
    for(std::size_t i = 0; i != n; ++i)
      {
	if(a[i] > *choose)
	  *choose = a[i];
      }
  }
}


#endif
