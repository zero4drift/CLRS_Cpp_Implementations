#include <memory>
#include <stdexcept>
#include <gtest/gtest.h>
#include "chapter-19/fibonacci_heap/fibonacci_heap.hpp"


using namespace CLRS;
using FibNodeUnsigned = FibHeapTreeNode<unsigned>; 

void scan_through_fib_tree
  (const std::shared_ptr<FibHeapTreeNode<unsigned>> &n)
  {
    if(n != nullptr)
      {
	std::cout << n->get_key() << " ";
	scan_through_fib_tree(n->get_child());
      }
  }

  void scan_through_fib_heap
  (const FibHeap<unsigned> &h)
  {
    std::cout << "heap begins" << std::endl;
    auto root = h.get_min();
    auto min = root;
    do
      {
	std::cout << "tree begins" << std::endl;
	scan_through_fib_tree(root);
	root = root->get_right();
	std::cout << "\ntree ends" << std::endl;
      }
    while(root != min);
    std::cout << "heap ends" << std::endl;
  }

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
  auto z = std::make_shared<FibNodeUnsigned>(1);
  fib_heap_insert(h, z);
  EXPECT_EQ(3, h.get_n());
  EXPECT_EQ(z, h.get_min());
  EXPECT_EQ(x, z->get_left());
  EXPECT_EQ(y, z->get_right());
}

TEST(FibHeap, Minimum)
{
  auto h = make_fib_heap<unsigned>();
  auto x = std::make_shared<FibNodeUnsigned>(3);
  fib_heap_insert(h, x);
  auto y = std::make_shared<FibNodeUnsigned>(2);
  fib_heap_insert(h, y);
  auto z = std::make_shared<FibNodeUnsigned>(1);
  fib_heap_insert(h, z);
  EXPECT_EQ(z, fib_heap_minimum(h));
}

TEST(FibHeap, Union2NonEmptyHeap)
{
  auto h1 = make_fib_heap<unsigned>();
  auto x1 = std::make_shared<FibNodeUnsigned>(3);
  fib_heap_insert(h1, x1);
  auto y1 = std::make_shared<FibNodeUnsigned>(2);
  fib_heap_insert(h1, y1);
  auto z1 = std::make_shared<FibNodeUnsigned>(1);
  fib_heap_insert(h1, z1);
  auto h2 = make_fib_heap<unsigned>();
  auto x2 = std::make_shared<FibNodeUnsigned>(6);
  fib_heap_insert(h2, x2);
  auto y2 = std::make_shared<FibNodeUnsigned>(5);
  fib_heap_insert(h2, y2);
  auto z2 = std::make_shared<FibNodeUnsigned>(4);
  fib_heap_insert(h2, z2);
  auto h = fib_heap_union(h1, h2);
  EXPECT_EQ(6, h.get_n());
  EXPECT_EQ(z1, h.get_min());
}

TEST(FibHeap, Union1NonEmptyHeap1)
{
  auto h1 = make_fib_heap<unsigned>();
  auto x1 = std::make_shared<FibNodeUnsigned>(3);
  fib_heap_insert(h1, x1);
  auto y1 = std::make_shared<FibNodeUnsigned>(2);
  fib_heap_insert(h1, y1);
  auto z1 = std::make_shared<FibNodeUnsigned>(1);
  fib_heap_insert(h1, z1);
  auto h2 = make_fib_heap<unsigned>();
  auto h = fib_heap_union(h1, h2);
  EXPECT_EQ(3, h.get_n());
  EXPECT_EQ(z1, h.get_min());
}

TEST(FibHeap, Union1NonEmptyHeap2)
{
  auto h1 = make_fib_heap<unsigned>();
  auto x1 = std::make_shared<FibNodeUnsigned>(3);
  fib_heap_insert(h1, x1);
  auto y1 = std::make_shared<FibNodeUnsigned>(2);
  fib_heap_insert(h1, y1);
  auto z1 = std::make_shared<FibNodeUnsigned>(1);
  fib_heap_insert(h1, z1);
  auto h2 = make_fib_heap<unsigned>();
  auto h = fib_heap_union(h2, h1);
  EXPECT_EQ(3, h.get_n());
  EXPECT_EQ(z1, h.get_min());
}

TEST(FibHeap, Union2EmptyHeap)
{
  auto h1 = make_fib_heap<unsigned>();
  auto h2 = make_fib_heap<unsigned>();
  auto h = fib_heap_union(h2, h1);
  EXPECT_EQ(0, h.get_n());
  EXPECT_EQ(nullptr, h.get_min());
}

