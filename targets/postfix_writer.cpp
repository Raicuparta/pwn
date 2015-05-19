// $Id: postfix_writer.cpp,v 1.7 2015/04/14 10:00:27 ist173639 Exp $ -*- c++ -*-
#include <string>
#include <string.h>
#include <sstream>
#include "targets/type_checker.h"
#include "targets/postfix_writer.h"
#include "targets/size_stack.h"
#include "ast/all.h"  // all.h is automatically generated

//---------------------------------------------------------------------------
//     THIS IS THE VISITOR'S DEFINITION
//---------------------------------------------------------------------------

void pwn::postfix_writer::do_sequence_node(cdk::sequence_node * const node, int lvl) {
	for (size_t i = 0; i < node->size(); i++) {
		node->node(i)->accept(this, lvl);
	}
}

//---------------------------------------------------------------------------

void pwn::postfix_writer::do_integer_node(cdk::integer_node * const node, int lvl) {
	_pf.INT(node->value()); // push an integer
}

void pwn::postfix_writer::do_string_node(cdk::string_node * const node, int lvl) {
	int lbl1;
	
	/* generate the string */
	_pf.RODATA(); // strings are DATA readonly
	_pf.ALIGN(); // make sure we are aligned
	_pf.LABEL(mklbl(lbl1 = ++_lbl)); // give the string a name
	_pf.STR(node->value()); // output string characters
	
	/* leave the address on the stack */
	_pf.TEXT(); // return to the TEXT segment
	_pf.ADDR(mklbl(lbl1)); // the string to be printed
}

//---------------------------------------------------------------------------

void pwn::postfix_writer::do_neg_node(cdk::neg_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);
	node->argument()->accept(this, lvl); // determine the value
	_pf.NEG(); // 2-complement
}

//---------------------------------------------------------------------------

void pwn::postfix_writer::do_add_node(cdk::add_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);
	node->left()->accept(this, lvl);
	node->right()->accept(this, lvl);
	_pf.ADD();
}
void pwn::postfix_writer::do_sub_node(cdk::sub_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);
	node->left()->accept(this, lvl);
	node->right()->accept(this, lvl);
	_pf.SUB();
}
void pwn::postfix_writer::do_mul_node(cdk::mul_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);
	node->left()->accept(this, lvl);
	node->right()->accept(this, lvl);
	_pf.MUL();
}
void pwn::postfix_writer::do_div_node(cdk::div_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);
	node->left()->accept(this, lvl);
	node->right()->accept(this, lvl);
	_pf.DIV();
}
void pwn::postfix_writer::do_mod_node(cdk::mod_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);
	node->left()->accept(this, lvl);
	node->right()->accept(this, lvl);
	_pf.MOD();
}
void pwn::postfix_writer::do_lt_node(cdk::lt_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);
	node->left()->accept(this, lvl);
	node->right()->accept(this, lvl);
	_pf.LT();
}
void pwn::postfix_writer::do_le_node(cdk::le_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);
	node->left()->accept(this, lvl);
	node->right()->accept(this, lvl);
	_pf.LE();
}
void pwn::postfix_writer::do_ge_node(cdk::ge_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);
	node->left()->accept(this, lvl);
	node->right()->accept(this, lvl);
	_pf.GE();
}
void pwn::postfix_writer::do_gt_node(cdk::gt_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);
	node->left()->accept(this, lvl);
	node->right()->accept(this, lvl);
	_pf.GT();
}
void pwn::postfix_writer::do_ne_node(cdk::ne_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);
	node->left()->accept(this, lvl);
	node->right()->accept(this, lvl);
	_pf.NE();
}
void pwn::postfix_writer::do_eq_node(cdk::eq_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);
	node->left()->accept(this, lvl);
	node->right()->accept(this, lvl);
	_pf.EQ();
}

//---------------------------------------------------------------------------

void pwn::postfix_writer::do_rvalue_node(pwn::rvalue_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);
	node->lvalue()->accept(this, lvl);
	_pf.LOAD(); //FIXME: depends on type size
}

//---------------------------------------------------------------------------

/* void pwn::postfix_writer::do_lvalue_node(pwn::lvalue_node * const node, int lvl) {
*	CHECK_TYPES(_compiler, _symtab, node);
*	// simplified generation: all variables are global
*	_pf.ADDR(node->value());
* } */

//---------------------------------------------------------------------------

