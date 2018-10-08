#ifndef ORDER_STATISTIC_TREE
#define ORDER_STATISTIC_TREE


#include <utility>
#include "chapter-13/red_black_tree/red_black_tree.h"

namespace CLRS
{
  template <typename T> class OrderStatisticTreeNode;

  template <typename T>
  class OrderStatisticTree
  {
    OrderStatisticTreeNode<T> nil;
    OrderStatisticTreeNode<T> *root;
  public:
    OrderStatisticTree()
    {nil.set_color(REDBLACK_BLACK); nil.set_size(0); root = &nil;}
    OrderStatisticTreeNode<T> *get_root() {return root;}
    OrderStatisticTreeNode<T> *get_nil() {return &nil;}
    void set_root(OrderStatisticTreeNode<T> *r) {root = r;}
  };

  template <typename T>
  class OrderStatisticTreeNode
  {
    T key;
    char color;
    std::size_t size = 1;
    OrderStatisticTreeNode *p = nullptr;
    OrderStatisticTreeNode *left = nullptr;
    OrderStatisticTreeNode *right = nullptr;
  public:
    OrderStatisticTreeNode(T k): key(k) {}
    OrderStatisticTreeNode() = default;
    T get_key() {return key;}
    char get_color() {return color;}
    T get_value() {return key;}
    std::size_t get_size() {return size;}
    OrderStatisticTreeNode *get_p() {return p;}
    OrderStatisticTreeNode *get_left() {return left;}
    OrderStatisticTreeNode *get_right() {return right;}
    void set_p(OrderStatisticTreeNode *parent) {p = parent;}
    void set_left(OrderStatisticTreeNode *l) {left = l;}
    void set_right(OrderStatisticTreeNode *r) {right = r;}
    void set_color(char c) {color = c;}
    void set_size(std::size_t s) {size = s;}
  };

  template <typename T>
  OrderStatisticTreeNode<T> *order_statistic_select(OrderStatisticTreeNode<T> *x, std::size_t i)
  {
    std::size_t r = x->get_left()->get_size() + 1;
    if(i == r)
      return x;
    else if(i < r)
      return order_statistic_select(x->get_left(), i);
    else
      return order_statistic_select(x->get_right(), i - r);
  }

  template <typename T>
  std::size_t order_statistic_rank(OrderStatisticTree<T> *t, OrderStatisticTreeNode<T> *x)
  {
    std::size_t r = x->get_left()->get_size() + 1;
    OrderStatisticTreeNode<T> *y = x;
    while(y != t->get_nil())
      {
	if(y == y->get_p()->get_right())
	  r += y->get_p()->get_left()->get_size() + 1;
	y = y->get_p();
      }
    return r;
  }

  template <typename T>
  OrderStatisticTreeNode<T> *order_statistic_tree_search(OrderStatisticTreeNode<T> *null, OrderStatisticTreeNode<T> *x, T k)
  {
    if(x == null || k == x->get_value())
      return x;
    if(k < x->get_value())
      return order_statistic_tree_search(null, x->get_left(), k);
    else
      return order_statistic_tree_search(null, x->get_right(), k);
  }

  // iterative version of serach
  template <typename T>
  OrderStatisticTreeNode<T> *iterative_order_statistic_tree_search(OrderStatisticTreeNode<T> *null, OrderStatisticTreeNode<T> *x, T k)
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
  OrderStatisticTreeNode<T> *order_statistic_tree_minimum(OrderStatisticTreeNode<T> *null, OrderStatisticTreeNode<T> *x)
  {
    while(x->get_left() != null)
      x = x->get_left();
    return x;
  }

  template <typename T>
  OrderStatisticTreeNode<T> *order_statistic_tree_maximum(OrderStatisticTreeNode<T> *null, OrderStatisticTreeNode<T> *x)
  {
    while(x->get_right() != null)
      x = x->get_right();
    return x;
  }
  
