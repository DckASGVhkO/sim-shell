
#line 1 "lexer.rl"
#include "parser.h"

#include <stdio.h>

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

extern char* input;
static const char* p = NULL;

// char* copy_str(const char* src, bool rm_quot) {
//     size_t len = strlen(src);
//     char* dst;

//     if (rm_quot) {
//         len -= 2;
//         dst = malloc(len + 1);
//         if (dst == NULL) { return NULL; }
//         strncpy(dst, src + 1, len);
//     } else {
//         dst = malloc(len + 1);
//         if (dst == NULL) { return NULL; }
//         strncpy(dst, src, len);
//     }

//     dst[len] = '\0';
//     return dst;
// }

char* copy_str(const char* start, const char* end, bool rm_quot) {
    size_t len = end - start;
    char* dst;

    if (rm_quot) {
        len -= 2;
        start += 1;
    }

    dst = malloc(len + 1);
    if (dst == NULL) {
        return NULL;
    }

    memcpy(dst, start, len);
    dst[len] = '\0';

    return dst;
}


#line 56 "/Users/roger/Desktop/shell/build/lexer.c"
static const int sh_parser_start = 4;
static const int sh_parser_first_final = 4;
static const int sh_parser_error = 0;

static const int sh_parser_en_main = 4;


#line 73 "lexer.rl"


int yylex(YYSTYPE yylval) {
    int ret = INT_MAX;
    int cs, act;
    const char* ts;
    const char* te;

    (void) sh_parser_first_final;
    (void) sh_parser_error;
    (void) sh_parser_en_main;


#line 78 "/Users/roger/Desktop/shell/build/lexer.c"
	{
	cs = sh_parser_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 86 "lexer.rl"
    
    if (p == NULL) {
        p = input;
    }
    const char* pe = input + strlen(input);
    const char* eof = pe;

    if (p == eof) {
        printf("Reached end of input.\n");
        return 0;
    }


#line 100 "/Users/roger/Desktop/shell/build/lexer.c"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
tr0:
#line 1 "NONE"
	{	switch( act ) {
	case 0:
	{{goto st0;}}
	break;
	case 7:
	{{p = ((te))-1;} ret = SING_QUOT; yylval.lexeme = copy_str(ts, te, true); {p++; cs = 4; goto _out;} }
	break;
	case 8:
	{{p = ((te))-1;} ret = DOUB_QUOT; yylval.lexeme = copy_str(ts, te, true); {p++; cs = 4; goto _out;} }
	break;
	case 9:
	{{p = ((te))-1;} ret = BACKQUOT; yylval.lexeme = copy_str(ts, te, true); {p++; cs = 4; goto _out;} }
	break;
	}
	}
	goto st4;
tr10:
#line 65 "lexer.rl"
	{te = p+1;{ ret = SEQ; yylval.lexeme = ";"; {p++; cs = 4; goto _out;} }}
	goto st4;
tr11:
#line 66 "lexer.rl"
	{te = p+1;{ ret = REDIR_IN; yylval.lexeme = "<"; {p++; cs = 4; goto _out;} }}
	goto st4;
tr12:
#line 67 "lexer.rl"
	{te = p+1;{ ret = REDIR_OUT; yylval.lexeme = ">"; {p++; cs = 4; goto _out;} }}
	goto st4;
tr13:
#line 64 "lexer.rl"
	{te = p+1;{ ret = PIPE; yylval.lexeme = "|"; {p++; cs = 4; goto _out;} }}
	goto st4;
tr14:
#line 63 "lexer.rl"
	{te = p;p--;{ ret = WHITESP; }}
	goto st4;
tr15:
#line 70 "lexer.rl"
	{te = p;p--;{ ret = DOUB_QUOT; yylval.lexeme = copy_str(ts, te, true); {p++; cs = 4; goto _out;} }}
	goto st4;
tr16:
#line 69 "lexer.rl"
	{te = p;p--;{ ret = SING_QUOT; yylval.lexeme = copy_str(ts, te, true); {p++; cs = 4; goto _out;} }}
	goto st4;
tr17:
#line 68 "lexer.rl"
	{te = p;p--;{ ret = ARG; printf("ARG\t"); yylval.lexeme = copy_str(ts, te, false); {p++; cs = 4; goto _out;} }}
	goto st4;
tr18:
#line 71 "lexer.rl"
	{te = p;p--;{ ret = BACKQUOT; yylval.lexeme = copy_str(ts, te, true); {p++; cs = 4; goto _out;} }}
	goto st4;
st4:
#line 1 "NONE"
	{ts = 0;}
#line 1 "NONE"
	{act = 0;}
	if ( ++p == pe )
		goto _test_eof4;
case 4:
#line 1 "NONE"
	{ts = p;}
#line 170 "/Users/roger/Desktop/shell/build/lexer.c"
	switch( (*p) ) {
		case 32: goto st5;
		case 34: goto st1;
		case 39: goto st2;
		case 59: goto tr10;
		case 60: goto tr11;
		case 62: goto tr12;
		case 96: goto st3;
		case 124: goto tr13;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st5;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st8;
		} else if ( (*p) >= 65 )
			goto st8;
	} else
		goto st8;
	goto st0;
st0:
cs = 0;
	goto _out;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
	if ( (*p) == 32 )
		goto st5;
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st5;
	goto tr14;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
	if ( (*p) == 34 )
		goto tr2;
	goto st1;
tr2:
#line 1 "NONE"
	{te = p+1;}
#line 70 "lexer.rl"
	{act = 8;}
	goto st6;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
#line 222 "/Users/roger/Desktop/shell/build/lexer.c"
	if ( (*p) == 34 )
		goto tr2;
	goto st1;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	if ( (*p) == 39 )
		goto tr4;
	goto st2;
tr4:
#line 1 "NONE"
	{te = p+1;}
#line 69 "lexer.rl"
	{act = 7;}
	goto st7;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
#line 243 "/Users/roger/Desktop/shell/build/lexer.c"
	if ( (*p) == 39 )
		goto tr4;
	goto st2;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st8;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st8;
	} else
		goto st8;
	goto tr17;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	if ( (*p) == 96 )
		goto tr6;
	goto st3;
tr6:
#line 1 "NONE"
	{te = p+1;}
#line 71 "lexer.rl"
	{act = 9;}
	goto st9;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
#line 277 "/Users/roger/Desktop/shell/build/lexer.c"
	if ( (*p) == 96 )
		goto tr6;
	goto st3;
	}
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof1: cs = 1; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 5: goto tr14;
	case 1: goto tr0;
	case 6: goto tr15;
	case 2: goto tr0;
	case 7: goto tr16;
	case 8: goto tr17;
	case 3: goto tr0;
	case 9: goto tr18;
	}
	}

	_out: {}
	}

#line 99 "lexer.rl"

    return ret == INT_MAX ? 0 : ret;
}
