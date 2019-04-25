%{//Блок определений
#include <stdio.h>
#include "y.tab.h"

#ifndef YYSTYPE
#define YYSTYPE char*
#endif
#define INTEGER 288
extern YYSTYPE yylval;
%}

%%
[0-9]+ yylval=strdup(yytext);return NUMBER;
("Var") yylval=strdup(yytext);return KEY_VAR;
("Begin"){1} return BG;
("End"){1} return ND;
([a-zA-Z]){1}([a-zA-Z0-9]|\_)* yylval=strdup(yytext);return IDENTIFIER;
(\*|\/){1} yylval=strdup(yytext);return OPERATION;
(\;){1} return SEMICOLON;
(\,){1} return COMMA;
(\:\=){1} return SIGN;
(\-){1} yylval=strdup(yytext);return MINUS;
(\+){1} yylval=strdup(yytext);return PLUS;
(\(){1} yylval=strdup(yytext);return OBRACKET;
(\)){1} yylval=strdup(yytext);return EBRACKET;
\n
[ \t]+ ;
%%
//Блок кода на СИ
int yywrap()
{return 1;}