TEST(FibHeap, ExtractMin)
{
  auto h1 = make_fib_heap<unsigned>();
  auto x1 = std::make_shared<FibNodeUnsigned>(23);
  fib_heap_insert(h1, x1);
  auto y1 = std::make_shared<FibNodeUnsigned>(7);
  fib_heap_insert(h1, y1);
  auto z1 = std::make_shared<FibNodeUnsigned>(21);
  fib_heap_insert(h1, z1);
  auto x2 = std::make_shared<FibNodeUnsigned>(3);
  auto x2_c1 = std::make_shared<FibNodeUnsigned>(18);
  fib_heap_list_add_child(x2_c1, x2);
  auto x2_c2 = std::make_shared<FibNodeUnsigned>(52);
  fib_heap_list_add_child(x2_c2, x2);
  auto x2_c3 = std::make_shared<FibNodeUnsigned>(38);
  fib_heap_list_add_child(x2_c3, x2);
  auto x2_c1_c = std::make_shared<FibNodeUnsigned>(39);
  fib_heap_list_add_child(x2_c1_c, x2_c1);
  auto x2_c3_c = std::make_shared<FibNodeUnsigned>(41);
  fib_heap_list_add_child(x2_c3_c, x2_c3);
  fib_heap_insert(h1, x2);
  auto y2 = std::make_shared<FibNodeUnsigned>(17);
  auto y2_c = std::make_shared<FibNodeUnsigned>(30);
  fib_heap_list_add_child(y2_c, y2);
  fib_heap_insert(h1, y2);
  auto z2 = std::make_shared<FibNodeUnsigned>(24);
  auto z2_c1 = std::make_shared<FibNodeUnsigned>(26);
  auto z2_c2 = std::make_shared<FibNodeUnsigned>(46);
  auto z2_c1_c = std::make_shared<FibNodeUnsigned>(35);
  fib_heap_list_add_child(z2_c1, z2);
  fib_heap_list_add_child(z2_c1_c, z2_c1);
  fib_heap_list_add_child(z2_c2, z2);
  fib_heap_insert(h1, z2);
  // statement below is just used for test(the whole heap is man-made)
  h1.set_n(15);

  auto result = fib_heap_extract_min(h1);
  EXPECT_EQ(3, result->get_key());
  EXPECT_EQ(14, h1.get_n());
  EXPECT_EQ(7, h1.get_min()->get_key());
  EXPECT_EQ(3, h1.get_min()->get_degree());
  EXPECT_EQ(18, h1.get_min()->get_right()->get_key());
  EXPECT_EQ(2, h1.get_min()->get_right()->get_degree());
  EXPECT_EQ(38, h1.get_min()->get_right()->get_right()->get_key());
  EXPECT_EQ(1, h1.get_min()->get_right()->get_right()->get_degree());
}

