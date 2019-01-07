#ifndef PROTO_VEB_TREE_H
#define PROTO_VEB_TREE_H


#include <math.h>
#include <vector>
#include <memory>
#include "chapter-20/veb_tree_utilities.hpp"

namespace CLRS
{
  /* Warning:
   * the parameter which is used to initialize an object 
   * of this class type must be an unsigned
   * restricted by rule (2**(2**k), k >= 1)
   */
  class ProtovEBTree;
  
  bool proto_veb_member(const ProtovEBTree &v, unsigned x);
  unsigned proto_veb_minimum(const ProtovEBTree &v);
  unsigned proto_veb_minimum(const ProtovEBTree &v);
  unsigned proto_veb_successor(const ProtovEBTree &v, unsigned x);
  unsigned proto_veb_predecessor(const ProtovEBTree &v, unsigned x);
  void proto_veb_insert(ProtovEBTree &v, unsigned x);
  void proto_veb_delete(ProtovEBTree &v, unsigned x);


  class ProtovEBTree
  {
  public:
    using ProtovEBTreeSHR = std::shared_ptr<ProtovEBTree>;
    ProtovEBTree(unsigned U);
    unsigned get_n() const {return n;}
    void incr_n() {++n;}
    void decr_n() {--n;}
    void set_n(unsigned N) {n = N;}
    unsigned get_u() const {return u;}
    const ProtovEBTreeSHR &get_summary() const {return summary;}
    const std::vector<ProtovEBTreeSHR> &get_cluster() const {return cluster;}
    unsigned get_A(unsigned i) const {return A[i];} 
    void set_A(unsigned i) {A[i] = 1;}
    void clear_A(unsigned i) {A[i] = 0;}
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
    /* 
     * cluster = std::vector<ProtovEBTreeSHR>
     * (u_next, std::make_shared<ProtovEBTree>(u_next));
     * illegal! all shared_ptr object point to the same place. 
     */
    for(unsigned i = u_next; i != 0; --i)
      cluster.push_back(std::make_shared<ProtovEBTree>(u_next));
  }

  bool proto_veb_member(const ProtovEBTree &v, unsigned x)
  {
    unsigned u = v.get_u();
    if(u == 2)
      return v.get_A(x);
    else
      return proto_veb_member(*v.get_cluster()[veb_high(x, u)],
			      veb_low(x, u));
  }

  unsigned proto_veb_minimum(const ProtovEBTree &v)
  {
    unsigned u = v.get_u();
    if(u == 2)
      {
	if(v.get_A(0) == 1)
	  return 0;
	else if(v.get_A(1) == 1)
	  return 1;
	// have to return u itself as a symbol
	else return u;
      }
    else
      {
	auto &vs = *v.get_summary();
	unsigned min_cluster = proto_veb_minimum(vs);
	if(min_cluster == vs.get_u())
	  /* 
	   * since u is an unclosed upper boundary,
	   * if return value is u, meaning v is empty.
	   */
	  return u;
	else
	  {
	    unsigned offset =
	      proto_veb_minimum(*v.get_cluster()[min_cluster]);
	    return veb_index(min_cluster, offset, u);
	  }
      }
  }

  unsigned proto_veb_maximum(const ProtovEBTree &v)
  {
    unsigned u = v.get_u();
    if(u == 2)
      {
	if(v.get_A(1) == 1)
	  return 1;
	else if(v.get_A(0) == 1)
	  return 0;
	// have to return u itself as a symbol
	else return u;
      }
    else
      {
	auto &vs = *v.get_summary();
	unsigned max_cluster = proto_veb_maximum(vs);
	if(max_cluster == vs.get_u())
	  /* 
	   * since u is an unclosed upper boundary,
	   * if return value is u, meaning v is empty.
	   */
	  return u;
	else
	  {
	    unsigned offset =
	      proto_veb_maximum(*v.get_cluster()[max_cluster]);
	    return veb_index(max_cluster, offset, u);
	  }
      }
  }

  unsigned proto_veb_successor(const ProtovEBTree &v, unsigned x)
  {
    unsigned u = v.get_u();
    if(u == 2)
      {
	if(x == 0 && v.get_A(1) == 1)
	  return 1;
	else
	  // same mechanism as the minimum and maximum
	  return u;
      }
    else
      {
	auto &vc = *v.get_cluster()[veb_high(x, u)];
	unsigned offset =
	  proto_veb_successor(vc, veb_low(x, u));
	if(offset != vc.get_u())
	  return veb_index(veb_high(x, u), offset, u);
	else
	  {
	    auto &vs = *v.get_summary();
	    unsigned succ_cluster =
	      proto_veb_successor(vs, veb_high(x, u));
	    if(succ_cluster == vs.get_u())
	      return u;
	    else
	      {
		unsigned offset =
		  proto_veb_minimum(*v.get_cluster()[succ_cluster]);
		return veb_index(succ_cluster, offset, u);
	      }
	  }
      }
  }

  unsigned proto_veb_predecessor(const ProtovEBTree &v, unsigned x)
  {
    unsigned u = v.get_u();
    if(u == 2)
      {
	if(x == 1 && v.get_A(0) == 1)
	  return 0;
	else
	  // same mechanism as the minimum and maximum
	  return u;
      }
    else
      {
	auto &vc = *v.get_cluster()[veb_high(x, u)];
	unsigned offset =
	  proto_veb_predecessor(vc, veb_low(x, u));
	if(offset != vc.get_u())
	  return veb_index(veb_high(x, u), offset, u);
	else
	  {
	    auto &vs = *v.get_summary();
	    unsigned pred_cluster =
	      proto_veb_predecessor(vs, veb_high(x, u));
	    if(pred_cluster == vs.get_u())
	      return u;
	    else
	      {
		unsigned offset =
		  proto_veb_maximum(*v.get_cluster()[pred_cluster]);
		return veb_index(pred_cluster, offset, u);
	      }
	  }
      }
  }

  // requires that 0 =< x < v.get_u()
  void proto_veb_insert(ProtovEBTree &v, unsigned x)
  {
    unsigned u = v.get_u();
    if(u == 2)
      {
	if(v.get_A(x) == 0)
	  {
	    v.incr_n();
	    v.set_A(x);
	  }
      }
    else
      {
	auto &vc = *v.get_cluster()[veb_high(x, u)];
	unsigned original_n = vc.get_n();
	proto_veb_insert(vc, veb_low(x, u));
	unsigned new_n = vc.get_n();
	v.set_n(v.get_n() + (new_n - original_n));
	if(original_n == 0 && new_n > 0)
	  proto_veb_insert(*v.get_summary(), veb_high(x, u));
      }
  }

  // requires that 0 =< x < v.get_u()
  void proto_veb_delete(ProtovEBTree &v, unsigned x)
  {
    unsigned u = v.get_u();
    if(u == 2)
      {
	if(v.get_A(x) == 1)
	  {
	    v.decr_n();
	    v.clear_A(x);
	  }
      }
    else
      {
	auto &vc = *v.get_cluster()[veb_high(x, u)];
	unsigned original_n = vc.get_n();
	proto_veb_delete(vc, veb_low(x, u));
	unsigned new_n = vc.get_n();
	v.set_n(v.get_n() - (original_n - new_n));
	if(original_n > 0 && new_n == 0)
	  proto_veb_delete(*v.get_summary(), veb_high(x, u));
      }
  }
  
}



#endif
