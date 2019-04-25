%{
#include <stdio.h>
#include "y.tab.h"

#ifdef YYSTYPE
#define YYSTYPE char*
#endif

extern YYSTYPE yylval;
%}

%%
(Var)
{
    yylval.str=strdup(yytext); 
    return SERVICE_WORD;
}

[0-9]+        
{
    yylval.str=strdup(yytext); 
    return CONST;
}

([a-zA-Z])+
{
    yylval.str=strdup(yytext);  
    return IDENT;
}

(\+|\-|\*|\/)
{
    yylval.str=strdup(yytext); 
    return BINARY;
}

(\-)
{
    yylval.str=strdup(yytext); 
    return UNARY;
}

(\:=){1}
{
    yylval.str=strdup(yytext);  
    return APPROP;
}

(\,){1}
{
    yylval.str=strdup(yytext); 
    return COMMA;
}

(\;){1}
{
    yylval.str=strdup(yytext);  
    return SEMICOLON;
}

(\:){1}
{
    yylval.str=strdup(yytext); 
    return ASSIGMENT;
}

(\(){1} 
{
    yylval.str=strdup(yytext); 
    return BRACKET_OPENING;
}

(\)){1}
{
    yylval.str=strdup(yytext); 
    return BRACKET_CLOSING;
}
\n
{
    ;
}

[\t]+
%%
