#ifndef TREE_DISJOINT_SET_H
#define TREE_DISJOINT_SET_H


#include <memory>
#include <utility>

namespace CLRS
{
  template <typename T>
  struct TreeDisjointSetNode;

  template <typename T>
  void tree_disjoint_make_set
  (const std::shared_ptr<TreeDisjointSetNode<T>> &x);
  template <typename T>
  void tree_disjoint_union
  (const std::shared_ptr<TreeDisjointSetNode<T>> &x,
   const std::shared_ptr<TreeDisjointSetNode<T>> &y);
  template <typename T>
  void tree_disjoint_link
  (const std::shared_ptr<TreeDisjointSetNode<T>> &x,
   const std::shared_ptr<TreeDisjointSetNode<T>> &y);
  template <typename T>
  std::shared_ptr<TreeDisjointSetNode<T>>
  tree_disjoint_find_set
  (const std::shared_ptr<TreeDisjointSetNode<T>> &x);


  template <typename T>
  struct TreeDisjointSetNode
  {
    using TDSN_SHR =
      std::shared_ptr<TreeDisjointSetNode<T>>;
    TreeDisjointSetNode(T k): key(k) {}
    T get_key() const {return key;}
    TDSN_SHR get_p() const {return p;}
    void set_p(const TDSN_SHR &P) {p = P;}
    std::size_t get_rank() const {return rank;}
    void incr_rank() {++rank;}
  private:
    T key;
    TDSN_SHR p;
    std::size_t rank = 0;
  };

  template <typename T>
  void tree_disjoint_make_set
  (const std::shared_ptr<TreeDisjointSetNode<T>> &x)
  {
    x->set_p(x);
  }

  template <typename T>
  void tree_disjoint_union
  (const std::shared_ptr<TreeDisjointSetNode<T>> &x,
   const std::shared_ptr<TreeDisjointSetNode<T>> &y)
  {
    tree_disjoint_link(tree_disjoint_find_set(x),
		       tree_disjoint_find_set(y));
  }

  template <typename T>
  void tree_disjoint_link
  (const std::shared_ptr<TreeDisjointSetNode<T>> &x,
   const std::shared_ptr<TreeDisjointSetNode<T>> &y)
  {
    // union by rank
    if(x->get_rank() > y->get_rank())
      y->set_p(x);
    else
      {
	x->set_p(y);
	if(x->get_rank() == y->get_rank())
	  y->incr_rank();
      }
  }

  template <typename T>
  std::shared_ptr<TreeDisjointSetNode<T>>
  tree_disjoint_find_set
  (const std::shared_ptr<TreeDisjointSetNode<T>> &x)
  {
    if(x != x->get_p())
      // path compression
      x->set_p(tree_disjoint_find_set(x->get_p()));
    return x->get_p();
  }
}


#endif