TEST(FibHeap, DecreaseKey)
{
  auto h1 = make_fib_heap<unsigned>();
  auto x1 = std::make_shared<FibNodeUnsigned>(23);
  fib_heap_insert(h1, x1);
  auto y1 = std::make_shared<FibNodeUnsigned>(7);
  fib_heap_insert(h1, y1);
  auto z1 = std::make_shared<FibNodeUnsigned>(21);
  fib_heap_insert(h1, z1);
  auto x2 = std::make_shared<FibNodeUnsigned>(3);
  auto x2_c1 = std::make_shared<FibNodeUnsigned>(18);
  x2_c1->set_mark();
  fib_heap_list_add_child(x2_c1, x2);
  auto x2_c2 = std::make_shared<FibNodeUnsigned>(52);
  fib_heap_list_add_child(x2_c2, x2);
  auto x2_c3 = std::make_shared<FibNodeUnsigned>(38);
  fib_heap_list_add_child(x2_c3, x2);
  auto x2_c1_c = std::make_shared<FibNodeUnsigned>(39);
  x2_c1_c->set_mark();
  fib_heap_list_add_child(x2_c1_c, x2_c1);
  auto x2_c3_c = std::make_shared<FibNodeUnsigned>(41);
  fib_heap_list_add_child(x2_c3_c, x2_c3);
  fib_heap_insert(h1, x2);
  auto y2 = std::make_shared<FibNodeUnsigned>(17);
  auto y2_c = std::make_shared<FibNodeUnsigned>(30);
  fib_heap_list_add_child(y2_c, y2);
  fib_heap_insert(h1, y2);
  auto z2 = std::make_shared<FibNodeUnsigned>(24);
  auto z2_c1 = std::make_shared<FibNodeUnsigned>(26);
  z2_c1->set_mark();
  auto z2_c2 = std::make_shared<FibNodeUnsigned>(46);
  auto z2_c1_c = std::make_shared<FibNodeUnsigned>(35);
  fib_heap_list_add_child(z2_c1, z2);
  fib_heap_list_add_child(z2_c1_c, z2_c1);
  fib_heap_list_add_child(z2_c2, z2);
  fib_heap_insert(h1, z2);
  // statement below is just used for test(the whole heap is man-made)
  h1.set_n(15);

  fib_heap_extract_min(h1);
  unsigned k = 15;
  fib_heap_decrease_key(h1, z2_c2, k);
  EXPECT_EQ(true, z2->get_mark());
  EXPECT_EQ(1, z2->get_degree());
  EXPECT_EQ(15, h1.get_min()->get_left()->get_key());
  // using an illegal value which is greater than current
  unsigned f = 69;
  EXPECT_THROW(fib_heap_decrease_key(h1, z2_c1_c, f), std::logic_error);
  // using a legal value
  unsigned j = 5;
  fib_heap_decrease_key(h1, z2_c1_c, j);
  EXPECT_EQ(5, h1.get_min()->get_key());
  EXPECT_EQ(2, y1->get_degree());
  EXPECT_EQ(2, x2_c1->get_degree());
  EXPECT_EQ(true, x2_c1->get_mark());
  EXPECT_EQ(true, x2_c1_c->get_mark());
  EXPECT_EQ(1, x2_c3->get_degree());
}

TEST(FibHeap, Delete)
{
  auto h1 = make_fib_heap<unsigned>();
  auto x1 = std::make_shared<FibNodeUnsigned>(23);
  fib_heap_insert(h1, x1);
  auto y1 = std::make_shared<FibNodeUnsigned>(7);
  fib_heap_insert(h1, y1);
  auto z1 = std::make_shared<FibNodeUnsigned>(21);
  fib_heap_insert(h1, z1);
  auto x2 = std::make_shared<FibNodeUnsigned>(3);
  auto x2_c1 = std::make_shared<FibNodeUnsigned>(18);
  fib_heap_list_add_child(x2_c1, x2);
  auto x2_c2 = std::make_shared<FibNodeUnsigned>(52);
  fib_heap_list_add_child(x2_c2, x2);
  auto x2_c3 = std::make_shared<FibNodeUnsigned>(38);
  fib_heap_list_add_child(x2_c3, x2);
  auto x2_c1_c = std::make_shared<FibNodeUnsigned>(39);
  fib_heap_list_add_child(x2_c1_c, x2_c1);
  auto x2_c3_c = std::make_shared<FibNodeUnsigned>(41);
  fib_heap_list_add_child(x2_c3_c, x2_c3);
  fib_heap_insert(h1, x2);
  auto y2 = std::make_shared<FibNodeUnsigned>(17);
  auto y2_c = std::make_shared<FibNodeUnsigned>(30);
  fib_heap_list_add_child(y2_c, y2);
  fib_heap_insert(h1, y2);
  auto z2 = std::make_shared<FibNodeUnsigned>(24);
  auto z2_c1 = std::make_shared<FibNodeUnsigned>(26);
  auto z2_c2 = std::make_shared<FibNodeUnsigned>(46);
  auto z2_c1_c = std::make_shared<FibNodeUnsigned>(35);
  fib_heap_list_add_child(z2_c1, z2);
  fib_heap_list_add_child(z2_c1_c, z2_c1);
  fib_heap_list_add_child(z2_c2, z2);
  fib_heap_insert(h1, z2);
  // statement below is just used for test(the whole heap is man-made)
  h1.set_n(15);

  unsigned k = 0;
  // back door for there is no way to make a negative infinite...
  // or need to define a class with a special data member
  fib_heap_delete(h1, x2_c2, k);
  // fib_heap_delete totally based on function extract_min and decrease_key
  // does not need detailed tests
  EXPECT_EQ(14, h1.get_n()); 
  EXPECT_NE(x2_c2, x2_c2->get_right()->get_left());
  EXPECT_NE(x2_c2, x2_c2->get_left()->get_right());
}
