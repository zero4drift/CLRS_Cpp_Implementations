#ifndef TREE_H
#define TREE_H


#include <utility>

namespace CLRS
{
  template <typename T> class TreeNode;

  template <typename T>
  class Tree
  {
    TreeNode<T> *root = nullptr;
  };

  template <typename T>
  class TreeNode
  {
    TreeNode<T> *p = nullptr;
    TreeNode<T> *left = nullptr;
    TreeNode<T> *right = nullptr;
    T key;
  };
}


#endif
