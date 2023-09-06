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

%%{
machine sh_parser;

whitesp   = space | '\t' | '\n';
arg       = alnum+;
sing_quot = '\'' any* '\'';
doub_quot = '\"' any* '\"';
backquot  = '`' any* '`';

main := |*
    whitesp*  => { ret = WHITESP; };
    '|'       => { ret = PIPE; fbreak; };
    ';'       => { ret = SEQ; fbreak; };
    '<'       => { ret = REDIR_IN; fbreak; };
    '>'       => { ret = REDIR_OUT; fbreak; };
    arg       => { ret = ARG; yylval->lexeme = ts; fbreak; };
    sing_quot => { ret = SING_QUOT; yylval->lexeme = copy_str(ts, true); fbreak; };
    doub_quot => { ret = DOUB_QUOT; yylval->lexeme = copy_str(ts, true); fbreak; };
    backquot  => { ret = BACKQUOT; yylval->lexeme = copy_str(ts, true); fbreak; };
    whitesp*  => { ret = WHITESP; };
*|;
}%%

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
