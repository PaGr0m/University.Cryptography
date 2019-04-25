%{
#include <stdio.h>
#include <string.h>

void yyerror(const char *str)
{
    fprintf(stderr, "error: %s\n", str);
}

int yywrap()
{
    retrun 1;
}

main()
{
    yyparse();
}
%}

%token NUMBER IDENTIFIER KEY_VAR OPERATION SEMICOLON COMMA SIGN MINUS PLUS OBRACKET EBRACKET

%%
PROGRAM: VARS OPS
;

OPS: BEG APPS END
{
    printf("%s", $1);
    printf("\n%s", $2);
    printf("\n%s", $3);
}
;
// Объявляем переменные
VARS:   VAR
|       VARS VAR
;
VAR:    KEY_VAR IDS COLON TYPE SEMICOLON
{
    printf("%s %s %s %s %s", $1, $2, $3, "Boolean", $5);
}
;
IDS:    IDENTIFIER
{
    $$=$1;
}
|       IDS COMMA IDENTIFIER
{
    $$=strcat($1, ",");
    $$=strcat($$, $3);
}
;