void pwn::postfix_writer::do_assignment_node(pwn::assignment_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);
	
	// DAVID: horrible hack!
	// (this is caused by Simple not having explicit variable declarations)
	/* const std::string &id = node->lvalue()->value();
	*	std::shared_ptr<pwn::symbol> symbol = _symtab.find(id);
	*	if (symbol->value() == -1) {
	*		_pf.DATA(); // variables are all global and live in DATA
	*		_pf.ALIGN(); // make sure we are aligned
	*		_pf.LABEL(id); // name variable location
	*		_pf.CONST(0); // initialize it to 0 (zero)
	*		_pf.TEXT(); // return to the TEXT segment
	*		symbol->value(0);
}*/
	
	std::cout<<"--------------ASSIGN----------------"<<std::endl;
	
	node->rvalue()->accept(this, lvl); // determine the new value
	_pf.DUP();
	node->lvalue()->accept(this, lvl); // where to store the value
	_pf.STORE(); // store the value at address
}

//---------------------------------------------------------------------------

void pwn::postfix_writer::do_func_def_node(pwn::func_def_node * const node, int lvl) {
	
	std::cout << "------ DEF -------" << std::endl;
	CHECK_TYPES(_compiler, _symtab, node);
	
	_pf.TEXT();
	
	
	std::string * name = node->name()->name(); //nome da funcao
	const std::string &cName = *name;
	if(cName == "pwn"){
		name = new std::string("_main");
		
	}
	else if(cName == "_main"){
		name = new std::string("._main");
	}
	
	const std::string &sName = *name;
	
	size_stack sc(_compiler, node);
	
	_pf.GLOBAL(sName, _pf.FUNC());
	_pf.ALIGN();
	_pf.LABEL(sName);
	_pf.ENTER(sc.size());  // Simple doesn't implement local variables
	
	// these are just a few library function imports
	_pf.EXTERN("readi");
	_pf.EXTERN("printi");
	_pf.EXTERN("prints");
	_pf.EXTERN("println");
	
	if(node->name()->arguments() != NULL) { std::cout<<"--------------ARGS----------------"<<std::endl;
						node->name()->arguments()->accept(this, lvl); //argumentos da funcao
	}
	if(node->instructions() != NULL) { std::cout<<"--------------Intres----------------"<<std::endl;
																							node->instructions()->accept(this, lvl); //corpo da funcao
	}
	if(node->value() != NULL)  { std::cout<<"--------------Vales----------------"<<std::endl;
						node->value()->accept(this, lvl); //retorno por omissao da funcao
	}
	// end the main function
	
	_pf.INT(0);
	_pf.POP();
	_pf.LEAVE();
	_pf.RET();
	
}

//---------------------------------------------------------------------------

void pwn::postfix_writer::do_evaluation_node(pwn::evaluation_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);
	node->argument()->accept(this, lvl); // determine the value
	if (node->argument()->type()->name() == basic_type::TYPE_INT) {
		_pf.TRASH(4); // delete the evaluated value
	}
	else if (node->argument()->type()->name() == basic_type::TYPE_STRING) {
		_pf.TRASH(4); // delete the evaluated value's address
	}
	else {
		std::cerr << "EVAL ERROR: CANNOT HAPPEN!" << std::endl;
		exit(1);
	}
}

void pwn::postfix_writer::do_print_node(pwn::print_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);
	std::cout<<"--------------PRINT_NODE----------------"<< node->argument()->type()->name() << " |?| " <<  basic_type::TYPE_INT <<std::endl;
	node->argument()->accept(this, lvl); // determine the value to print
	
	if (node->argument()->type()->name() == basic_type::TYPE_INT) {
		_pf.CALL("printi");
		_pf.TRASH(4); // delete the printed value
	}
	else if (node->argument()->type()->name() == basic_type::TYPE_STRING) {
		_pf.CALL("prints");
		_pf.TRASH(4); // delete the printed value's address
	}
	else {
		std::cerr << "PRINT ERROR: CANNOT HAPPEN!" << std::endl;
		exit(1);
	}
}

//---------------------------------------------------------------------------

void pwn::postfix_writer::do_read_node(pwn::read_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);
	_pf.CALL("readi");
	_pf.PUSH();
	// node->argument()->accept(this, lvl);
	_pf.STORE();
}

//---------------------------------------------------------------------------

void pwn::postfix_writer::do_while_node(cdk::while_node * const node, int lvl) {
	int lbl1, lbl2;
	_pf.LABEL(mklbl(lbl1 = ++_lbl));
	node->condition()->accept(this, lvl);
	_pf.JZ(mklbl(lbl2 = ++_lbl));
	node->block()->accept(this, lvl + 2);
	_pf.JMP(mklbl(lbl1));
	_pf.LABEL(mklbl(lbl2));
}

