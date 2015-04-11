#ifndef __PWN_INDEXNODE_H__
#define __PWN_INDEXNODE_H__

#include "ast/lvalue_node.h"

namespace pwn {
  
  class index_node: public lvalue_node {
    cdk::expression_node * _value;
    
  public:
    inline index_node(int lineno,  cdk::expression_node * value) :
    lvalue_node(lineno), _value(value) {
    }
    
  public:
    inline  cdk::expression_node * value() {
      return _value;
    }
    
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_index_node(this, level);
    }
  };
} // pwn

#endif
