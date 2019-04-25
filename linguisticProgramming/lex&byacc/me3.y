%{
#include <stdio.h>
#include <string.h>
#ifndef YYSTYPE
#define YYSTYPE char*
#endif
#define INTEGER 288

extern YYSTYPE yylval;
extern FILE* yyin; 
void yyerror (const char *str);
int yylex(void);

void yyerror(const char *str)
{
    fprintf(stderr, "error: %s\n", str);
}

int main()
{
    return yyparse();
}
%}

%union {
    char* str;
}

%token <str> 
    SERVICE_WORD
    CONST 
    IDENT
    UNARY
    BINARY 
    APPROP 
    COMMA 
    SEMICOLON
    ASSIGMENT 
    BRACKET_OPENING 
    BRACKET_CLOSING

%left PLUS MINUS
%left OPERATION
%left UNARY

%type <str> 
    DESCRIPTION 
    VARIABLE_DECLARATION 
    VARIABLE_LIST 
    ASSIGNMENT_LIST 
    ASSIGNMENT 
    BINARY_OPERATION
    EXPRESSION 
    SUBEXPRESSION 
    OPERAND

%%
PROGRAM:    
    VARIABLE_DECLARATIONS DESCRIPTION;

VARIABLE_DECLARATIONS:  
    VARIABLE_DECLARATION 
    {
        printf("\n%s", $1);
    } | 
    VARIABLE_DECLARATIONS VARIABLE_DECLARATION
    {
        printf("%s", $2);
    };

VARIABLE_DECLARATION:    
    SERVICE_WORD VARIABLE_LIST SEMICOLON
    {
        $$ = strcat($1, " ");
        $$ = strcat($$, $2);
        $$ = strcat($$, ";\n");
    };

VARIABLE_LIST:    
    IDENT 
    {
        $$ = $1;
    } | 
    IDENT COMMA VARIABLE_LIST
    {
        $$ = strcat($1, ", ");
        $$ = strcat($$, $3);
    };

DESCRIPTION:
    ASSIGNMENT_LIST;

ASSIGNMENT_LIST:    
    ASSIGNMENT 
    {
        printf("%s", $1);
    } | ASSIGNMENT_LIST ASSIGNMENT
    {
        printf("%s", $2);
    };

ASSIGNMENT:     
    IDENT APPROP EXPRESSION SEMICOLON
    {
        $$ = strcat($1," := ");
        $$ = strcat($$,$3);
        $$ = strcat($$,"\n");
    }

EXPRESSION:     
    UNARY SUBEXPRESSION 
    {
        printf(" -");
    } | 
    SUBEXPRESSION
    {
        printf("");
    };

BINARY_OPERATION:
    BINARY SUBEXPRESSION | 
    UNARY SUBEXPRESSION;

SUBEXPRESSION:      
    BRACKET_OPENING EXPRESSION BRACKET_CLOSING |
    OPERAND | 
    SUBEXPRESSION BINARY_OPERATION;

OPERAND:    
    IDENT |
    CONST;







