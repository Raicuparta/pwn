%{
// $Id: pwn_parser.y,v 1.5 2015/04/14 10:00:27 ist173639 Exp $
//-- don't change *any* of these: if you do, you'll break the compiler.
#include <cdk/compiler.h>
#include "ast/all.h"
#define LINE       compiler->scanner()->lineno()
#define yylex()    compiler->scanner()->scan()
#define yyerror(s) compiler->scanner()->error(s)
#define YYPARSE_PARAM_TYPE std::shared_ptr<cdk::compiler>
#define YYPARSE_PARAM      compiler
//-- don't change *any* of these --- END!
%}

%union {
	int                   i;	/* integer value */
	double				d;	/* double value */
	std::string          *s;	/* symbol name or string literal */
	cdk::basic_node      *node;	/* node pointer */
	cdk::sequence_node   *sequence;
	cdk::expression_node *expression; /* expression nodes */
	pwn::lvalue_node  *lvalue;
	pwn::var_node *var;
	pwn::func_decl_node *func;
	pwn::block_node * block;
	pwn::index_node * index;
	cdk::integer_node * in;
	
	basic_type			*btype;
};

%token <node> tNOOB
%token <d> tREAL
%token <i> tINTEGER
%token <s> tIDENTIFIER tSTRING
%token tIF tREAD tBEGIN tEND tREPEAT tNEXT tSTOP
%token tLOCAL tIMPORT tRETURN tPRINTLN

%nonassoc tIFX
%nonassoc tELSE
%nonassoc LOWER_THAN_ELSE

%right '=' 
%left tGE tLE tEQ tNE '>' '<'
%left '+' '-' 
%left '*' '/' '%'
%left '&' '|'
%left '~'
%nonassoc tUNARY '{' '(' 

%type <node> stmt
%type <sequence> argscall argsdecl declist stmtlist exprlist
%type <expression> expr literal decl vardecl funcdecl funcall
%type <lvalue> lval 
%type <btype> type 
%type <s> qualifier string
%type <var> var
%type <func> func
%type <block> block
%type <index> index
%type <in> arg

%{
//-- The rules below will be included in yyparse, the main parsing function.
%}
%%

file : declist 							{ compiler->ast($1); }
     ;
	
declist : decl	     						{ $$ = new cdk::sequence_node(LINE, $1); }
	| declist decl 						{ $$ = new cdk::sequence_node(LINE, $2, $1); }
	;
		
stmtlist : stmt	     						{ $$ = new cdk::sequence_node(LINE, $1); }
	 | stmtlist stmt 					{ $$ = new cdk::sequence_node(LINE, $2, $1); }
	 ;
		
literal : tSTRING						{$$ = new cdk::string_node(LINE, $1); }
	|tREAL							{$$ = new cdk::double_node(LINE, $1); }
	|tINTEGER						{$$ = new cdk::integer_node(LINE, $1); }
	|tNOOB							{$$ = new pwn::noob_node(LINE); }
	;	   
			
decl : vardecl ';' 						{ $$ = $1; }
     | funcdecl							{ $$ = $1; }
     ;
		
vardecl : qualifier type var %prec LOWER_THAN_ELSE		{ $$ = new pwn::var_decl_node(LINE, $3, $2); }
	| qualifier type var '=' expr				{ $$ = new pwn::assignment_node(LINE, new pwn::var_decl_node(LINE, $3, $2), $3);}
	;

funcdecl : qualifier func %prec LOWER_THAN_ELSE			{ $$ = new pwn::func_def_node(LINE, $2, nullptr, nullptr, $1); }
	 |  qualifier func '=' literal				{ $$ = new pwn::func_def_node(LINE, $2, nullptr, $4, $1); }
	 |  qualifier func block				{ $$ = new pwn::func_def_node(LINE, $2, $3, nullptr, $1); }
	 |  qualifier func '=' literal block			{ $$ = new pwn::func_def_node(LINE, $2, $5, $4, $1); }
	 ;
		
funcall : tIDENTIFIER '(' argscall ')'				{ $$ = new pwn::func_call_node(LINE, $1, $3); }
	| tIDENTIFIER '(' ')'					{ $$ = new pwn::func_call_node(LINE, $1, nullptr); }
	;
		
qualifier : tLOCAL						{$$ = new std::string("local"); }
	  | tIMPORT						{$$ = new std::string("import"); }
	  |							{$$ = new std::string("public"); }
	  ;
		
var :  tIDENTIFIER %prec LOWER_THAN_ELSE			{ $$ = new pwn::var_node(LINE, $1); }	
    ;
		
func : type tIDENTIFIER '(' ')'					{ $$ = new pwn::func_decl_node(LINE, $2, $1, nullptr); }
     | type tIDENTIFIER 	'(' argsdecl ')'		{ $$ = new pwn::func_decl_node(LINE, $2, $1,$4 ); }
     | '!' tIDENTIFIER '(' ')'					{ $$ = new pwn::func_decl_node(LINE, $2, new basic_type(4, basic_type::TYPE_VOID), nullptr); }
     | '!' tIDENTIFIER 	'(' argsdecl ')'			{ $$ = new pwn::func_decl_node(LINE, $2, new basic_type(4, basic_type::TYPE_VOID),$4 ); }
     ;
	
argsdecl : vardecl	     					{ $$ = new cdk::sequence_node(LINE, $1); }
	 | argsdecl ',' vardecl 				{ $$ = new cdk::sequence_node(LINE, $3, $1); }
	 ;

