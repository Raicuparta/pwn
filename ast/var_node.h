#ifndef __PWN_VARNODE_H__
#define __PWN_VARNODE_H__

#include <cdk/ast/expression_node.h>

namespace pwn {

  class var_node: public cdk::basic_node {
    cdk::string_node * _name;
	cdk::expression_node *_type;
	cdk::expression_node *_content;
	

  public:
    inline var_node(int lineno,  cdk::string_node * name,  cdk::expression_node *type, cdk::expression_node * content) :
        cdk::basic_node(lineno),  _name(name), _type(type), _content(content) {
    }

  public:
    inline cdk::string_node *name() {
      return _name;
    }
    inline cdk::expression_node *type() {
      return _type;
    }
    inline cdk::expression_node *content() {
      return _content;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_var_node(this, level);
    }

  };

} // pwn

#endif
