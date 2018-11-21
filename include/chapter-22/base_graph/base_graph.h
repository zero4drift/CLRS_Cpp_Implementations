#ifndef BASE_GRAPH_H
#define BASE_GRAPH_H


#include <vector>

namespace CLRS
{
  /*
   * T1 should be class VertexGraph or its derivation
   * T2 should be class EdgeGraph or its derivation
   */
  template <typename T1, typename T2>
  class BaseGraph
  {
  protected:
    std::vector<T1> vertexes;
    std::vector<T2> edges;
  public:
    /* 
     * when construct, 
     * make sure passed-in vs has every
     * graph node stored in an order of index;
     * and es only stores existing graph edges. 
     */
    BaseGraph(const std::vector<T1> &vs,
	      const std::vector<T2> &es):
      vertexes(vs), edges(es) {}
    
    // indexes of the passed in object are inside the range
    virtual bool edge_or_not (const T2 &) const = 0;

    // exception if nothing match
    T1 &vertex(std::size_t i)
    {return vertexes[i];}
    T2 &edge(std::size_t i, std::size_t j);

    // return amount of vertexes
    std::size_t get_vertexes_size() const
    {return vertexes.size();}
  };

  template <typename T1, typename T2>
  T2 & BaseGraph<T1, T2>::edge(std::size_t i, std::size_t j)
  {
    for(auto &e : edges)
      {
	if(e.get_first_vertex() == i &&
	   e.get_second_vertex() == j)
	  return e;
      }
    // exception if nothing match
  }
}


#endif
