#ifndef LIST_H
#define LIST_H


#include <utility>

namespace CLRS
{
  template <typename T> class ListNode;
  template <typename T> class List;
  template <typename T> ListNode<T> *list_search(const List<T> &, T k);
  template <typename T> void list_insert(List<T> &, ListNode<T> &);
  template <typename T> void list_delete(List<T> &, ListNode<T> &);

  template <typename T>
  class ListNode
  {
    friend ListNode<T> *list_search<T> (const List<T> &, T k);
    friend void list_insert<T> (List<T> &, ListNode<T> &);
    friend void list_delete<T> (List<T> &, ListNode<T> &);
    ListNode *prev = nullptr;
    ListNode *next = nullptr;
    T key;
  public:
    ListNode(T t) {key = t;}
    inline T get_value() {return key;}
  };

  template <typename T>
  class List
  {
    friend ListNode<T> *list_search<T> (const List<T> &, T k);
    friend void list_insert<T> (List<T> &, ListNode<T> &);
    friend void list_delete<T> (List<T> &, ListNode<T> &);
    ListNode<T> *head = nullptr;
  };

  template <typename T> ListNode<T> *list_search(const List<T> &l, T k)
  {
    ListNode<T> *x = l.head;
    while(x != nullptr && x->key != k)
      x = x->next;
    return x;
  }

  template <typename T> void list_insert(List<T> &l, ListNode<T> &x)
  {
    x.next = l.head;
    if(l.head != nullptr)
      l.head->prev = &x;
    l.head = &x;
    x.prev = nullptr;
  }

  template <typename T> void list_delete(List<T> &l, ListNode<T> &x)
  {
    if(x.prev != nullptr)
      x.prev->next = x.next;
    else
      l.head = x.next;
    if(x.next != nullptr)
      x.next->prev = x.prev;
  }
}


#endif
