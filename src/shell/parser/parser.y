%{
#include "common.h"
#include "parser.h"

#include <stdio.h>
#include <stdlib.h>
%}

%union {
    const char* lexeme;
}

%token <lexeme> WHITESP PIPE SEQ REDIR_IN REDIR_OUT ARG SING_QUOT DOUB_QUOT BACKQUOT UNKNOWN

%lex-param { Ctx* ctx }
%parse-param { Ctx* ctx }

%%

pipe : cmd | pipe PIPE cmd;
cmd : /* empty */ | cmd_elem | cmd cmd_elem;
cmd_elem : arg | REDIR_IN arg | REDIR_OUT arg | WHITESP;
arg : ARG | SING_QUOT | DOUB_QUOT | BACKQUOT;

%%

void yyerror(Ctx* ctx, const char* msg) {
    fprintf(stderr, "Error: %s near %s\n", msg, ctx->lexeme);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    Ctx ctx;
    if (argc > 1) {
        ctx.input = argv[1];
    }
    yyparse(&ctx);
    return 0;
}
