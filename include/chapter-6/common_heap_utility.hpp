#ifndef COMMON_HEAP_UTILITY_H
#define COMMON_HEAP_UTILITY_H


#include <utility>

namespace CLRS
{
  inline std::size_t pre_proc(std::size_t i)
  {
    return ++i;
  }

  inline std::size_t post_proc(std::size_t i)
  {
    return --i;
  }

  inline std::size_t parent(std::size_t i)
  {
    i = pre_proc(i);
    i /= 2;
    return post_proc(i);
  }

  inline std::size_t left(std::size_t i)
  {
    i = pre_proc(i);
    i = 2 * i;
    return post_proc(i);
  }

  inline std::size_t right(std::size_t i)
  {
    i = pre_proc(i);
    i = 2 * i + 1;
    return post_proc(i);
  }
}


#endif
