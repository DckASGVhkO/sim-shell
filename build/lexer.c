
#line 1 "lexer.rl"
#include "parser.h"

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

extern char* input;

char* copy_str(const char* src, bool rm_quot) {
    size_t len = strlen(src);
    char* dst;

    if (rm_quot) {
        len -= 2;
        dst = malloc(len + 1);
        if (dst == NULL) { return NULL; }
        strncpy(dst, src + 1, len);
    } else {
        dst = malloc(len + 1);
        if (dst == NULL) { return NULL; }
        strncpy(dst, src, len);
    }

    dst[len] = '\0';
    return dst;
}


#line 50 "lexer.rl"


int yylex(YYSTYPE* yylval) {
    if (input == NULL) {
        return 0;
    }

    int ret = INT_MAX;
    const char* p = input;
    const char* pe = input + strlen(input);
    const char* eof = pe;

    if (p == eof) {
        ret = 0;
    }

    return ret == INT_MAX ? 0 : ret;
}
