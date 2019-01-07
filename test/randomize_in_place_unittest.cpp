#include <gtest/gtest.h>
#include "chapter-5/hire_assistant_randomize_in_place/randomize_in_place.hpp"

using namespace CLRS;

// Due to array randomize sorted, have to do this:
bool randomize_in_place_unittest_if_randomized(int a, int b, int c, int d)
{
  bool p1 = a != b && a != c && a != d;
  bool p2 = b != c && b != d;
  bool p3 = c != d;
  bool p4 = (a >= 1 && a <= 4) && (b >= 1 && b <= 4)
    && (c >= 1 && c <= 4) && (d >= 1 && d <= 4);
  return p1 && p2 && p3 && p4;
}

TEST(RandomizedInPlace, NormalArray)
{
  int a[4] = {4, 3, 2, 1};
  randomize_in_place(a);
  EXPECT_PRED4(randomize_in_place_unittest_if_randomized, a[0], a[1], a[2], a[3]);
}
