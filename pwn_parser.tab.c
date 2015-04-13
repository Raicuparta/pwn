#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20120115

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "pwn_parser.y"
/* $Id: pwn_parser.y,v 1.2 2015/03/25 11:17:11 ist173639 Exp $*/
/*-- don't change *any* of these: if you do, you'll break the compiler.*/
#include <cdk/compiler.h>
#include "ast/all.h"
#define LINE       compiler->scanner()->lineno()
#define yylex()    compiler->scanner()->scan()
#define yyerror(s) compiler->scanner()->error(s)
#define YYPARSE_PARAM_TYPE std::shared_ptr<cdk::compiler>
#define YYPARSE_PARAM      compiler
/*-- don't change *any* of these --- END!*/
#line 14 "pwn_parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
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
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 62 "pwn_parser.y"
/*-- The rules below will be included in yyparse, the main parsing function.*/
#line 56 "pwn_parser.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define tNOOB 257
#define tREAL 258
#define tINTEGER 259
#define tIDENTIFIER 260
#define tSTRING 261
#define tIF 262
#define tPRINT 263
#define tREAD 264
#define tBEGIN 265
#define tEND 266
#define tREPEAT 267
#define tNEXT 268
#define tSTOP 269
#define tLOCAL 270
#define tIMPORT 271
#define tRETURN 272
#define tPRINTLN 273
#define tIFX 274
#define tELSE 275
#define tGE 276
#define tLE 277
#define tEQ 278
#define tNE 279
#define tUNARY 280
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    3,    3,    5,    5,    5,    5,    6,    6,
    6,    6,    6,   10,   10,   10,   11,   12,   12,    9,
    9,    2,    2,   15,   15,    8,    8,    8,    8,    8,
    8,    8,    8,   13,   13,   13,   13,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    4,    4,
    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
    4,    4,    4,    4,    4,    4,    4,    4,    7,    7,
   14,
};
static const short yylen[] = {                            2,
    1,    2,    1,    2,    1,    1,    1,    1,    3,    2,
    4,    3,    5,    1,    1,    0,    1,    4,    5,    1,
    1,    1,    3,    1,    0,    1,    1,    1,    1,    1,
    1,    1,    1,    4,    3,    3,    2,    2,    2,    2,
    1,    3,    3,    2,    9,    5,    7,    1,    1,    1,
    2,    2,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    5,    1,    1,
    4,
};
static const short yydefred[] = {                         0,
   14,   15,    0,    1,    0,    2,   29,   27,   20,   26,
   28,   30,   31,   32,   33,    0,    0,    0,   17,    9,
    0,    0,    0,   12,    0,    8,    6,    7,    5,    0,
   49,   50,    0,   41,    0,    0,    0,    0,    0,    0,
    0,   37,    0,    3,    0,    0,    0,   70,   48,   69,
   18,    0,   22,   13,    0,    0,   24,    0,    0,   44,
   51,   52,    0,   36,    0,   35,    4,   39,   40,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   38,    0,    0,   19,    0,    0,    0,   42,
   43,   66,   34,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   60,   59,    0,    0,    0,   23,
    0,    0,    0,   71,    0,    0,   68,    0,    0,   47,
    0,    0,   45,
};
static const short yydgoto[] = {                          3,
   44,   52,   45,   46,   30,    4,   47,   16,   17,    5,
   48,   18,   49,   50,   58,
};
static const short yysindex[] = {                      -240,
    0,    0, -240,    0,  -33,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -234, -225,  -29,    0,    0,
   -1, -209,  435,    0,  -36,    0,    0,    0,    0,  -79,
    0,    0,    5,    0,   15, -201, -201,    6,  153,  153,
  153,    0,  454,    0,  468,   39,  -32,    0,    0,    0,
    0,   13,    0,    0,  153,  153,    0,    7,    9,    0,
    0,    0,  128,    0,  482,    0,    0,    0,    0,  153,
  153,  153,  153,  153,  153,  153,  153,  153,  153,  153,
  153,  153,    0,   16, -234,    0, -234,  140,  154,    0,
    0,    0,    0,  -24,  -24,  -24,  -24,  -24,  -24,  -22,
  -22,  -16,  -16,  -16,    0,    0, -189,  325,  -40,    0,
  522,  153,  -20,    0, -204,  180,    0,  522,  153,    0,
  297,  522,    0,
};
static const short yyrindex[] = {                       -25,
    0,    0,  -25,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    1,    0,    0,
    0,    0,  -25,    0,    0,    0,    0,    0,    0,   27,
    0,    0,    0,    0,    0,   19,   19,    0,    0,    0,
    0,    0,  -25,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  174,  349,  379,  386,  403,  414,  260,
  337,   50,   74,   98,    0,    0,    0,  -35,    0,    0,
    0,    0,    0,    0,  506,    0,    0,    0,    0,    0,
    0,    0,    0,
};
static const short yygindex[] = {                        51,
  119,    0,   32,  756,    0,    4,   -6,    0,    0,    0,
   17,    0,   10,    0,   43,
};
#define YYTABLESIZE 875
static const short yytable[] = {                          9,
   10,   10,   11,    8,   51,   67,    6,   16,    7,   16,
   16,   16,   80,   81,   80,   81,   16,   78,   76,   78,
   77,   81,   79,   67,   79,   19,   11,   24,   84,    1,
    2,   22,   20,   10,   21,   10,   10,   10,   25,   54,
   10,   53,   10,   23,   55,   10,    6,   26,   27,   28,
   85,   29,  114,   86,   56,   41,   87,   57,   85,   11,
   39,   11,   11,   11,   60,   90,   11,   91,   11,  113,
  118,   11,  117,   43,   65,   80,   81,   25,  109,   59,
   78,   76,    0,   77,    0,   79,   55,    0,    0,    0,
   55,   55,   55,   23,   55,    0,   55,   83,   75,   82,
   74,   82,    0,  110,    0,    0,  107,   82,   55,   55,
   56,   55,    0,    0,   56,   56,   56,    0,   56,    0,
   56,    0,    0,    0,    0,   10,   10,    0,    0,    0,
    0,    0,   56,   56,   57,   56,    0,    0,   57,   57,
   57,   40,   57,    0,   57,    0,    0,    0,    0,    0,
    0,   11,   11,    0,    0,    0,   57,   57,    0,   57,
    0,    0,   82,   67,   80,   81,    0,    0,   92,   78,
   76,    0,   77,    0,   79,    0,   80,   81,    0,    0,
  111,   78,   76,   67,   77,    0,   79,   75,    0,   74,
   80,   81,   41,    0,    0,   78,   76,   39,   77,   75,
   79,   74,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  112,   75,   62,   74,   80,   81,    0,    0,
    0,   78,   76,   19,   77,    0,   79,   67,    0,  115,
    0,    0,   62,   62,    0,   62,  120,   67,  119,   75,
  123,   74,    0,    0,    0,    0,    0,   12,   13,   14,
   15,   82,    0,    0,    0,   16,   16,   16,   16,   10,
   10,   10,   10,   82,   10,    0,    0,   10,   10,   10,
   10,   10,   10,    0,   31,   19,   32,   82,   40,    0,
    0,   10,   10,   10,   10,   11,   11,   11,   11,    0,
   11,    0,    0,   11,   11,   11,   11,   11,   11,    0,
   53,   68,   53,   82,   53,    0,    0,   11,   11,   11,
   11,   69,   55,    0,   70,   71,   72,   73,   53,   53,
    0,   53,   55,    0,    0,   55,   55,   55,   55,    0,
    0,    0,    0,   80,   81,    0,   56,  122,   78,   76,
    0,   77,    0,   79,    0,    0,   56,    0,    0,   56,
   56,   56,   56,    0,    0,    0,   75,    0,   74,    0,
   57,   80,   81,    0,    0,    0,   78,   76,    0,   77,
   57,   79,    0,   57,   57,   57,   57,   54,    0,   54,
    0,   54,    0,    0,   75,    0,   74,    0,    0,   63,
    0,    0,    0,    0,    0,   54,   54,    0,   54,    0,
    0,    0,    0,   70,   71,   72,   73,   63,   63,    0,
   63,   31,   19,   32,    0,   70,   71,   72,   73,   65,
   82,    0,    0,    0,    0,    0,   64,    0,    0,   70,
   71,   72,   73,    0,    0,    0,   62,   65,   65,    0,
   65,    0,    0,   61,   64,   64,   62,   64,   82,   62,
   62,   62,   62,    0,   58,   70,   71,   72,   73,    0,
    0,   61,   61,    0,   61,    0,    0,    0,    0,    0,
    0,    0,   58,   58,   41,   58,    0,    0,    0,   39,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   41,    0,    0,    0,    0,   39,    0,
    0,    0,    0,    0,    0,    0,    0,   41,    0,    0,
    0,    0,   39,    0,    0,    0,    0,    0,    0,    0,
    0,   41,   53,    0,    0,    0,   39,    0,    0,    0,
    0,    0,   53,    0,    0,   53,   53,   53,   53,    0,
    0,    0,    0,    0,    0,   46,    0,    0,    0,    0,
   46,    0,    0,    0,    0,    0,    0,   23,    0,   42,
   40,   41,    0,    0,    0,    0,   39,    0,    0,    0,
    0,    0,   70,   71,   72,   73,   23,    0,   64,   40,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   23,    0,   66,   40,    0,    0,    0,    0,    0,   54,
   70,   71,   72,   73,   23,    0,   93,   40,    0,   54,
    0,   63,   54,   54,   54,   54,    0,    0,    0,    0,
    0,   63,    0,    0,   63,   63,   63,   63,   46,    0,
   46,   46,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   65,    0,    0,   23,    0,    0,   40,   64,    0,
    0,   65,    0,    0,   65,   65,   65,   65,   64,    0,
    0,   64,   64,   64,   64,   61,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   61,   58,    0,   61,   61,
   61,   61,    0,    0,    0,    0,   58,    0,    0,   58,
   58,   58,   58,   31,   19,   32,   33,    0,   34,    0,
    0,   35,   36,   37,    1,    2,   38,    0,    0,    0,
    0,    0,   31,   19,   32,   33,    0,   34,    0,    0,
   35,   36,   37,    1,    2,   38,   31,   19,   32,   33,
    0,   34,    0,    0,   35,   36,   37,    0,    0,   38,
   31,   19,   32,   33,    0,   34,    0,    0,   35,   36,
   37,    0,    0,   38,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   46,   46,   46,   46,    0,   46,
    0,    0,   46,   46,   46,    0,    0,   46,    0,    0,
   31,   19,   32,   33,    0,   34,    0,    0,   35,   36,
   37,    0,    0,   38,   61,   62,   63,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   88,   89,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   94,   95,   96,   97,   98,
   99,  100,  101,  102,  103,  104,  105,  106,    0,  108,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  116,    0,    0,
    0,    0,    0,    0,  121,
};
static const short yycheck[] = {                         33,
    0,   35,   36,   37,   41,   41,    3,   33,   42,   35,
   36,   37,   37,   38,   37,   38,   42,   42,   43,   42,
   45,   38,   47,   59,   47,  260,    0,   18,   61,  270,
  271,   61,   16,   33,  260,   35,   36,   37,   40,   30,
   40,   25,   42,  123,   40,   45,   43,  257,  258,  259,
   91,  261,   93,   41,   40,   40,   44,  259,   91,   33,
   45,   35,   36,   37,   59,   59,   40,   59,   42,  259,
  275,   45,   93,   23,   43,   37,   38,   59,   85,   37,
   42,   43,   -1,   45,   -1,   47,   37,   -1,   -1,   -1,
   41,   42,   43,  123,   45,   -1,   47,   59,   60,  124,
   62,  124,   -1,   87,   -1,   -1,   91,  124,   59,   60,
   37,   62,   -1,   -1,   41,   42,   43,   -1,   45,   -1,
   47,   -1,   -1,   -1,   -1,  125,  126,   -1,   -1,   -1,
   -1,   -1,   59,   60,   37,   62,   -1,   -1,   41,   42,
   43,  126,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,
   -1,  125,  126,   -1,   -1,   -1,   59,   60,   -1,   62,
   -1,   -1,  124,   45,   37,   38,   -1,   -1,   41,   42,
   43,   -1,   45,   -1,   47,   -1,   37,   38,   -1,   -1,
   41,   42,   43,   65,   45,   -1,   47,   60,   -1,   62,
   37,   38,   40,   -1,   -1,   42,   43,   45,   45,   60,
   47,   62,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   59,   60,   41,   62,   37,   38,   -1,   -1,
   -1,   42,   43,  260,   45,   -1,   47,  263,   -1,  111,
   -1,   -1,   59,   60,   -1,   62,  118,  273,   59,   60,
  122,   62,   -1,   -1,   -1,   -1,   -1,  281,  282,  283,
  284,  124,   -1,   -1,   -1,  281,  282,  283,  284,  259,
  260,  261,  262,  124,  264,   -1,   -1,  267,  268,  269,
  270,  271,  272,   -1,  259,  260,  261,  124,  126,   -1,
   -1,  281,  282,  283,  284,  259,  260,  261,  262,   -1,
  264,   -1,   -1,  267,  268,  269,  270,  271,  272,   -1,
   41,  263,   43,  124,   45,   -1,   -1,  281,  282,  283,
  284,  273,  263,   -1,  276,  277,  278,  279,   59,   60,
   -1,   62,  273,   -1,   -1,  276,  277,  278,  279,   -1,
   -1,   -1,   -1,   37,   38,   -1,  263,   41,   42,   43,
   -1,   45,   -1,   47,   -1,   -1,  273,   -1,   -1,  276,
  277,  278,  279,   -1,   -1,   -1,   60,   -1,   62,   -1,
  263,   37,   38,   -1,   -1,   -1,   42,   43,   -1,   45,
  273,   47,   -1,  276,  277,  278,  279,   41,   -1,   43,
   -1,   45,   -1,   -1,   60,   -1,   62,   -1,   -1,   41,
   -1,   -1,   -1,   -1,   -1,   59,   60,   -1,   62,   -1,
   -1,   -1,   -1,  276,  277,  278,  279,   59,   60,   -1,
   62,  259,  260,  261,   -1,  276,  277,  278,  279,   41,
  124,   -1,   -1,   -1,   -1,   -1,   41,   -1,   -1,  276,
  277,  278,  279,   -1,   -1,   -1,  263,   59,   60,   -1,
   62,   -1,   -1,   41,   59,   60,  273,   62,  124,  276,
  277,  278,  279,   -1,   41,  276,  277,  278,  279,   -1,
   -1,   59,   60,   -1,   62,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   59,   60,   40,   62,   -1,   -1,   -1,   45,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   40,   -1,   -1,   -1,   -1,   45,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   40,   -1,   -1,
   -1,   -1,   45,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   40,  263,   -1,   -1,   -1,   45,   -1,   -1,   -1,
   -1,   -1,  273,   -1,   -1,  276,  277,  278,  279,   -1,
   -1,   -1,   -1,   -1,   -1,   40,   -1,   -1,   -1,   -1,
   45,   -1,   -1,   -1,   -1,   -1,   -1,  123,   -1,  125,
  126,   40,   -1,   -1,   -1,   -1,   45,   -1,   -1,   -1,
   -1,   -1,  276,  277,  278,  279,  123,   -1,  125,  126,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  123,   -1,  125,  126,   -1,   -1,   -1,   -1,   -1,  263,
  276,  277,  278,  279,  123,   -1,  125,  126,   -1,  273,
   -1,  263,  276,  277,  278,  279,   -1,   -1,   -1,   -1,
   -1,  273,   -1,   -1,  276,  277,  278,  279,  123,   -1,
  125,  126,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  263,   -1,   -1,  123,   -1,   -1,  126,  263,   -1,
   -1,  273,   -1,   -1,  276,  277,  278,  279,  273,   -1,
   -1,  276,  277,  278,  279,  263,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  273,  263,   -1,  276,  277,
  278,  279,   -1,   -1,   -1,   -1,  273,   -1,   -1,  276,
  277,  278,  279,  259,  260,  261,  262,   -1,  264,   -1,
   -1,  267,  268,  269,  270,  271,  272,   -1,   -1,   -1,
   -1,   -1,  259,  260,  261,  262,   -1,  264,   -1,   -1,
  267,  268,  269,  270,  271,  272,  259,  260,  261,  262,
   -1,  264,   -1,   -1,  267,  268,  269,   -1,   -1,  272,
  259,  260,  261,  262,   -1,  264,   -1,   -1,  267,  268,
  269,   -1,   -1,  272,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  259,  260,  261,  262,   -1,  264,
   -1,   -1,  267,  268,  269,   -1,   -1,  272,   -1,   -1,
  259,  260,  261,  262,   -1,  264,   -1,   -1,  267,  268,
  269,   -1,   -1,  272,   39,   40,   41,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   55,   56,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   70,   71,   72,   73,   74,
   75,   76,   77,   78,   79,   80,   81,   82,   -1,   84,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  112,   -1,   -1,
   -1,   -1,   -1,   -1,  119,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 284
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,"'#'","'$'","'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,
0,0,0,0,0,0,0,0,0,0,"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"tNOOB","tREAL",
"tINTEGER","tIDENTIFIER","tSTRING","tIF","tPRINT","tREAD","tBEGIN","tEND",
"tREPEAT","tNEXT","tSTOP","tLOCAL","tIMPORT","tRETURN","tPRINTLN","tIFX",
"tELSE","tGE","tLE","tEQ","tNE","tUNARY","\"<#>\"","\"<%>\"","\"<$>\"",
"\"<*>\"",
};
static const char *yyrule[] = {
"$accept : declist",
"declist : decl",
"declist : declist decl",
"stmtlist : stmt",
"stmtlist : stmtlist stmt",
"literal : tSTRING",
"literal : tREAL",
"literal : tINTEGER",
"literal : tNOOB",
"decl : qualifier type var",
"decl : qualifier func",
"decl : qualifier func '=' literal",
"decl : qualifier func block",
"decl : qualifier func '=' literal block",
"qualifier : tLOCAL",
"qualifier : tIMPORT",
"qualifier :",
"var : tIDENTIFIER",
"func : ftype tIDENTIFIER '(' ')'",
"func : ftype tIDENTIFIER '(' args ')'",
"ftype : '!'",
"ftype : type",
"args : var",
"args : args ',' var",
"arg : tINTEGER",
"arg :",
"type : '#'",
"type : '%'",
"type : '$'",
"type : '*'",
"type : \"<#>\"",
"type : \"<%>\"",
"type : \"<$>\"",
"type : \"<*>\"",
"block : '{' declist stmtlist '}'",
"block : '{' stmtlist '}'",
"block : '{' declist '}'",
"block : '{' '}'",
"stmt : expr ';'",
"stmt : expr tPRINT",
"stmt : expr tPRINTLN",
"stmt : tREAD",
"stmt : tNEXT arg ';'",
"stmt : tSTOP arg ';'",
"stmt : tRETURN ';'",
"stmt : tREPEAT '(' expr ';' expr ';' expr ')' stmt",
"stmt : tIF '(' expr ')' stmt",
"stmt : tIF '(' expr ')' stmt tELSE stmt",
"stmt : block",
"expr : tINTEGER",
"expr : tSTRING",
"expr : '-' expr",
"expr : '~' expr",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '<' expr",
"expr : expr '|' expr",
"expr : expr '&' expr",
"expr : expr '>' expr",
"expr : expr tGE expr",
"expr : expr tLE expr",
"expr : expr tNE expr",
"expr : expr tEQ expr",
"expr : '(' expr ')'",
"expr : lval '=' expr",
"expr : lval '=' '[' tINTEGER ']'",
"lval : index",
"lval : var",
"index : lval '[' lval ']'",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = data->s_mark - data->s_base;
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 69 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].expression); }
break;
case 2:
#line 70 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].expression, yystack.l_mark[-1].sequence); }
break;
case 3:
#line 73 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node); }
break;
case 4:
#line 74 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node, yystack.l_mark[-1].sequence); }
break;
case 5:
#line 77 "pwn_parser.y"
	{yyval.expression = new cdk::string_node(LINE, yystack.l_mark[0].s); }
