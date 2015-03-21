#ifndef __PWN_MEMADDRESSNODE_H__
#define __PWN_MEMADDRESSNODE_H__

#include "ast/lvalue_node.h"

namespace pwn {

  class mem_address_node: public cdk::basic_node {
    pwn::lvalue_node * _value;

  public:
	inline mem_address_node(int lineno,  pwn::lvalue_node * value) :
        cdk::basic_node(lineno), _value(value) {
    }

  public:
    inline  pwn::lvalue_node * value() {
      return _value;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_mem_address_node(this, level);
    }
  };
} // pwn

#endif
