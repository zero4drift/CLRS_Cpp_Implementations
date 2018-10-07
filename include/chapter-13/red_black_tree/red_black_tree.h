#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <iostream>
using std::cout;
using std::endl;

namespace CLRS

{
  constexpr char REDBLACK_RED = 'R';
  constexpr char REDBLACK_BLACK = 'B';
  template <typename T> class RedBlackTreeNode;

  template <typename T>
  class RedBlackTree
  {
    RedBlackTreeNode<T> nil;
    RedBlackTreeNode<T> *root;
  public:
    RedBlackTree() {nil.set_color(REDBLACK_BLACK); root = &nil;}
    RedBlackTreeNode<T> *get_root() {return root;}
    RedBlackTreeNode<T> *get_nil() {return &nil;}
    void set_root(RedBlackTreeNode<T> *r) {root = r;}
  };

  template <typename T>
  class RedBlackTreeNode
  {
    T key;
    char color;
    RedBlackTreeNode *p = nullptr;
    RedBlackTreeNode *left = nullptr;
    RedBlackTreeNode *right = nullptr;
  public:
    RedBlackTreeNode(T k): key(k) {}
    RedBlackTreeNode() = default;
    T get_key() {return key;}
    char get_color() {return color;}
    T get_value() {return key;}
    RedBlackTreeNode *get_p() {return p;}
    RedBlackTreeNode *get_left() {return left;}
    RedBlackTreeNode *get_right() {return right;}
    void set_p(RedBlackTreeNode *parent) {p = parent;}
    void set_left(RedBlackTreeNode *l) {left = l;}
    void set_right(RedBlackTreeNode *r) {right = r;}
    void set_color(char c) {color = c;}
  };

  template <typename T>
  RedBlackTreeNode<T> *red_black_tree_search(RedBlackTreeNode<T> *null, RedBlackTreeNode<T> *x, T k)
  {
    if(x == null || k == x->get_value())
      return x;
    if(k < x->get_value())
      return red_black_tree_search(null, x->get_left(), k);
    else
      return red_black_tree_search(null, x->get_right(), k);
  }

  // iterative version of serach
  template <typename T>
  RedBlackTreeNode<T> *iterative_red_black_tree_search(RedBlackTreeNode<T> *null, RedBlackTreeNode<T> *x, T k)
  {
    while(x != null && k != x->get_value())
      {
	if(k < x->get_value())
	  x = x->get_left();
	else
	  x = x->get_right();
      }
    return x;
  }
  
  template <typename T>
  RedBlackTreeNode<T> *red_black_tree_minimum(RedBlackTreeNode<T> *null, RedBlackTreeNode<T> *x)
  {
    while(x->get_left() != null)
      x = x->get_left();
    return x;
  }

  template <typename T>
  RedBlackTreeNode<T> *red_black_tree_maximum(RedBlackTreeNode<T> *null, RedBlackTreeNode<T> *x)
  {
    while(x->get_right() != null)
      x = x->get_right();
    return x;
  }
  
  template <typename T>
  RedBlackTreeNode<T> *red_black_tree_successor(RedBlackTreeNode<T> *null, RedBlackTreeNode<T> *x)
  {
    if(x->get_right() != null)
      return red_black_tree_minimum(null, x->get_right());
    RedBlackTreeNode<T> *y = x->get_p();
    while(y != null && x == y->get_right())
      {
	x = y;
	y = y->get_p();
      }
    return y;
  }

  template <typename T>
  RedBlackTreeNode<T> *red_black_tree_predecessor(RedBlackTreeNode<T> *null, RedBlackTreeNode<T> *x)
  {
    if(x->get_left() != null)
      return red_black_tree_maximum(null, x->get_left());
    RedBlackTreeNode<T> *y = x->get_p();
    while(y != null && x == y->get_left())
      {
	x = y;
	y = y->get_p();
      }
    return y;
  }

