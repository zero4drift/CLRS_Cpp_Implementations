#ifndef FIBONACCI_H
#define FIBONACCI_H


#include <math.h>
#include <memory>
#include <utility>
#include <stdexcept>

namespace CLRS
{
  
  template <typename T>
  class FibHeap;
  template <typename T>
  class FibHeapTreeNode;

  template <typename T>
  FibHeap<T> make_fib_heap();
  template <typename T>
  void fib_heap_insert(const FibHeap<T> &,
		       const std::shared_ptr<FibHeapTreeNode<T>> &);
  template <typename T>
  std::shared_ptr<FibHeapTreeNode<T>>
  fib_heap_minimum(const FibHeap<T> &);
  template <typename T>
  FibHeap<T> fib_heap_union(const FibHeap<T> &, const FibHeap<T> &);
  template <typename T>
  std::shared_ptr<FibHeapTreeNode<T>> fib_heap_extract_min(FibHeap<T> &);
  template <typename T>
  void consolidate(FibHeap<T> &);
  template <typename T>
  void fib_heap_link(const FibHeap<T> &,
		     const std::shared_ptr<FibHeapTreeNode<T>> &,
		     const std::shared_ptr<FibHeapTreeNode<T>> &);
  template <typename T>
  void fib_heap_decrease_key(FibHeap<T> &,
			     const std::shared_ptr<FibHeapTreeNode<T>> &,
			     T);
  template <typename T>
  void cut(const FibHeap<T> &,
	   const std::shared_ptr<FibHeapTreeNode<T>> &,
	   const std::shared_ptr<FibHeapTreeNode<T>> &);
  template <typename T>
  void cascading_cut(const FibHeap<T> &,
		     const std::shared_ptr<FibHeapTreeNode<T>> &);
  template <typename T>
  void fib_heap_delete(FibHeap<T> &,
		       const std::shared_ptr<FibHeapTreeNode<T>> &);

  /*
   * doubly linked circular list helper functions
   */
  
  // just assign itself to the left and right of node. 
  template <typename T>
  void fib_heap_list_make(const std::shared_ptr<FibHeapTreeNode<T>> &x)
  {
    x->set_left(x);
    x->set_right(x);
  }

  // just link first to the second and the left of second
  template <typename T>
  void fib_heap_list_insert(const std::shared_ptr<FibHeapTreeNode<T>> &x,
			    const std::shared_ptr<FibHeapTreeNode<T>> &y)
  {
    x->set_right(y);
    x->set_left(y->get_left());
    y->get_left()->set_right(x);
    y->set_left(x);
  }

  // just need the removing node as parameter, link its left and right
  template <typename T>
  void fib_heap_list_remove(const std::shared_ptr<FibHeapTreeNode<T>> &x)
  {
    x->get_left()->set_right(x->get_right());
    x->get_right()->set_left(x->get_left());
  }
  
  // make the first a child of the second, increase second's degree
  template <typename T>
  void fib_heap_list_add_child(
			       const std::shared_ptr<FibHeapTreeNode<T>> &x,
			       const std::shared_ptr<FibHeapTreeNode<T>> &y)
  {
    if(y->get_child() != nullptr)
      {
	fib_heap_list_insert(x, y->get_child());
	x->set_p(y);
      }
    else
      {
	fib_heap_list_make(x);
	y->set_child(x);
	x->set_p(y);
      }
    y->incr_degree();
  }
  
  // make the first not a child of the second, decrease second's degree
  template <typename T>
  void fib_heap_list_remove_child(
				  const std::shared_ptr<FibHeapTreeNode<T>> &x,
				  const std::shared_ptr<FibHeapTreeNode<T>> &y)
  {
    fib_heap_list_remove(x);
    if(x->get_right() == x)
      y->set_child(nullptr);
    else
      y->set_child(x->get_right());
    y->decr_degree(); 
  }

  /*
   * calculate maxmum degreee based on amount of nodes
   */
  std::size_t fib_maximum_degree(std::size_t n)
  {
    // loga(b) = log2(b) / log2(a)
    double gold = (1 + std::sqrt(2)) / 2;
    double below = std::log2(gold);
    double top = std::log2(n);
    return top / below;
  } 

