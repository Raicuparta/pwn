#ifndef __PWN_MALOCNODE_H__
#define __PWN_MALOCNODE_H__

#include "ast/lvalue_node.h"

/**
 * Class to represent memory allocation nodes
 */

namespace pwn {
  class maloc_node: public cdk::expression_node {
    int _value;
    
  public:
    inline maloc_node(int lineno,  int value) :
    cdk::expression_node(lineno), _value(value) {
    }
    
  public:
    inline int value() {
      return _value;
    }
    
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_maloc_node(this, level);
    }
  };
} // pwn

#endif