break;
case 6:
#line 78 "pwn_parser.y"
	{yyval.expression = new cdk::double_node(LINE, yystack.l_mark[0].d); }
break;
case 7:
#line 79 "pwn_parser.y"
	{yyval.expression = new cdk::integer_node(LINE, yystack.l_mark[0].i); }
break;
case 8:
#line 80 "pwn_parser.y"
	{yyval.expression = new pwn::noob_node(LINE); }
break;
case 9:
#line 83 "pwn_parser.y"
	{ yyval.expression = new pwn::var_decl_node(LINE, yystack.l_mark[0].var, yystack.l_mark[-1].btype); }
break;
case 10:
#line 84 "pwn_parser.y"
	{ yyval.expression = new pwn::func_def_node(LINE, yystack.l_mark[0].func, NULL, NULL, yystack.l_mark[-1].s); }
break;
case 11:
#line 85 "pwn_parser.y"
	{ yyval.expression = new pwn::func_def_node(LINE, yystack.l_mark[-2].func, NULL, yystack.l_mark[0].expression, yystack.l_mark[-3].s); }
break;
case 12:
#line 86 "pwn_parser.y"
	{ yyval.expression = new pwn::func_def_node(LINE, yystack.l_mark[-1].func, yystack.l_mark[0].block, NULL, yystack.l_mark[-2].s); }