  template <typename T>
  OrderStatisticTreeNode<T> *order_statistic_tree_successor(OrderStatisticTreeNode<T> *null, OrderStatisticTreeNode<T> *x)
  {
    if(x->get_right() != null)
      return order_statistic_tree_minimum(null, x->get_right());
    OrderStatisticTreeNode<T> *y = x->get_p();
    while(y != null && x == y->get_right())
      {
	x = y;
	y = y->get_p();
      }
    return y;
  }

  template <typename T>
  OrderStatisticTreeNode<T> *order_statistic_tree_predecessor(OrderStatisticTreeNode<T> *null, OrderStatisticTreeNode<T> *x)
  {
    if(x->get_left() != null)
      return order_statistic_tree_maximum(null, x->get_left());
    OrderStatisticTreeNode<T> *y = x->get_p();
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
  void left_rotate(OrderStatisticTree<T> *t, OrderStatisticTreeNode<T> *x)
  {
    OrderStatisticTreeNode<T> *y = x->get_right();
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
    y-set_size(x->get_size());
    x->set_size(x->get_left()->get_size() +
		x->get_right()->get_size() + 1);
  }

  template <typename T>
  void right_rotate(OrderStatisticTree<T> *t, OrderStatisticTreeNode<T> *x)
  {
    OrderStatisticTreeNode<T> *y = x->get_left();
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
    x-set_size(y->get_size());
    y->set_size(y->get_left()->get_size() +
		y->get_right()->get_size() + 1);
  }

  template <typename T>
  void order_statistic_insert_fixup(OrderStatisticTree<T> *t, OrderStatisticTreeNode<T> *z)
  {
    while(z->get_p()->get_color() == REDBLACK_RED)
      {
	if(z->get_p() == z->get_p()->get_p()->get_left())
	  {
	    OrderStatisticTreeNode<T> *y = z->get_p()->get_p()->get_right();
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
	    OrderStatisticTreeNode<T> *y = z->get_p()->get_p()->get_left();
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
  void order_statistic_tree_insert(OrderStatisticTree<T> *t, OrderStatisticTreeNode<T> *z)
  {
    OrderStatisticTreeNode<T> *y = t->get_nil();
    OrderStatisticTreeNode<T> *x = t->get_root();
    while(x != t->get_nil())
      {
	x->set_size(x->get_size() + 1);
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
    order_statistic_insert_fixup(t, z);
  }

  // helper functions for order_statistic_delete
  template <typename T>
  void order_statistic_transplant(OrderStatisticTree<T> *t, OrderStatisticTreeNode<T> *u, OrderStatisticTreeNode<T> *v)
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
  void order_statistic_delete_fixup(OrderStatisticTree<T> *t, OrderStatisticTreeNode<T> *x)
  {
    OrderStatisticTreeNode<T> *w;
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
  void order_statistic_tree_delete(OrderStatisticTree<T> *t, OrderStatisticTreeNode<T> *z)
  { 
    OrderStatisticTreeNode<T> *y = z, *x;
    char y_original_color = y->get_color();
    if(z->get_left() == t->get_nil())
      {
	while(y->get_p() != t->get_nil())
	  y->get_p()->set_size(y->get_p()->get_size() - 1);
	x = z->get_right();
	order_statistic_transplant(t, z, z->get_right());
      }
    else if(z->get_right() == t->get_nil())
      {
	while(y->get_p() != t->get_nil())
	  y->get_p()->set_size(y->get_p()->get_size() - 1);
	x = z->get_left();
	order_statistic_transplant(t, z, z->get_left());
      }
    else
      {
	y = order_statistic_tree_minimum(t->get_nil(), z->get_right());
	y_original_color = y->get_color();
	while(y->get_p() != t->get_nil())
	  y->get_p()->set_size(y->get_p()->get_size() - 1);
	x = y->get_right();
	if(y->get_p() == z)
	  x->set_p(y);		// why
	else
	  {
	    order_statistic_transplant(t, y, y->get_right());
	    y->set_right(z->get_right());
	    y->get_right()->set_p(y);
	  }
	order_statistic_transplant(t, z, y);
	y->set_left(z->get_left());
	y->get_left()->set_p(y);
	y->set_color(z->get_color());
      }
    if(y_original_color == REDBLACK_BLACK)
      order_statistic_delete_fixup(t, x);
  }
}


#endif
