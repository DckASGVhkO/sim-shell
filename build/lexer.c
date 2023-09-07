
#line 1 "lexer.rl"
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


#line 29 "/Users/roger/Desktop/shell/build/lexer.c"
static const int sh_parser_start = 3;
static const int sh_parser_first_final = 3;
static const int sh_parser_error = -1;

static const int sh_parser_en_main = 3;


#line 46 "lexer.rl"


int yylex(Ctx* ctx) {
    int ret = INT_MAX, cs, act;
    const char* ts;
    const char* te;

    (void) sh_parser_first_final;
    (void) sh_parser_error;
    (void) sh_parser_en_main;


#line 50 "/Users/roger/Desktop/shell/build/lexer.c"
	{
	cs = sh_parser_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 58 "lexer.rl"
    if (p == NULL) p = ctx->input;
    const char* pe = ctx->input + strlen(ctx->input);
    const char* eof = pe;
    
    if (p == eof) return 0;

#line 65 "/Users/roger/Desktop/shell/build/lexer.c"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
tr0:
#line 1 "NONE"
	{	switch( act ) {
	case 2:
	{{p = ((te))-1;} ret = PIPE; ctx->lexeme = "|"; printf("%s\n", ctx->lexeme); {p++; cs = 3; goto _out;} }
	break;
	case 3:
	{{p = ((te))-1;} ret = SEQ; ctx->lexeme = ";"; printf("%s\n", ctx->lexeme); {p++; cs = 3; goto _out;} }
	break;
	case 4:
	{{p = ((te))-1;} ret = REDIR_IN; ctx->lexeme = "<"; printf("%s\n", ctx->lexeme); {p++; cs = 3; goto _out;} }
	break;
	case 5:
	{{p = ((te))-1;} ret = REDIR_OUT; ctx->lexeme = ">"; printf("%s\n", ctx->lexeme); {p++; cs = 3; goto _out;} }
	break;
	case 6:
	{{p = ((te))-1;} ret = ARG; ctx->lexeme = copy_str(ts, te, false); printf("%s\n", ctx->lexeme); {p++; cs = 3; goto _out;} }
	break;
	case 7:
	{{p = ((te))-1;} ret = SING_QUOT; ctx->lexeme = copy_str(ts, te, true); printf("%s\n", ctx->lexeme); {p++; cs = 3; goto _out;} }
	break;
	case 8:
	{{p = ((te))-1;} ret = DOUB_QUOT; ctx->lexeme = copy_str(ts, te, true); printf("%s\n", ctx->lexeme); {p++; cs = 3; goto _out;} }
	break;
	case 9:
	{{p = ((te))-1;} ret = BACKQUOT; ctx->lexeme = copy_str(ts, te, true); printf("%s\n", ctx->lexeme); {p++; cs = 3; goto _out;} }
	break;
	case 10:
	{{p = ((te))-1;} ret = UNKNOWN; ctx->lexeme = copy_str(ts, te, false); printf("%s\n", ctx->lexeme); {p++; cs = 3; goto _out;} }
	break;
	}
	}
	goto st3;
tr16:
#line 35 "lexer.rl"
	{te = p;p--;{ ret = WHITESP; }}
	goto st3;
st3:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof3;
case 3:
#line 1 "NONE"
	{ts = p;}
#line 116 "/Users/roger/Desktop/shell/build/lexer.c"
	switch( (*p) ) {
		case 32: goto st5;
		case 34: goto tr9;
		case 39: goto tr10;
		case 59: goto tr11;
		case 60: goto tr12;
		case 62: goto tr13;
		case 96: goto tr14;
		case 124: goto tr15;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st5;
	goto tr7;
tr7:
#line 1 "NONE"
	{te = p+1;}
#line 40 "lexer.rl"
	{act = 6;}
	goto st4;
tr11:
#line 1 "NONE"
	{te = p+1;}
#line 37 "lexer.rl"
	{act = 3;}
	goto st4;
tr12:
#line 1 "NONE"
	{te = p+1;}
#line 38 "lexer.rl"
	{act = 4;}
	goto st4;
tr13:
#line 1 "NONE"
	{te = p+1;}
#line 39 "lexer.rl"
	{act = 5;}
	goto st4;
tr15:
#line 1 "NONE"
	{te = p+1;}
#line 36 "lexer.rl"
	{act = 2;}
	goto st4;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
#line 164 "/Users/roger/Desktop/shell/build/lexer.c"
	switch( (*p) ) {
		case 34: goto tr0;
		case 39: goto tr0;
		case 96: goto tr0;
	}
	goto tr7;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
	switch( (*p) ) {
		case 32: goto st5;
		case 34: goto tr16;
		case 39: goto tr16;
		case 96: goto tr16;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st5;
	goto tr7;
tr2:
#line 1 "NONE"
	{te = p+1;}
#line 42 "lexer.rl"
	{act = 8;}
	goto st6;
tr9:
#line 1 "NONE"
	{te = p+1;}
#line 44 "lexer.rl"
	{act = 10;}
	goto st6;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
#line 200 "/Users/roger/Desktop/shell/build/lexer.c"
	if ( (*p) == 34 )
		goto tr2;
	goto st0;
st0:
	if ( ++p == pe )
		goto _test_eof0;
case 0:
	if ( (*p) == 34 )
		goto tr2;
	goto st0;
tr4:
#line 1 "NONE"
	{te = p+1;}
#line 41 "lexer.rl"
	{act = 7;}
	goto st7;
tr10:
#line 1 "NONE"
	{te = p+1;}
#line 44 "lexer.rl"
	{act = 10;}
	goto st7;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
#line 227 "/Users/roger/Desktop/shell/build/lexer.c"
	if ( (*p) == 39 )
		goto tr4;
	goto st1;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
	if ( (*p) == 39 )
		goto tr4;
	goto st1;
tr6:
#line 1 "NONE"
	{te = p+1;}
#line 43 "lexer.rl"
	{act = 9;}
	goto st8;
tr14:
#line 1 "NONE"
	{te = p+1;}
#line 44 "lexer.rl"
	{act = 10;}
	goto st8;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
#line 254 "/Users/roger/Desktop/shell/build/lexer.c"
	if ( (*p) == 96 )
		goto tr6;
	goto st2;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	if ( (*p) == 96 )
		goto tr6;
	goto st2;
	}
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof0: cs = 0; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof1: cs = 1; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 4: goto tr0;
	case 5: goto tr16;
	case 6: goto tr0;
	case 0: goto tr0;
	case 7: goto tr0;
	case 1: goto tr0;
	case 8: goto tr0;
	case 2: goto tr0;
	}
	}

	_out: {}
	}

#line 64 "lexer.rl"

    if (ret == UNKNOWN) yyerror(ctx, "Syntax error");

    return ret == INT_MAX ? 0 : ret;
}
