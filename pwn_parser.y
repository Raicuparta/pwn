%{
// $Id: pwn_parser.y,v 1.2 2015/03/25 11:17:11 ist173639 Exp $
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
%token tIF tPRINT tREAD tBEGIN tEND tREPEAT tNEXT tSTOP
%token tLOCAL tIMPORT tRETURN tPRINTLN

%nonassoc tIFX
%nonassoc tELSE

%right '='
%left tGE tLE tEQ tNE '>' '<'
%left '+' '-' 
%left '*' '/' '%'
%left '&' '|'
%left '~'
%nonassoc tUNARY

%type <node> stmt   
%type <sequence> args declist stmtlist
%type <expression> expr literal decl
%type <lvalue> lval 
%type <btype> type ftype
%type <s> qualifier
%type <var> var
%type <func> func
%type <block> block
%type <index> index
%type <in> arg

%{
//-- The rules below will be included in yyparse, the main parsing function.
%}
%%

//-- program	: tBEGIN list tEND { compiler->ast(new pwn::program_node(LINE, $2)); }
	//--      ;

declist : decl	     			{ $$ = new cdk::sequence_node(LINE, $1); }
		| declist decl 			{ $$ = new cdk::sequence_node(LINE, $2, $1); }
		;
		
stmtlist : stmt	     			{ $$ = new cdk::sequence_node(LINE, $1); }
		| stmtlist stmt 			{ $$ = new cdk::sequence_node(LINE, $2, $1); }
		;
		
literal : tSTRING		{$$ = new cdk::string_node(LINE, $1); }
			|tREAL		{$$ = new cdk::double_node(LINE, $1); }
			|tINTEGER		{$$ = new cdk::integer_node(LINE, $1); }
			|tNOOB		{$$ = new pwn::noob_node(LINE); }
			;	   
			
decl :  qualifier type var					{ $$ = new pwn::var_decl_node(LINE, $3, $2); }
		|  qualifier func 					{ $$ = new pwn::func_def_node(LINE, $2, NULL, NULL, $1); }
		|  qualifier func '=' literal		{ $$ = new pwn::func_def_node(LINE, $2, NULL, $4, $1); }
		|  qualifier func block				{ $$ = new pwn::func_def_node(LINE, $2, $3, NULL, $1); }
		|  qualifier func '=' literal block	{ $$ = new pwn::func_def_node(LINE, $2, $5, $4, $1); }
		;
		
qualifier: tLOCAL			{$$ = new std::string("local"); }
			| tIMPORT			{$$ = new std::string("import"); }
			|					{$$ = new std::string("public"); }
			;
		
var :  tIDENTIFIER		{ $$ = new pwn::var_node(LINE, $1); }	
		;
		
func : ftype tIDENTIFIER '(' args ')'		{ $$ = new pwn::func_decl_node(LINE, $2, $1, $4); }
	| ftype tIDENTIFIER 	'(' ')'			{ $$ = new pwn::func_decl_node(LINE, $2, $1, NULL); }
	;
	
ftype :'!'			{$$ = new basic_type(4, basic_type::TYPE_VOID); }
		| type			{$$ = $1; }
		;
	
args : var	     			{ $$ = new cdk::sequence_node(LINE, $1); }
		| args ',' var 		{ $$ = new cdk::sequence_node(LINE, $3, $1); }
		;
		
arg : tINTEGER	{ $$ = new cdk::integer_node(LINE, $1); }
	| 			{ $$ = new cdk::integer_node(LINE, 1); }
	;
		
type : '#'				{ $$ = new basic_type(4, basic_type::TYPE_INT); }
		|'%'				{ $$ = new basic_type(8, basic_type::TYPE_DOUBLE); }
		|'$'				{ $$ = new basic_type(4, basic_type::TYPE_STRING); }
		|'*'				{ $$ = new basic_type(4, basic_type::TYPE_POINTER); }
		//TODO CONST TYPES
		|"<#>"				{ $$ = new basic_type(4, basic_type::TYPE_INT); }
		|"<%>"				{ $$ = new basic_type(8, basic_type::TYPE_DOUBLE); }
		|"<$>"				{ $$ = new basic_type(4, basic_type::TYPE_STRING); }
		|"<*>"				{ $$ = new basic_type(4, basic_type::TYPE_POINTER); }
		;
		
		
block : '{' declist stmtlist '}'    { $$ = new pwn::block_node(LINE, $3, $2); }
		  | '{' stmtlist '}'    { $$ = new pwn::block_node(LINE, $2); }
		  | "{}"								{ $$ = new pwn::block_node(LINE, NULL); }
		  
		  //TODO ARGUMENTS
		;

stmt : expr ';'                        							{ $$ = new pwn::evaluation_node(LINE, $1); }
		| expr tPRINT		                								{ $$ = new pwn::print_node(LINE, $1); }
		| expr tPRINTLN                									{ $$ = new pwn::println_node(LINE, $1); }
		| tREAD                    											{ $$ = new pwn::read_node(LINE); }
		| tNEXT arg ';'                 										{ $$ = new pwn::next_node(LINE, $2); }
		| tSTOP arg ';'                 										{ $$ = new pwn::stop_node(LINE, $2); }
		| tRETURN ';'																				{ $$ = new pwn::return_node(LINE); }
		| tREPEAT '(' expr ';' expr ';' expr ')' stmt		{$$ = new pwn::repeat_node(LINE, $3, $5, $7, $9); }
		| tIF '(' expr ')' stmt %prec tIFX 								{ $$ = new cdk::if_node(LINE, $3, $5); }
		| tIF '(' expr ')' stmt tELSE stmt 							{ $$ = new cdk::if_else_node(LINE, $3, $5, $7); }
		| block																					{ $$ = $1; }
		;

expr : tINTEGER                { $$ = new cdk::integer_node(LINE, $1); }
	| tSTRING                 { $$ = new cdk::string_node(LINE, $1); }
		| '-' expr %prec tUNARY   { $$ = new cdk::neg_node(LINE, $2); }
		| '~' expr 			     { $$ = new pwn::not_node(LINE, $2); }
		| expr '+' expr	         { $$ = new cdk::add_node(LINE, $1, $3); }
		| expr '-' expr	         { $$ = new cdk::sub_node(LINE, $1, $3); }
		| expr '*' expr	         { $$ = new cdk::mul_node(LINE, $1, $3); }
		| expr '/' expr	         { $$ = new cdk::div_node(LINE, $1, $3); }
		| expr '%' expr	         { $$ = new cdk::mod_node(LINE, $1, $3); }
		| expr '<' expr	         { $$ = new cdk::lt_node(LINE, $1, $3); }
		| expr '|' expr	         { $$ = new pwn::or_node(LINE, $1, $3); }
		| expr '&' expr	         { $$ = new pwn::and_node(LINE, $1, $3); }
		| expr '>' expr	         { $$ = new cdk::gt_node(LINE, $1, $3); }
		| expr tGE expr	         { $$ = new cdk::ge_node(LINE, $1, $3); }
		| expr tLE expr           	 { $$ = new cdk::le_node(LINE, $1, $3); }
		| expr tNE expr	         { $$ = new cdk::ne_node(LINE, $1, $3); }
		| expr tEQ expr	       	 { $$ = new cdk::eq_node(LINE, $1, $3); }
		| '(' expr ')'              { $$ = $2; }
		| lval '=' expr             { $$ = new pwn::assignment_node(LINE, $1, $3); }
		| lval '=' '[' tINTEGER ']' { $$ = new pwn::maloc_node(LINE, $4); } 					 					
		;

lval : index		{ $$ = $1; }
	| var			{ $$ = $1; }
		;
		
index : lval '[' lval ']'		{ $$ = new pwn::index_node(LINE, $1, $3); }
			;


%%
