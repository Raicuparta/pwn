#ifndef __PWN_VARDECLNODE_H__
#define __PWN_VARDECLNODE_H__

#include <cdk/ast/expression_node.h>

namespace pwn {

  class var_decl_node: public cdk::basic_node {
    cdk::string_node * _name;
	cdk::expression_node *_type;

  public:
    inline var_decl_node(int lineno,  cdk::string_node * name,  cdk::expression_node *type) :
        cdk::basic_node(lineno),  _name(name), _type(type) {
    }

  public:
    inline cdk::string_node *name() {
      return _name;
    }
    inline cdk::expression_node *type() {
      return _type;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_var_decl_node(this, level);
    }

  };

} // pwn

#endif
