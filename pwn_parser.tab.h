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
extern YYSTYPE yylval;
