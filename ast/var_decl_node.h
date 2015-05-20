#ifndef __PWN_VARDECLNODE_H__
#define __PWN_VARDECLNODE_H__

#include <cdk/ast/expression_node.h>

namespace pwn {
  
  class var_decl_node: public cdk::expression_node {
    var_node * _name;
		std::string *_qualifier;
		pwn::assignment_node * _assignment;
    
  public:
    inline var_decl_node(int lineno,  var_node * name,  basic_type *type, std::string * qualifier, pwn::assignment_node * assignment) :
    cdk::expression_node(lineno),  _name(name), _qualifier(qualifier), _assignment(assignment) {
			cdk::expression_node::type(type);
			
    }
    
  public:
    inline var_node *var() {
      return _name;
    }
    
		inline pwn::assignment_node *  assignment() {
      return _assignment;
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