break;
case 13:
#line 87 "pwn_parser.y"
	{ yyval.expression = new pwn::func_def_node(LINE, yystack.l_mark[-3].func, yystack.l_mark[0].block, yystack.l_mark[-1].expression, yystack.l_mark[-4].s); }
break;
case 14:
#line 90 "pwn_parser.y"
	{yyval.s = new std::string("local"); }
break;
case 15:
#line 91 "pwn_parser.y"
	{yyval.s = new std::string("import"); }
break;
case 16:
#line 92 "pwn_parser.y"
	{yyval.s = new std::string("public"); }
break;
case 17:
#line 95 "pwn_parser.y"
	{ yyval.var = new pwn::var_node(LINE, yystack.l_mark[0].s); }
break;
case 18:
#line 98 "pwn_parser.y"
	{ yyval.func = new pwn::func_decl_node(LINE, yystack.l_mark[-2].s, yystack.l_mark[-3].btype, NULL); }
break;
case 19:
#line 99 "pwn_parser.y"
	{ yyval.func = new pwn::func_decl_node(LINE, yystack.l_mark[-3].s, yystack.l_mark[-4].btype,yystack.l_mark[-1].sequence ); }
break;
case 20:
#line 102 "pwn_parser.y"
	{yyval.btype = new basic_type(4, basic_type::TYPE_VOID); }
