#ifndef RANDOMIZE_IN_PLACE_H
#define RANDOMIZE_IN_PLACE_H


#include <utility>
#include <random>
#include <ctime>

namespace CLRS
{
  template <typename T, std::size_t n>
  void randomize_in_place(T (&a)[n])
  {
    std::default_random_engine e(std::time(0));
    for(std::size_t i = 0; i != n; ++i)
      {
	std::uniform_int_distribution<unsigned> u(i, n - 1);
	T temp = a[i];
	std::size_t j = u(e);
	a[i] = a[j];
	a[i] = temp;
      }
  }
}


#endif
