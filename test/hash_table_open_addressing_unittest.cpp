#include <gtest/gtest.h>
#include <stdexcept>
#include "chapter-11/hash_table_open_addressing/hash_table_open_addressing.h"

using namespace CLRS;

TEST(HashTableOpenAddressing, HashFunction)
{
  auto result = hash_function_double<int, 701>(123456, 0);
  EXPECT_EQ(80, result);
}

TEST(HashTableOpenAddressing, InsertSearch)
{
  HashTableOpenAddressingNode<int> t[7];
  open_addressing_hash_insert(t, 1);
  open_addressing_hash_insert(t, 2);
  open_addressing_hash_insert(t, 3);
  open_addressing_hash_insert(t, 4);
  open_addressing_hash_insert(t, 5);
  open_addressing_hash_insert(t, 6);
  open_addressing_hash_insert(t, 7);
  EXPECT_THROW(open_addressing_hash_insert(t, 8), std::overflow_error);
  EXPECT_EQ(t[open_addressing_hash_search(t, 4)].get_value(), 4);
  // -1 means not found
  EXPECT_EQ(open_addressing_hash_search(t, 8), -1);
}

TEST(HashTableOpenAddressing, Delete)
{
  HashTableOpenAddressingNode<int> t[701];
  open_addressing_hash_insert(t, 123456);
  open_addressing_hash_insert(t, 123456);
  open_addressing_hash_delete(t, 123456);
  EXPECT_EQ(t[open_addressing_hash_search(t, 123456)].get_value(), 123456);
}