//---------------------------------------------------------------------------

void pwn::postfix_writer::do_if_node(cdk::if_node * const node, int lvl) {
	int lbl1;
	node->condition()->accept(this, lvl);
	_pf.JZ(mklbl(lbl1 = ++_lbl));
	node->block()->accept(this, lvl + 2);
	_pf.LABEL(mklbl(lbl1));
}

//---------------------------------------------------------------------------

void pwn::postfix_writer::do_if_else_node(cdk::if_else_node * const node, int lvl) {
	int lbl1, lbl2;
	node->condition()->accept(this, lvl);
	_pf.JZ(mklbl(lbl1 = ++_lbl));
	node->thenblock()->accept(this, lvl + 2);
	_pf.JMP(mklbl(lbl2 = ++_lbl));
	_pf.LABEL(mklbl(lbl1));
	node->elseblock()->accept(this, lvl + 2);
	_pf.LABEL(mklbl(lbl1 = lbl2));
}

//------------Novos nodes-----------------------------------------------


void pwn::postfix_writer::do_repeat_node(pwn::repeat_node * const node, int lvl) {
	
	std::string label_cond = mklbl(++_lbl);
	std::string label_end = mklbl(++_lbl);
	std::string label_after = mklbl(++_lbl);
	
	_stops.push_back(label_end);
	_nexts.push_back(label_after);
	
	_symtab.push();
	
	node->before()->accept(this, lvl+2);
	
	_pf.ALIGN();
	_pf.LABEL(label_cond);
	
	node->condition()->accept(this, lvl+2);
	_pf.JZ(label_end); //salta para o final caso a condicao seja falsa
	
	node->block()->accept(this, lvl+2);
	
	_pf.ALIGN();
	_pf.LABEL(label_after);
	
	node->after()->accept(this, lvl+2);
	
	_pf.JMP(label_cond); //volta para o inicio
	
	_pf.ALIGN();
	_pf.LABEL(label_end);
	
	_stops.pop_back();
	_nexts.pop_back();
	
	_symtab.pop();
	
}
void pwn::postfix_writer::do_stop_node(pwn::stop_node * const node, int lvl) {
	
	if (node->value() < (int)_stops.size())
		_pf.JMP(_stops[_stops.size() - node->value()]);
	else
		throw node->lineno() + " stop arg too big";
}
void pwn::postfix_writer::do_and_node(pwn::and_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);
	node->left()->accept(this, lvl);
	node->right()->accept(this, lvl);
	_pf.AND();
}
void pwn::postfix_writer::do_or_node(pwn::or_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);
	node->left()->accept(this, lvl);
	node->right()->accept(this, lvl);
	_pf.OR();
}
void pwn::postfix_writer::do_return_node(pwn::return_node * const node, int lvl) {
	_pf.POP();
	_pf.LEAVE();
	_pf.RET();
}
void pwn::postfix_writer::do_identity_node(pwn::identity_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);
	node->argument()->accept(this, lvl+2);
}
void pwn::postfix_writer::do_next_node(pwn::next_node * const node, int lvl) {
	if (node->value() < (int)_nexts.size())
		_pf.JMP(_nexts[_nexts.size() - node->value()]);
	else
		throw node->lineno() + " next arg too big";
}
void pwn::postfix_writer::do_noob_node(pwn::noob_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);
	_pf.LOCAL(0);
}
void pwn::postfix_writer::do_index_node(pwn::index_node * const node, int lvl) {
	
	CHECK_TYPES(_compiler, _symtab, node);
	
	node->var()->accept(this, lvl+1);
	_pf.LOAD();
	
	node->value()->accept(this, lvl+1);
	_pf.LOAD();
	
	_pf.INT(node->var()->type()->size());
	_pf.MUL();
	_pf.ADD();
}
void pwn::postfix_writer::do_block_node(pwn::block_node * const node, int lvl) {
	if(node->vars())
		node->vars()->accept(this, lvl + 2);
	if(node->instructions())
		node->instructions()->accept(this, lvl + 2);
}
void pwn::postfix_writer::do_func_decl_node(pwn::func_decl_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);
	std::cout << "------ DECL -------" << std::endl;
	
	
	
	std::string * name = node->name(); //nome da funcao
	const std::string &cName = *name;
	if(cName == "pwn"){
		name = new std::string("_main");
	}
	else if(cName == "_main"){
		name = new std::string("._main");
	}
	
	const std::string &sName = *name;
	std::shared_ptr<pwn::symbol> symbol = _symtab.find(sName);
}

