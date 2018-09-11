#ifndef QUICKSORT_H
#define QUICKSORT_H


#include <utility>

template <typename T, std::size_t n>
  std::size_t partition(T (&a)[n], long long p, long long r)
{
  T x = a[r];
  std::size_t i = p;
  for(std::size_t j = p; j != r; ++j)
    {
      if(a[j] <= x)
	{
	  T temp = a[i];
	  a[i] = a[j];
	  a[j] = temp;
	  ++i;
	}
    }
  T temp = a[i];
  a[i] = a[r];
  a[r] = temp;
  return i;
}

template <typename T, std::size_t n>
  void quicksort(T (&a)[n], long long p, long long r)
{
  if(p < r)
    {
      std::size_t q = partition(a, p, r);
      quicksort(a, p, q - 1);
      quicksort(a, q + 1, r);
    }
}


#endif
