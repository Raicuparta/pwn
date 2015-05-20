// $Id: size_stack.cpp,v 1.1 2015/05/20 06:03:00 ist173639 Exp $ -*- c++ -*-
#include <string>
#include <string.h>
#include <sstream>
#include "targets/size_stack.h"
#include "ast/all.h"  // all.h is automatically generated

//---------------------------------------------------------------------------
//     THIS IS THE VISITOR'S DEFINITION
//---------------------------------------------------------------------------

void pwn::size_stack::do_sequence_node(cdk::sequence_node * const node, int lvl) {
	for (size_t i = 0; i < node->size(); i++)
		node->node(i)->accept(this, lvl);
}

void pwn::size_stack::do_while_node(cdk::while_node * const node, int lvl) {
	if(node->block() != NULL)
		node->block()->accept(this, lvl +2);
}

void pwn::size_stack::do_if_node(cdk::if_node * const node, int lvl) {
	if(node->block() != NULL)
		node->block()->accept(this, lvl +2);

}

void pwn::size_stack::do_if_else_node(cdk::if_else_node * const node, int lvl) {
	if(node->thenblock() != NULL)
		node->thenblock()->accept(this, lvl +2);
	if(node->elseblock() != NULL)
		node->elseblock()->accept(this, lvl +2);
}

void pwn::size_stack::do_repeat_node(pwn::repeat_node * const node, int lvl) {
	if(node->block() != NULL)
		node->block()->accept(this, lvl +2);
}

void pwn::size_stack::do_block_node(pwn::block_node * const node, int lvl) {
	if(node->vars() != NULL)
		node->vars()->accept(this, lvl +2);
	if(node->instructions() != NULL)
		node->instructions()->accept(this, lvl +2);
}

void pwn::size_stack::do_func_def_node(pwn::func_def_node * const node, int lvl) {
	if(node->name()->type()->name() != basic_type::TYPE_VOID)
		_size += node->name()->type()->size();
	node->instructions()->accept(this, lvl +2);
}

void pwn::size_stack::do_func_call_node(pwn::func_call_node * const node, int lvl) { 
	if(node->arguments() != NULL)
		node->arguments()->accept(this, lvl +2);
}

void pwn::size_stack::do_var_decl_node(pwn::var_decl_node * const node, int lvl) {
	_size += node->type()->size();
}


