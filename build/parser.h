#ifndef _yy_defines_h_
#define _yy_defines_h_

#define WHITESP 257
#define PIPE 258
#define SEQ 259
#define REDIR_IN 260
#define REDIR_OUT 261
#define ARG 262
#define SING_QUOT 263
#define DOUB_QUOT 264
#define BACKQUOT 265
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
    int token;
    const char* lexeme;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