  template <typename T>
  class FibHeap
  {
  public:
    using FibNodeSHPTR = std::shared_ptr<FibHeapTreeNode<T>>;
    FibHeap() = default;
    std::size_t get_n() const {return n;}
    FibNodeSHPTR get_min() const {return min;}
    void incr_n() {++n;}
    void decr_n() {--n;}
    void set_n(std::size_t m) {n = m;}
    void set_min(FibNodeSHPTR m) {min = m;}
  private:
    std::size_t n = 0;
    FibNodeSHPTR min = nullptr;
  };

  template <typename T>
  class FibHeapTreeNode
  {
  public:
    using FibNodeSHPTR = std::shared_ptr<FibHeapTreeNode>;
    FibHeapTreeNode() = default;
    FibHeapTreeNode(T k): key(k) {}
    T get_key() const {return key;}
    void set_key(T k) {key = k;}
    bool get_mark() const {return mark;}
    void set_mark() {mark = true;}
    void clear_mark() {mark = false;}
    std::size_t get_degree() const {return degree;}
    void incr_degree() {++degree;}
    void decr_degree() {--degree;}
    FibNodeSHPTR get_p() const {return p;}
    void set_p(const FibNodeSHPTR &parent) {p = parent;}
    FibNodeSHPTR get_child() const {return child;}
    void set_child(const FibNodeSHPTR &c) {child = c;}
    FibNodeSHPTR get_left() const {return left;}
    void set_left(const FibNodeSHPTR &l) {left = l;}
    FibNodeSHPTR get_right() const {return right;}
    void set_right(const FibNodeSHPTR &r) {right = r;}
  private:
    T key;
    bool mark = false;
    std::size_t degree = 0;
    FibNodeSHPTR p = nullptr;
    FibNodeSHPTR child = nullptr;
    FibNodeSHPTR left = nullptr;
    FibNodeSHPTR right = nullptr;
  };

  template <typename T>
  FibHeap<T> make_fib_heap()
  {
    return FibHeap<T>();
  }

  template <typename T>
  void fib_heap_insert(FibHeap<T> &h,
		       const std::shared_ptr<FibHeapTreeNode<T>> &x)
  {
    if(h.get_min() == nullptr)
      {
	fib_heap_list_make(x);
	h.set_min(x);
      }
    else
      {
	fib_heap_list_insert(x, h.get_min());
	if(x->get_key() < h.get_min()->get_key())
	  h.set_min(x);
      }
    h.incr_n();
  }

  template <typename T>
  std::shared_ptr<FibHeapTreeNode<T>>
  fib_heap_minimum(const FibHeap<T> &h)
  {
    return h.get_min();
  }

  template <typename T>
  FibHeap<T> fib_heap_union(const FibHeap<T> &h1, const FibHeap<T> &h2)
  {
    FibHeap<T> h;
    h.set_min(h1.get_min());
    auto h_min = h.get_min();
    auto h2_n = h2.get_min();
    // concatenate
    if(h_min == nullptr)
      h.set_min(h2_n);
    else if(h2_n != nullptr)
      do
	{
	  auto temp = h2_n;
	  h2_n = h2_n->get_right();
	  fib_heap_list_insert(temp, h_min);
	}
      while(h2_n != h2.get_min());
    if(h2.get_min() != nullptr && h1.get_min() != nullptr &&
       h2.get_min()->get_key() < h1.get_min()->get_key())
      h.set_min(h2.get_min());
    h.set_n(h1.get_n() + h2.get_n());
    return h;
  }

  template <typename T>
  std::shared_ptr<FibHeapTreeNode<T>> fib_heap_extract_min(FibHeap<T> &h)
  {
    auto z = h.get_min();
    if(z != nullptr)
      {
	auto n = z->get_child();
	for(std::size_t d = 1; d <= z->get_degree(); ++d)
	  {
	    auto temp = n->get_right();
	    fib_heap_list_insert(n, z);
	    n->set_p(nullptr);
	    n = temp;
	  }
	fib_heap_list_remove(z);
	if(z->get_right() == z)
	  h.set_min(nullptr);
	else
	  {
	    h.set_min(z->get_right());
	    consolidate(h);
	  }
	h.decr_n();
      }
    return z;
  }

