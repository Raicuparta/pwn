#ifndef __PWN_MALOCNODE_H__
#define __PWN_MALOCNODE_H__

#include "ast/lvalue_node.h"

/**
 * Class to represent memory allocation nodes
 */

namespace pwn {
  class maloc_node: public cdk::basic_node {
    pwn::lvalue_node * _value;
    
  public:
    inline maloc_node(int lineno,  pwn::lvalue_node * value) :
    cdk::basic_node(lineno), _value(value) {
    }
    
  public:
    inline  pwn::lvalue_node * value() {
      return _value;
    }
    
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_maloc_node(this, level);
    }
  };
} // pwn

#endif