break;
case 21:
#line 103 "pwn_parser.y"
	{yyval.btype = yystack.l_mark[0].btype; }
break;
case 22:
#line 106 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].var); }
break;
case 23:
#line 107 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].var, yystack.l_mark[-2].sequence); }
break;
case 24:
#line 110 "pwn_parser.y"
	{ yyval.in = new cdk::integer_node(LINE, yystack.l_mark[0].i); }
break;
case 25:
#line 111 "pwn_parser.y"
	{ yyval.in = new cdk::integer_node(LINE, 1); }
break;
case 26:
#line 114 "pwn_parser.y"
	{ yyval.btype = new basic_type(4, basic_type::TYPE_INT); }
break;
case 27:
#line 115 "pwn_parser.y"
	{ yyval.btype = new basic_type(8, basic_type::TYPE_DOUBLE); }
break;
case 28:
#line 116 "pwn_parser.y"
	{ yyval.btype = new basic_type(4, basic_type::TYPE_STRING); }
break;
case 29:
#line 117 "pwn_parser.y"
	{ yyval.btype = new basic_type(4, basic_type::TYPE_POINTER); }
break;
case 30:
#line 119 "pwn_parser.y"
	{ yyval.btype = new basic_type(4, basic_type::TYPE_INT); }
break;
case 31:
#line 120 "pwn_parser.y"
	{ yyval.btype = new basic_type(8, basic_type::TYPE_DOUBLE); }
