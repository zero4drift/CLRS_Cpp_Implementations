#ifndef INTERVAL_TREE
#define INTERVAL_TREE


#include <utility>
#include "chapter-13/red_black_tree/red_black_tree.h"

namespace CLRS
{
  template <typename T> class IntervalTreeNode;

  template <typename T>
  struct Interval
  {
    T low;
    T high;
  };

  template <typename T>
  class IntervalTree
  {
    IntervalTreeNode<T> nil;
    IntervalTreeNode<T> *root;
  public:
    IntervalTree() {nil.set_color(REDBLACK_BLACK); root = &nil;}
    IntervalTreeNode<T> *get_root() {return root;}
    IntervalTreeNode<T> *get_nil() {return &nil;}
    void set_root(IntervalTreeNode<T> *r) {root = r;}
  };

  template <typename T>
  class IntervalTreeNode
  {
    Interval<T> inter;
    T max;
    char color;
    IntervalTreeNode *p = nullptr;
    IntervalTreeNode *left = nullptr;
    IntervalTreeNode *right = nullptr;
  public:
    IntervalTreeNode(Interval<T> i): inter(i) {}
    IntervalTreeNode() = default;
    char get_color() {return color;}
    Interval<T> get_interval() {return inter;}
    T get_value() {return inter.low;}
    T get_max() {return max;}
    IntervalTreeNode *get_p() {return p;}
    IntervalTreeNode *get_left() {return left;}
    IntervalTreeNode *get_right() {return right;}
    void set_p(IntervalTreeNode *parent) {p = parent;}
    void set_left(IntervalTreeNode *l) {left = l;}
    void set_right(IntervalTreeNode *r) {right = r;}
    void set_color(char c) {color = c;}
  };

  template <typename T>
  IntervalTreeNode<T> *interval_tree_search(IntervalTree<T> *t, Interval<T> i)
  {
    IntervalTreeNode<T> *x = t->get_root();
    while(x != t->get_nil() &&
	  (i.high < x->get_interval().low
	   || x->get_interval().high < i.low))
      {
	if(x->get_left() != t->get_nil()
	   && x->get_left()->get_max() >= i.low)
	  x = x->get_left();
	else
	  x = x->get_right();
      }
    return x;
  }
  
  template <typename T>
  IntervalTreeNode<T> *interval_tree_minimum(IntervalTreeNode<T> *null, IntervalTreeNode<T> *x)
  {
    while(x->get_left() != null)
      x = x->get_left();
    return x;
  }

  template <typename T>
  IntervalTreeNode<T> *interval_tree_maximum(IntervalTreeNode<T> *null, IntervalTreeNode<T> *x)
  {
    while(x->get_right() != null)
      x = x->get_right();
    return x;
  }
  
  template <typename T>
  IntervalTreeNode<T> *interval_tree_successor(IntervalTreeNode<T> *null, IntervalTreeNode<T> *x)
  {
    if(x->get_right() != null)
      return interval_tree_minimum(null, x->get_right());
    IntervalTreeNode<T> *y = x->get_p();
    while(y != null && x == y->get_right())
      {
	x = y;
	y = y->get_p();
      }
    return y;
  }

  template <typename T>
  IntervalTreeNode<T> *interval_tree_predecessor(IntervalTreeNode<T> *null, IntervalTreeNode<T> *x)
  {
    if(x->get_left() != null)
      return interval_tree_maximum(null, x->get_left());
    IntervalTreeNode<T> *y = x->get_p();
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
  void left_rotate(IntervalTree<T> *t, IntervalTreeNode<T> *x)
  {
    IntervalTreeNode<T> *y = x->get_right();
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
  void right_rotate(IntervalTree<T> *t, IntervalTreeNode<T> *x)
  {
    IntervalTreeNode<T> *y = x->get_left();
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
  void red_black_insert_fixup( IntervalTree<T> *t, IntervalTreeNode<T> *z)
  {
    while(z->get_p()->get_color() == REDBLACK_RED)
      {
	if(z->get_p() == z->get_p()->get_p()->get_left())
	  {
	    IntervalTreeNode<T> *y = z->get_p()->get_p()->get_right();
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
	    IntervalTreeNode<T> *y = z->get_p()->get_p()->get_left();
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
  void interval_tree_insert(IntervalTree<T> *t, IntervalTreeNode<T> *z)
  {
    IntervalTreeNode<T> *y = t->get_nil();
    IntervalTreeNode<T> *x = t->get_root();
    while(x != t->get_nil())
      {
	y = x;
	if(z->get_value() < x->get_value())
	  x = x->get_left();
	else
	  x = x->get_right();
      }
    z->set_p(y);
    if(y == t->get_nil())
      t->set_root(z);
    else if(z->get_value() < y->get_value())
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
  void red_black_transplant(IntervalTree<T> *t, IntervalTreeNode<T> *u, IntervalTreeNode<T> *v)
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
  void red_black_delete_fixup(IntervalTree<T> *t, IntervalTreeNode<T> *x)
  {
    IntervalTreeNode<T> *w;
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
  void interval_tree_delete(IntervalTree<T> *t, IntervalTreeNode<T> *z)
  {
    IntervalTreeNode<T> *y = z, *x;
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
	y = interval_tree_minimum(t->get_nil(), z->get_right());
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
