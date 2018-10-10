%{

#include<stdio.h>

%}

%%

0(10|01)* {printf("Valid");}
.*          	      {printf("Not Valid");}

%%

int yywrap(){
}

void main()
{

yylex();

}
