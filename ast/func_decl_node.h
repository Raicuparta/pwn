#ifndef __PWN_FUNCDECLNODE_H__
#define __PWN_FUNCDECLNODE_H__

#include <cdk/ast/expression_node.h>

namespace pwn {

  class func_decl_node: public cdk::basic_node {
    cdk::identifier_node * _name;
    cdk::expression_node *_type;
    cdk::sequence_node *_arguments;

  public:
    inline func_decl_node(int lineno,  cdk::identifier_node * name,  cdk::expression_node *type, cdk::sequence_node *arguments) :
        cdk::basic_node(lineno),  _name(name), _type(type), _arguments(arguments) {
    }

  public:
    inline cdk::identifier_node *name() {
      return _name;
    }
    inline cdk::expression_node *type() {
      return _type;
    }
    inline cdk::sequence_node *arguments() {
      return _arguments;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_func_decl_node(this, level);
    }

  };

} // pwn

#endif
