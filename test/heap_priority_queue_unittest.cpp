#include <vector>
#include <stdexcept>
#include <gtest/gtest.h>
#include "chapter-6/heap_priority_queue/heap_priority_queue.h"

using std::vector;
using std::underflow_error;
using std::logic_error;

TEST(HeapMaximum, EmptyQueue)
{
  vector<int> a;
  EXPECT_THROW(heap_maximum(a), logic_error);
}

TEST(HeapMaximum, NormalQueue)
{
  vector<int> a{16, 14, 10};
  EXPECT_EQ(16, heap_maximum(a));
}

TEST(HeapExtractMax, EmptyQueue)
{
  vector<int> a;
  EXPECT_THROW(heap_extract_max(a), underflow_error);
}

TEST(HeapExtractMax, NormalQueue)
{
  vector<int> a{16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
  auto i = heap_extract_max(a);
  EXPECT_EQ(16, i);
  EXPECT_EQ(9, a.size());
}

TEST(HeapIncreaseKey, InvalidKey)
{
  vector<int> a{16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
  EXPECT_THROW(heap_increase_key(a, 1, 5), logic_error);
}

TEST(HeapIncreaseKey, ValidKey)
{
  vector<int> a{16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
  heap_increase_key(a, 8, 15);
  EXPECT_EQ(a[1], 15);
  EXPECT_EQ(a[3], 14);
  EXPECT_EQ(a[8], 8);
}

TEST(MaxHeapInsert, MediumNumber)
{
  vector<int> a{16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
  max_heap_insert(a, 11);
  EXPECT_EQ(a[10], 7);
  EXPECT_EQ(a[4], 11);
}

TEST(MaxHeapInsert, LargeNumber)
{
  vector<int> a{16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
  max_heap_insert(a, 18);
  EXPECT_EQ(a[10], 7);
  EXPECT_EQ(a[4], 14);
  EXPECT_EQ(a[1], 16);
  EXPECT_EQ(a[0], 18);
}
