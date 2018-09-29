#ifndef LIST_SENTINEL_H
#define LIST_SENTINEL_H


#include <utility>

template <typename T> class ListSentinelNode;
template <typename T> class ListSentinel;
template <typename T> ListSentinelNode<T> *list_sentinel_search(const ListSentinel<T> &, T k);
template <typename T> void list_sentinel_insert(ListSentinel<T> &, ListSentinelNode<T> &);
template <typename T> void list_sentinel_delete(ListSentinel<T> &, ListSentinelNode<T> &);

template <typename T>
class ListSentinelNode
{
  friend class ListSentinel<T>;
  friend ListSentinelNode<T> *list_sentinel_search<T> (const ListSentinel<T> &, T k);
  friend void list_sentinel_insert<T> (ListSentinel<T> &, ListSentinelNode<T> &);
  friend void list_sentinel_delete<T> (ListSentinel<T> &, ListSentinelNode<T> &);
  ListSentinelNode *prev = nullptr;
  ListSentinelNode *next = nullptr;
  T key;
public:
  ListSentinelNode(T t) {key = t;}
  ListSentinelNode() = default;
  inline T get_value() {return key;}
};

template <typename T>
class ListSentinel
{
  friend ListSentinelNode<T> *list_sentinel_search<T> (const ListSentinel<T> &, T k);
  friend void list_sentinel_insert<T> (ListSentinel<T> &, ListSentinelNode<T> &);
  friend void list_sentinel_delete<T> (ListSentinel<T> &, ListSentinelNode<T> &);
  ListSentinelNode<T> lsn;
  ListSentinelNode<T> *nil = &lsn;
 public:
 ListSentinel() {nil->prev = nil; nil->next = nil;}
};

template <typename T> ListSentinelNode<T> *list_sentinel_search(const ListSentinel<T> &l, T k)
{
  ListSentinelNode<T> *x = l.nil->next;
  while(x != l.nil && x->key != k)
    x = x->next;
  if(x == l.nil)
    return nullptr;
  return x;
}

template <typename T> void list_sentinel_insert(ListSentinel<T> &l, ListSentinelNode<T> &x)
{
  x.next = l.nil->next;
  l.nil->next->prev = &x;
  l.nil->next = &x;
  x.prev = l.nil;
}

template <typename T> void list_sentinel_delete(ListSentinel<T> &l, ListSentinelNode<T> &x)
{
  x.prev->next = x.next;
  x.next->prev = x.prev;
}


#endif
