#include <stdexcept>
#include <gtest/gtest.h>
#include "chapter-10/stack/stack.h"

using namespace CLRS;

TEST(Stack, EmptyStack)
{
  Stack<int, 10> s;
  EXPECT_TRUE(stack_empty(s));
  EXPECT_THROW(pop(s), std::underflow_error);
}

TEST(Stack, FullStack)
{
  Stack<int, 3> s;
  push(s, 1);
  push(s, 2);
  push(s, 3);
  EXPECT_THROW(push(s, 4), std::overflow_error);
}

TEST(Stack, NormalStack)
{
  Stack<int, 3> s;
  push(s, 1);
  push(s, 2);
  push(s, 3);
  EXPECT_EQ(3, pop(s));
  EXPECT_EQ(2, pop(s));
  EXPECT_EQ(1, pop(s));
  EXPECT_THROW(pop(s), std::underflow_error);
}
