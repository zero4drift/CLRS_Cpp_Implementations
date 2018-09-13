#ifndef BUCKET_SORT_H
#define BUCKET_SORT_H


#include <utility>
#include <list>
#include <iostream>

/*
 * Suppose elements of array uniformly and individually
 * scattered in half open interval [0, 1)
 * TODO: this time uses standard library list and iterator,
 * this program would be refactored after list implementation.
 */
template <typename T, std::size_t n>
void bucket_sort(T (&a)[n])
{
  std::list<T> b[n];
  for(std::size_t i = 0; i != n; ++i)
    b[static_cast<std::size_t>(n*a[i])].push_back(a[i]);
  
  for(std::size_t j = 0; j != n; ++j)
    /* be careful that the commom algorithm sort
     * could not be applied on containers which
     * do not support random access
     */
    b[j].sort();
  
  std::size_t i = 0;
  for(std::size_t j = 0; j != n; ++j)
    {
      auto it = b[j].cbegin();
      while(it != b[j].cend())
	{
	  a[i] = *it;
	  ++it;
	  ++i;
	}
    }
}


#endif
