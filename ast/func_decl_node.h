#ifndef __PWN_FUNCDECLNODE_H__
#define __PWN_FUNCDECLNODE_H__

#include <cdk/ast/expression_node.h>

namespace pwn {

  class func_decl_node: public cdk::expression_node {
    std::string * _name;
    basic_type *_type;
    cdk::sequence_node *_arguments;

  public:
    inline func_decl_node(int lineno,  std::string  * name,  basic_type *type, cdk::sequence_node *arguments) :
        cdk::expression_node(lineno),  _name(name), _type(type), _arguments(arguments) {
    }

  public:
    inline std::string  *name() {
      return _name;
    }
    inline basic_type *type() {
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
