%{
#include<stdio.h>
%}
%token NUM NL
%left '+''-'
%left '*''/'
%right '^'
	

%%

S : E NL {	printf("\nValid: %d\n",$1);

		}
;
E : E '+' E  {$$=$1+$3;}
    |E '-' E {$$=$1-$3;}  	
    |E '*' E {$$=$1*$3;}
    |E '/' E {$$=$1/$3;}
    |'('E')' {$$=$2;}    
    |NUM	{$$=$1;}
;

%%

int yyerror(){

printf("\nInvalid");

}

void main(){

extern YY_FLUSH_BUFFER;
yyparse();


}
