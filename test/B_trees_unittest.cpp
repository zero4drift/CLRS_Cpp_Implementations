#include <memory>
#include <vector>
#include <gtest/gtest.h>
#include "chapter-18/B_trees/B_trees.hpp"

using namespace CLRS;

TEST(BTrees, Create)
{
  BTree<char, 3> t;
  b_tree_create(&t);
  EXPECT_EQ(0, t.get_root()->get_n());
  EXPECT_EQ(true, t.get_root()->get_leaf());
  EXPECT_EQ(3, t.get_root()->get_t());
}

TEST(BTrees, Search)
{
  BTree<char, 3> t;
  std::vector<char> v1 = {'G', 'M', 'P', 'X'};
  std::vector<char> v2 = {'A', 'C', 'D', 'E'};
  std::vector<char> v3 = {'J', 'K'};
  std::vector<char> v4 = {'N', 'O'};
  std::vector<char> v5 = {'R', 'S', 'T', 'U', 'V'};
  std::vector<char> v6 = {'Y', 'Z'};
  auto r = std::make_shared<BTreeNode<char, 3>>(v1);
  auto c1 = std::make_shared<BTreeNode<char, 3>>(v2);
  auto c2 = std::make_shared<BTreeNode<char, 3>>(v3);
  auto c3 = std::make_shared<BTreeNode<char, 3>>(v4);
  auto c4 = std::make_shared<BTreeNode<char, 3>>(v5);
  auto c5 = std::make_shared<BTreeNode<char, 3>>(v6);
  r->set_leaf(false);
  t.set_root(r);
  r->push_back_child(c1);
  r->push_back_child(c2);
  r->push_back_child(c3);
  r->push_back_child(c4);
  r->push_back_child(c5);
  // a tree formed with hack method to make a search test
  auto result1 = b_tree_search(r, 'N');
  EXPECT_EQ('N', result1.first->get_key(result1.second));
  auto result2 = b_tree_search(r, 'U');
  EXPECT_EQ('U', result2.first->get_key(result2.second));
  auto unfound = b_tree_search(r, 'B');
  EXPECT_EQ(nullptr, unfound.first);
}

TEST(BTrees, Insert)
{
  BTree<char, 3> t;
  std::vector<char> v1 = {'G', 'M', 'P', 'X'};
  std::vector<char> v2 = {'A', 'C', 'D', 'E'};
  std::vector<char> v3 = {'J', 'K'};
  std::vector<char> v4 = {'N', 'O'};
  std::vector<char> v5 = {'R', 'S', 'T', 'U', 'V'};
  std::vector<char> v6 = {'Y', 'Z'};
  auto r = std::make_shared<BTreeNode<char, 3>>(v1);
  auto c1 = std::make_shared<BTreeNode<char, 3>>(v2);
  auto c2 = std::make_shared<BTreeNode<char, 3>>(v3);
  auto c3 = std::make_shared<BTreeNode<char, 3>>(v4);
  auto c4 = std::make_shared<BTreeNode<char, 3>>(v5);
  auto c5 = std::make_shared<BTreeNode<char, 3>>(v6);
  r->set_leaf(false);
  t.set_root(r);
  r->push_back_child(c1);
  r->push_back_child(c2);
  r->push_back_child(c3);
  r->push_back_child(c4);
  r->push_back_child(c5);
  // a tree formed with hack method to make a insert test
  // fig-18.7
  // step 1 insert B
  b_tree_insert(&t, 'B');
  EXPECT_EQ(5, c1->get_n());
  EXPECT_EQ('B', c1->get_key(1));
  // step 2 insert Q
  b_tree_insert(&t, 'Q');
  EXPECT_EQ(5, r->get_n());
  EXPECT_EQ('T', r->get_key(3));
  EXPECT_EQ(3, r->get_child(3)->get_n());
  EXPECT_EQ('Q', r->get_child(3)->get_key(0));
  EXPECT_EQ(2, r->get_child(4)->get_n());
  // step 3 insert L
  b_tree_insert(&t, 'L');
  EXPECT_EQ(1, t.get_root()->get_n());
  EXPECT_EQ(2, t.get_root()->get_child(0)->get_n());
  EXPECT_EQ(2, t.get_root()->get_child(1)->get_n());
  EXPECT_EQ('L', t.get_root()->get_child(0)->get_child(1)->get_key(2));
  // step 3 insert F
  b_tree_insert(&t, 'F');
  EXPECT_EQ(3, t.get_root()->get_child(0)->get_n());
  EXPECT_EQ(2, t.get_root()->get_child(0)->get_child(0)->get_n());
  EXPECT_EQ(3, t.get_root()->get_child(0)->get_child(1)->get_n());
  EXPECT_EQ('F', t.get_root()->get_child(0)->get_child(1)->get_key(2));
}

