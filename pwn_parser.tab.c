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
#line 61 "pwn_parser.y"
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
    0,    0,    4,    4,    4,    4,    5,    5,    5,    5,
    5,    9,    9,    9,   10,   11,   11,    2,    2,   14,
   14,    7,    7,    7,    7,    7,    8,    8,   12,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    6,    6,   13,
};
static const short yylen[] = {                            2,
    1,    2,    1,    1,    1,    1,    3,    2,    4,    3,
    5,    1,    1,    0,    1,    5,    4,    1,    3,    1,
    0,    1,    1,    1,    1,    3,    1,    1,    3,    2,
    2,    2,    1,    2,    2,    1,    9,    5,    7,    1,
    1,    1,    2,    2,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    5,
    1,    1,    1,    4,
};
static const short yydefred[] = {                         0,
   41,   15,   42,    0,   33,    0,    0,    0,   12,   13,
   36,    0,    0,    0,    0,    0,    1,    0,   61,    0,
    0,   63,   40,   62,    0,    0,   20,   34,   35,   43,
   44,    0,    0,    2,   31,   32,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   30,
    0,    0,    0,   25,   23,   22,   24,   28,    0,    0,
    0,    0,    0,   58,   29,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   52,   51,    0,    0,
    0,    0,    7,    0,    0,   10,    0,    0,    0,   64,
   26,    0,    6,    4,    5,    3,    0,    0,    0,   60,
   17,    0,   18,   11,    0,    0,   16,    0,   39,    0,
   19,    0,   37,
};
static const short yydgoto[] = {                         16,
   17,  102,   18,   97,   19,   20,   59,   60,   21,   22,
   61,   23,   24,   28,
};
static const short yysindex[] = {                       420,
    0,    0,    0,  -20,    0,  -19, -244, -244,    0,    0,
    0,  377,  377,  377,  420,  420,    0,   39,    0,  -47,
  100,    0,    0,    0,  377,  377,    0,    0,    0,    0,
    0,  134,  212,    0,    0,    0,  377,  377,  377,  377,
  377,  377,  377,  377,  377,  377,  377,  377,  377,    0,
  406, -238,  122,    0,    0,    0,    0,    0, -238, -234,
  -44,  150,  171,    0,    0,  448,  448,  448,  448,  448,
  448,   10,   10,  -29,  -29,  -29,    0,    0, -231,  393,
  -80,  -33,    0,  -10, -165,    0,  420,  377,  -60,    0,
    0,  -41,    0,    0,    0,    0,  -88, -236,  313,    0,
    0,  -25,    0,    0,  420,  377,    0, -238,    0,  354,
    0,  420,    0,
};
static const short yyrindex[] = {                       187,
    0,    0,    0,    0,    0,    0,    1,    1,    0,    0,
    0,  187,  187,  187,  187,  187,    0,    0,    0,    0,
    0,    0,    0,    0,  187,  187,    0,    0,    0,    0,
    0,    0,  187,    0,    0,    0,  187,  187,  187,  187,
  187,  187,  187,  187,  187,  187,  187,  187,  187,    0,
  187,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -35,    0,    0,    0,    0,  142,  262,  303,  320,  347,
  382,  191,  251,   63,   70,  108,    0,    0,    0,  -36,
    0,    0,    0,    0,    0,    0,  187,  187,    0,    0,
    0,    0,    0,    0,    0,    0,   28,   18,    0,    0,
    0,    0,    0,    0,  187,  187,    0,    0,    0,    0,
    0,  187,    0,
};
static const short yygindex[] = {                        27,
   16,    0,  681,    0,    0,   -7,   -3,    0,    0,  -28,
    0,  -57,    0,   48,
};
#define YYTABLESIZE 787
static const short yytable[] = {                        101,
   21,    8,    8,   86,   59,    8,    8,    8,   48,    8,
   52,    8,   90,   51,   27,  107,   85,   38,  108,   25,
   26,    2,   59,    8,    8,   84,    8,   89,   91,   92,
   83,   34,  100,   21,   15,   21,   21,   21,  105,  104,
   21,   33,   21,   52,   81,   21,   47,   48,   34,   82,
   38,   45,   38,   38,   38,   29,   46,   38,    0,   38,
   21,    0,   38,  103,    9,    9,    0,    0,    9,    9,
    9,    0,    9,    0,    9,   47,   48,   38,   15,  111,
   45,   43,    0,   44,    0,   46,    9,    9,    8,    9,
    0,   93,   94,   95,   49,   96,    0,   50,   42,   47,
   41,    0,   98,   47,   47,   47,   48,   47,    0,   47,
   48,   48,   48,    0,   48,    0,   48,    0,    0,    0,
  109,   47,   47,   21,   47,   21,   21,  113,   48,   48,
    0,   48,   58,   49,   56,   57,   55,    0,    0,    0,
   38,   54,   38,   38,   49,    0,    0,    0,   49,   49,
   49,    9,   49,    0,   49,    0,   56,   57,   55,   53,
    0,    0,   49,   54,    0,    0,   49,   49,    0,   49,
   47,   48,    0,    0,   64,   45,   43,    0,   44,    0,
   46,   53,   54,    0,    0,    0,   47,   48,    0,    0,
   87,   45,   43,   42,   44,   41,   46,    0,    0,    0,
   54,   54,    0,   54,    0,    0,    0,   47,   48,   42,
    0,   41,   45,   43,    0,   44,    0,   46,    2,   14,
    0,   14,   14,   14,    0,    0,   59,    8,   14,   88,
   42,   45,   41,   45,    0,   45,   59,    8,    0,    0,
    8,    8,    8,    8,    0,    0,   14,    0,    0,   45,
   45,   14,   45,    0,    0,    0,   12,   49,    0,    0,
   21,   21,   21,    0,   21,    0,    0,   21,   21,   21,
   21,   21,   21,   49,    0,   21,   38,   38,   38,   38,
    0,   38,    0,    0,   38,   38,   38,   38,   38,   38,
    9,   46,    0,   46,   49,   46,    0,    0,    0,    0,
    9,   35,   55,    9,    9,    9,    9,    0,    0,   46,
   46,   36,   46,    0,   37,   38,   39,   40,    0,    0,
   55,   55,    0,   55,    0,   47,    0,    0,    0,    0,
    0,    0,   48,    0,   15,   47,   65,   13,   47,   47,
   47,   47,   48,   57,    0,   48,   48,   48,   48,   47,
   48,    0,    0,    0,   45,   43,    0,   44,    0,   46,
   56,   57,   57,    0,   57,    0,    0,    0,    0,    0,
   49,  106,   42,    0,   41,    0,    0,    0,   56,   56,
   49,   56,    0,   49,   49,   49,   49,   53,    0,    0,
   47,   48,    0,    0,  112,   45,   43,    0,   44,    0,
   46,    0,    0,    0,   54,   53,   53,    0,   53,   37,
   38,   39,   40,   42,   54,   41,   14,   54,   54,   54,
   54,   12,   50,    0,    0,   37,   38,   39,   40,   47,
   48,    0,    0,    0,   45,   43,   49,   44,    0,   46,
   50,   50,    0,   50,    0,   14,   37,   38,   39,   40,
   12,    0,   42,   45,   41,    0,    0,    0,    0,   14,
    0,    0,    0,   45,   12,    0,   45,   45,   45,   45,
    1,    2,    3,    4,    0,    5,    0,   49,    6,    7,
    8,    9,   10,   11,   47,   48,    0,    0,    0,   45,
   43,    0,   44,    0,   46,    0,   79,    0,    0,    0,
    0,    0,   13,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   46,    0,    0,   49,    0,    0,    0,
    0,    0,    0,   46,   55,    0,   46,   46,   46,   46,
    0,   13,    0,    0,   55,    0,    0,   55,   55,   55,
   55,    0,   15,    0,    0,   13,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   57,    0,    0,    0,    0,
    0,   49,    0,    0,    0,   57,    0,    0,   57,   57,
   57,   57,   56,    0,    0,    0,    0,    0,   37,   38,
   39,   40,   56,    0,    0,   56,   56,   56,   56,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   53,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   53,
    0,    0,   53,   53,   53,   53,    0,    0,    0,   37,
   38,   39,   40,    0,    0,    1,    2,    3,    0,    0,
    0,    0,    0,    0,   50,    0,    9,   10,    0,    0,
    0,    0,    0,    0,   50,    0,    0,   50,   50,   50,
   50,    0,    0,    0,    1,    2,    3,    0,   37,   38,
   39,   40,    0,    0,    0,    9,   10,    0,    1,    2,
    3,    4,    0,    5,    0,    0,    6,    7,    8,    9,
   10,   11,   30,   31,   32,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   62,   63,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   66,   67,   68,
   69,   70,   71,   72,   73,   74,   75,   76,   77,   78,
    0,   80,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   99,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  110,
};
static const short yycheck[] = {                         41,
    0,   37,   38,   61,   41,   41,   42,   43,   38,   45,
   91,   47,   93,   61,  259,   41,   61,    0,   44,   40,
   40,  260,   59,   59,   60,  260,   62,  259,   62,   40,
   59,   16,   93,   33,  123,   35,   36,   37,  275,   97,
   40,   15,   42,   91,   52,   45,   37,   38,   33,   53,
   33,   42,   35,   36,   37,    8,   47,   40,   -1,   42,
   60,   -1,   45,   92,   37,   38,   -1,   -1,   41,   42,
   43,   -1,   45,   -1,   47,   37,   38,   60,  123,  108,
   42,   43,   -1,   45,   -1,   47,   59,   60,  124,   62,
   -1,  257,  258,  259,  124,  261,   -1,   59,   60,   37,
   62,   -1,   87,   41,   42,   43,   37,   45,   -1,   47,
   41,   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,
  105,   59,   60,  123,   62,  125,  126,  112,   59,   60,
   -1,   62,   33,  124,   35,   36,   37,   -1,   -1,   -1,
  123,   42,  125,  126,   37,   -1,   -1,   -1,   41,   42,
   43,  124,   45,   -1,   47,   -1,   35,   36,   37,   60,
   -1,   -1,  124,   42,   -1,   -1,   59,   60,   -1,   62,
   37,   38,   -1,   -1,   41,   42,   43,   -1,   45,   -1,
   47,   60,   41,   -1,   -1,   -1,   37,   38,   -1,   -1,
   41,   42,   43,   60,   45,   62,   47,   -1,   -1,   -1,
   59,   60,   -1,   62,   -1,   -1,   -1,   37,   38,   60,
   -1,   62,   42,   43,   -1,   45,   -1,   47,  260,   33,
   -1,   35,   36,   37,   -1,   -1,  263,  263,   42,   59,
   60,   41,   62,   43,   -1,   45,  273,  273,   -1,   -1,
  276,  277,  278,  279,   -1,   -1,   60,   -1,   -1,   59,
   60,   40,   62,   -1,   -1,   -1,   45,  124,   -1,   -1,
  260,  261,  262,   -1,  264,   -1,   -1,  267,  268,  269,
  270,  271,  272,  124,   -1,  275,  259,  260,  261,  262,
   -1,  264,   -1,   -1,  267,  268,  269,  270,  271,  272,
  263,   41,   -1,   43,  124,   45,   -1,   -1,   -1,   -1,
  273,  263,   41,  276,  277,  278,  279,   -1,   -1,   59,
   60,  273,   62,   -1,  276,  277,  278,  279,   -1,   -1,
   59,   60,   -1,   62,   -1,  263,   -1,   -1,   -1,   -1,
   -1,   -1,  263,   -1,  123,  273,  125,  126,  276,  277,
  278,  279,  273,   41,   -1,  276,  277,  278,  279,   37,
   38,   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,
   41,   59,   60,   -1,   62,   -1,   -1,   -1,   -1,   -1,
  263,   59,   60,   -1,   62,   -1,   -1,   -1,   59,   60,
  273,   62,   -1,  276,  277,  278,  279,   41,   -1,   -1,
   37,   38,   -1,   -1,   41,   42,   43,   -1,   45,   -1,
   47,   -1,   -1,   -1,  263,   59,   60,   -1,   62,  276,
  277,  278,  279,   60,  273,   62,   40,  276,  277,  278,
  279,   45,   41,   -1,   -1,  276,  277,  278,  279,   37,
   38,   -1,   -1,   -1,   42,   43,  124,   45,   -1,   47,
   59,   60,   -1,   62,   -1,   40,  276,  277,  278,  279,
   45,   -1,   60,  263,   62,   -1,   -1,   -1,   -1,   40,
   -1,   -1,   -1,  273,   45,   -1,  276,  277,  278,  279,
  259,  260,  261,  262,   -1,  264,   -1,  124,  267,  268,
  269,  270,  271,  272,   37,   38,   -1,   -1,   -1,   42,
   43,   -1,   45,   -1,   47,   -1,   91,   -1,   -1,   -1,
   -1,   -1,  126,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  263,   -1,   -1,  124,   -1,   -1,   -1,
   -1,   -1,   -1,  273,  263,   -1,  276,  277,  278,  279,
   -1,  126,   -1,   -1,  273,   -1,   -1,  276,  277,  278,
  279,   -1,  123,   -1,   -1,  126,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  263,   -1,   -1,   -1,   -1,
   -1,  124,   -1,   -1,   -1,  273,   -1,   -1,  276,  277,
  278,  279,  263,   -1,   -1,   -1,   -1,   -1,  276,  277,
  278,  279,  273,   -1,   -1,  276,  277,  278,  279,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  263,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  273,
   -1,   -1,  276,  277,  278,  279,   -1,   -1,   -1,  276,
  277,  278,  279,   -1,   -1,  259,  260,  261,   -1,   -1,
   -1,   -1,   -1,   -1,  263,   -1,  270,  271,   -1,   -1,
   -1,   -1,   -1,   -1,  273,   -1,   -1,  276,  277,  278,
  279,   -1,   -1,   -1,  259,  260,  261,   -1,  276,  277,
  278,  279,   -1,   -1,   -1,  270,  271,   -1,  259,  260,
  261,  262,   -1,  264,   -1,   -1,  267,  268,  269,  270,
  271,  272,   12,   13,   14,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   25,   26,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   37,   38,   39,
   40,   41,   42,   43,   44,   45,   46,   47,   48,   49,
   -1,   51,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   88,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  106,
};
#define YYFINAL 16
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 280
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
"tELSE","tGE","tLE","tEQ","tNE","tUNARY",
};
static const char *yyrule[] = {
"$accept : list",
"list : stmt",
"list : list stmt",
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
"func : ftype tIDENTIFIER '(' args ')'",
"func : ftype tIDENTIFIER '(' ')'",
"args : var",
"args : args ',' var",
"arg : tINTEGER",
"arg :",
"type : '#'",
"type : '%'",
"type : '$'",
"type : '*'",
"type : '<' type '>'",
"ftype : type",
"ftype : '!'",
"block : '{' list '}'",
"stmt : expr ';'",
"stmt : expr tPRINT",
"stmt : expr tPRINTLN",
"stmt : tREAD",
"stmt : tNEXT arg",
"stmt : tSTOP arg",
"stmt : tRETURN",
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
"expr : decl",
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
#line 68 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node); }
break;
case 2:
#line 69 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node, yystack.l_mark[-1].sequence); }
break;
case 3:
#line 72 "pwn_parser.y"
	{yyval.expression = new cdk::string_node(LINE, yystack.l_mark[0].s); }
break;
case 4:
#line 73 "pwn_parser.y"
	{yyval.expression = new cdk::double_node(LINE, yystack.l_mark[0].d); }
break;
case 5:
#line 74 "pwn_parser.y"
	{yyval.expression = new cdk::integer_node(LINE, yystack.l_mark[0].i); }
break;
case 6:
#line 75 "pwn_parser.y"
	{yyval.expression = new pwn::noob_node(LINE); }
break;
case 7:
#line 78 "pwn_parser.y"
	{ yyval.expression = new pwn::var_decl_node(LINE, yystack.l_mark[0].var, yystack.l_mark[-1].btype); }
break;
case 8:
#line 79 "pwn_parser.y"
	{ yyval.expression = new pwn::func_def_node(LINE, yystack.l_mark[0].func, NULL, NULL, yystack.l_mark[-1].s); }
break;
case 9:
#line 80 "pwn_parser.y"
	{ yyval.expression = new pwn::func_def_node(LINE, yystack.l_mark[-2].func, NULL, yystack.l_mark[0].expression, yystack.l_mark[-3].s); }
break;
case 10:
#line 81 "pwn_parser.y"
	{ yyval.expression = new pwn::func_def_node(LINE, yystack.l_mark[-1].func, yystack.l_mark[0].block, NULL, yystack.l_mark[-2].s); }
break;
case 11:
#line 82 "pwn_parser.y"
	{ yyval.expression = new pwn::func_def_node(LINE, yystack.l_mark[-3].func, yystack.l_mark[0].block, yystack.l_mark[-1].expression, yystack.l_mark[-4].s); }
break;
case 12:
#line 85 "pwn_parser.y"
	{yyval.s = new std::string("local"); }
break;
case 13:
#line 86 "pwn_parser.y"
	{yyval.s = new std::string("import"); }
break;
case 14:
#line 87 "pwn_parser.y"
	{yyval.s = new std::string("public"); }
break;
case 15:
#line 92 "pwn_parser.y"
	{ yyval.var = new pwn::var_node(LINE, yystack.l_mark[0].s); }
break;
case 16:
#line 95 "pwn_parser.y"
	{ yyval.func = new pwn::func_decl_node(LINE, yystack.l_mark[-3].s, yystack.l_mark[-4].btype, yystack.l_mark[-1].sequence); }
break;
case 17:
#line 96 "pwn_parser.y"
	{ yyval.func = new pwn::func_decl_node(LINE, yystack.l_mark[-2].s, yystack.l_mark[-3].btype, NULL); }
break;
case 18:
#line 99 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].var); }
break;
case 19:
#line 100 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].var, yystack.l_mark[-2].sequence); }
break;
case 20:
#line 103 "pwn_parser.y"
	{ yyval.in = new cdk::integer_node(LINE, yystack.l_mark[0].i); }
break;
case 21:
#line 104 "pwn_parser.y"
	{ yyval.in = new cdk::integer_node(LINE, 1); }
break;
case 22:
#line 107 "pwn_parser.y"
	{ yyval.btype = new basic_type(4, basic_type::TYPE_INT); }
break;
case 23:
#line 108 "pwn_parser.y"
	{ yyval.btype = new basic_type(8, basic_type::TYPE_DOUBLE); }
break;
case 24:
#line 109 "pwn_parser.y"
	{ yyval.btype = new basic_type(4, basic_type::TYPE_STRING); }
break;
case 25:
#line 110 "pwn_parser.y"
	{ yyval.btype = new basic_type(4, basic_type::TYPE_POINTER); }
break;
case 26:
#line 111 "pwn_parser.y"
	{ yyval.btype = yystack.l_mark[-1].btype; }
break;
case 27:
#line 114 "pwn_parser.y"
	{yyval.btype = yystack.l_mark[0].btype; }
break;
case 28:
#line 115 "pwn_parser.y"
	{yyval.btype = new basic_type(4, basic_type::TYPE_VOID); }
break;
case 29:
#line 117 "pwn_parser.y"
	{ yyval.block = new pwn::block_node(LINE, yystack.l_mark[-1].sequence); }
break;
case 30:
#line 120 "pwn_parser.y"
	{ yyval.node = new pwn::evaluation_node(LINE, yystack.l_mark[-1].expression); }
break;
case 31:
#line 121 "pwn_parser.y"
	{ yyval.node = new pwn::print_node(LINE, yystack.l_mark[-1].expression); }
break;
case 32:
#line 122 "pwn_parser.y"
	{ yyval.node = new pwn::println_node(LINE, yystack.l_mark[-1].expression); }
break;
case 33:
#line 123 "pwn_parser.y"
	{ yyval.node = new pwn::read_node(LINE); }
break;
case 34:
#line 124 "pwn_parser.y"
	{ yyval.node = new pwn::next_node(LINE, yystack.l_mark[0].in); }
break;
case 35:
#line 125 "pwn_parser.y"
	{ yyval.node = new pwn::stop_node(LINE, yystack.l_mark[0].in); }
break;
case 36:
#line 126 "pwn_parser.y"
	{ yyval.node = new pwn::return_node(LINE); }
break;
case 37:
#line 127 "pwn_parser.y"
	{yyval.node = new pwn::repeat_node(LINE, yystack.l_mark[-6].expression, yystack.l_mark[-4].expression, yystack.l_mark[-2].expression, yystack.l_mark[0].node); }
break;
case 38:
#line 128 "pwn_parser.y"
	{ yyval.node = new cdk::if_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].node); }
