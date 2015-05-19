#ifndef __PWN_VARDECLNODE_H__
#define __PWN_VARDECLNODE_H__

#include <cdk/ast/expression_node.h>

namespace pwn {
  
  class var_decl_node: public cdk::expression_node {
    var_node * _name;
    basic_type *_type;
		std::string *_qualifier;
		
    
  public:
    inline var_decl_node(int lineno,  var_node * name,  basic_type *type, std::string * qualifier) :
    cdk::expression_node(lineno),  _name(name), _type(type), _qualifier(qualifier) {
    }
    
  public:
    inline var_node *name() {
      return _name;
    }
    inline basic_type *type() {
      return _type;
    }
		inline std::string *qualifier() {
      return _qualifier;
    }
    
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_var_decl_node(this, level);
    }
    
  };
  
} // pwn

#endif
