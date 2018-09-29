#ifndef STACK_H
#define STACK_H


#include <utility>
#include <stdexcept>

template <typename T, std::size_t n> class Stack;

template <typename T, std::size_t n>
bool stack_empty(const Stack<T, n> &s)
{
  if(!s.top)
    return true;
  else
    return false;
}

template <typename T, std::size_t n>
void push(Stack<T, n> &s, T x)
{
  std::size_t l = s.top + 1;
  if(l > n)
    throw std::overflow_error("Stack size overflow.");
  s.top = l;
  s[s.top - 1] = x;
}

template <typename T, std::size_t n>
T pop(Stack<T, n> &s)
{
  if(stack_empty(s))
    throw std::underflow_error("Stack size underflow");
  --s.top;
  return s[s.top];
}

template <typename T, std::size_t n>
class Stack
{
  friend void push<T, n> (Stack<T, n> &, T);
  friend bool stack_empty<T, n> (const Stack<T, n> &);
  friend T pop<T, n> (Stack<T, n> &);
  T stack_array[n];
  std::size_t top = 0;
public:
  T &operator[](std::size_t i) {return stack_array[i];}
};


#endif
