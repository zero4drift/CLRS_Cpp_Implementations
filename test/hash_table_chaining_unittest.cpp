#include <gtest/gtest.h>
#include "chapter-11/hash_table_chaining/hash_table_chaining.hpp"

using namespace CLRS;

TEST(HashTableChaining, HashFunction)
{
  HashTableChaining<int, 12, 12, 4> t;
  EXPECT_EQ(10, t.hash_function_division(10));
  EXPECT_EQ(2, t.hash_function_multiply(10));
}

TEST(HashTableChaining, InsertSearchDelete)
{
  HashTableChaining<int, 12, 12, 4> t;
  ListNode<int> n1(1);
  ListNode<int> n2(2);
  ListNode<int> n3(3);
  ListNode<int> n4(4);
  ListNode<int> n5(5);
  ListNode<int> n6(6);
  ListNode<int> n7(13);
  chained_hash_insert(t, n1);
  chained_hash_insert(t, n2);
  chained_hash_insert(t, n3);
  chained_hash_insert(t, n4);
  chained_hash_insert(t, n5);
  chained_hash_insert(t, n6);
  chained_hash_insert(t, n7);
  EXPECT_EQ(13, chained_hash_search(t, 13)->get_value());
  EXPECT_EQ(5, chained_hash_search(t, 5)->get_value());
  EXPECT_EQ(nullptr, chained_hash_search(t, 14));
  chained_hash_delete(t, n7);
  EXPECT_EQ(nullptr, chained_hash_search(t, 13));
}
