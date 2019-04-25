%{//Блок определений
#include <stdio.h>
extern FILE* yyin;
int yylex(void);
%}
//Блок правил
%%
[0-9]+ 							printf("Константа ");
("Var"|"Begin"|"End") 			printf("Ключевое_слово ");	
([a-zA-Z]){1}([a-zA-Z0-9]|\_)* 	printf("Идентификатор ");
(\*|\/|\+|\-){1} 				printf("Операция ");
(\:\=){1} 						printf("Операция_присваивания ");
(\(|\)|\,|\;){1} 				printf("Разделительный_символ ");
\n								printf("\n");
[ \t]+							printf("\t");
%%
//Блок кода на СИ
int main() 
{ 
yyin = fopen("prog.txt","r"); 
yylex(); 
}
