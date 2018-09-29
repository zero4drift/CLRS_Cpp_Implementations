#include <stdexcept>
#include <gtest/gtest.h>
#include "chapter-10/queue/queue.h"

TEST(Queue, EmptyQueue)
{
  Queue<int, 4> q;
  EXPECT_THROW(dequeue(q), std::underflow_error);
}

TEST(Queue, FullQueue)
{
  Queue<int, 4> q;
  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);
  EXPECT_THROW(enqueue(q, 4), std::overflow_error);
}

TEST(Queue, Dequeue)
{
  Queue<int, 4> q;
  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);
  EXPECT_EQ(1, dequeue(q));
  EXPECT_EQ(2, dequeue(q));
  EXPECT_EQ(3, dequeue(q));
}

TEST(Queue, EnqueueDequeue)
{
  Queue<int, 4> q;
  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);
  dequeue(q);
  enqueue(q, 4);
  dequeue(q);
  enqueue(q, 5);
  dequeue(q);
  enqueue(q, 6);
  EXPECT_EQ(4, dequeue(q));
  EXPECT_EQ(5, dequeue(q));
  EXPECT_EQ(6, dequeue(q));
}
