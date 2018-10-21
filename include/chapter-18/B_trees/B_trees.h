#ifndef B_TREES_H
#define B_TREES_H


#include <utility>
// here all b tree nodes allocated in heap, not disk.
#include <memory>
#include <vector>

namespace CLRS
{
  template <typename T, std::size_t D> class BTree;
  template <typename T, std::size_t D> class BTreeNode;
  
  template <typename T, std::size_t D>
  std::pair<std::shared_ptr<BTreeNode<T, D>>, std::size_t>
  b_tree_search(const std::shared_ptr<BTreeNode<T, D>> &x, T k);
  template <typename T, std::size_t D>
  void b_tree_create(BTree<T, D> *t);
  template <typename T, std::size_t D>
  void b_tree_split_child(const std::shared_ptr<BTreeNode<T, D>> &x,
			  std::size_t i);
  template <typename T, std::size_t D>
  void b_tree_insert(BTree<T, D> *t, T k);
  template <typename T, std::size_t D>
  void b_tree_insert_nonfull(const std::shared_ptr<BTreeNode<T, D>> &x,
			     T k);
  template <typename T, std::size_t D>
  void b_tree_delete(BTree<T, D> *t,
		     const std::shared_ptr<BTreeNode<T, D>> &x,
		     T k);


  template <typename T, std::size_t D>
  class BTree
  {
    std::shared_ptr<BTreeNode<T, D>> root;
  public:
    BTree() = default;
    std::shared_ptr<BTreeNode<T, D>> get_root() {return root;}
    void set_root(std::shared_ptr<BTreeNode<T, D>> r) {root = r;}
  };

  template <typename T, std::size_t D>
  class BTreeNode
  {
    std::size_t n = 0;
    // default minimum degree specified by template parameter D
    std::size_t t = D;
    bool leaf = true;
    std::vector<T> keys;
    std::vector<std::shared_ptr<BTreeNode>> childs; 
  public:
    BTreeNode() = default;
    // constructor only for unittest use
    BTreeNode(const std::vector<T> &vk): n(vk.size()), keys(vk) {}
    std::size_t get_n() const {return n;}
    void set_n(std::size_t m) {n = m;}
    // minimum D is set in constructor once and for all
    std::size_t get_t() const {return t;}
    bool get_leaf() const {return leaf;}
    void set_leaf(bool l) {leaf = l;}
    T get_key(std::size_t i) const {return keys[i];}
    void keys_push_back(T k) {keys.push_back(k);}
    void insert_key(T k, std::size_t i)
    {auto it = keys.begin() + i; keys.insert(it, k);}
    void delete_key(std::size_t i)
    {auto it = keys.begin() + i; keys.erase(it);}
    void replace_key(T k, std::size_t i) {keys[i] = k;}
    std::shared_ptr<BTreeNode> get_child(std::size_t i) const
    {return childs[i];}
    void childs_push_back(std::shared_ptr<BTreeNode> n)
    {childs.push_back(n);}
    void insert_child(std::shared_ptr<BTreeNode> n, std::size_t i)
    {auto it = childs.begin() + i; childs.insert(it, n);}
    void delete_child(std::size_t i)
    {auto it = childs.begin() + i; childs.erase(it);}
  };

  template <typename T, std::size_t D>
  void b_tree_create(BTree<T, D> *t)
  {
    std::shared_ptr<BTreeNode<T, D>> x =
      std::make_shared<BTreeNode<T, D>>();
    t->set_root(x);
  }

  template <typename T, std::size_t D>
  std::pair<std::shared_ptr<BTreeNode<T, D>>, std::size_t>
  b_tree_search(const std::shared_ptr<BTreeNode<T, D>> &x, T k)
  {
    std::size_t i = 1;
    while(i <= x->get_n() && k > x->get_key(i - 1))
      ++i;
    if(i <= x->get_n() && k == x->get_key(i - 1))
      return std::make_pair(x, i - 1);
    else if(x->get_leaf())
      return std::make_pair(nullptr, 0);
    else
      return b_tree_search(x->get_child(i - 1), k);
  }
  
  template <typename T, std::size_t D>
  void b_tree_split_child(const std::shared_ptr<BTreeNode<T, D>> &x,
			  std::size_t i)
  {
    auto z = std::make_shared<BTreeNode<T, D>>();
    auto y = x->get_child(i);
    z->set_leaf(y->get_leaf());
    z->set_n(D - 1);
    for(std::size_t j = 1; j <= D - 1; ++j)
      z->keys_push_back(y->get_key(j + D - 1));
    if(!y->get_leaf())
      for(std::size_t j = 1; j <= D; ++j)
	z->childs_push_back(y->get_child(j + D - 1));
    y->set_n(D - 1);
    x->insert_child(z, i + 1);
    x->insert_key(y->get_key(D - 1), i);
    x->set_n(x->get_n() + 1);
  }

  template <typename T, std::size_t D>
  void b_tree_insert(BTree<T, D> *t, T k)
  {
    auto r = t->get_root();
    if(r->get_n() == 2 * D - 1)
      {
	auto s = std::make_shared<BTreeNode<T, D>>();
	t->set_root(s);
	s->set_leaf(false);
	s->childs_push_back(r);
	b_tree_split_child(s, 0);
	b_tree_insert_nonfull(s, k);
      }
    else
      b_tree_insert_nonfull(r, k);
  }

