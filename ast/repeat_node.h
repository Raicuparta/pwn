#ifndef __PWN_REPEATNODE_H__
#define __PWN_REPEATNODE_H__

#include <cdk/ast/expression_node.h>

namespace pwn {
  
  class repeat_node: public cdk::basic_node {
    cdk::sequence_node *_before;
    cdk::sequence_node *_condition;
    cdk::sequence_node *_after;
    cdk::basic_node *_block;
    
  public:
    inline repeat_node(int lineno, cdk::sequence_node *before,  cdk::sequence_node *condition, cdk::sequence_node *after, cdk::basic_node *block) :
    cdk::basic_node(lineno),  _before(before), _condition(condition), _after(after), _block(block) {
    }
    
  public:
    inline cdk::sequence_node *before() {
      return _before;
    }
    inline cdk::sequence_node *condition() {
      return _condition;
    }
    inline cdk::sequence_node *after() {
      return _after;
    }
    
    inline cdk::basic_node *block() {
      return _block;
    }
    
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_repeat_node(this, level);
    }
    
  };
  
} // pwn

#endif
