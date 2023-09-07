#include "common.h"
#include "parser.h"

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char* p = NULL;

char* copy_str(const char* start, const char* end, bool rm_quot) {
    size_t len = end - start;
    if (rm_quot) {
        len -= 2;
        start += 1;
    }
    char* dst = malloc(len + 1);
    if (dst == NULL) return NULL;
    memcpy(dst, start, len);
    dst[len] = '\0';
    return dst;
}

%%{
machine sh_parser;
write data;

whitesp   = space | '\t' | '\n';
sing_quot = '\'' any* '\'';
doub_quot = '\"' any* '\"';
backquot  = '`' any* '`';

main := |*
    whitesp*  => { ret = WHITESP; };
    '|'       => { ret = PIPE; ctx->lexeme = "|"; printf("%s\n", ctx->lexeme); fbreak; };
    ';'       => { ret = SEQ; ctx->lexeme = ";"; printf("%s\n", ctx->lexeme); fbreak; };
    '<'       => { ret = REDIR_IN; ctx->lexeme = "<"; printf("%s\n", ctx->lexeme); fbreak; };
    '>'       => { ret = REDIR_OUT; ctx->lexeme = ">"; printf("%s\n", ctx->lexeme); fbreak; };
    [^'"`]+   => { ret = ARG; ctx->lexeme = copy_str(ts, te, false); printf("%s\n", ctx->lexeme); fbreak; };
    sing_quot => { ret = SING_QUOT; ctx->lexeme = copy_str(ts, te, true); printf("%s\n", ctx->lexeme); fbreak; };
    doub_quot => { ret = DOUB_QUOT; ctx->lexeme = copy_str(ts, te, true); printf("%s\n", ctx->lexeme); fbreak; };
    backquot  => { ret = BACKQUOT; ctx->lexeme = copy_str(ts, te, true); printf("%s\n", ctx->lexeme); fbreak; };
    any       => { ret = UNKNOWN; ctx->lexeme = copy_str(ts, te, false); printf("%s\n", ctx->lexeme); fbreak; };
*|;
}%%

int yylex(Ctx* ctx) {
    int ret = INT_MAX, cs, act;
    const char* ts;
    const char* te;

    (void) sh_parser_first_final;
    (void) sh_parser_error;
    (void) sh_parser_en_main;

%% write init;
    if (p == NULL) p = ctx->input;
    const char* pe = ctx->input + strlen(ctx->input);
    const char* eof = pe;
    
    if (p == eof) return 0;
%% write exec;

    if (ret == UNKNOWN) yyerror(ctx, "Syntax error");

    return ret == INT_MAX ? 0 : ret;
}