  /* 
   * helper functions for insert and delete
   * to keep red black tree legal.
   */
  template <typename T>
  void left_rotate(RedBlackTree<T> *t, RedBlackTreeNode<T> *x)
  {
    RedBlackTreeNode<T> *y = x->get_right();
    x->set_right(y->get_left());
    if(y->get_left() != t->get_nil())
      y->get_left()->set_p(x);
    y->set_p(x->get_p());
    if(x->get_p() == t->get_nil())
      t->set_root(y);
    else if(x == x->get_p()->get_left())
      x->get_p()->set_left(y);
    else x->get_p()->set_right(y);
    y->set_left(x);
    x->set_p(y);
  }

  template <typename T>
  void right_rotate(RedBlackTree<T> *t, RedBlackTreeNode<T> *x)
  {
    RedBlackTreeNode<T> *y = x->get_left();
    x->set_left(y->get_right());
    if(y->get_right() != t->get_nil())
      y->get_right()->set_p(x);
    y->set_p(x->get_p());
    if(x->get_p() == t->get_nil())
      t->set_root(y);
    else if(x == x->get_p()->get_left())
      x->get_p()->set_left(y);
    else x->get_p()->set_right(y);
    y->set_right(x);
    x->set_p(y);  
  }

  template <typename T>
  void red_black_insert_fixup(RedBlackTree<T> *t, RedBlackTreeNode<T> *z)
  {
    while(z->get_p()->get_color() == REDBLACK_RED)
      {
	if(z->get_p() == z->get_p()->get_p()->get_left())
	  {
	    RedBlackTreeNode<T> *y = z->get_p()->get_p()->get_right();
	    if(y->get_color() == REDBLACK_RED)
	      {
		z->get_p()->set_color(REDBLACK_BLACK);
		y->set_color(REDBLACK_BLACK);
		z->get_p()->get_p()->set_color(REDBLACK_RED);
		z = z->get_p()->get_p();
		continue;
	      }
	    else if(z == z->get_p()->get_right())
	      {
		z = z->get_p();
		left_rotate(t, z);
	      }
	    z->get_p()->set_color(REDBLACK_BLACK);
	    z->get_p()->get_p()->set_color(REDBLACK_RED);
	    right_rotate(t, z->get_p()->get_p());
	  }
	else if(z->get_p() == z->get_p()->get_p()->get_right())
	  {
	    RedBlackTreeNode<T> *y = z->get_p()->get_p()->get_left();
	    if(y->get_color() == REDBLACK_RED)
	      {
		z->get_p()->set_color(REDBLACK_BLACK);
		y->set_color(REDBLACK_BLACK);
		z->get_p()->get_p()->set_color(REDBLACK_RED);
		z = z->get_p()->get_p();
		continue;
	      }
	    else if(z == z->get_p()->get_left())
	      {
		z = z->get_p();
		right_rotate(t, z);
	      }
	    z->get_p()->set_color(REDBLACK_BLACK);
	    z->get_p()->get_p()->set_color(REDBLACK_RED);
	    left_rotate(t, z->get_p()->get_p());
	  }
	t->get_root()->set_color(REDBLACK_BLACK);
      }
  }

  template <typename T>
  void red_black_tree_insert(RedBlackTree<T> *t, RedBlackTreeNode<T> *z)
  {
    RedBlackTreeNode<T> *y = t->get_nil();
    RedBlackTreeNode<T> *x = t->get_root();
    while(x != t->get_nil())
      {
	y = x;
	if(z->get_key() < x->get_key())
	  x = x->get_left();
	else
	  x = x->get_right();
      }
    z->set_p(y);
    if(y == t->get_nil())
      t->set_root(z);
    else if(z->get_key() < y->get_key())
      y->set_left(z);
    else
      y->set_right(z);
    z->set_left(t->get_nil());
    z->set_right(t->get_nil());
    z->set_color(REDBLACK_RED);
    red_black_insert_fixup(t, z);
  }

