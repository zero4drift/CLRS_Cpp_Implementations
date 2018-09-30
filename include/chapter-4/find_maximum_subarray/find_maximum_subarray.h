#ifndef FIND_MAXIMUM_SUBARRAY_H
#define FIND_MAXIMUM_SUBARRAY_H


#include <utility>

namespace CLRS
{
  template <typename T>
  std::pair<std::pair<std::size_t, std::size_t>, T>
  find_max_crossing_subarray(const T *a,
			     std::size_t low,
			     std::size_t mid,
			     std::size_t high)
  {
    T left_sum = a[mid], sum1 = 0;
    std::size_t max_left = mid;
    for(std::size_t i = mid; i != low; --i)
      {
	sum1 += a[i];
	if(sum1 > left_sum)
	  {
	    left_sum = sum1;
	    max_left = i;
	  }
      }
    T right_sum = a[mid + 1], sum2 = 0;
    std::size_t max_right = mid + 1;
    for(std::size_t i = mid + 1; i != high; ++i)
      {
	sum2 += a[i];
	if(sum2 > right_sum)
	  {
	    right_sum = sum2;
	    max_right = i;
	  }
      }
    return std::pair<std::pair<std::size_t, std::size_t>, T>
      (std::pair<std::size_t, std::size_t>
       (max_left, max_right), left_sum + right_sum);
  }
  template <typename T>
  std::pair<std::pair<std::size_t, std::size_t>, T>
  find_maximum_subarray(const T *a,
			std::size_t low,
			std::size_t high)
  {
    if(high == low)
      return std::pair<std::pair<std::size_t, std::size_t>, T>
	(std::pair<std::size_t, std::size_t>(low, high), a[low]);
    else
      {
	std::size_t mid = (low + high) / 2;
	auto r1 = find_maximum_subarray(a, low, mid);
	auto r2 = find_maximum_subarray(a, mid + 1, high);
	auto r3 = find_max_crossing_subarray(a, low, mid, high);
	if(r1.second > r2.second && r1.second > r3.second)
	  return r1;
	else if(r2.second > r1.second && r2.second > r3.second)
	  return r2;
	else
	  return r3;
      }
  }
}


#endif
