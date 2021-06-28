#ifndef __NODE_BASE_H__
#define __NODE_BASE_H__

#include "type.h"
using namespace std;

class NodeBase
{
  private:
    TX m_value = 0;
  protected:
    TX getValue() { return m_value; }
  public:
    NodeBase(TX val = 0) : m_value(val) {};
    
    virtual TX eval() = 0;

};



#endif
