#ifndef MINIMUM_H
#define MINIMUM_H


#include <utility>

template <typename T, std::size_t n>
  T minimum(T (&a)[n])
{
  T min = a[0];
  for(std::size_t i = 1; i != n; ++i)
    if(min > a[i])
      min = a[i];
  return min;
}


#endif
