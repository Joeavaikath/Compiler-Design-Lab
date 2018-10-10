%{

#include<stdio.h>
#include<string.h>

int j =0;
int flag = 0;
char buf[10][10];
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
[a-zA-Z][a-zA-Z0-9]* {flag = 0;
		      for(int i=0;i<10;i++){
			if(strcmp(buf[i], yytext) == 0)
				flag = 1; 	
			}
			if(flag == 0){
			
				printf("ID[%s]", yytext);
				strcpy(buf[j], yytext);
				j++;
			} 
		     }
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

