#ifndef SWAP_RANDOMIZED_HIRE_ASSISTANT_H
#define SWAP_RANDOMIZED_HIRE_ASSISTANT_H


#include <utility>
#include "randomize_in_place.hpp"

namespace CLRS
{
  template <typename T, std::size_t n>
  void swap_randomized_hire_assistant(T (&a)[n], T *choose)
  {
    randomize_in_place(a);
    *choose = 0;
    for(std::size_t i = 0; i != n; ++i)
      {
	if(a[i] > *choose)
	  *choose = a[i];
      }
  }
}


#endif