  // helper functions for red_black_delete
  template <typename T>
  void red_black_transplant(RedBlackTree<T> *t, RedBlackTreeNode<T> *u, RedBlackTreeNode<T> *v)
  {
    if(u->get_p() == t->get_nil())
      t->set_root(v);
    else if(u == u->get_p()->get_left())
      u->get_p()->set_left(v);
    else
      u->get_p()->set_right(v);
    v->set_p(u->get_p());
  }

  template <typename T>
  void red_black_delete_fixup(RedBlackTree<T> *t, RedBlackTreeNode<T> *x)
  {
    RedBlackTreeNode<T> *w;
    while(x != t->get_nil() && x->get_color() == REDBLACK_BLACK)
      if(x == x->get_p()->get_left())
	{
	  w = x->get_p()->get_right();
	  if(w->get_color() == REDBLACK_RED)
	    {
	      w->set_color(REDBLACK_BLACK);
	      x->get_p()->set_color(REDBLACK_RED);
	      left_rotate(t, x->get_p());
	      w = x->get_p()->get_right(); 
	    }
	  if(w->get_left()->get_color() == REDBLACK_BLACK
	     && w->get_right()->get_color() == REDBLACK_BLACK)
	    {
	      w->set_color(REDBLACK_RED);
	      x = x->get_p();
	      continue;
	    }
	  else if(w->get_right()->get_color() == REDBLACK_BLACK)
	    {
	      w->get_left()->set_color(REDBLACK_BLACK);
	      w->set_color(REDBLACK_RED);
	      right_rotate(t, w);
	      w = x->get_p()->get_right();
	    }
	  w->set_color(x->get_p()->get_color());
	  x->get_p()->set_color(REDBLACK_BLACK);
	  left_rotate(t, x->get_p());
	  x = t->get_root();
	}
      else if(x == x->get_p()->get_right())
	{
	  w = x->get_p()->get_left();
	  if(w->get_color() == REDBLACK_RED)
	    {
	      w->set_color(REDBLACK_BLACK);
	      x->get_p()->set_color(REDBLACK_RED);
	      right_rotate(t, x->get_p());
	      w = x->get_p()->get_left(); 
	    }
	  if(w->get_right()->get_color() == REDBLACK_BLACK
	     && w->get_left()->get_color() == REDBLACK_BLACK)
	    {
	      w->set_color(REDBLACK_RED);
	      x = x->get_p();
	      continue;
	    }
	  else if(w->get_left()->get_color() == REDBLACK_BLACK)
	    {
	      w->get_right()->set_color(REDBLACK_BLACK);
	      w->set_color(REDBLACK_RED);
	      left_rotate(t, w);
	      w = x->get_p()->get_left();
	    }
	  w->set_color(x->get_p()->get_color());
	  x->get_p()->set_color(REDBLACK_BLACK);
	  right_rotate(t, x->get_p());
	  x = t->get_root();
	}
    x->set_color(REDBLACK_BLACK);
  }

  template <typename T>
  void red_black_tree_delete(RedBlackTree<T> *t, RedBlackTreeNode<T> *z)
  {
    RedBlackTreeNode<T> *y = z, *x;
    char y_original_color = y->get_color();
    if(z->get_left() == t->get_nil())
      {
	x = z->get_right();
	red_black_transplant(t, z, z->get_right());
      }
    else if(z->get_right() == t->get_nil())
      {
	x = z->get_left();
	red_black_transplant(t, z, z->get_left());
      }
    else
      {
	y = red_black_tree_minimum(t->get_nil(), z->get_right());
	y_original_color = y->get_color();
	x = y->get_right();
	if(y->get_p() == z)
	  x->set_p(y);		// why
	else
	  {
	    red_black_transplant(t, y, y->get_right());
	    y->set_right(z->get_right());
	    y->get_right()->set_p(y);
	  }
	red_black_transplant(t, z, y);
	y->set_left(z->get_left());
	y->get_left()->set_p(y);
	y->set_color(z->get_color());
      }
    if(y_original_color == REDBLACK_BLACK)
      red_black_delete_fixup(t, x);
  }
}


#endif
