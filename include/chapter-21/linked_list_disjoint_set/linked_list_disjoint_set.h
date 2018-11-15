#ifndef LINKED_LIST_DISJOINT_SET_H
#define LINKED_LIST_DISJOINT_SET_H


#include <memory>
#include <utility>

namespace CLRS
{
  template <typename T> class LinkedListDisjointSet;
  template <typename T> class LinkedListDisjointSetNode;

  template <typename T>
  LinkedListDisjointSet<T>
  linked_list_disjoint_make_set(T x);
  template <typename T> 
  void linked_list_disjoint_union(LinkedListDisjointSetNode<T> &x,
				  LinkedListDisjointSetNode<T> &y);
  template <typename T>
  T linked_list_disjoint_find_set(const LinkedListDisjointSetNode<T> &x);


  template <typename T>
  struct LinkedListDisjointSet
  {
    using LLDSN = LinkedListDisjointSetNode<T>;
    using LLDSN_SHR = std::shared_ptr<LLDSN>;
    LinkedListDisjointSet(T x): head(std::make_shared<LLDSN>(x)),
				tail(head), length(1)
    {head->set_set_p(this);}
    const LLDSN_SHR &get_head() const {return head;}
    void set_head(const LLDSN_SHR &p) {head = p;}
    const LLDSN_SHR &get_tail() const {return tail;}
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
    using LLDSN_SHR = std::shared_ptr<LLDSN>;
    LinkedListDisjointSetNode(T x): key(x) {}
    const T &get_key() const {return key;}
    const LLDS *get_set_p() const {return set_p;}
    void set_set_p(const LLDS *p) {set_p = p;}
    const LLDSN_SHR get_next() {return next;}
    void set_next(const LLDSN_SHR &n) {next = n;}
  private:
    T key;
    LLDS *set_p = nullptr;
    LLDSN_SHR next;
  };
}


#endif
