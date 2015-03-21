#ifndef __PWN_FUNCDEFNODE_H__
#define __PWN_FUNCDEFNODE_H__

#include <cdk/ast/expression_node.h>

namespace pwn {

  class func_def_node: public cdk::basic_node {
    cdk::string_node * _name;
	block_node * _instructions;

  public:
    inline func_def_node(int lineno,  cdk::string_node * name,  block_node * instructions) :
        cdk::basic_node(lineno),  _name(name), _instructions(instructions) {
    }

  public:
    inline cdk::string_node *name() {
      return _name;
    }

    inline block_node * instructions() {
      return _instructions;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_func_def_node(this, level);
    }

  };

} // pwn

#endif
