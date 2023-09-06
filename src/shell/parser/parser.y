%{
#include "lexer.h"

#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse(LexerState* state);
extern FILE* yyin;

void yyerror(LexerState* state, const char* s);
%}

%parse-param { LexerState* state }

%union {
  char *str;
}

%token <str> PIPE SEQ REDIRECTION_IN REDIRECTION_OUT ARGUMENT SINGLE_QUOTED DOUBLE_QUOTED BACKQUOTED

%left SEQ
%left PIPE

%%

command : /* empty */
        | command PIPE command %prec PIPE
        | command SEQ command %prec SEQ
        | simple_command
        ;

simple_command : argument
               | simple_command argument
               | simple_command REDIRECTION_IN argument
               | simple_command REDIRECTION_OUT argument
               ;

argument : ARGUMENT
         | SINGLE_QUOTED
         | DOUBLE_QUOTED
         | BACKQUOTED
         ;

%%

void yyerror(LexerState *state, const char* s) {
  fprintf(stderr, "Error: %s at token '%s'\n", s, state->lexeme);
}

int main(int argc, char* argv[]) {
    LexerState state;
    if (argc > 1) {
      yyin = fopen(argv[1], "r");
      if (yyin == NULL) {
        perror("fopen");
        return 1;
      }
    }

    yyparse(&state);
    return 0;
}
