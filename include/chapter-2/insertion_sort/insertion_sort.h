#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H


#include <utility>

namespace CLRS
{
  template <typename T, std::size_t n> void insertion_sort(T (&array)[n])
  {
    /*
     * for std::size_t is a alias of unsigned long,
     * and the index in while loop must not be an unsigned,
     * then index should be long long which could
     * accommodate the maximum unsigned long integer
     * to avoid bug.
     */
    if(n <= 1)
      // in this case there is no need to sort.
      return;
    for(long long j = 1; j != n; ++j)
      {
	T temp = array[j];
	long long i = j - 1;
	while(i >=0 && array[i] > temp)
	  {
	    array[i + 1] = array[i];
	    --i;
	  }
	array[i + 1] = temp;
      }
  }
}


#endif
