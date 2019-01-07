#ifndef LCS_H
#define LCS_H


#include <utility>
#include <iostream>

namespace CLRS
{
  template <typename t, std::size_t m, std::size_t n>
  void lcs_length(t (&x)[m], t (&y)[n],
		  char (&b)[m + 1][n + 1], t (&c)[m + 1][n + 1])
  {
    for(std::size_t i = 1; i != m; ++i)
      c[i][0] = 0;
    for(std::size_t j = 0; j != n; ++j)
      c[0][j] = 0;
    for(std::size_t i = 1; i <= m; ++i)
      for(std::size_t j = 1; j <= n; ++j)
	{
	  if(x[i - 1] == y[j - 1])
	    {
	      c[i][j] = c[i - 1][j - 1] + 1;
	      b[i][j] = 'c';
	    }
	  else if(c[i - 1][j] >= c[i][j - 1])
	    {
	      c[i][j] = c[i - 1][j];
	      b[i][j] = 'u';
	    }
	  else
	    {
	      c[i][j] = c[i][j - 1];
	      b[i][j] = 'l';
	    }
	}
  }

  template <typename t, std::size_t m, std::size_t n>
  void print_lcs(char (&b)[m][n], t (&x)[m - 1],
		 std::size_t i, std::size_t j)
  {
    if(i == 0 || j == 0)
      return;
    if(b[i][j] == 'c')
      {
	print_lcs(b, x, i - 1, j - 1);
	std::cout << x[i - 1];
      }
    else if(b[i][j] == 'u')
      print_lcs(b, x, i - 1, j);
    else
      print_lcs(b, x, i, j - 1);
  }
}


#endif
