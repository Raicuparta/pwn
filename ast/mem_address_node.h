#ifndef __PWN_MEMADDRESSNODE_H__
#define __PWN_MEMADDRESSNODE_H__

#include "ast/lvalue_node.h"

namespace pwn {
  
  class mem_address_node: public cdk::unary_expression_node {
    
  public:
    inline mem_address_node(int lineno,  cdk::expression_node * arg) :
    cdk::unary_expression_node(lineno, arg) {
    }
    
  public:
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_mem_address_node(this, level);
    }
  };
} // pwn

#endif
