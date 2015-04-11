// $Id: lvalue_node.h,v 1.2 2015/03/21 18:02:49 ist173639 Exp $
#ifndef __PWN_NODE_EXPRESSION_LEFTVALUE_H__
#define __PWN_NODE_EXPRESSION_LEFTVALUE_H__

#include <cdk/ast/simple_value_node.h>
#include <string>

namespace pwn {

  /**
   * Class for describing syntactic tree leaves for holding lvalues.
   */
  
  class lvalue_node: public cdk::expression_node {
  public:
    
    inline lvalue_node(int lineno) : cdk::expression_node(lineno) {
		
    }
    
    virtual void accept(basic_ast_visitor *sp, int level) =0;


  };

} // pwn

#endif
