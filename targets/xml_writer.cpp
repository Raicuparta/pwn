// $Id: xml_writer.cpp,v 1.7 2015/04/14 10:00:27 ist173639 Exp $ -*- c++ -*-
#include <string>
#include "targets/xml_writer.h"
#include "targets/type_checker.h"
#include "ast/all.h"  // automatically generated

//---------------------------------------------------------------------------

void pwn::xml_writer::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  os() << std::string(lvl, ' ') << "<sequence_node size='" << node->size() << "'>" << std::endl;
  for (size_t i = 0; i < node->size(); i++)
    node->node(i)->accept(this, lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void pwn::xml_writer::do_integer_node(cdk::integer_node * const node, int lvl) {
  processSimple(node, lvl);
}

void pwn::xml_writer::do_string_node(cdk::string_node * const node, int lvl) {
  processSimple(node, lvl);
}

//---------------------------------------------------------------------------

inline void pwn::xml_writer::processUnaryExpression(cdk::unary_expression_node * const node, int lvl) {
 CHECK_TYPES(_compiler, _symtab, node);
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void pwn::xml_writer::do_neg_node(cdk::neg_node * const node, int lvl) {
   processUnaryExpression(node, lvl);
}

//---------------------------------------------------------------------------

inline void pwn::xml_writer::processBinaryExpression(cdk::binary_expression_node * const node, int lvl) {
 CHECK_TYPES(_compiler, _symtab, node);
  openTag(node, lvl);
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void pwn::xml_writer::do_add_node(cdk::add_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void pwn::xml_writer::do_sub_node(cdk::sub_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void pwn::xml_writer::do_mul_node(cdk::mul_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void pwn::xml_writer::do_div_node(cdk::div_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void pwn::xml_writer::do_mod_node(cdk::mod_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void pwn::xml_writer::do_lt_node(cdk::lt_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void pwn::xml_writer::do_le_node(cdk::le_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void pwn::xml_writer::do_ge_node(cdk::ge_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void pwn::xml_writer::do_gt_node(cdk::gt_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void pwn::xml_writer::do_ne_node(cdk::ne_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void pwn::xml_writer::do_eq_node(cdk::eq_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}

//---------------------------------------------------------------------------

void pwn::xml_writer::do_rvalue_node(pwn::rvalue_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  openTag(node, lvl);
  node->lvalue()->accept(this, lvl + 4);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

/* void pwn::xml_writer::do_lvalue_node(pwn::lvalue_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  processSimple(node, lvl);
} */

//---------------------------------------------------------------------------

void pwn::xml_writer::do_assignment_node(pwn::assignment_node * const node, int lvl) {
 CHECK_TYPES(_compiler, _symtab, node);
  openTag(node, lvl);
  node->lvalue()->accept(this, lvl + 2);
  openTag("rvalue", lvl + 2);
  node->rvalue()->accept(this, lvl + 4);
  closeTag("rvalue", lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

/*void pwn::xml_writer::do_program_node(pwn::program_node * const node, int lvl) {
  openTag(node, lvl);
  node->statements()->accept(this, lvl + 4);
  closeTag(node, lvl);
}*/

//---------------------------------------------------------------------------

void pwn::xml_writer::do_evaluation_node(pwn::evaluation_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void pwn::xml_writer::do_print_node(pwn::print_node * const node, int lvl) {
 CHECK_TYPES(_compiler, _symtab, node);
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void pwn::xml_writer::do_read_node(pwn::read_node * const node, int lvl) {
  openTag(node, lvl);
  //node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void pwn::xml_writer::do_while_node(cdk::while_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("block", lvl + 2);
  node->block()->accept(this, lvl + 4);
  closeTag("block", lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void pwn::xml_writer::do_if_node(cdk::if_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("then", lvl + 2);
  node->block()->accept(this, lvl + 4);
  closeTag("then", lvl + 2);
  closeTag(node, lvl);
}

void pwn::xml_writer::do_if_else_node(cdk::if_else_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("then", lvl + 2);
  node->thenblock()->accept(this, lvl + 4);
  closeTag("then", lvl + 2);
  openTag("else", lvl + 2);
  node->elseblock()->accept(this, lvl + 4);
  closeTag("else", lvl + 2);
  closeTag(node, lvl);
}

//------------Novos nodes-----------------------------------------------


void pwn::xml_writer::do_repeat_node(pwn::repeat_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("before", lvl + 2);
  node->before()->accept(this, lvl + 4);
  closeTag("before", lvl + 2);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("after", lvl + 2);
  node->after()->accept(this, lvl + 4);
  closeTag("after", lvl + 2);
  openTag("block", lvl + 2);
  node->block()->accept(this, lvl + 4);
  closeTag("block", lvl + 2);
  closeTag(node, lvl);
}

void pwn::xml_writer::do_stop_node(pwn::stop_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("stop", lvl + 2);
  //node->value()->accept(this, lvl + 4);
  closeTag("stop", lvl + 2);
  closeTag(node, lvl);
}

void pwn::xml_writer::do_and_node(pwn::and_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}

void pwn::xml_writer::do_or_node(pwn::or_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}

void pwn::xml_writer::do_return_node(pwn::return_node * const node, int lvl) {
  openTag(node, lvl);
  //openTag("return", lvl + 2);
  //node->value()->accept(this, lvl + 4);
  //closeTag("return", lvl + 2);
  closeTag(node, lvl);
}

void pwn::xml_writer::do_identity_node(pwn::identity_node * const node, int lvl) {
  processUnaryExpression(node, lvl);
}

void pwn::xml_writer::do_next_node(pwn::next_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("next", lvl + 2);
  //node->value()->accept(this, lvl + 4);
  closeTag("next", lvl + 2);
  closeTag(node, lvl);
}
void pwn::xml_writer::do_noob_node(pwn::noob_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("noob", lvl + 2);
  closeTag("noob", lvl + 2);
  closeTag(node, lvl);
}
void pwn::xml_writer::do_index_node(pwn::index_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("index", lvl + 2);
  openTag("var", lvl + 2);
  node->var()->accept(this, lvl + 4);
  closeTag("var", lvl + 2);
  openTag("value", lvl + 2);
  node->value()->accept(this, lvl + 4);
  closeTag("value", lvl + 2);
  closeTag("index", lvl + 2);
  closeTag(node, lvl);
}
void pwn::xml_writer::do_block_node(pwn::block_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("block", lvl + 2);
	
	if (node->vars() != nullptr) {
		openTag("vars", lvl + 2);
		node->vars()->accept(this, lvl + 4);
		closeTag("vars", lvl + 2);
	}
	
  if (node->instructions() != nullptr) {
		openTag("instructions", lvl + 2);
		node->instructions()->accept(this, lvl + 4);
		closeTag("instructions", lvl + 2);
	}

  closeTag("block", lvl + 2);
  closeTag(node, lvl);
}
void pwn::xml_writer::do_func_decl_node(pwn::func_decl_node * const node, int lvl) {
  //TODO
  openTag(node, lvl);
  openTag("func_decl", lvl + 2);
  //openTag("type", lvl + 2);
  //node->type()->accept(this, lvl + 4);
  //closeTag("type", lvl + 2);
  openTag("name", lvl + 2);
	//os() << std::string(lvl+4, ' ') + "<" + &(node->name()) + ">" << std::endl;
  closeTag("name", lvl + 2);
	
	if (node->arguments() != nullptr) {
		openTag("arguments", lvl + 2);
		node->arguments()->accept(this, lvl + 4);
		closeTag("arguments", lvl + 2);		
	}

  closeTag("func_decl", lvl + 2);
  closeTag(node, lvl);
}
void pwn::xml_writer::do_func_def_node(pwn::func_def_node * const node, int lvl) {
  //TODO
  openTag(node, lvl);
  openTag("func_def", lvl + 2);
  //openTag("qualifier", lvl + 2);
  //node->qualifier()->accept(this, lvl + 4);
 //closeTag("qualifier", lvl + 2);
  openTag("func", lvl + 2);
  node->name()->accept(this, lvl + 4);
  closeTag("func", lvl + 2);
	
	if (node->instructions() != nullptr) {
		openTag("instructions", lvl + 2);
		node->instructions()->accept(this, lvl + 4);
		closeTag("instructions", lvl + 2);		
	}
	if (node->value() != nullptr) {
		openTag("value", lvl + 2);
		node->value()->accept(this, lvl + 4);
		closeTag("value", lvl + 2);		
	}
  closeTag("func_def", lvl + 2);
  closeTag(node, lvl);
}
void pwn::xml_writer::do_func_call_node(pwn::func_call_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("func_call", lvl + 2);
  /*openTag("name", lvl + 2);
  node->name()->accept(this, lvl + 4);
  closeTag("name", lvl + 2);*/
	if (node->arguments() != nullptr) {
		openTag("arguments", lvl + 2);
		node->arguments()->accept(this, lvl + 4);
		closeTag("arguments", lvl + 2);
	}
  closeTag("func_call", lvl + 2);
  closeTag(node, lvl);
}
void pwn::xml_writer::do_var_node(pwn::var_node * const node, int lvl) {
  openTag(node, lvl);
 // openTag("var", lvl + 2);
 // node->var()->accept(this, lvl + 4);
  //closeTag("var", lvl + 2);
  closeTag(node, lvl);
}
void pwn::xml_writer::do_var_decl_node(pwn::var_decl_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("var_decl", lvl + 2);
  //openTag("type", lvl + 2);
 // node->type()->accept(this, lvl + 4);
 // closeTag("type", lvl + 2);
  openTag("name", lvl + 2);
  node->var()->accept(this, lvl + 4);
  closeTag("name", lvl + 2);
  closeTag("var_decl", lvl + 2);
  closeTag(node, lvl);
}
void pwn::xml_writer::do_println_node(pwn::println_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}
void pwn::xml_writer::do_maloc_node(pwn::maloc_node * const node, int lvl) {
  //TODO
  openTag(node, lvl);
  //openTag("maloc", lvl + 2);
  //node->value()->accept(this, lvl + 4);
 // closeTag("maloc", lvl + 2);
  closeTag(node, lvl);
}
void pwn::xml_writer::do_mem_address_node(pwn::mem_address_node * const node, int lvl) {
  //TODO
  openTag(node, lvl);
  openTag("mem_address", lvl + 2);
  node->argument()->accept(this, lvl + 4);
  closeTag("mem_address", lvl + 2);
  closeTag(node, lvl);
}

void pwn::xml_writer::do_not_node(pwn::not_node * const node, int lvl){
  processUnaryExpression(node, lvl);
}

