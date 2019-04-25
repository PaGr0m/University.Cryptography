%{//Блок определений
#include <stdio.h>
#include "y.tab.h"

#ifndef YYSTYPE
#define YYSTYPE char*
#endif
#define INTEGER 288
%}
//Блок правил
%%
[0-9]+ {return NUMBER;}
("Var") {return KEY_VAR;}
("Begin"){1} {return BG;}
("End"){1} {return ND;}
([a-zA-Z]){1}([a-zA-Z0-9]|\_)* {return IDENTIFIER;}
(\*|\/){1} {return OPERATION;}
(\+){1} {return PLUS;}
(\;){1} {return SEMICOLON;}
(\,){1} {return COMMA;}
(\:\=){1} {return SIGN;}
(\-){1} { return MINUS;}
(\(){1} {return OBRACKET;}
(\)){1} {return EBRACKET;}
\n ;
[ \t]+ ;
%%
//Блок кода на СИ
int yywrap()
{return 1;}

