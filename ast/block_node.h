#ifndef __PWN_BLOCKNODE_H__
#define __PWN_BLOCKNODE_H__

#include <vector>
#include <cdk/ast/expression_node.h>

namespace pwn {

  class block_node: public cdk::basic_node {
	  
	std::vector<var_node*> _vars;
    std::vector<cdk::basic_node*> _instructions;


  public:
  
	block_node(int lineno, var_node * vars, cdk::basic_node* instructions, block_node *block = nullptr) :
        basic_node(lineno) {
			if (block != nullptr){
				if(vars != nullptr){
					_vars = block->nodes_vars();
					_vars.push_back(vars);
				} else {
					_instructions = block->nodes_instructions();
					_instructions.push_back(instructions);
				}
			}
			_instructions.push_back(instructions);

		}

  public:
  
    inline ~block_node() {
      for (auto node : _vars)
        delete node;
      _vars.clear();
       for (auto node : _instructions)
        delete node;
      _instructions.clear();
    }

  public:
  
    basic_node *node_vars(size_t i) {
      return _vars[i];
    }
    std::vector<var_node*> &nodes_vars() {
      return _vars;
    }
    size_t size_vars() {
      return _vars.size();
    }
    
     basic_node *node_instructions(size_t i) {
      return _instructions[i];
    }
    std::vector<cdk::basic_node*> &nodes_instructions() {
      return _instructions;
    }
    size_t size_instructions() {
      return _instructions.size();
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_block_node(this, level);
    }

  };

} // pwn

#endif
