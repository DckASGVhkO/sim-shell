%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);
%}

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
    ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s at token '%s'\n", s, yylval.lexeme);
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (yyin == NULL) {
            perror("fopen");
            return 1;
        }
    }

    yyparse();

    if (yyin != NULL) {
        fclose(yyin);
    }

    return 0;
}
