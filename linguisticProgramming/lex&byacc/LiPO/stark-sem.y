%{//Блок определений
#include <stdio.h>
#include <string.h>

#ifndef YYSTYPE
#define YYSTYPE char*
#endif

#define INTEGER 288
extern FILE* yyin; 
void yyerror (const char *str);
int yylex(void);
%}

%token NUMBER IDENTIFIER KEY_VAR OPERATION SEMICOLON COMMA SIGN MINUS  OBRACKET EBRACKET BG ND PLUS
%left PLUS MINUS
%left OPERATION
%left UNARY
//Блок првил
%%
PROGRAM: 
	VARS OPS
;
VARS: 
VAR
{
printf("\n%s",$1);
}
|VARS VAR
{
printf("%s",$2);
}
;
VAR: 
KEY_VAR IDS SEMICOLON 
{
$$ = strcat($1," ");
$$ = strcat($$,$2);
$$ = strcat($$,"\n");
}
;
IDS: 
	IDENTIFIER
|IDS COMMA IDENTIFIER
{
$$ = strcat($1,",");
$$ = strcat($$,$3);
}
;
OPS: 
	BG LISTASSIGMENTS ND
;
LISTASSIGMENTS:	
ASSIGMENT
{
printf("%s",$1);
}
|ASSIGMENT LISTASSIGMENTS
{
printf("%s",$1);
}
;
ASSIGMENT:
	IDENTIFIER SIGN EXPRESSION SEMICOLON
{
$$ = strcat($1,"=");
$$ = strcat($$,$3);
$$ = strcat($$,"\n");
}
;
EXPRESSION:
	MINUS SUB %prec UNARY
{
$$ = strcat($1,$2);
}	
|SUB
;
SUB:		
OBRACKET EXPRESSION EBRACKET
{
$$ = strcat($1,$2);
$$ = strcat($$,$3);	
}
|OPERAND
|SUB OPERATION SUB 
{
$$ = strcat($1,$2);
$$ = strcat($$,$3);	
}
|SUB PLUS SUB
{
$$ = strcat($1,$2);
$$ = strcat($$,$3);	
}
|SUB MINUS SUB
{
$$ = strcat($1,$2);
$$ = strcat($$,$3);	
}
;
OPERAND:
	IDENTIFIER
	|NUMBER
;
%%
//Блок кода на СИ
void yyerror (const char *str)
{	
fprintf(stderr,"error: %s\n",str);
}

int main()
{
	yyin = fopen("prog.txt","r"); 	
	yyparse();
	fclose(yyin);
	return 0; 

}






