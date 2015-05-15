// $Id: read_node.h,v 1.3 2015/04/14 10:00:27 ist173639 Exp $ -*- c++ -*-
#ifndef __PWN_READNODE_H__
#define __PWN_READNODE_H__

#include "ast/lvalue_node.h"

namespace pwn {

  /**
   * Class for describing read nodes.
   */
  class read_node: public cdk::basic_node {

  public:
    inline read_node(int lineno) :
        cdk::basic_node(lineno) {
    }

  public:

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_read_node(this, level);
    }

  };

} // pwn

#endif
