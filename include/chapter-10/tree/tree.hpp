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
  public:
    TreeNode<T> *get_root() {return root;}
    void set_root(TreeNode<T> *r) {root = r;}
  };

  template <typename T>
  class TreeNode
  {
    TreeNode *p = nullptr;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    T key;
  public:
    TreeNode(T k): key(k) {}
    T get_value() {return key;}
    TreeNode *get_left() {return left;}
    TreeNode *get_right() {return right;}
    TreeNode *get_parent() {return p;}
    void set_parent(TreeNode *parent) {p = parent;}
    void set_left(TreeNode *l) {left = l;}
    void set_right(TreeNode *r) {right = r;}
  };
}


#endif