break;
case 32:
#line 121 "pwn_parser.y"
	{ yyval.btype = new basic_type(4, basic_type::TYPE_STRING); }
break;
case 33:
#line 122 "pwn_parser.y"
	{ yyval.btype = new basic_type(4, basic_type::TYPE_POINTER); }
break;
case 34:
#line 126 "pwn_parser.y"
	{ yyval.block = new pwn::block_node(LINE, yystack.l_mark[-1].sequence, yystack.l_mark[-2].sequence); }
break;
case 35:
#line 127 "pwn_parser.y"
	{ yyval.block = new pwn::block_node(LINE, yystack.l_mark[-1].sequence); }
break;
case 36:
#line 128 "pwn_parser.y"
	{ yyval.block = new pwn::block_node(LINE, NULL, yystack.l_mark[-1].sequence); }
break;
case 37:
#line 129 "pwn_parser.y"
	{ yyval.block = new pwn::block_node(LINE, NULL); }
break;
case 38:
#line 134 "pwn_parser.y"
	{ yyval.node = new pwn::evaluation_node(LINE, yystack.l_mark[-1].expression); }
break;
case 39:
#line 135 "pwn_parser.y"
	{ yyval.node = new pwn::print_node(LINE, yystack.l_mark[-1].expression); }
break;
case 40:
#line 136 "pwn_parser.y"
	{ yyval.node = new pwn::println_node(LINE, yystack.l_mark[-1].expression); }
