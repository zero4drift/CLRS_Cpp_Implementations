#include <gtest/gtest.h>
#include "chapter-8/bucket_sort/bucket_sort.h"

using namespace CLRS;

TEST(BucketSort, UniformIndividualDoubleArray)
{
  double d[10] = {0.78, 0.17, 0.39, 0.26, 0.72,
		  0.94, 0.21, 0.12, 0.23, 0.68};
  bucket_sort(d);
  EXPECT_EQ(0.12, d[0]);
  EXPECT_EQ(0.17, d[1]);
  EXPECT_EQ(0.21, d[2]);
  EXPECT_EQ(0.23, d[3]);
  EXPECT_EQ(0.26, d[4]);
  EXPECT_EQ(0.39, d[5]);
  EXPECT_EQ(0.68, d[6]);
  EXPECT_EQ(0.72, d[7]);
  EXPECT_EQ(0.78, d[8]);
  EXPECT_EQ(0.94, d[9]);
}
