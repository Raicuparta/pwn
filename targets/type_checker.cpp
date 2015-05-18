// $Id: type_checker.cpp,v 1.6 2015/04/14 10:00:27 ist173639 Exp $ -*- c++ -*-
#include <string>
#include "targets/type_checker.h"
#include "ast/all.h"  // automatically generated

#define ASSERT_UNSPEC \
{ if (node->type() != nullptr && \
node->type()->name() != basic_type::TYPE_UNSPEC) return; }


//metodo auxiliar para verificar se um tipo e' pertence a um conjunto de tipos
inline bool pwn::type_checker::isCompatibleType(basic_type::type type, const basic_type::type accepedTypes[]) {
  return true;
	//TODO
}


//---------------------------------------------------------------------------

void pwn::type_checker::do_integer_node(cdk::integer_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(new basic_type(4, basic_type::TYPE_INT));
}

void pwn::type_checker::do_string_node(cdk::string_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(new basic_type(4, basic_type::TYPE_STRING));
}


//---------------------------------------------------------------------------

inline void pwn::type_checker::processBinaryExpression(cdk::binary_expression_node * const node, int lvl, const basic_type::type acceptedTypes[]) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  if (!isCompatibleType(node->left()->type()->name(), acceptedTypes))
    throw std::string("wrong type in left argument of binary expression");
  
  node->right()->accept(this, lvl + 2);
  if (!isCompatibleType(node->right()->type()->name(), acceptedTypes))
    throw std::string("wrong type in right argument of binary expression");
}


void pwn::type_checker::do_add_node(cdk::add_node * const node, int lvl) {
  const basic_type::type acceptedTypes[3] = {basic_type::TYPE_INT, basic_type::TYPE_DOUBLE, basic_type::TYPE_POINTER};
  processBinaryExpression(node, lvl, acceptedTypes);
  
  basic_type* newType = new basic_type(4, basic_type::TYPE_INT);
  
  if (node->left()->type()->name() == basic_type::TYPE_POINTER) {
    if(node->right()->type()->name() != basic_type::TYPE_INT)
      throw std::string("only int can be added to pointer");
    
    newType = node->left()->type();
  }
  
  if (node->right()->type()->name() == basic_type::TYPE_POINTER) {
    if(node->left()->type()->name() != basic_type::TYPE_INT)
      throw std::string("only int can be added to pointer");
    
    newType = node->right()->type();
  }
  
  if (node->left()->type()->name() == basic_type::TYPE_DOUBLE) {
    if(node->right()->type()->name() == basic_type::TYPE_POINTER)
      throw std::string("real can only be added to real or int");
    
    newType = node->left()->type();
  }
  
  if (node->right()->type()->name() == basic_type::TYPE_DOUBLE) {
    if(node->left()->type()->name() == basic_type::TYPE_POINTER)
      throw std::string("real can only be added to real or int");
    
    newType = node->right()->type();
  }
  
  node->type(newType);
}

void pwn::type_checker::do_sub_node(cdk::sub_node * const node, int lvl) {
  const basic_type::type acceptedTypes[3] = {basic_type::TYPE_INT, basic_type::TYPE_DOUBLE, basic_type::TYPE_POINTER};
  processBinaryExpression(node, lvl, acceptedTypes);
  
  basic_type* newType = new basic_type(4, basic_type::TYPE_INT);
  
  if (node->left()->type()->name() == basic_type::TYPE_POINTER) {
    newType = node->left()->type();
  }
  
  if (node->right()->type()->name() == basic_type::TYPE_POINTER) {
    newType = node->right()->type();
  }
  
  if (node->left()->type()->name() == basic_type::TYPE_DOUBLE) {
    if(node->right()->type()->name() == basic_type::TYPE_POINTER)
      throw std::string("real can only be subtracted from real or int");
    
    newType = node->left()->type();
  }
  
  if (node->right()->type()->name() == basic_type::TYPE_DOUBLE) {
    if(node->left()->type()->name() == basic_type::TYPE_POINTER)
      throw std::string("real can only be subtracted from real or int");
    
    newType = node->right()->type();
  }
  
  node->type(newType);
}


