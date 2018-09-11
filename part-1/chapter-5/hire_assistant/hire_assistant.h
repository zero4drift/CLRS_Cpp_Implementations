#ifndef HIRE_ASSISTANT_H
#define HIRE_ASSISTANT_H


#include <utility>

template <typename T, std::size_t n>
void hire_assistant(const T (&a)[n], T *choose)
{
  *choose = 0;
  for(std::size_t i = 0; i != n; ++i)
    {
      if(a[i] > *choose)
	*choose = a[i];
    }
}


#endif
