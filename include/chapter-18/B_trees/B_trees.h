#ifndef B_TREES_H
#define B_TREES_H


#include <utility>
// all b tree nodes allocated in heap, not disk.
#include <memory>

namespace CLRS
{
  template <typename T> class BTree;
  template <typename T> class BTreeNode;
  
  template <typename T>
  std::pair<BTreeNode<T> *, std::size_t> b_tree_search(BTreeNode<T> *x,
						       T k);
  template <typename T>
  void b_tree_create(BTree<T> *t);
  template <typename T>
  void b_tree_split_child(BTreeNode<T> *x, std::size_t i);
  template <typename T>
  void b_tree_insert(BTree<T> *t, T k);
  template <typename T>
  void b_tree_insert_nonfull(BTreeNode<T> *x, T k);
  template <typename T>
  void b_tree_delete(BTreeNode<T> *x, T k);
}


#endif
