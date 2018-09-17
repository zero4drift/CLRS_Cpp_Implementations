#ifndef SELECT_H
#define SELECT_H


#include <utility>
#include <vector>
#include "chapter-2/insertion_sort/insertion_sort.h"
#include "chapter-7/quicksort/quicksort.h"

template <typename T, std::size_t n>
std::size_t select_partition(T (&a)[n], long long p, long long r, long long i)
{
  T temp = a[r];
  a[r] = a[i];
  a[i] = temp;
  return partition(a, p, r);
}

template <typename T, std::size_t n>
T select(T (&a)[n], std::size_t p, std::size_t r, std::size_t i)
{
  std::size_t n_5 = n / 5, k = 5 * n_5;
  std::vector<T> mid_nums;
  for(std::size_t m = 0; m != k; m += 5)
    {
      T temp[5];
      temp[0] = a[m];
      temp[1] = a[m + 1];
      temp[2] = a[m + 2];
      temp[3] = a[m + 3];
      temp[4] = a[m + 4];
      insertion_sort(temp);
      mid_nums.push_back(temp[2]);
    }
  std::size_t n_5_left = n % 5;
  if(n_5_left)
    {      
      std::size_t i = k;
      T temp_left[n_5_left];
      while(i != n)
	{
	  temp_left[i] = a[i];
	  ++i;
	}
      insertion_sort(temp_left);
      std::size_t mid = (n_5_left - 1) / 2;
      mid_nums.push_back(temp_left[mid]);
    }
}


#endif