inline void pwn::type_checker::processMulDivMod(cdk::binary_expression_node * const node, int lvl) {
  const basic_type::type acceptedTypes[2] = {basic_type::TYPE_INT, basic_type::TYPE_DOUBLE};
  processBinaryExpression(node, lvl, acceptedTypes);
  
  basic_type* newType = new basic_type(4, basic_type::TYPE_INT);
  
  if (node->left()->type()->name() == basic_type::TYPE_DOUBLE) {
    newType = node->left()->type();
  }
  
  if (node->right()->type()->name() == basic_type::TYPE_DOUBLE) {
    newType = node->right()->type();
  }
  
  node->type(newType);
}  

void pwn::type_checker::do_mul_node(cdk::mul_node * const node, int lvl) {
  processMulDivMod(node, lvl);
}

void pwn::type_checker::do_div_node(cdk::div_node * const node, int lvl) {
  processMulDivMod(node, lvl);
}

void pwn::type_checker::do_mod_node(cdk::mod_node * const node, int lvl) {
  processMulDivMod(node, lvl);
}

inline void pwn::type_checker::processCompare(cdk::binary_expression_node * const node, int lvl) {
  const basic_type::type acceptedTypes[2] = {basic_type::TYPE_INT, basic_type::TYPE_DOUBLE};
  processBinaryExpression(node, lvl, acceptedTypes);
  node->type(new basic_type(4, basic_type::TYPE_INT));
}

void pwn::type_checker::do_lt_node(cdk::lt_node * const node, int lvl) {
  processCompare(node, lvl);
}
void pwn::type_checker::do_le_node(cdk::le_node * const node, int lvl) {
  processCompare(node, lvl);
}
void pwn::type_checker::do_ge_node(cdk::ge_node * const node, int lvl) {
  processCompare(node, lvl);
}
void pwn::type_checker::do_gt_node(cdk::gt_node * const node, int lvl) {
  processCompare(node, lvl);
}


inline void pwn::type_checker::processEquality(cdk::binary_expression_node * const node, int lvl) {
  const basic_type::type acceptedTypes[3] = {basic_type::TYPE_INT, basic_type::TYPE_DOUBLE, basic_type::TYPE_POINTER};
  processBinaryExpression(node, lvl, acceptedTypes);
  node->type(new basic_type(4, basic_type::TYPE_INT));
}

void pwn::type_checker::do_ne_node(cdk::ne_node * const node, int lvl) {
  processEquality(node, lvl);
}
void pwn::type_checker::do_eq_node(cdk::eq_node * const node, int lvl) {
  processEquality(node, lvl);
}

//---------------------------------------------------------------------------

void pwn::type_checker::do_rvalue_node(pwn::rvalue_node * const node, int lvl) {
  node->lvalue()->accept(this, lvl);
  node->type(node->lvalue()->type());
}

//---------------------------------------------------------------------------

/*void pwn::type_checker::do_lvalue_node(pwn::lvalue_node * const node, int lvl) {
 *  const std::string &id = node->value();
 *  std::shared_ptr<pwn::symbol> symbol = _symtab.find(id);
 *  if (symbol == nullptr) throw id + " undeclared";
 *  // hackish stuff...
 *  node->type(new basic_type(4, basic_type::TYPE_INT));
 * }*/

//---------------------------------------------------------------------------

void pwn::type_checker::do_assignment_node(pwn::assignment_node * const node, int lvl) {
  ASSERT_UNSPEC;
  
  node->lvalue()->accept(this, lvl + 2);
  node->rvalue()->accept(this, lvl + 2);
	//lvalue e rvalue tem que ser iguais, excepto se lvalue for doube e rvalue for int
  if (node->lvalue()->type()->name() != node->rvalue()->type()->name()
    && !((node->lvalue()->type()->name() == basic_type::TYPE_DOUBLE && node->rvalue()->type()->name() == basic_type::TYPE_INT)))
    throw std::string("incompatible types in assignment");
  
  node->type(node->lvalue()->type());
}

