#ifndef HASH_TABLE_CHAINING_H
#define HASH_TABLE_CHAINING_H


#include <utility>
#include "chapter-10/list/list.h"

namespace CLRS
{
  template <typename T, std::size_t m, std::size_t m_d, std::size_t p_m>
  class HashTableChaining;

  template <typename T, std::size_t m, std::size_t m_d, std::size_t p_m>
  void chained_hash_insert(HashTableChaining<T, m, m_d, p_m> &, ListNode<T> &);
  template <typename T, std::size_t m, std::size_t m_d, std::size_t p_m>
  ListNode<T> *chained_hash_search(HashTableChaining<T, m, m_d, p_m> &, T);
  template <typename T, std::size_t m, std::size_t m_d, std::size_t p_m>
  void chained_hash_delete(HashTableChaining<T, m, m_d, p_m> &, ListNode<T> &);

  template <typename T, std::size_t m, std::size_t m_d, std::size_t p_m>
  class HashTableChaining
  {
    List<T> array[m];
  public:
    List<T> &operator[](std::size_t i) {return array[i];}
    /* template needs explicitly instanced
     * with template non-type parameter m,
     * m is a prime number which is not close
     * to any power of 2.
     */
    std::size_t hash_function_division(T key)
    {
      return key % m_d;
    }

    /* template needs explicitly instanced
     * with template non-type parameter p,
     * p is a integer number which is used
     * to calculate a integer: 2^p
     */
    std::size_t hash_function_multiply(T key)
    { 
      double A = 0.6180339887;
      std::size_t f_m = 1 << p_m; 
      double multi = key * A;
      T int_part = multi;
      double dec_part = multi - int_part;
      return dec_part * f_m; 
    }
  };
  
  template <typename T, std::size_t m, std::size_t m_d, std::size_t p_m>
  void chained_hash_insert(HashTableChaining<T, m, m_d, p_m> &t, ListNode<T> &n)
  {
    std::size_t i = t.hash_function_division(n.get_value());
    list_insert(t[i], n);
  }

  template <typename T, std::size_t m, std::size_t m_d, std::size_t p_m>
  ListNode<T> *chained_hash_search(HashTableChaining<T, m, m_d, p_m> &t, T key)
  {
    std::size_t i = t.hash_function_division(key);
    return list_search(t[i], key);
  }

  template <typename T, std::size_t m, std::size_t m_d, std::size_t p_m>
  void chained_hash_delete(HashTableChaining<T, m, m_d, p_m> &t, ListNode<T> &n)
  {
    std::size_t i = t.hash_function_division(n.get_value());
    list_delete(t[i], n);
  }
}


#endif
