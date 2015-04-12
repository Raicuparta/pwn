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
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 46 "pwn_parser.y"
/*-- The rules below will be included in yyparse, the main parsing function.*/
#line 49 "pwn_parser.tab.c"

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

#define tREAL 257
#define tINTEGER 258
#define tIDENTIFIER 259
#define tSTRING 260
#define tIF 261
#define tPRINT 262
#define tREAD 263
#define tBEGIN 264
#define tEND 265
#define tREPEAT 266
#define tNEXT 267
#define tSTOP 268
#define tLOCAL 269
#define tIMPORT 270
#define tNOOB 271
#define tRETURN 272
#define tPRINTLN 273
#define tIFX 274
#define tELSE 275
#define tGE 276
#define tLE 277
#define tEQ 278
#define tNE 279
#define tUNARY 280
#define lval 281
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    1,    1,    1,    1,    1,    1,    1,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,
};
static const short yylen[] = {                            2,
    1,    2,    2,    3,    3,    9,    5,    7,    3,    1,
    1,    2,    2,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    1,    3,
};
static const short yydefred[] = {                         0,
   10,   11,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    1,    0,    0,    0,    0,    0,   12,   13,
    0,    0,    0,    2,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    3,    0,    4,
    5,    0,    0,   27,    9,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   21,   20,    0,    0,
    0,    0,    0,    0,    8,    0,    0,    6,
};
static const short yydgoto[] = {                         12,
   13,   14,
};
static const short yysindex[] = {                        72,
    0,    0,  -31,  -25, -276,  -29,  -25,  -25,  -45,  -25,
   72,   72,    0,  -24,  -25,    7,  -42,  -25,    0,    0,
  -25,   18,   96,    0,  -25,  -25,  -25,  -25,  -25,  -25,
  -25,  -25,  -25,  -25,  -25,  -25,  -25,    0,   34,    0,
    0,   45,  114,    0,    0,  326,  326,  326,  326,  326,
  326,   -5,   -5,  -38,  -38,  -38,    0,    0,   72,  -25,
 -249,   73,   72,  -25,    0,  102,   72,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,  -35,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -37,    0,    0,  158,  198,  228,  239,  266,
  277,  170,  206,  130,  141,  165,    0,    0,    0,    0,
    1,    0,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                        17,
   39,  504,
};
#define YYTABLESIZE 568
static const short yytable[] = {                         36,
    7,   28,   28,   29,   17,   28,   28,   28,   15,   28,
   18,   28,   35,   36,   10,   21,   41,   33,   31,    7,
   32,   29,   34,   28,   28,   63,   28,   23,    0,    0,
    0,   35,   36,    0,   38,   30,   33,   29,    0,    0,
    7,   34,    0,   35,   36,    7,    0,    0,   33,   31,
   24,   32,    0,   34,   35,   36,    0,    0,   44,   33,
   31,   24,   32,    0,   34,   40,   30,    0,   29,    0,
   35,   36,    0,    0,   59,   33,   31,   30,   32,   29,
   34,   35,   36,    0,    0,   37,   33,   31,   28,   32,
    0,   34,    0,   30,    0,   29,    0,   61,    0,   37,
    8,   65,    0,   60,   30,   68,   29,    0,    0,   35,
   36,   10,    0,    0,   33,   31,    7,   32,   37,   34,
    0,    0,    0,    7,    0,    7,    7,    0,    0,    0,
   37,   64,   30,    0,   29,   10,    0,    0,   35,   36,
    7,   37,   67,   33,   31,    0,   32,    0,   34,    0,
   35,   36,    0,    0,    0,   33,   31,   37,   32,    0,
   34,   30,    0,   29,    0,    0,   16,    0,   37,    0,
   16,   16,   16,   30,   16,   29,   16,   17,    0,    0,
    0,   17,   17,   17,    0,   17,    0,   17,   16,   16,
    0,   16,    0,    0,   11,    0,   37,    8,   23,   17,
   17,   18,   17,    0,    0,   18,   18,   18,    0,   18,
   14,   18,   14,    0,   14,    0,   23,   23,   11,   23,
   45,    8,    0,   18,   18,   37,   18,    0,   14,   14,
    0,   14,    1,    0,    2,    0,    0,   37,   24,    0,
   28,   28,   28,   28,    0,    0,   15,    0,   15,    0,
   15,   25,   26,   27,   28,    9,   24,   24,    7,   24,
    7,    7,    7,    7,   15,   15,    7,   15,   26,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   25,
    0,    7,   25,   26,   27,   28,   26,   26,    0,   26,
    0,    0,    0,   25,   26,   27,   28,   25,   25,    0,
   25,    0,    0,    0,    0,    0,   22,    0,    0,   25,
   26,   27,   28,    0,    0,    0,    0,   19,    0,    0,
   25,   26,   27,   28,   22,   22,    0,   22,    0,    1,
    0,    2,    3,    4,    5,   19,   19,    6,   19,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   25,   26,
   27,   28,    9,    1,    0,    2,    3,    4,    5,    0,
    0,    6,   35,   36,    0,    0,    0,   33,   31,    0,
   32,    0,   34,    0,    0,    0,    9,   25,   26,   27,
   28,    0,    0,    0,    0,    0,    0,    0,    0,   25,
   26,   27,   28,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   16,   16,   16,   16,    0,
    0,    0,    0,    0,    0,    0,   17,   17,   17,   17,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   23,   23,   23,   23,    0,    0,    0,
   18,   18,   18,   18,    0,   14,   14,   14,   14,   37,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   24,   24,   24,   24,    0,    0,    0,
    0,   15,   15,   15,   15,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   26,   26,   26,   26,   16,    0,    0,
   19,   20,    0,   22,   25,   25,   25,   25,   39,    0,
    0,   42,    0,    0,   43,    0,    0,    0,   46,   47,
   48,   49,   50,   51,   52,   53,   54,   55,   56,   57,
   58,   22,   22,   22,   22,    0,    0,    0,    0,    0,
    0,    0,   19,   19,   19,   19,    0,    0,    0,    0,
    0,    0,    0,   62,    0,    0,    0,   66,
};
static const short yycheck[] = {                         38,
    0,   37,   38,   41,  281,   41,   42,   43,   40,   45,
   40,   47,   37,   38,   40,   61,   59,   42,   43,   45,
   45,   59,   47,   59,   60,  275,   62,   11,   -1,   -1,
   -1,   37,   38,   -1,   59,   60,   42,   62,   -1,   -1,
   40,   47,   -1,   37,   38,   45,   -1,   -1,   42,   43,
   12,   45,   -1,   47,   37,   38,   -1,   -1,   41,   42,
   43,   23,   45,   -1,   47,   59,   60,   -1,   62,   -1,
   37,   38,   -1,   -1,   41,   42,   43,   60,   45,   62,
   47,   37,   38,   -1,   -1,  124,   42,   43,  124,   45,
   -1,   47,   -1,   60,   -1,   62,   -1,   59,   -1,  124,
  126,   63,   -1,   59,   60,   67,   62,   -1,   -1,   37,
   38,   40,   -1,   -1,   42,   43,   45,   45,  124,   47,
   -1,   -1,   -1,  123,   -1,  125,  126,   -1,   -1,   -1,
  124,   59,   60,   -1,   62,   40,   -1,   -1,   37,   38,
   45,  124,   41,   42,   43,   -1,   45,   -1,   47,   -1,
   37,   38,   -1,   -1,   -1,   42,   43,  124,   45,   -1,
   47,   60,   -1,   62,   -1,   -1,   37,   -1,  124,   -1,
   41,   42,   43,   60,   45,   62,   47,   37,   -1,   -1,
   -1,   41,   42,   43,   -1,   45,   -1,   47,   59,   60,
   -1,   62,   -1,   -1,  123,   -1,  124,  126,   41,   59,
   60,   37,   62,   -1,   -1,   41,   42,   43,   -1,   45,
   41,   47,   43,   -1,   45,   -1,   59,   60,  123,   62,
  125,  126,   -1,   59,   60,  124,   62,   -1,   59,   60,
   -1,   62,  258,   -1,  260,   -1,   -1,  124,   41,   -1,
  276,  277,  278,  279,   -1,   -1,   41,   -1,   43,   -1,
   45,  276,  277,  278,  279,  281,   59,   60,  258,   62,
  260,  261,  262,  263,   59,   60,  266,   62,   41,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   41,
   -1,  281,  276,  277,  278,  279,   59,   60,   -1,   62,
   -1,   -1,   -1,  276,  277,  278,  279,   59,   60,   -1,
   62,   -1,   -1,   -1,   -1,   -1,   41,   -1,   -1,  276,
  277,  278,  279,   -1,   -1,   -1,   -1,   41,   -1,   -1,
  276,  277,  278,  279,   59,   60,   -1,   62,   -1,  258,
   -1,  260,  261,  262,  263,   59,   60,  266,   62,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  276,  277,
  278,  279,  281,  258,   -1,  260,  261,  262,  263,   -1,
   -1,  266,   37,   38,   -1,   -1,   -1,   42,   43,   -1,
   45,   -1,   47,   -1,   -1,   -1,  281,  276,  277,  278,
  279,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  276,
  277,  278,  279,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  276,  277,  278,  279,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  276,  277,  278,  279,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  276,  277,  278,  279,   -1,   -1,   -1,
  276,  277,  278,  279,   -1,  276,  277,  278,  279,  124,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  276,  277,  278,  279,   -1,   -1,   -1,
   -1,  276,  277,  278,  279,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  276,  277,  278,  279,    4,   -1,   -1,
    7,    8,   -1,   10,  276,  277,  278,  279,   15,   -1,
   -1,   18,   -1,   -1,   21,   -1,   -1,   -1,   25,   26,
   27,   28,   29,   30,   31,   32,   33,   34,   35,   36,
   37,  276,  277,  278,  279,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  276,  277,  278,  279,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   60,   -1,   -1,   -1,   64,
};
#define YYFINAL 12
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 281
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,
0,"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'","'|'",
"'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"tREAL","tINTEGER","tIDENTIFIER","tSTRING",
"tIF","tPRINT","tREAD","tBEGIN","tEND","tREPEAT","tNEXT","tSTOP","tLOCAL",
"tIMPORT","tNOOB","tRETURN","tPRINTLN","tIFX","tELSE","tGE","tLE","tEQ","tNE",
"tUNARY","lval",
};
static const char *yyrule[] = {
"$accept : list",
"list : stmt",
"list : list stmt",
"stmt : expr ';'",
"stmt : tPRINT expr ';'",
"stmt : tREAD lval ';'",
"stmt : tREPEAT '(' expr ';' expr ';' expr ')' stmt",
"stmt : tIF '(' expr ')' stmt",
"stmt : tIF '(' expr ')' stmt tELSE stmt",
"stmt : '{' list '}'",
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
"expr : lval",
"expr : lval '=' expr",

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
#line 53 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node); }
break;
case 2:
#line 54 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node, yystack.l_mark[-1].sequence); }
break;
case 3:
#line 57 "pwn_parser.y"
	{ yyval.node = new pwn::evaluation_node(LINE, yystack.l_mark[-1].expression); }
break;
case 4:
#line 58 "pwn_parser.y"
	{ yyval.node = new pwn::print_node(LINE, yystack.l_mark[-1].expression); }
break;
case 5:
#line 59 "pwn_parser.y"
	{ yyval.node = new pwn::read_node(LINE, yystack.l_mark[-1].lvalue); }
break;
case 6:
#line 61 "pwn_parser.y"
	{yyval.node = new pwn::repeat_node(LINE, yystack.l_mark[-6].expression, yystack.l_mark[-4].expression, yystack.l_mark[-2].expression, yystack.l_mark[0].node); }
break;
case 7:
#line 62 "pwn_parser.y"
	{ yyval.node = new cdk::if_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].node); }
