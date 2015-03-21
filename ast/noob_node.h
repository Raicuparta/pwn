#ifndef __PWN_NOOBNODE_H__
#define __PWN_NOOBNODE_H__

#include <cdk/ast/simple_value_node.h>

namespace pwn {

  class noob_node: public virtual cdk::simple_value_node<int> {
  public:
    inline noob_node(int lineno, int i) :
        cdk::simple_value_node<int>(lineno, i) {
    }

    /**
     * @param sp semantic processor visitor
     * @param level syntactic tree level
     */
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_noob_node(this, level);
    }

  };

} // pwn

#endif
