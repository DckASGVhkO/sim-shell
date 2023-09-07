%{
#include "parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* input;
extern int yylex(YYSTYPE yylval);
extern int yyparse();
void yyerror(const char* msg);
%}

%lex-param { YYSTYPE yylval }

%union {
    int token;
    const char* lexeme;
}

%token <lexeme> WHITESP PIPE SEQ REDIR_IN REDIR_OUT ARG SING_QUOT DOUB_QUOT BACKQUOT

%left SEQ
%left PIPE

%%
cmd : /* empty */
    | cmd PIPE cmd %prec PIPE
    | cmd SEQ cmd %prec SEQ
    | simp_cmd
    ;

simp_cmd : arg
         | simp_cmd arg
         | simp_cmd REDIR_IN arg
         | simp_cmd REDIR_OUT arg
         ;

arg : ARG
    | SING_QUOT
    | DOUB_QUOT
    | BACKQUOT
    | error { yyerror("Invalid argument"); }
    ;
%%

void yyerror(const char* msg) {
    fprintf(stderr, "Error: %s at token '%s'\n", msg, yylval.lexeme);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        input = argv[1];
    }

    yyparse();

    return 0;
}
