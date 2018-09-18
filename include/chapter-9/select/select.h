#ifndef SELECT_H
#define SELECT_H


#include <utility>
#include <vector>
#include <algorithm>
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
  if(p == r)
    return a[p];

  std::size_t len = r - p + 1, n_5 = len / 5, l = 5 * n_5;
  std::vector<T> mid_nums;
  for(std::size_t m = p; m != p + l; m += 5)
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
  std::size_t n_5_left = len % 5;
  if(n_5_left)
    {
      T temp_left[n_5_left];
      /* 
       * this program must be compiled with -O1;
       * or parameter i varies when running.
       * do not know why, compiler issue?
       */
      for(std::size_t x = p + l; x <= r; ++x)
	temp_left[x - p - l] = a[x]; 
      // for n_5_left is not a constexpr, insertion_sort not used here
      for(long long j = 1; j != n_5_left; ++j)
	{
	  T temp = temp_left[j];
	  long long y = j - 1;
	  while(y >=0 && temp_left[y] > temp)
	    {
	      temp_left[y + 1] = temp_left[y];
	      --y;
	    }
	  temp_left[y + 1] = temp;
	}
      std::size_t mid = (n_5_left - 1) / 2;
      mid_nums.push_back(temp_left[mid]);
    }
  
  std::sort(mid_nums.begin(), mid_nums.end());
  T mid_num = mid_nums[(mid_nums.size() - 1) / 2];
  std::size_t wanted_mid = p;
  while(wanted_mid <= r)
    {
      if(a[wanted_mid] == mid_num)
	break;
      ++wanted_mid;
    }
  std::size_t q = select_partition(a, p, r, wanted_mid);
  std::size_t k = q - p + 1;
  
  if(i == k)
    return mid_num;
  else if(i < k)
    return select(a, p, q - 1, i);
  else
    return select(a, q + 1, r, i - k);
}


#endif
