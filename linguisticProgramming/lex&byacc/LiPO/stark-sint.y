%{
#include <stdio.h>
#include <string.h>
extern FILE* yyin; 
void yyerror(const char *str);
int yylex(void);
%}

%token NUMBER IDENTIFIER KEY_VAR OPERATION SEMICOLON COMMA SIGN MINUS  OBRACKET EBRACKET BG ND PLUS 
%left PLUS MINUS
%left OPERATION
%left UNARY

%%
PROGRAM: 
	VARS OPS
;
VARS: 
	VAR
	|VARS VAR
;
VAR: 
	KEY_VAR IDS SEMICOLON 

;
IDS: 
	IDENTIFIER
	|IDS COMMA IDENTIFIER
;
OPS: 
	BG LISTASSIGMENTS ND
;
LISTASSIGMENTS:
	ASSIGMENT
	|LISTASSIGMENTS ASSIGMENT
;
ASSIGMENT:
	IDENTIFIER SIGN EXPRESSION SEMICOLON
;
EXPRESSION:
	MINUS SUB %prec UNARY
	|SUB
;
SUB:	
	OBRACKET EXPRESSION EBRACKET
	|OPERAND
	|SUB PLUS SUB|SUB OPERATION SUB
	|SUB MINUS SUB
;
OPERAND:
	IDENTIFIER
	|NUMBER
;
%%

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






