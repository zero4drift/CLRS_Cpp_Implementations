#ifndef MAXIMUM_MINIMUM_H
#define MAXIMUM_MINIMUM_H


#include <utility>

template <typename T, std::size_t n>
std::pair<T, T> maximum_minimum(T (&a)[n])
{
  T maximum, minimum;
  std::size_t index;
  if(n % 2 == 0)
    {
      if(a[0] >= a[1])
	{
	  maximum = a[0];
	  minimum = a[1];
	}
      else
	{
	  maximum = a[1];
	  minimum = a[0];
	}
      index = 2;
    }
  else if(n % 2 == 1)
    {
      maximum = minimum = a[0];
      index = 1;
    }
  while(index != n)
    {
      if(a[index] >= a[index + 1])
	{
	  if(a[index] >= maximum)
	    maximum = a[index];
	  if(a[index + 1] <= minimum)
	    minimum = a[index + 1];
	}
      else
	{
	  if(a[index + 1] >= maximum)
	    maximum = a[index + 1];
	  if(a[index] <= minimum)
	    minimum = a[index];
	}
      index += 2;
    }
  return {maximum, minimum};
}


#endif
