#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H


#include <utility>
#include <chapter-10/tree/tree.h>

namespace CLRS
{
  // recursive version of search
  template <typename T>
  TreeNode<T> *tree_search(TreeNode<T> *x, T k)
  {
    if(x == nullptr || k == x->get_value())
      return x;
    if(k < x->get_value())
      return tree_search(x->get_left(), k);
    else
      return tree_search(x->get_right(), k);
  }

  // iterative version of serach
  template <typename T>
  TreeNode<T> *iterative_tree_search(TreeNode<T> *x, T k)
  {
    while(x != nullptr && k != x->get_value())
      {
	if(k < x->get_value())
	  x = x->get_left();
	else
	  x = x->get_right();
      }
    return x;
  }
  
  template <typename T>
  TreeNode<T> *tree_minimum(TreeNode<T> *x)
  {
    while(x->get_left() != nullptr)
      x = x->get_left();
    return x;
  }

  template <typename T>
  TreeNode<T> *tree_maximum(TreeNode<T> *x)
  {
    while(x->get_right() != nullptr)
      x = x->get_right();
    return x;
  }
  
  template <typename T>
  TreeNode<T> *tree_successor(TreeNode<T> *x)
  {
    if(x->get_right() != nullptr)
      return tree_minimum(x->get_right());
    TreeNode<T> *y = x->get_parent();
    while(y != nullptr && x == y->get_right())
      {
	x = y;
	y = y->get_parent();
      }
    return y;
  }

  template <typename T>
  TreeNode<T> *tree_predecessor(TreeNode<T> *x)
  {
    if(x->get_left() != nullptr)
      return tree_maximum(x->get_left());
    TreeNode<T> *y = x->get_parent();
    while(y != nullptr && x == y->get_left())
      {
	x = y;
	y = y->get_parent();
      }
    return y;
  }

  template <typename T>
  void tree_insert(Tree<T> *t, TreeNode<T> *z)
  {
    TreeNode<T> *y = nullptr;
    TreeNode<T> *x = t->get_root();
    while(x != nullptr)
      {
	y = x;
	if(z->get_value() < x->get_value())
	  x = x->get_left();
	else
	  x = x->get_right();
      }
    z->set_parent(y);
    if(y == nullptr)
      t->set_root(z);
    else if(z->get_value() < y->get_value())
      y->set_left(z);
    else
      y->set_right(z);
  }

  // update of left and right of v is caller's duty.
  template <typename T>
  void transplant(Tree<T> *t, TreeNode<T> *u, TreeNode<T> *v)
  {
    if(u->get_parent() == nullptr)
      t->set_root(v);
    else if(u == u->get_parent()->get_left())
      u->get_parent()->set_left(v);
    else
      u->get_parent()->set_right(v);
    if(v != nullptr)
      v->set_parent(u->get_parent());
  }

  template <typename T>
  void tree_delete(Tree<T> *t, TreeNode<T> *z)
  {
    if(z->get_left() == nullptr)
      transplant(t, z, z->get_right());
    else if(z->get_right() == nullptr)
      transplant(t, z, z->get_left());
    else
      {
	TreeNode<T> *y = tree_minimum(z->get_right());
	if(y->get_parent() != z)
	  {
	    transplant(t, y, y->get_right());
	    y->set_right(z->get_right());
	    y->get_right()->set_parent(y);
	  }
	transplant(t, z, y);
	y->set_left(z->get_left());
	y->get_left()->set_parent(y);
      }
  } 
}

#endif
