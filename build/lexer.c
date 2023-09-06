
#line 1 "lexer.rl"
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


#line 53 "lexer.rl"