  template <typename T>
  void consolidate(FibHeap<T> &h)
  {
    std::size_t max_degree = fib_maximum_degree(h.get_n());
    std::shared_ptr<FibHeapTreeNode<T>> a[max_degree + 1];
    auto w = h.get_min();
    /* 
     * the reason why the former commit of code below causes a bug:
     * the min of fib heap may be removed from the root list
     * and then the former while loop is infinite. 
     * Fix: compute the length of root list and take it as the while contition
     * TODO: data root list length better stored in class FibHeap
     */
    std::size_t root_list_len = 0;
    do
      {
	++root_list_len;
	w = w->get_right();
      }
    while(w != h.get_min());
    // handle each node of root list
    while(root_list_len != 0)
      {
	auto x = w;
	w = w->get_right();
	std::size_t d = x->get_degree();
	while(a[d] != nullptr)
	  {
	    auto y = a[d];
	    if(y->get_key() < x->get_key())
	      {
		auto temp = x;
		x = y;
		y = temp;
	      }
	    fib_heap_link(h, y, x);
	    a[d] = nullptr;
	    ++d;
	  }
	a[d] = x;
	--root_list_len;
      }
    // now the root list must be reconstructed
    h.set_min(nullptr);
    for(std::size_t i = 0; i <= max_degree; ++i)
      {
	if(a[i] != nullptr)
	  {
	    if(h.get_min() == nullptr)
	      {
		fib_heap_list_make(a[i]);
		h.set_min(a[i]);
	      }
	    else
	      {
		fib_heap_list_insert(a[i], h.get_min());
		if(a[i]->get_key() < h.get_min()->get_key())
		  h.set_min(a[i]);
	      }
	  }
      }
  }

  template <typename T>
  void fib_heap_link(const FibHeap<T> &h,
		     const std::shared_ptr<FibHeapTreeNode<T>> &y,
		     const std::shared_ptr<FibHeapTreeNode<T>> &x)
  {
    fib_heap_list_remove(y);
    fib_heap_list_add_child(y, x);
    y->clear_mark();
  }

  template <typename T>
  void fib_heap_decrease_key(FibHeap<T> &h,
			     const std::shared_ptr<FibHeapTreeNode<T>> &x,
			     T k)
  {
    if(x->get_key() < k)
      throw std::logic_error("new key is greater than current key");
    x->set_key(k);
    auto y = x->get_p();
    if(y != nullptr && x->get_key() < y->get_key())
      {
	cut(h, x, y);
	cascading_cut(h, y);
      }
    if(x->get_key() < h.get_min()->get_key())
      h.set_min(x);
  }
  
  template <typename T>
  void cut(const FibHeap<T> &h,
	   const std::shared_ptr<FibHeapTreeNode<T>> &x,
	   const std::shared_ptr<FibHeapTreeNode<T>> &y)
  {
    fib_heap_list_remove_child(x, y);
    fib_heap_list_insert(x, h.get_min());
    x->set_p(nullptr);
    x->clear_mark();
  }
  
  template <typename T>
  void cascading_cut(const FibHeap<T> &h,
		     const std::shared_ptr<FibHeapTreeNode<T>> &y)
  {
    auto z = y->get_p();
    if(z != nullptr)
      {
	if(!y->get_mark())
	  y->set_mark();
	else
	  {
	    cut(h, y, z);
	    cascading_cut(h, z);
	  }
      }
  }

  template <typename T>
  void fib_heap_delete(FibHeap<T> &h,
		       const std::shared_ptr<FibHeapTreeNode<T>> &x,
		       T k)
  {
    fib_heap_decrease_key(h, x, k);
    fib_heap_extract_min(h);
  } 
}


#endif