//---------------------------------------------------------------------------

void pwn::type_checker::do_evaluation_node(pwn::evaluation_node * const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
}

//---------------------------------------------------------------------------

void pwn::type_checker::do_read_node(pwn::read_node * const node, int lvl) {
  //node->argument()->accept(this, lvl + 2);
  //TODO
}

//---------------------------------------------------------------------------

void pwn::type_checker::do_while_node(cdk::while_node * const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
}

//---------------------------------------------------------------------------

void pwn::type_checker::do_if_node(cdk::if_node * const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
}

void pwn::type_checker::do_if_else_node(cdk::if_else_node * const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
}

/*Novos nodes*/

void pwn::type_checker::do_repeat_node(pwn::repeat_node * const node, int lvl) {;
  node->before()->accept(this, lvl + 4);
  node->condition()->accept(this, lvl + 4);
  node->after()->accept(this, lvl + 4);
  node->block()->accept(this, lvl + 4);
}


inline void pwn::type_checker::processAndOr(cdk::binary_expression_node * const node, int lvl) {
  const basic_type::type acceptedTypes[1] = {basic_type::TYPE_INT};
  processBinaryExpression(node, lvl, acceptedTypes);
  node->type(new basic_type(4, basic_type::TYPE_INT));
}

void pwn::type_checker::do_and_node(pwn::and_node * const node, int lvl) {
  processAndOr(node, lvl);
}

void pwn::type_checker::do_or_node(pwn::or_node * const node, int lvl) {
  processAndOr(node, lvl);
}

void pwn::type_checker::do_stop_node(pwn::stop_node * const node, int lvl) {
  const basic_type::type acceptedTypes[1] = {basic_type::TYPE_INT};
  node->value()->accept(this, lvl + 4);
  if (!isCompatibleType(node->value()->type()->name(), acceptedTypes))
    throw std::string("wrong type in argument of STOP");
}

void pwn::type_checker::do_return_node(pwn::return_node * const node, int lvl) {
  //no types to check
}


inline void pwn::type_checker::processIdSym(cdk::unary_expression_node * const node, int lvl) {
  ASSERT_UNSPEC;
	const basic_type::type acceptedTypes[2] = {basic_type::TYPE_INT, basic_type::TYPE_DOUBLE};
  node->argument()->accept(this, lvl + 4);
  if (!isCompatibleType(node->argument()->type()->name(), acceptedTypes))
    throw std::string("wrong type in argument of identity/symetric expression");
	
  node->type(node->argument()->type());
}

void pwn::type_checker::do_identity_node(pwn::identity_node * const node, int lvl) {
	processIdSym(node, lvl);
}

void pwn::type_checker::do_neg_node(cdk::neg_node * const node, int lvl) {
  processIdSym(node, lvl);
}

