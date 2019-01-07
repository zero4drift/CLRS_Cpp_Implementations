#include <vector>
#include <bitset>
#include <memory>
#include <gtest/gtest.h>
#include "chapter-16/huffman/huffman.hpp"


using namespace CLRS;

using HNode_u = HuffmanCodingNode<unsigned>;

TEST(Huffman, EncodingDecoding)
{
  std::vector<std::shared_ptr<HNode_u>> v;
  v.push_back(std::make_shared<HNode_u>('f', 5));
  v.push_back(std::make_shared<HNode_u>('e', 9));
  v.push_back(std::make_shared<HNode_u>('c', 12));
  v.push_back(std::make_shared<HNode_u>('b', 13));
  v.push_back(std::make_shared<HNode_u>('d', 16));
  v.push_back(std::make_shared<HNode_u>('a', 45));
  HNode_u q = huffman(v);
  EXPECT_EQ('a', huffman_decode(std::bitset<1>("0"), q));
  EXPECT_EQ('b', huffman_decode(std::bitset<3>("101"), q));
  EXPECT_EQ('c', huffman_decode(std::bitset<3>("100"), q));
  EXPECT_EQ('d', huffman_decode(std::bitset<3>("111"), q));
  EXPECT_EQ('f', huffman_decode(std::bitset<4>("1100"), q));
  EXPECT_EQ('e', huffman_decode(std::bitset<4>("1101"), q));
}
