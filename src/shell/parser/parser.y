%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);
%}

%union {
    int token;
    const char* lexeme;
}

%token <lexeme> WHITESP PIPE SEQ REDIR_IN REDIR_OUT ARG SING_QUOT DOUB_QUOT BACKQUOT

%left SEQ
%left PIPE

%%

cmd : /* empty */
    | cmd PIPE cmd %prec PIPE
    | cmd SEQ cmd %prec SEQ
    | simp_cmd
    ;

simp_cmd : arg
         | simp_cmd arg
         | simp_cmd REDIR_IN arg
         | simp_cmd REDIR_OUT arg
         ;

arg : ARG
    | SING_QUOT
    | DOUB_QUOT
    | BACKQUOT
    ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s at token '%s'\n", s, yylval.lexeme);
}

int main(int argc, char* argv[]) {
    char input_buffer[256];
    FILE* yyin = NULL;

    while (1) {
        printf("请输入命令：");
        
        if (scanf("%255[^\n]", input_buffer) != 1) {
            fprintf(stderr, "Error: 无法读取输入\n");
            break;
        }

        while (getchar() != '\n');

        FILE* temp_file = tmpfile();
        if (temp_file == NULL) {
            perror("tmpfile");
            return 1;
        }
        fprintf(temp_file, "%s", input_buffer);
        rewind(temp_file);

        yyin = temp_file;

        yyparse();

        fclose(temp_file);

        memset(input_buffer, 0, sizeof(input_buffer));
    }

    return 0;
}
