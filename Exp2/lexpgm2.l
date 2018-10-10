%{

#include<stdio.h>

%}


%%


\".*\"
\'.*
#.*
.*\(
\)
[{}]
"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"register"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"
;|=|\+|\-|\/|\<|\>
[0-9]
[a-zA-Z][a-zA-Z0-9]* {printf(" <ID[%s]> ",yytext);}
" "

%%

int yywrap(){
}

void main(){

FILE *fh;
fh = fopen("program", "r");
yyin = fh;
yylex();
fclose(fh);

}

