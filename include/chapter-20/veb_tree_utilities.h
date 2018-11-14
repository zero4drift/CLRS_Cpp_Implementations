#ifndef VEB_TREE_UTILITIES_H
#define VEB_TREE_UTILITIES_H


// Three utility functions for Proto vEB Tree.

#include <math.h>

namespace CLRS
{
  // get the high ((log2(u)) / 2) bits part of x
  unsigned veb_high(unsigned x, unsigned u)
  {
    unsigned bits = std::log2(u) / 2;
    return x >> bits;
  }

  // get the low ((log2(u)) / 2) bits part of x
  unsigned veb_low(unsigned x, unsigned u)
  {
    unsigned mask = std::sqrt(u) - 1;
    return x & mask;
  }

  // get the original value based on its high and low half parts
  unsigned veb_index(unsigned h, unsigned l, unsigned u)
  {
    unsigned bits = std::log2(u) / 2;
    return (h << bits) + l;
  }
}


#endif
