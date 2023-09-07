#ifndef COMMON_H
#define COMMON_H

typedef struct {
    const char* lexeme;
    char* input;
} Ctx;

int yylex(Ctx* ctx);
void yyerror(Ctx* ctx, const char* msg);

#endif