TEST(BTrees, Delete) 
{
  BTree<char, 3> t;
  std::vector<char> v1 = {'P'};
  std::vector<char> v2 = {'C', 'G', 'M'};
  std::vector<char> v3 = {'T', 'X'};
  std::vector<char> v4 = {'A', 'B'};
  std::vector<char> v5 = {'D', 'E', 'F'};
  std::vector<char> v6 = {'J', 'K', 'L'};
  std::vector<char> v7 = {'N', 'O'};
  std::vector<char> v8 = {'Q', 'R', 'S'};
  std::vector<char> v9 = {'U', 'V'};
  std::vector<char> v10 = {'Y', 'Z'};
  auto r = std::make_shared<BTreeNode<char, 3>>(v1);
  auto c1 = std::make_shared<BTreeNode<char, 3>>(v2);
  auto c2 = std::make_shared<BTreeNode<char, 3>>(v3);
  auto c3 = std::make_shared<BTreeNode<char, 3>>(v4);
  auto c4 = std::make_shared<BTreeNode<char, 3>>(v5);
  auto c5 = std::make_shared<BTreeNode<char, 3>>(v6);
  auto c6 = std::make_shared<BTreeNode<char, 3>>(v7);
  auto c7 = std::make_shared<BTreeNode<char, 3>>(v8);
  auto c8 = std::make_shared<BTreeNode<char, 3>>(v9);
  auto c9 = std::make_shared<BTreeNode<char, 3>>(v10);
  r->set_leaf(false);
  t.set_root(r);
  c1->set_leaf(false);
  c2->set_leaf(false);
  r->push_back_child(c1);
  r->push_back_child(c2);
  c1->push_back_child(c3);
  c1->push_back_child(c4);
  c1->push_back_child(c5);
  c1->push_back_child(c6);
  c2->push_back_child(c7);
  c2->push_back_child(c8);
  c2->push_back_child(c9);
  // a tree formed with hack method to make a insert test
  // fig-18.8
  // step 1 case 1: delete F
  b_tree_delete(&t, r, 'F');
  EXPECT_EQ(2, c4->get_n());
  EXPECT_EQ('E', c4->get_key(1));
  // step 2 case 2a: delete M
  b_tree_delete(&t, r, 'M');
  EXPECT_EQ(3, c1->get_n());
  EXPECT_EQ('L', c1->get_key(2));
  EXPECT_EQ(2, c5->get_n());
  // step 3 case 2c delete G
  b_tree_delete(&t, r, 'G');
  EXPECT_EQ('L', c1->get_key(1));
  EXPECT_EQ(2, c1->get_n());
  EXPECT_EQ(4, c4->get_n());
  EXPECT_EQ('K', c4->get_key(3));
  // step 4 case 3b delete D
  b_tree_delete(&t, r, 'D');
  EXPECT_EQ(5, t.get_root()->get_n());
  EXPECT_EQ(3, c4->get_n());
  EXPECT_EQ('E', c4->get_key(0));
  // step 5 case 3a delete B
  b_tree_delete(&t, t.get_root(), 'B');
  EXPECT_EQ('E', c1->get_key(0));
  EXPECT_EQ('C', c3->get_key(1));
  EXPECT_EQ(2, c4->get_n());
  EXPECT_EQ('J', c4->get_key(0));
}
