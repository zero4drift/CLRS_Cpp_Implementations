#ifndef RECURSIVE_CUT_ROD_H
#define RECURSIVE_CUT_ROD_H


#include <utility>
#include <algorithm>

namespace CLRS
{
  constexpr unsigned CUT_ROD_PRICES[11] =
    {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

  template <std::size_t m>
  unsigned recursive_cut_rod(const unsigned (&prices)[m],
			     unsigned n)
  {
    if(n == 0)
      return 0;
    unsigned q = 0;
    for(unsigned i = 1; i <= n && i < m; ++i)
      q = std::max(q, prices[i] +
		   recursive_cut_rod(prices, n - i));
    return q;
  }
}


#endif
