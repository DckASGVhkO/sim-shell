#include "lexer.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void handler(LexerState* state) {
    printf("Token: %d, Lexeme: %s\n", state->token, state->lexeme);
}

void emit(LexerState* state, int token, char* lexeme) {
    state->token = token;
    state->lexeme = lexeme;
    handler(state);
}

char* copy_str(const char* src, bool rm_quot) {
    size_t len = strlen(src);
    size_t offset = rm_quot ? 1 : 0;
    size_t new_len = len - 2 * offset;

    char* dst = malloc(new_len + 1);
    if (dst == NULL) return NULL;

    strncpy(dst, src + offset, new_len);
    dst[new_len] = '\0';

    return dst;
}

%%{
  machine sh_parser;

  action act_ign { }
  action act_pipe { emit($lexer_state, handler, PIPE, NULL); }
  action act_seq { emit($lexer_state, handler, SEQ, NULL); }
  action act_redir_in { emit($lexer_state, handler, REDIR_IN, NULL); }
  action act_redir_out { emit($lexer_state, handler, REDIR_OUT, NULL); }
  action act_arg { emit($lexer_state, handler, ARGUMENT, copy_str(yytext, false)); }
  action act_sing_quot { emit($lexer_state, handler, SING_QUOT, copy_str(yytext, true)); }
  action act_doub_quot { emit($lexer_state, handler, DOUB_QUOT, copy_str(yytext, true)); }
  action act_backquot { emit($lexer_state, handler, BACKQUOT, copy_str(yytext, true)); }

  whitesp = space | '\t' | '\n' @act_ign;
  arg = alnum+ @act_arg;
  sing_quot = "'" any* "'" @act_sing_quot;
  doub_quot = "\"" any* "\"" @act_doub_quot;
  backquot = "`" any* "`" @act_backquot;

  main := whitesp* | '|' @act_pipe | ';' @act_seq | '<' @act_redir_in | '>' @act_redir_out
         | arg | sing_quot | doub_quot | backquot | whitesp*;
}%%
