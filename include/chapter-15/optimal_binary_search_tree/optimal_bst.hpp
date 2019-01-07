#ifndef OPTIMAL_BST_H
#define OPTIMAL_BST_H


#include <utility>

namespace CLRS
{
  template <std::size_t n>
  void optimal_bst(double (&p)[n], double (&q)[n],
		   double (&e)[n + 1][n], std::size_t(&root)[n][n])
  {
    double w[n + 1][n];
    for(std::size_t i = 1; i <= n; ++i)
      {
	e[i][i - 1] = q[i - 1];
	w[i][i - 1] = q[i - 1];
      }
    for(std::size_t l = 1; l != n; ++l)
      for(std::size_t i = 1; i != n - l + 1; ++i)
	{
	  std::size_t j = i + l - 1;
	  e[i][j] = 1000;
	  w[i][j] = w[i][j - 1] + p[j] + q[j];
	  for(std::size_t r = i; r <= j; ++r)
	    {
	      double t = e[i][r - 1]
		+ e[r + 1][j] + w[i][j];
	      if(t < e[i][j])
		{
		  e[i][j] = t;
		  root[i][j] = r;
		}
	    }
	}
  }
}


#endif
