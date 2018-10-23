#ifndef FIBONACCI_H
#define FIBONACCI_H


#include <memory>
#include <utility>

namespace CLRS
{
  template <typename T>
  class FiboHeap;
  template <typename T>
  class FiboHeapTreeNode;

  template <typename T>
  FiboHeap<T> make_fib_heap();
  template <typename T>
  void fib_heap_insert(const FiboHeap<T> &,
		       const std::shared_ptr<FiboHeapTreeNode<T>> &);
  template <typename T>
  std::shared_ptr<FiboHeapTreeNode<T>>
  fib_heap_minimum(const FiboHeap<T> &);
  template <typename T>
  FiboHeap<T> fib_heap_union(const FiboHeap<T> &, const FiboHeap<T> &);
  template <typename T>
  std::shared_ptr<FiboHeapTreeNode<T>> fib_heap_extract_min(FiboHeap<T> &);
  template <typename T>
  void consolicate(FiboHeap<T> &);
  template <typename T>
  void fib_heap_link(const FiboHeap<T> &,
		     const std::shared_ptr<FiboHeapTreeNode<T>> &,
		     const std::shared_ptr<FiboHeapTreeNode<T>> &);
  template <typename T>
  void fib_heap_decrease_key(FiboHeap<T> &,
			     const std::shared_ptr<FiboHeapTreeNode<T>> &,
			     T);
  template <typename T>
  void cut(const FiboHeap<T> &,
	   const std::shared_ptr<FiboHeapTreeNode<T>> &,
	   const std::shared_ptr<FiboHeapTreeNode<T>> &);
  template <typename T>
  void cascading_cut(const FiboHeap<T> &,
		     const std::shared_ptr<FiboHeapTreeNode<T>>);
  // just assign itself to the left and right of node. 
  template <typename T>
  void fib_heap_list_make(const std::shared_ptr<FiboHeapTreeNode<T>> &);
  // just link first to the second and the left of second
  template <typename T>
  void fib_heap_list_insert(const std::shared_ptr<FiboHeapTreeNode<T>> &,
			    const std::shared_ptr<FiboHeapTreeNode<T>> &);
  // just need the removing node as parameter, link its left and right
  template <typename T>
  void fib_heap_list_remove(const std::shared_ptr<FiboHeapTreeNode<T>> &);
  // make the first a child of the second, increase second's degree
  template <typename T>
  void fib_heap_list_add_child(
				const std::shared_ptr<FiboHeapTreeNode<T>> &,
				const std::shared_ptr<FiboHeapTreeNode<T>> &);
  // make the first not a child of the second, decrease second's degree
  template <typename T>
  void fib_heap_list_remove_child(
				const std::shared_ptr<FiboHeapTreeNode<T>> &,
				const std::shared_ptr<FiboHeapTreeNode<T>> &);

}


#endif
