// $Id: type_checker.h,v 1.7 2015/04/14 10:00:27 ist173639 Exp $ -*- c++ -*-
#ifndef __PWN_SEMANTICS_TYPE_CHECKER_H__
#define __PWN_SEMANTICS_TYPE_CHECKER_H__

#include <string>
#include <iostream>
#include <cdk/symbol_table.h>
#include <cdk/ast/basic_node.h>
#include "targets/symbol.h"
#include "targets/basic_ast_visitor.h"

namespace pwn {

  /**
   * Print nodes as XML elements to the output stream.
   */
  class type_checker: public basic_ast_visitor {
    cdk::symbol_table<pwn::symbol> &_symtab;

  public:
    type_checker(std::shared_ptr<cdk::compiler> compiler, cdk::symbol_table<pwn::symbol> &symtab) :
        basic_ast_visitor(compiler), _symtab(symtab) {
    }

  public:
    ~type_checker() {
      os().flush();
    }

  public:
    void do_sequence_node(cdk::sequence_node * const node, int lvl) {
    }

  protected:
    template<typename T>
    void processSimple(cdk::simple_value_node<T> * const node, int lvl) {
    }

  public:
    void do_integer_node(cdk::integer_node * const node, int lvl);
    void do_string_node(cdk::string_node * const node, int lvl);

  protected:
    void processUnaryExpression(cdk::unary_expression_node * const node, int lvl);

  public:
    void do_neg_node(cdk::neg_node * const node, int lvl);

  protected:
    void processBinaryExpression(cdk::binary_expression_node * const node, int lvl);
		void processAddSub(cdk::binary_expression_node * const node, int lvl);

	protected:
		bool compareType(const basic_type::type type, const basic_type::type accepedTypes[]);

  public:
    void do_add_node(cdk::add_node * const node, int lvl);
    void do_sub_node(cdk::sub_node * const node, int lvl);
    void do_mul_node(cdk::mul_node * const node, int lvl);
    void do_div_node(cdk::div_node * const node, int lvl);
    void do_mod_node(cdk::mod_node * const node, int lvl);
    void do_lt_node(cdk::lt_node * const node, int lvl);
    void do_le_node(cdk::le_node * const node, int lvl);
    void do_ge_node(cdk::ge_node * const node, int lvl);
    void do_gt_node(cdk::gt_node * const node, int lvl);
    void do_ne_node(cdk::ne_node * const node, int lvl);
    void do_eq_node(cdk::eq_node * const node, int lvl);

  public:
    void do_while_node(cdk::while_node * const node, int lvl);
    void do_if_node(cdk::if_node * const node, int lvl);
    void do_if_else_node(cdk::if_else_node * const node, int lvl);

  public:
//    void do_lvalue_node(pwn::lvalue_node * const node, int lvl);
    void do_rvalue_node(pwn::rvalue_node * const node, int lvl);

  public:

    void do_evaluation_node(pwn::evaluation_node * const node, int lvl);
    void do_print_node(pwn::print_node * const node, int lvl);
    void do_read_node(pwn::read_node * const node, int lvl);
    void do_assignment_node(pwn::assignment_node * const node, int lvl);
		
/*Novos nodes*/
	public:
		void do_repeat_node(pwn::repeat_node * const node, int lvl);
		void do_stop_node(pwn::stop_node * const node, int lvl);
		void do_and_node(pwn::and_node * const node, int lvl);
		void do_or_node(pwn::or_node * const node, int lvl);
		void do_return_node(pwn::return_node * const node, int lvl);
		void do_identity_node(pwn::identity_node * const node, int lvl);
		void do_next_node(pwn::next_node * const node, int lvl);
		void do_noob_node(pwn::noob_node * const node, int lvl);
		void do_index_node(pwn::index_node * const node, int lvl);
		void do_block_node(pwn::block_node * const node, int lvl);
		void do_func_decl_node(pwn::func_decl_node * const node, int lvl);
		void do_func_def_node(pwn::func_def_node * const node, int lvl);
		void do_func_call_node(pwn::func_call_node * const node, int lvl);
		void do_var_node(pwn::var_node * const node, int lvl);
		void do_var_decl_node(pwn::var_decl_node * const node, int lvl);
		void do_println_node(pwn::println_node * const node, int lvl);
		void do_maloc_node(pwn::maloc_node * const node, int lvl);
		void do_mem_address_node(pwn::mem_address_node * const node, int lvl);
		void do_not_node(pwn::not_node * const node, int lvl);


  };

} // pwn

//---------------------------------------------------------------------------
//     HELPER MACRO FOR TYPE CHECKING
//---------------------------------------------------------------------------

#define CHECK_TYPES(compiler, symtab, node) { \
  try { \
    pwn::type_checker checker(compiler, symtab); \
    (node)->accept(&checker, 0); \
  } \
  catch (std::string &problem) { \
    std::cerr << (node)->lineno() << ": FATAL: " << problem << std::endl; \
    return; \
  } \
}

#endif
