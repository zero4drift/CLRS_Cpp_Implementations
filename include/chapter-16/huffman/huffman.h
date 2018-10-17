#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <utility>
#include <vector>
#include <bitset>
#include <memory>
#include "chapter-6/build_max_min_heap/build_max_min_heap.h"
#include "chapter-6/heap_priority_queue/heap_priority_queue.h"

namespace CLRS
{
  template <typename T>
  class HuffmanCodingNode
  {
    char c;
    T freq;
    std::shared_ptr<HuffmanCodingNode> left;
    std::shared_ptr<HuffmanCodingNode> right;
    bool leaf = true;
  public:
    HuffmanCodingNode(const char &x, const T &f):
      c(x), freq(f) {}
    HuffmanCodingNode(): leaf(false) {}
    T get_freq() const {return freq;}
    char get_char() const {return c;}
    std::shared_ptr<HuffmanCodingNode> get_left() const {return left;}
    std::shared_ptr<HuffmanCodingNode> get_right() const {return right;}
    void set_left(const std::shared_ptr<HuffmanCodingNode> &l) {left = l;}
    void set_right(const std::shared_ptr<HuffmanCodingNode> &r) {right = r;}
    void set_freq(T f) {freq = f;};
  };

  template <typename T>
  bool operator<(const std::shared_ptr<HuffmanCodingNode<T>> &h1,
		 const std::shared_ptr<HuffmanCodingNode<T>> &h2)
  {return h1->get_freq() < h2->get_freq();}

  template <typename T>
  bool operator>(const std::shared_ptr<HuffmanCodingNode<T>> &h1,
		 const std::shared_ptr<HuffmanCodingNode<T>> &h2)
  {return h1->get_freq() > h2->get_freq();}


  template <typename T>
  HuffmanCodingNode<T> huffman(std::vector
			       <std::shared_ptr<HuffmanCodingNode<T>>> &c)
  {
    std::size_t n = c.size();
    build_min_heap(c);
    for(std::size_t i = 1; i != n; ++i)
      {
	auto z = std::make_shared<HuffmanCodingNode<T>>();
	auto x = heap_extract_min(c);
	auto y = heap_extract_min(c);
	z->set_left(x);
	z->set_right(y);
	z->set_freq(x->get_freq() + y->get_freq());
	min_heap_insert(c, z);
      }
    return *heap_extract_min(c);
  }

  template <typename T, std::size_t n>
  char huffman_decode(const std::bitset<n> &b, const HuffmanCodingNode<T> &q)
  {
    HuffmanCodingNode<T> node = q;
    for(long long i = n - 1; i >= 0; --i)
      {
	bool direction = b[i];
	// direction 0: left, 1: right;
	if(!direction)
	  node = *node.get_left();
	else
	  node = *node.get_right(); 
      }
    return node.get_char();
  }
  
}


#endif
