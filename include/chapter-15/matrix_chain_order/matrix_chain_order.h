#ifndef MATRIX_CHAIN_ORDER
#define MATRIX_CHAIN_ORDER


#include <utility>
#include <iostream>

namespace CLRS
{
  template <std::size_t n>
  void matrix_chain_order(unsigned (&p)[n],
			  unsigned (&m)[n][n],
			  std::size_t (&s)[n][n])
  {
    std::size_t x = n - 1;
    for(std::size_t i = 1; i <= x; ++i)
      m[i][i] = 0;
    for(std::size_t l = 2; l <= x; ++l)
      {
	for(std::size_t i = 1; i <= x - l + 1; ++i)
	  {
	    std::size_t j = i + l - 1;
	    m[i][j] = -1;
	    for(std::size_t k = i; k <= j - 1; ++k)
	      {
		unsigned q = m[i][k] + m[k + 1][j]+
		  p[i - 1] * p[k] * p[j];
		if(q < m[i][j])
		  {
		    m[i][j] = q;
		    s[i][j] = k;
		  }
	      }
	  }
      }
  }
  
  template <std::size_t n>
  void print_optimal_parens(const unsigned (&s)[n][n],
			    unsigned i, unsigned j)
  {
    if(i == j)
      std::cout << "A" << i;
    else
      {
	std::cout << "(";
	print_optimal_parens(s, i, s[i][j]);
	print_optimal_parens(s, s[i][j] + 1, j);
	std::cout << ")";
      }
  }
}


#endif
