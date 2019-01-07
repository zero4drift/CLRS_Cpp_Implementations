/* 
 * Since auxiliary hash functions for linear probing and
 * quadratic probing hash functions are not illustrated in text, 
 * both would not be implemented here.
 */
#ifndef HASH_TABLE_OPEN_ADDRESSING_H
#define HASH_TABLE_OPEN_ADDRESSING_H


#include <utility>
#include <stdexcept>
#include <iostream>

namespace CLRS
{
  // m must be a prime number in this implementation
  template <typename T>
  class HashTableOpenAddressingNode
  {
    T key;
    bool occupied = false;
    bool deleted = false;
  public:
    T get_value() {return key;}
    void set_value(T k) {key = k; occupied = true; deleted = false;}
    void del_value() {deleted = true;}
    bool is_occupied() {return occupied;}
    bool is_deleted() {return deleted;}
  };

  // m must be a prime number in this implementation
  template <typename T, std::size_t m>
  std::size_t hash_function_double(T key, std::size_t i)
  {
    std::size_t first_part = key % m;
    std::size_t second_part = 1 + (key % (m - 1));
    return (first_part + i * second_part) % m;
  }

  template <typename T, std::size_t m>
  std::size_t open_addressing_hash_insert(HashTableOpenAddressingNode<T> (&t)[m], T key)
  {
    std::size_t i = 0;
    while(i != m)
      {
	std::size_t j = hash_function_double<T, m>(key, i);
	if(!t[j].is_occupied() || t[j].is_deleted())
	  {
	    t[j].set_value(key);
	    return j;
	  }
	else
	  ++i;
      }
    throw std::overflow_error("Hash table is overflow");
  }

  /*
   * return -1 it search failed
   * return type is long long which is able to store maximum std::size_t 
   */
  template <typename T, std::size_t m>
  long long open_addressing_hash_search(HashTableOpenAddressingNode<T> (&t)[m], std::size_t key)
  {
    std::size_t i = 0;
    std::size_t j = 0;
    do
      {
	j = hash_function_double<T, m>(key, i);
	if(t[j].is_deleted())
	  ;
	else if(t[j].get_value() == key)
	  return j;
	++i;
      }
    while(t[j].is_occupied() && i != m);
    return -1;
  }

  template <typename T, std::size_t m>
  void open_addressing_hash_delete(HashTableOpenAddressingNode<T> (&t)[m], std::size_t key)
  {
    std::size_t i = 0;
    std::size_t j = 0;
    do
      {
	j = hash_function_double<T, m>(key, i);
	if(t[j].is_deleted())
	  ;
	else if(t[j].get_value() == key)
	  {
	    t[j].del_value();
	    return;
	  } 
	++i;
      }
    while(t[j].is_occupied() && i != m);
  }
}


#endif
