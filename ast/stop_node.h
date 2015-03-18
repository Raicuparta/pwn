// $Id: read_node.h,v 1.1 2015/02/21 20:27:31 ist13500 Exp $ -*- c++ -*-
#ifndef __PWN_STOPNODE_H__
#define __PWN_STOPNODE_H__

#include "ast/lvalue_node.h"

namespace pwn {

  class stop_node: public cdk::basic_node {
    pwn::lvalue_node *_argument;

  public:
    inline stop_node(int lineno, pwn::lvalue_node *argument) :
        cdk::basic_node(lineno), _argument(argument) {
    }

  public:
    inline pwn::lvalue_node *argument() {
      return _argument;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_stop_node(this, level);
    }

  };

} // pwn

#endif
