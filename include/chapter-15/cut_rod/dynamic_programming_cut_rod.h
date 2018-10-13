#ifndef DYNAMIC_PROGRAMMING_CUT_ROD_H
#define DYNAMIC_PROGRAMMING_CUT_ROD_H


#include <utility>
#include <algorithm>

namespace CLRS
{
  template <std::size_t m>
  unsigned memoized_cut_rod_aux(const unsigned (&)[m],
				unsigned, long *);

  template <std::size_t m>
  unsigned memoized_cut_rod(const unsigned (&prices)[m],
			    unsigned n)
  {
    long r[n + 1];
    for(std::size_t i = 0; i <= n; ++i)
      r[i] = -1;
    return memoized_cut_rod_aux(prices, n, r);
  }
  
  template <std::size_t m>
  unsigned memoized_cut_rod_aux(const unsigned (&prices)[m],
				unsigned n, long *r)
  {
    if(r[n] >= 0)
      return r[n];
    unsigned q = 0;
    if(n == 0)
      q = 0;
    else
      {
	for(unsigned i = 1; i <= n && i < m; ++i)
	  {
	    q = std::max(q, prices[i] +
			 memoized_cut_rod_aux(prices, n - i, r));
	  }
      }
    r[n] = q;
    return q;
  }

  template <std::size_t m>
  unsigned bottom_up_cut_rod(const unsigned (&prices)[m], unsigned n)
  {
    unsigned r[n + 1];
    r[0] = 0;
    for(std::size_t j = 1; j <= n; ++j)
      {
	unsigned q = 0;
	for(std::size_t i = 1; i <= j && i < m; ++i)
	  q = std::max(q, prices[i] + r[j - i]);
	r[j] = q;
      }
    return r[n];
  }

  template <std::size_t m>
  void extended_bottom_up_cut_rod(const unsigned (&prices)[m],
				  unsigned n,
				  unsigned *r,
				  std::size_t *s)
  {
    r[0] = 0;
    for(std::size_t j = 1; j <= n; ++j)
      {
	unsigned q = 0;
	for(std::size_t i = 1; i <= j && i < m; ++i)
	  {
	    if(q < prices[i] + r[j - i])
	      {
		q = prices[i] + r[j - i];
		s[j] = i;
	      }
	  }
	r[j] = q;
      }
  }
}


#endif
