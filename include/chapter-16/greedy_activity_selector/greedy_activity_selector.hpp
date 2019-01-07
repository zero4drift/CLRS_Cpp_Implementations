#ifndef GREEDY_ACTIVITY_SELECTOR
#define GREEDY_ACTIVITY_SELECTOR


#include <utility>
#include <vector>

namespace CLRS
{
  template <std::size_t j>
  void recursive_activity_selector(unsigned (&s)[j],
				   unsigned (&f)[j],
				   unsigned k,
				   unsigned n,
				   std::vector<unsigned> &r)
  {
    std:size_t m = k + 1;
    while(m <= n && s[m] < f[k])
      ++m;
    if(m <= n)
      {
	r.push_back(m);
	recursive_activity_selector(s, f, m, n, r);
      }
  }

  template <std::size_t n>
  std::vector<unsigned> greedy_activity_selector(unsigned (&s)[n],
						 unsigned (&f)[n])
  {
    std::size_t length = n - 1;
    std::vector<unsigned> a = {1};
    std::size_t k = 1;
    for(std::size_t m = 2; m <= length; ++m)
      {
	if(s[m] >= f[k])
	  {
	    a.push_back(m);
	    k = m;
	  }
      }
    return a;
  }
}


#endif
