%{
#include <stdio.h>
#include "y.tab.h"

#ifdef YYSTYPE
#define YYSTYPE char*
#endif
#define INTEGER 288
extern YYSTYPE yylval;
%}

%%
(Var)               yylval=strdup(yytext);return SERVICE_WORD;
[0-9]+              yylval=strdup(yytext);return CONST;
([a-zA-Z])+         yylval=strdup(yytext);return IDENT;
(\+|\*|\/){1}       yylval=strdup(yytext);return BINARY;

(\-){1}             return UNARY;
(\:=){1}            return APPROP;
(\,){1}             return COMMA;
(\;){1}             return SEMICOLON;
(\:){1}             return ASSIGMENT;
(\(){1}             return BRACKET_OPENING;
(\)){1}             return BRACKET_CLOSING;
\n                  
[ \t]+              ;

%%
int yywrap()
{
    return 1;
}
