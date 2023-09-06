#ifndef _yy_defines_h_
#define _yy_defines_h_

#define PIPE 257
#define SEQ 258
#define REDIRECTION_IN 259
#define REDIRECTION_OUT 260
#define ARGUMENT 261
#define SINGLE_QUOTED 262
#define DOUBLE_QUOTED 263
#define BACKQUOTED 264
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
  char *str;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
