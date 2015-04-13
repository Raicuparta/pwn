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
extern YYSTYPE yylval;
