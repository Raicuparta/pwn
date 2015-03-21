#ifndef __PWN_FUNCDECLNODE_H__
#define __PWN_FUNCDECLNODE_H__

#include <cdk/ast/expression_node.h>

namespace pwn {

  class func_decl_node: public cdk::basic_node {
    cdk::string_node * _name;
	cdk::expression_node *_type;
	std::vector<cdk::basic_node*> _arguments;

  public:
    inline func_decl_node(int lineno,  cdk::string_node * name,  cdk::expression_node *type, std::vector<cdk::basic_node*> arguments) :
        cdk::basic_node(lineno),  _name(name), _type(type), _arguments(arguments) {
    }

  public:
    inline cdk::string_node *name() {
      return _name;
    }
    inline cdk::expression_node *type() {
      return _type;
    }
    inline std::vector<cdk::basic_node*> arguments() {
      return _arguments;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_func_decl_node(this, level);
    }

  };

} // pwn

#endif