void pwn::postfix_writer::do_func_call_node(pwn::func_call_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);
	
	size_stack sc(_compiler, node);
	std::string * name = node->name(); //nome da funcao
	const std::string &fName = * name;
	if(node->arguments() != NULL){
		node->arguments()->accept(this, lvl+1);
	}
	
	_pf.CALL(fName);
	_pf.TRASH(sc.size());
	
	const std::string &cName = * name;
	if(cName == "pwn"){
		name = new std::string("_main");
	}
	else if(cName == "_main"){
		name = new std::string("._main");
	}
	const std::string &sName = * name;

	std::shared_ptr<pwn::symbol> symbol = _symtab.find(sName);
	
	if( (symbol->type()->name() == basic_type::TYPE_INT) || (symbol->type()->name() == basic_type::TYPE_STRING) )
		_pf.PUSH();
	
	if(symbol->type()->name() == basic_type::TYPE_DOUBLE)
		_pf.DPUSH();
	
}
void pwn::postfix_writer::do_var_node(pwn::var_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);
	
	const std::string &id = *node->var();
	std::shared_ptr<pwn::symbol> symbol = _symtab.find(id);
	
	std::cout<<"--------------VAR NODE PF ----------------" << symbol->type()->name() <<std::endl;
	
	if(symbol->value() == 0) { //Local Variable
		_pf.LOCAL(symbol->offset());
		std::cout<<"--------------OFFFFSETTTTTTTT ----------------" << symbol->offset() <<std::endl;
		
		
	} else if (symbol->value() == -1) { // Global variable
		_pf.ADDR(*node->var());
	}
	
}

void pwn::postfix_writer::do_var_decl_node(pwn::var_decl_node * const node, int lvl) {
	
	CHECK_TYPES(_compiler, _symtab, node);
	
	std::cout<<"--------------VAR DECL PF ----------------" << node->type()->name() <<std::endl; 
	
	std::string * qualifier = node->qualifier();
	const std::string &qual = * qualifier;
	if (qual == "import") { //TODO remove this
		_pf.EXTERN(*node->name()->var());
		return;
	}
	
	const std::string &id = *node->name()->var();
	std::shared_ptr<pwn::symbol> symbol = _symtab.find(id);
	std::cout<<"--------------VAR DECL SYM PF ----------------" << symbol->type()->name() <<std::endl;
	
	if (symbol->value() == 0) { //Local Variable

		_offset_vars -= symbol->type()->size();
		symbol->offset(_offset_vars);
		
	} else if (symbol->value() == -1) { // Global variable
		/*_pf.BSS();
				_pf.ALIGN();
				_pf.LABEL(*node->name()->var());
				_pf.BYTE(node->type()->size());*/
		
		_pf.DATA();
		_pf.ALIGN();
		_pf.LABEL(*node->name()->var());
	}
}

void pwn::postfix_writer::do_println_node(pwn::println_node * const node, int lvl) {
	std::cout<<"--------------PRINTLN----------------"<<std::endl;
	CHECK_TYPES(_compiler, _symtab, node);
	node->argument()->accept(this, lvl); // determine the value to print
	if (node->argument()->type()->name() == basic_type::TYPE_INT) {
		_pf.CALL("printi");
		_pf.TRASH(4); // delete the printed value
	}
	else if (node->argument()->type()->name() == basic_type::TYPE_STRING) {
		_pf.CALL("prints");
		_pf.TRASH(4); // delete the printed value's address
	}
	else {
		std::cerr << "PRINTLN ERROR: CANNOT HAPPEN!" << std::endl;
		exit(1);
	}
	_pf.CALL("println"); // print a newline
}
void pwn::postfix_writer::do_maloc_node(pwn::maloc_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);
	
	_pf.INT(node->type()->size()); //coloca o tamanho do tipo na pilha
	_pf.INT(node->value()); //coloca o valor na pilha
	
	_pf.MUL(); //multiplica o valor pelo tamanho
	_pf.ALLOC(); //alocar memoria
	_pf.SP(); //coloca endereço do espaco alocado na pilha
}
void pwn::postfix_writer::do_mem_address_node(pwn::mem_address_node * const node, int lvl) {
	
	CHECK_TYPES(_compiler, _symtab, node);
	node->argument()->accept(this, lvl+2);
	
}
void pwn::postfix_writer::do_not_node(pwn::not_node * const node, int lvl) {
	CHECK_TYPES(_compiler, _symtab, node);
	node->argument()->accept(this, lvl); // determine the value
	_pf.NOT(); // 2-complement
}

