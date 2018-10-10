%{
#include<stdio.h>
%}
%token NUM NL ID
%left '+''-'
%left '*''/'
%right '^'
	

%%

S : E NL {	printf("\nValid");

		}
;
E : E '+' E  
    |E '-' E   	
    |E '*' E 
    |E '/' E 
    |'('E')'     
    |NUM|ID
;

%%

int yyerror(){

printf("\nInvalid");

}

void main(){

extern YY_FLUSH_BUFFER;
yyparse();


}