break;
case 8:
#line 63 "pwn_parser.y"
	{ yyval.node = new cdk::if_else_node(LINE, yystack.l_mark[-4].expression, yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 9:
#line 64 "pwn_parser.y"
	{ yyval.node = yystack.l_mark[-1].sequence; }
break;
case 10:
#line 67 "pwn_parser.y"
	{ yyval.expression = new cdk::integer_node(LINE, yystack.l_mark[0].i); }
break;
case 11:
#line 68 "pwn_parser.y"
	{ yyval.expression = new cdk::string_node(LINE, yystack.l_mark[0].s); }
break;
case 12:
#line 69 "pwn_parser.y"
	{ yyval.expression = new cdk::neg_node(LINE, yystack.l_mark[0].expression); }
break;
case 13:
#line 70 "pwn_parser.y"
	{ yyval.expression = new pwn::not_node(LINE, yystack.l_mark[0].expression); }
break;
case 14:
#line 71 "pwn_parser.y"
	{ yyval.expression = new cdk::add_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 15:
#line 72 "pwn_parser.y"
	{ yyval.expression = new cdk::sub_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 16:
#line 73 "pwn_parser.y"
	{ yyval.expression = new cdk::mul_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 17:
#line 74 "pwn_parser.y"
	{ yyval.expression = new cdk::div_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 18:
#line 75 "pwn_parser.y"
	{ yyval.expression = new cdk::mod_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 19:
#line 76 "pwn_parser.y"
	{ yyval.expression = new cdk::lt_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 20:
#line 77 "pwn_parser.y"
	{ yyval.expression = new pwn::or_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 21:
#line 78 "pwn_parser.y"
	{ yyval.expression = new pwn::and_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 22:
#line 79 "pwn_parser.y"
	{ yyval.expression = new cdk::gt_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 23:
#line 80 "pwn_parser.y"
	{ yyval.expression = new cdk::ge_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 24:
#line 81 "pwn_parser.y"
	{ yyval.expression = new cdk::le_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 25:
#line 82 "pwn_parser.y"
	{ yyval.expression = new cdk::ne_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 26:
#line 83 "pwn_parser.y"
	{ yyval.expression = new cdk::eq_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 27:
#line 84 "pwn_parser.y"
	{ yyval.expression = yystack.l_mark[-1].expression; }
break;
case 28:
#line 85 "pwn_parser.y"
	{ yyval.expression = new pwn::rvalue_node(LINE, yystack.l_mark[0].lvalue); }
break;
case 29:
#line 86 "pwn_parser.y"
	{ yyval.expression = new pwn::assignment_node(LINE, yystack.l_mark[-2].lvalue, yystack.l_mark[0].expression); }
break;
#line 679 "pwn_parser.tab.c"
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