break;
case 41:
#line 137 "pwn_parser.y"
	{ yyval.node = new pwn::read_node(LINE); }
break;
case 42:
#line 138 "pwn_parser.y"
	{ yyval.node = new pwn::next_node(LINE, yystack.l_mark[-1].in); }
break;
case 43:
#line 139 "pwn_parser.y"
	{ yyval.node = new pwn::stop_node(LINE, yystack.l_mark[-1].in); }
break;
case 44:
#line 140 "pwn_parser.y"
	{ yyval.node = new pwn::return_node(LINE); }
break;
case 45:
#line 141 "pwn_parser.y"
	{yyval.node = new pwn::repeat_node(LINE, yystack.l_mark[-6].expression, yystack.l_mark[-4].expression, yystack.l_mark[-2].expression, yystack.l_mark[0].node); }
break;
case 46:
#line 142 "pwn_parser.y"
	{ yyval.node = new cdk::if_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].node); }
break;
case 47:
#line 143 "pwn_parser.y"
	{ yyval.node = new cdk::if_else_node(LINE, yystack.l_mark[-4].expression, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 48:
#line 144 "pwn_parser.y"
	{ yyval.node = yystack.l_mark[0].block; }
break;
case 49:
#line 147 "pwn_parser.y"
	{ yyval.expression = new cdk::integer_node(LINE, yystack.l_mark[0].i); }
break;
case 50:
#line 148 "pwn_parser.y"
	{ yyval.expression = new cdk::string_node(LINE, yystack.l_mark[0].s); }
break;
case 51:
#line 149 "pwn_parser.y"
	{ yyval.expression = new cdk::neg_node(LINE, yystack.l_mark[0].expression); }
break;
case 52:
#line 150 "pwn_parser.y"
	{ yyval.expression = new pwn::not_node(LINE, yystack.l_mark[0].expression); }
break;
case 53:
#line 151 "pwn_parser.y"
	{ yyval.expression = new cdk::add_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 54:
#line 152 "pwn_parser.y"
	{ yyval.expression = new cdk::sub_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 55:
#line 153 "pwn_parser.y"
	{ yyval.expression = new cdk::mul_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 56:
#line 154 "pwn_parser.y"
	{ yyval.expression = new cdk::div_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 57:
#line 155 "pwn_parser.y"
	{ yyval.expression = new cdk::mod_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 58:
#line 156 "pwn_parser.y"
	{ yyval.expression = new cdk::lt_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 59:
#line 157 "pwn_parser.y"
	{ yyval.expression = new pwn::or_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 60:
#line 158 "pwn_parser.y"
	{ yyval.expression = new pwn::and_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 61:
#line 159 "pwn_parser.y"
	{ yyval.expression = new cdk::gt_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 62:
#line 160 "pwn_parser.y"
	{ yyval.expression = new cdk::ge_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 63:
#line 161 "pwn_parser.y"
	{ yyval.expression = new cdk::le_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 64:
#line 162 "pwn_parser.y"
	{ yyval.expression = new cdk::ne_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 65:
#line 163 "pwn_parser.y"
	{ yyval.expression = new cdk::eq_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 66:
#line 164 "pwn_parser.y"
	{ yyval.expression = yystack.l_mark[-1].expression; }
break;
case 67:
#line 165 "pwn_parser.y"
	{ yyval.expression = new pwn::assignment_node(LINE, yystack.l_mark[-2].lvalue, yystack.l_mark[0].expression); }
break;
case 68:
#line 166 "pwn_parser.y"
	{ yyval.expression = new pwn::maloc_node(LINE, yystack.l_mark[-1].i); }
break;
case 69:
#line 169 "pwn_parser.y"
	{ yyval.lvalue = yystack.l_mark[0].index; }
break;
case 70:
#line 170 "pwn_parser.y"
	{ yyval.lvalue = yystack.l_mark[0].var; }
break;
case 71:
#line 173 "pwn_parser.y"
	{ yyval.index = new pwn::index_node(LINE, yystack.l_mark[-3].lvalue, yystack.l_mark[-1].lvalue); }
break;
#line 988 "pwn_parser.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
