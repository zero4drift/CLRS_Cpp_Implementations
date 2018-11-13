#ifndef PROTO_VEB_TREE_H
#define PROTO_VEB_TREE_H


#include <math.h>
#include <vector>
#include <memory>

namespace CLRS
{
  /* Warning:
   * the parameter which is used to initialize an object 
   * of this class type must be an unsigned
   * restricted by rule (2**(2**k), k >= 1)
   */
  class ProtovEBTree;
  
  bool proto_veb_member(const ProtovEBTree &pvt, unsigned x);
  unsigned proto_veb_minimum(const ProtovEBTree &pvt);
  unsigned proto_veb_minimum(const ProtovEBTree &pvt);
  unsigned proto_veb_successor(const ProtovEBTree &pvt, unsigned x);
  unsigned proto_veb_predecessor(const ProtovEBTree &pvt, unsigned x);
  void proto_veb_insert(ProtovEBTree &pvt, unsigned x);
  void proto_veb_delete(ProtovEBTree &pvt, unsigned x);


  class ProtovEBTree
  {
  public:
    using ProtovEBTreeSHR = std::shared_ptr<ProtovEBTree>;
    ProtovEBTree(unsigned U);
    unsigned get_n() const {return n;}
    void incr_n() {++n;}
    void decr_n() {--n;}
    unsigned get_u() const {return u;}
    const ProtovEBTreeSHR &get_summary() const {return summary;}
    const std::vector<ProtovEBTreeSHR> &get_cluster() const {return cluster;}
    unsigned get_A_0() const {return A[0];} 
    unsigned get_A_1() const {return A[1];} 
    void set_A_0(bool f) {A[0] = f;}
    void set_A_1(bool f) {A[1] = f;}
  private:
    unsigned n = 0;
    unsigned u;
    ProtovEBTreeSHR summary;
    std::vector<ProtovEBTreeSHR> cluster;
    unsigned A[2] = {0, 0};
  };

  ProtovEBTree::ProtovEBTree(unsigned U): u(U)
  {
    if(u == 2)
      return;
    unsigned u_next = std::sqrt(u);
    summary = std::make_shared<ProtovEBTree>(u_next);
    cluster = std::vector<ProtovEBTreeSHR>(u_next, std::make_shared<ProtovEBTree>(u_next));
  }
}


#endif