break;
case 39:
#line 129 "pwn_parser.y"
	{ yyval.node = new cdk::if_else_node(LINE, yystack.l_mark[-4].expression, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 40:
#line 130 "pwn_parser.y"
	{ yyval.node = yystack.l_mark[0].block;}
break;
case 41:
#line 133 "pwn_parser.y"
	{ yyval.expression = new cdk::integer_node(LINE, yystack.l_mark[0].i); }
break;
case 42:
#line 134 "pwn_parser.y"
	{ yyval.expression = new cdk::string_node(LINE, yystack.l_mark[0].s); }
break;
case 43:
#line 135 "pwn_parser.y"
	{ yyval.expression = new cdk::neg_node(LINE, yystack.l_mark[0].expression); }
break;
case 44:
#line 136 "pwn_parser.y"
	{ yyval.expression = new pwn::not_node(LINE, yystack.l_mark[0].expression); }
break;
case 45:
#line 137 "pwn_parser.y"
	{ yyval.expression = new cdk::add_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 46:
#line 138 "pwn_parser.y"
	{ yyval.expression = new cdk::sub_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 47:
#line 139 "pwn_parser.y"
	{ yyval.expression = new cdk::mul_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 48:
#line 140 "pwn_parser.y"
	{ yyval.expression = new cdk::div_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 49:
#line 141 "pwn_parser.y"
	{ yyval.expression = new cdk::mod_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 50:
#line 142 "pwn_parser.y"
	{ yyval.expression = new cdk::lt_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 51:
#line 143 "pwn_parser.y"
	{ yyval.expression = new pwn::or_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 52:
#line 144 "pwn_parser.y"
	{ yyval.expression = new pwn::and_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 53:
#line 145 "pwn_parser.y"
	{ yyval.expression = new cdk::gt_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 54:
#line 146 "pwn_parser.y"
	{ yyval.expression = new cdk::ge_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 55:
#line 147 "pwn_parser.y"
	{ yyval.expression = new cdk::le_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 56:
#line 148 "pwn_parser.y"
	{ yyval.expression = new cdk::ne_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 57:
#line 149 "pwn_parser.y"
	{ yyval.expression = new cdk::eq_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 58:
#line 150 "pwn_parser.y"
	{ yyval.expression = yystack.l_mark[-1].expression; }
break;
case 59:
#line 151 "pwn_parser.y"
	{ yyval.expression = new pwn::assignment_node(LINE, yystack.l_mark[-2].lvalue, yystack.l_mark[0].expression); }
break;
case 60:
#line 152 "pwn_parser.y"
	{ yyval.expression = new pwn::maloc_node(LINE, yystack.l_mark[-1].i); }
break;
case 61:
#line 153 "pwn_parser.y"
	{ yyval.expression = yystack.l_mark[0].expression; }
break;
case 62:
#line 156 "pwn_parser.y"
	{ yyval.lvalue = yystack.l_mark[0].index; }
break;
case 63:
#line 157 "pwn_parser.y"
	{ yyval.lvalue = yystack.l_mark[0].var; }
break;
case 64:
#line 160 "pwn_parser.y"
	{ yyval.index = new pwn::index_node(LINE, yystack.l_mark[-3].lvalue, yystack.l_mark[-1].lvalue); }
break;
#line 929 "pwn_parser.tab.c"
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
