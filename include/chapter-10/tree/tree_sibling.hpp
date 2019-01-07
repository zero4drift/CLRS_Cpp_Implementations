#ifndef TREE_SIBLING_H
#define TREE_SIBLING_H


#include <utility>

namespace CLRS
{
  template <typename T> class TreeSiblingNode;

  template <typename T>
  class TreeSibling
  {
    TreeSiblingNode<T> *root = nullptr;
  };

  template <typename T>
  class TreeSiblingNode
  {
    TreeSiblingNode<T> *p = nullptr;
    TreeSiblingNode<T> *left_child = nullptr;
    TreeSiblingNode<T> *right_sibling = nullptr;
    T key;
  };
}


#endif
