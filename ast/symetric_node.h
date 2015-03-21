#ifndef __PWN_SYMETRICNODE_H__
#define __PWN_SYMETRICNODE_H__

#include <cdk/ast/unary_expression_node.h>

namespace pwn {

  class symetric_node: public cdk::unary_expression_node {
  public:
    inline symetric_node(int lineno, expression_node *arg) :
        cdk::unary_expression_node(lineno, arg) {
    }

    /**
     * @param sp semantic processor visitor
     * @param level syntactic tree level
     */
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_symetric_node(this, level);
    }

  };

} // pwn

#endif