void pwn::type_checker::do_next_node(pwn::next_node * const node, int lvl) {
	const basic_type::type acceptedTypes[1] = {basic_type::TYPE_INT};
  node->value()->accept(this, lvl + 2);
  if (!isCompatibleType(node->value()->type()->name(), acceptedTypes))
    throw std::string("wrong type in argument of NEXT");
}
void pwn::type_checker::do_noob_node(pwn::noob_node * const node, int lvl) {
  node->type(new basic_type(4, basic_type::TYPE_POINTER));
}
void pwn::type_checker::do_index_node(pwn::index_node * const node, int lvl) {
  const basic_type::type acceptedTypes[1] = {basic_type::TYPE_INT};
  node->value()->accept(this, lvl + 2);
  if (!isCompatibleType(node->value()->type()->name(), acceptedTypes))
    throw std::string("wrong type in argument of STOP");
	
	node->var()->accept(this, lvl + 2);
	node->type(node->var()->type());
}
void pwn::type_checker::do_block_node(pwn::block_node * const node, int lvl) {
  node->vars()->accept(this, lvl + 2);
  node->instructions()->accept(this, lvl + 2);
}
void pwn::type_checker::do_func_decl_node(pwn::func_decl_node * const node, int lvl) {
  ASSERT_UNSPEC;
  const std::string &id = *node->name();
  if (!_symtab.find(id)) {
    _symtab.insert(id, std::make_shared<pwn::symbol>(node->type(), id, -1)); // put in the symbol table
  }
}
void pwn::type_checker::do_func_def_node(pwn::func_def_node * const node, int lvl) {
  ASSERT_UNSPEC;
  const std::string &id = *node->name()->name();
  std::shared_ptr<pwn::symbol> symbol = _symtab.find(id);
  if (!symbol) throw id + " undeclared";
  basic_type type = *symbol->type();
  node->type(&type);
  
  node->instructions()->accept(this, lvl + 2);
}
void pwn::type_checker::do_func_call_node(pwn::func_call_node * const node, int lvl) {
  ASSERT_UNSPEC;
  const std::string &id = *node->name();
  std::shared_ptr<pwn::symbol> symbol = _symtab.find(id);
  if (!symbol) throw id + " undeclared";
  basic_type type = *symbol->type();
  node->type(&type);
}

void pwn::type_checker::do_var_node(pwn::var_node * const node, int lvl) {
  ASSERT_UNSPEC;
  const std::string &id = *node->var();
  std::shared_ptr<pwn::symbol> symbol = _symtab.find(id);
  if (!symbol) throw id + " undeclared";
  basic_type type = *symbol->type();
  node->type(&type);
}

void pwn::type_checker::do_var_decl_node(pwn::var_decl_node * const node, int lvl) {
  ASSERT_UNSPEC;
  const std::string &id = *node->name()->var();
  if (!_symtab.find(id)) {
    _symtab.insert(id, std::make_shared<pwn::symbol>(node->type(), id, -1)); // put in the symbol table
  }
  
  node->name()->type(node->type());
}


void pwn::type_checker::do_println_node(pwn::println_node * const node, int lvl) {
	const basic_type::type acceptedTypes[3] = {basic_type::TYPE_STRING, basic_type::TYPE_INT, basic_type::TYPE_DOUBLE};
  node->argument()->accept(this, lvl + 4);
  if (!isCompatibleType(node->argument()->type()->name(), acceptedTypes))
    throw std::string("wrong type in argument of println expression");
}

void pwn::type_checker::do_print_node(pwn::print_node * const node, int lvl) {
	const basic_type::type acceptedTypes[3] = {basic_type::TYPE_STRING, basic_type::TYPE_INT, basic_type::TYPE_DOUBLE};
  node->argument()->accept(this, lvl + 4);
  if (!isCompatibleType(node->argument()->type()->name(), acceptedTypes))
    throw std::string("wrong type in argument of println expression");
}

void pwn::type_checker::do_maloc_node(pwn::maloc_node * const node, int lvl) {
  node->type(new basic_type(4, basic_type::TYPE_POINTER));
}

void pwn::type_checker::do_mem_address_node(pwn::mem_address_node * const node, int lvl) {
	ASSERT_UNSPEC;
	const basic_type::type acceptedTypes[1] = {basic_type::TYPE_DOUBLE};
  node->argument()->accept(this, lvl + 4);
  if (!isCompatibleType(node->argument()->type()->name(), acceptedTypes))
    throw std::string("wrong type in argument of memory address (?) expression");
	
  node->type(new basic_type(4, basic_type::TYPE_POINTER));
}

void pwn::type_checker::do_not_node(pwn::not_node * const node, int lvl) {
	ASSERT_UNSPEC;
	const basic_type::type acceptedTypes[1] = {basic_type::TYPE_INT};
  node->argument()->accept(this, lvl + 4);
  if (!isCompatibleType(node->argument()->type()->name(), acceptedTypes))
    throw std::string("wrong type in argument of NOT expression");
		
	node->type(node->argument()->type());
}
