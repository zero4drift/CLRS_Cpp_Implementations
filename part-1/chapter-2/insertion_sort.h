#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H


#include <utility>

template <typename T, std::size_t n> void insertion_sort(T (&array)[n])
{
  for(int j = 1; j != n; ++j)
    {
      T temp = array[j];
      int i = j - 1;
      while(i >=0 && array[i] > temp)
	{
	  array[i + 1] = array[i];
	  --i;
	}
      array[i + 1] = temp;
    }
}


#endif
