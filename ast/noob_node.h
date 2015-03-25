#ifndef __PWN_NOOBNODE_H__
#define __PWN_NOOBNODE_H__

#include <cdk/ast/simple_value_node.h>

namespace pwn {
  
  class noob_node: public virtual cdk::expression_node{
  public:
    
    
    inline noob_node(int lineno) :
    cdk::expression_node(lineno) {
    }
    
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_noob_node(this, level);
    }
    
  };
  
} // pwn

#endif
