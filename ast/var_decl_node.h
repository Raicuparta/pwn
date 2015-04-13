#ifndef __PWN_VARDECLNODE_H__
#define __PWN_VARDECLNODE_H__

#include <cdk/ast/expression_node.h>

namespace pwn {
  
  class var_decl_node: public cdk::expression_node {
    var_node * _name;
    basic_type *_type;
    
  public:
    inline var_decl_node(int lineno,  var_node * name,  basic_type *type) :
    cdk::expression_node(lineno),  _name(name), _type(type) {
    }
    
  public:
    inline var_node *name() {
      return _name;
    }
    inline basic_type *type() {
      return _type;
    }
    
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_var_decl_node(this, level);
    }
    
  };
  
} // pwn

#endif
