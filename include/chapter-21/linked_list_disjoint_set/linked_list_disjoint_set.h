#ifndef LINKED_LIST_DISJOINT_SET_H
#define LINKED_LIST_DISJOINT_SET_H


#include <memory>
#include <utility>

namespace CLRS
{
  template <typename T> class LinkedListDisjointSet;
  template <typename T> class LinkedListDisjointSetNode;

  template <typename T>
  std::shared_ptr<LinkedListDisjointSet<T>>
  linked_list_disjoint_make_set(const std::shared_ptr
				<LinkedListDisjointSetNode<T>> &);
  template <typename T> 
  void linked_list_disjoint_union(const std::shared_ptr
				  <LinkedListDisjointSetNode<T>> &,
				  const std::shared_ptr
				  <LinkedListDisjointSetNode<T>> &);
  template <typename T>
  T linked_list_disjoint_find_set(const std::shared_ptr
				  <LinkedListDisjointSetNode<T>> &);


  template <typename T>
  struct LinkedListDisjointSet
  {
    using LLDSN = LinkedListDisjointSetNode<T>;
    using LLDSN_SHR = std::shared_ptr<LLDSN>;
    LinkedListDisjointSet(const std::shared_ptr
			  <LLDSN> &x):
      head(x), tail(head), length(1) {}
    LLDSN_SHR get_head() const {return head;}
    void set_head(const LLDSN_SHR &p) {head = p;}
    LLDSN_SHR get_tail() const {return tail;}
    void set_tail(const LLDSN_SHR &p) {tail = p;}
    std::size_t get_length() {return length;}
    void add_length(std::size_t l) {length += l;}
  private:
    LLDSN_SHR head;
    LLDSN_SHR tail;
    std::size_t length = 0;
  };

  template <typename T>
  struct LinkedListDisjointSetNode
  {
    using LLDS = LinkedListDisjointSet<T>;
    using LLDSN = LinkedListDisjointSetNode;
    using LLDS_SHR = std::shared_ptr<LLDS>;
    using LLDSN_SHR = std::shared_ptr<LLDSN>;
    LinkedListDisjointSetNode(T x): key(x) {}
    T get_key() const {return key;}
    LLDS_SHR get_set_p() const {return set_p;}
    void set_set_p(const LLDS_SHR &p) {set_p = p;}
    LLDSN_SHR get_next() {return next;}
    void set_next(const LLDSN_SHR &n) {next = n;}
  private:
    T key;
    LLDS_SHR set_p;
    LLDSN_SHR next;
  };

  template <typename T>
  std::shared_ptr<LinkedListDisjointSet<T>>
  linked_list_disjoint_make_set(const std::shared_ptr
				<LinkedListDisjointSetNode<T>> &x)
  {
    auto set = std::make_shared<LinkedListDisjointSet<T>>(x); 
    x->set_set_p(set);
    return set;
  }

  template <typename T> 
  void linked_list_disjoint_union(const std::shared_ptr
				  <LinkedListDisjointSetNode<T>> &x,
				  const std::shared_ptr
				  <LinkedListDisjointSetNode<T>> &y)
  {
    auto x_set_p = x->get_set_p();
    std::size_t x_set_len = x_set_p->get_length();
    auto y_set_p = y->get_set_p();
    std::size_t y_set_len = y_set_p->get_length();
    if(x_set_len <= y_set_len)
      {
	auto x_head = x_set_p->get_head();
	auto x_tail = x_set_p->get_tail();
	// update the set_p data member of objects in linked list
	for(auto shr = x_head;
	    shr != nullptr;
	    shr = shr->get_next())
	  shr->set_set_p(y_set_p);
	auto y_tail = y_set_p->get_tail();
	y_tail->set_next(x_head);
	y_set_p->set_tail(x_tail);
	y_set_p->add_length(x_set_p->get_length());
	// clear after merge
	x_set_p->set_head(nullptr);
	x_set_p->set_tail(nullptr);
      }
    else
      {
	auto y_head = y_set_p->get_head();
	auto y_tail = y_set_p->get_tail();
	// update the set_p data member of objects in linked list
	for(auto shr = y_head;
	    shr != nullptr;
	    shr = shr->get_next())
	  shr->set_set_p(x_set_p);
	auto x_tail = x_set_p->get_tail();
	x_tail->set_next(y_head);
	x_set_p->set_tail(y_tail);
	x_set_p->add_length(y_set_p->get_length());
	// clear after merge
	y_set_p->set_head(nullptr);
	y_set_p->set_tail(nullptr);

      }
  }
  
  template <typename T>
  T linked_list_disjoint_find_set(const std::shared_ptr
				  <LinkedListDisjointSetNode<T>> &x)
  {
    auto set_p = x->get_set_p();
    T key = set_p->get_head()->get_key();
    return key;
  }
}


#endif
