#include <memory>
#include <stdexcept>
#include <gtest/gtest.h>
#include "chapter-19/fibonacci_heap/fibonacci_heap.h"


using namespace CLRS;
using FibNodeUnsigned = FibHeapTreeNode<unsigned>; 

TEST(FibHeap, Create)
{
  auto h = make_fib_heap<unsigned>();
  EXPECT_EQ(0, h.get_n());
  EXPECT_EQ(nullptr, h.get_min());
  FibHeapTreeNode<unsigned> x(3);
  EXPECT_EQ(0, x.get_degree());
  EXPECT_EQ(nullptr, x.get_p());
  EXPECT_EQ(nullptr, x.get_left());
  EXPECT_EQ(nullptr, x.get_right());
  EXPECT_EQ(nullptr, x.get_child());
  EXPECT_EQ(3, x.get_key());
  EXPECT_EQ(false, x.get_mark());
  EXPECT_EQ(0, x.get_degree());
}

TEST(FibHeap, Insert)
{
  auto h = make_fib_heap<unsigned>();
  auto x = std::make_shared<FibNodeUnsigned>(3);
  fib_heap_insert(h, x);
  EXPECT_EQ(1, h.get_n());
  EXPECT_EQ(x, h.get_min());
  EXPECT_EQ(x, x->get_left());
  EXPECT_EQ(x, x->get_right());
  auto y = std::make_shared<FibNodeUnsigned>(2);
  fib_heap_insert(h, y);
  EXPECT_EQ(2, h.get_n());
  EXPECT_EQ(y, h.get_min());
  EXPECT_EQ(x, y->get_left());
  EXPECT_EQ(x, y->get_right());
}
