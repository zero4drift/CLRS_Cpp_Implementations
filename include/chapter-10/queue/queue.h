#ifndef QUEUE_H
#define QUEUE_H


#include <utility>
#include <stdexcept>

template <typename T, std::size_t n>
class Queue;

template <typename T, std::size_t n>
void enqueue(Queue<T, n> &, T);

template <typename T, std::size_t n>
T dequeue(Queue<T, n> &);

template <typename T, std::size_t n>
class Queue
{
  friend void enqueue<T, n> (Queue<T, n> &, T);
  friend T dequeue<T, n> (Queue<T, n> &);
  T queue_array[n];
  std::size_t head = 0;
  std::size_t tail = 0;
public:
  T &operator[](std::size_t i) {return queue_array[i];}
};

template <typename T, std::size_t n>
void enqueue(Queue<T, n> &q, T x)
{
  if((q.tail + 1 == q.head) || (q.tail + 1 - n == q.head))
    throw std::overflow_error("Queue is overflow");
  q[q.tail] = x;
  if(q.tail == n - 1)
    q.tail = 0;
  else
    ++q.tail;
}

template <typename T, std::size_t n>
T dequeue(Queue<T, n> &q)
{
  if(q.tail == q.head)
    throw std::underflow_error("Queue is underflow");
  T x = q[q.head];
  if(q.head == n - 1)
    q.head = 0;
  else
    ++q.head;
  return x;
}


#endif