argscall : expr	     						{ $$ = new cdk::sequence_node(LINE, $1); }
	 | argscall ',' expr 					{ $$ = new cdk::sequence_node(LINE, $3, $1); }
	 ;
		
arg : tINTEGER							{ $$ = new cdk::integer_node(LINE, $1); }
    | 								{ $$ = new cdk::integer_node(LINE, 1); }
    ;
		
type : '#'							{ $$ = new basic_type(4, basic_type::TYPE_INT); }
     |'%'							{ $$ = new basic_type(8, basic_type::TYPE_DOUBLE); }
     |'$'							{ $$ = new basic_type(4, basic_type::TYPE_STRING); }
     |'*'							{ $$ = new basic_type(4, basic_type::TYPE_POINTER); }
     //TODO CONST TYPES
     |"<#>"							{ $$ = new basic_type(4, basic_type::TYPE_INT); }
     |"<%>"							{ $$ = new basic_type(8, basic_type::TYPE_DOUBLE); }
     |"<$>"							{ $$ = new basic_type(4, basic_type::TYPE_STRING); }
     |"<*>"							{ $$ = new basic_type(4, basic_type::TYPE_POINTER); }
     ;
		
		
block : '{' declist stmtlist '}'   				{ $$ = new pwn::block_node(LINE, $3, $2); }
      | '{' stmtlist '}'   					{ $$ = new pwn::block_node(LINE, $2); }
      | '{' declist '}'    					{ $$ = new pwn::block_node(LINE, nullptr, $2); }
      | '{' '}'							{ $$ = new pwn::block_node(LINE, nullptr); }
      //TODO ARGUMENTS
      ;

stmt : expr ';'                        				{ $$ = new pwn::evaluation_node(LINE, $1); }
     | expr '!'		                			{ $$ = new pwn::print_node(LINE, $1); }
     | expr tPRINTLN              				{ $$ = new pwn::println_node(LINE, $1); }
     | tNEXT arg ';'                 				{ $$ = new pwn::next_node(LINE, $2); }
     | tSTOP arg ';'                				{ $$ = new pwn::stop_node(LINE, $2); }
     | tRETURN							{ $$ = new pwn::return_node(LINE); }
     | tREPEAT '(' exprlist ';' exprlist ';' exprlist ')' stmt	{ $$ = new pwn::repeat_node(LINE, $3, $5, $7, $9); }
     | tIF '(' expr ')' stmt %prec tIFX 			{ $$ = new cdk::if_node(LINE, $3, $5); }
     | tIF '(' expr ')' stmt tELSE stmt 			{ $$ = new cdk::if_else_node(LINE, $3, $5, $7); }
     | block							{ $$ = $1; }
     ;

exprlist : expr							{ $$ = new cdk::sequence_node(LINE, $1); }
	 | exprlist ','  expr 					{ $$ = new cdk::sequence_node(LINE, $3, $1); }
	 ;

string : tSTRING           					{ $$ = $1; }
       | string tSTRING   					{ $$ = new std::string(*$1 + *$2); }
       ;


expr : tINTEGER                					{ $$ = new cdk::integer_node(LINE, $1); }
     | string  												{ $$ = new cdk::string_node(LINE, $1); }
	   | '-' expr %prec tUNARY  					{ $$ = new cdk::neg_node(LINE, $2); }
     | '~' expr %prec tUNARY 			     		{ $$ = new pwn::not_node(LINE, $2); }
     | expr '+' expr	     						{ $$ = new cdk::add_node(LINE, $1, $3); }
     | expr '-' expr	         				{ $$ = new cdk::sub_node(LINE, $1, $3); }
     | expr '*' expr	         				{ $$ = new cdk::mul_node(LINE, $1, $3); }
     | expr '/' expr	         				{ $$ = new cdk::div_node(LINE, $1, $3); }
     | expr '%' expr	         				{ $$ = new cdk::mod_node(LINE, $1, $3); }
     | expr '<' expr	         				{ $$ = new cdk::lt_node(LINE, $1, $3); }
     | expr '|' expr	         				{ $$ = new pwn::or_node(LINE, $1, $3); }
     | expr '&' expr	         				{ $$ = new pwn::and_node(LINE, $1, $3); }
     | expr '>' expr	         				{ $$ = new cdk::gt_node(LINE, $1, $3); }
     | expr tGE expr	         				{ $$ = new cdk::ge_node(LINE, $1, $3); }
     | expr tLE expr           	 				{ $$ = new cdk::le_node(LINE, $1, $3); }
     | expr tNE expr	         				{ $$ = new cdk::ne_node(LINE, $1, $3); }
     | expr tEQ expr	       	 				{ $$ = new cdk::eq_node(LINE, $1, $3); }
     | '(' expr ')'              				{ $$ = $2; }
     | tREAD                    				{ $$ = new pwn::read_node(LINE); }
     | lval '=' expr             				{ $$ = new pwn::assignment_node(LINE, $1, $3); }
     | lval '=' '[' tINTEGER ']' 				{ $$ = new pwn::maloc_node(LINE, $4); } 	
     | lval							{ $$ = $1; }
     | funcall							{ $$ = $1; }
     ;

lval : index							{ $$ = $1; }
     | var							{ $$ = $1; }
     ;
		
index : lval '[' lval ']'					{ $$ = new pwn::index_node(LINE, $1, $3); }
      ;



%%
