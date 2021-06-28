#ifndef __NODE_VARIABLE_H__
#define __NODE_VARIABLE_H__

#include "NodeBase.h"

class NodeVariable : public NodeBase
{
  T1 m_name;
  public:
    NodeVariable(T1 name, TX val) 
                : NodeBase(val), m_name(name) {}

    virtual TX eval() { return getValue(); }
};

#endif
