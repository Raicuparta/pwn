#ifndef __PWN_BLOCKNODE_H__
#define __PWN_BLOCKNODE_H__

#include <vector>
#include <cdk/ast/expression_node.h>

namespace pwn {
  
  class block_node: public cdk::basic_node {
    
    cdk::sequence_node * _instructions;
    
  public:
    block_node(int lineno, cdk::sequence_node * instructions) :
    basic_node(lineno), _instructions(instructions) {
    }
    
  public:
    inline cdk::sequence_node * instructions() {
      return _instructions;
    }
    
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_block_node(this, level);
    }
    
  };
  
} // pwn

#endif