  template <typename T, std::size_t D>
  void b_tree_insert_nonfull(const std::shared_ptr<BTreeNode<T, D>> &x, T k)
  {
    std::size_t i = x->get_n();
    if(x->get_leaf())
      {
	while(i >= 0 && k < x->get_key(i - 1))
	  --i;
	x->insert_key(k, i);
	x->set_n(x->get_n() + 1);
      }
    else
      {
	while(i >= 0 && k < x->get_key(i - 1))
	  --i;
	if(x->get_child(i)->get_n() == 2 * D - 1)
	  {
	    b_tree_split_child(x, i);
	    if(k > x->get_key(i))
	      ++i;
	  }
	b_tree_insert_nonfull(x->get_child(i), k);
      }
  }

  template <typename T, std::size_t D>
  void b_tree_delete(BTree<T, D> *t, const std::shared_ptr<BTreeNode<T, D>> &x, T k)
  {
    std::size_t i = 1;
    while(i <= x->get_n() && k > x->get_key(i - 1))
      ++i;
    if(i <= x->get_n() && k == x->get_key(i - 1))
      {
	// case 1: leaf node
	if(x->get_leaf())
	  {
	    x->delete_key(i - 1);
	    x->set_n(x->get_n() - 1);
	  }
	else
	  {
	    // case 2a
	    if(x->get_child(i - 1)->get_n() >= D)
	      {
		auto y = x->get_child(i - 1);
		T j = y->get_key(y->get_n() - 1);
		b_tree_delete(t, y, j);
		x->replace_key(j, i - 1);
	      }
	    // case 2b which is opposite to 2a
	    else if(x->get_child(i)->get_n() >= D)
	      {
		auto z = x->get_child(i);
		T j = z->get_key(0);
		b_tree_delete(t, z, j);
		x->replace_key(j, i - 1);
	      }
	    // case 2c
	    else
	      {
		auto y = x->get_child(i - 1);
		auto z = x->get_child(i);
		y->keys_push_back(k);
		y->set_n(y->get_n() + 1);
		x->delete_key(i - 1);
		x->delete_child(i);
		x->set_n(x->get_n() - 1);
		for(std::size_t n = 0; n < z->get_n(); ++n)
		  y->keys_push_back(z->get_key(n));
		y->set_n(z->get_n() + y->get_n());
		if(!y->get_leaf())
		  for(std::size_t n = 0; n <= z->get_n(); ++n)
		    y->childs_push_back(z->get_child(n));
		b_tree_delete(t, y, k);
	      }
	  }
      }
    else
      {
	auto self = x->get_child(i - 1);
	std::shared_ptr<BTreeNode<T, D>> brother;
	// case 3a
	if(x->get_child(i - 1)->get_n() == D - 1)
	  {
	    if(i - 1 > 0 && x->get_child(i - 2)->get_n() >= D)
	      {
		brother = x->get_child(i - 2);
		std::size_t bl = brother->get_n();
		T down = x->get_key(i - 2);
		T up = brother->get_key(bl - 1);
		self->insert_key(down, 0);
		self->set_n(self->get_n() + 1);
		x->replace_key(up, i - 2);
		if(!brother->get_leaf())
		  {
		    self->insert_child(brother->get_child(bl), 0);
		    brother->delete_child(bl);
		  }
		brother->delete_key(bl - 1);
		brother->set_n(bl - 1);
	      }
	    else if(i <= x->get_n() && x->get_child(i)->get_n() >= D)
	      {
		brother = x->get_child(i);
		std::size_t bl = brother->get_n();
		T down = x->get_key(i - 1);
		T up = brother->get_key(0);
		self->keys_push_back(down);
		self->set_n(x->get_n() + 1);
		x->replace_key(up, i - 1);
		if(!brother->get_leaf())
		  {
		    self->childs_push_back(brother->get_child(0));
		    brother->delete_child(0);
		  }
		brother->delete_key(0);
		brother->set_n(bl - 1);
	      }
	    // case 3b
	    else
	      {
		if(i - 1 == 0)
		  {
		    brother = x->get_child(i);
		    T down = x->get_key(i - 1);
		    self->keys_push_back(down);
		    self->set_n(self->get_n() + 1);
		    for(std::size_t i = 0; i < brother->get_n(); ++i)
		      self->keys_push_back(brother->get_key(i));
		    if(!self->get_leaf())
		      for(std::size_t i = 0; i <= brother->get_n(); ++i)
			self->childs_push_back(brother->get_child(i));
		    self->set_n(self->get_n() + brother->get_n());
		    x->delete_key(i - 1);
		    x->delete_child(i);
		    x->set_n(x->get_n() - 1);
		    if(x->get_n() == 0)
		      t->set_root(self);
		  }
		else
		  {
		    brother = x->get_child(i - 2);
		    T down = x->get_key(i - 2);
		    brother->keys_push_back(down);
		    brother->set_n(brother->get_n() + 1);
		    for(std::size_t i = 0; i < self->get_n(); ++i)
		      brother->keys_push_back(self->get_key(i));
		    if(!brother->get_leaf())
		      for(std::size_t i = 0; i <= self->get_n(); ++i)
			brother->childs_push_back(self->get_child(i));
		    brother->set_n(self->get_n() + brother->get_n());
		    x->delete_key(i - 2);
		    x->delete_child(i - 1);
		    x->set_n(x->get_n() - 1);
		    if(x->get_n() == 0)
		      t->set_root(brother);
		    self = brother;
		  }
	      } 
	  }
	b_tree_delete(t, self, k);
      }
  }

}


#endif
