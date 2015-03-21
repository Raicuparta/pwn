#ifndef __PWN_FUNCCALLNODE_H__
#define __PWN_FUNCCALLNODE_H__

#include <cdk/ast/expression_node.h>

namespace pwn {

  class func_call_node: public cdk::basic_node {
    cdk::string_node * _name;
	std::vector<cdk::basic_node*> _arguments;

  public:
    inline func_call_node(int lineno,  cdk::string_node * name,  std::vector<cdk::basic_node*> arguments) :
        cdk::basic_node(lineno),  _name(name), _arguments(arguments) {
    }

  public:
    inline cdk::string_node *name() {
      return _name;
    }

	inline std::vector<cdk::basic_node*> arguments() {
      return _arguments;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_func_call_node(this, level);
    }

  };

} // pwn

#endif
