%{

#include<stdio.h>

%}


%token SW OB CB ID NL COB CCB CS Q BR SEM NUM EQ OP

%%

S:X NL {printf("Valid");}
;
X:SW OB ID CB NL COB CS NUM Q ID EQ Z OP Z SEM NL BR SEM NL Y CCB NL  
;
Y:CS NUM Q ID EQ Z OP Z SEM NL BR SEM NL |
;
Z:NUM|ID
;
%%

int yyerror(){

printf("\nInvalid");

}

void main(){

yyparse();

}


