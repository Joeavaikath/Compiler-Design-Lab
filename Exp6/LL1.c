#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>


int top = -1, ipInd = 0;
int rCount = 6, cCount = 7;
char stack[10];
char cur;
char ip[10];
char curIp;

//Transition Table 
char table[6][7][4] = { "NT","id","+","*","(",")","$",
			 "E" ,"TX","-","-","TX","-","-",
			 "X","-","+TX","-","-","#","#",
			 "T","FY","-","-","FY","-","-",
			 "Y","-","#","*FY","-","#","#",
			 "F","i","-","-","(E)","-","-"};

//Push into stack
void push(char a){

	top++;
	stack[top] = a;

}

//Pop from stack
char pop(){

	top--;
	return stack[top+1];

}

int getRow(char c){

	for(int i=0;i<rCount;i++){
		
		if(table[i][0][0] == c)
			return i;
	}

}

int getCol(char c){

	for(int i=0;i<cCount;i++){
		
		if(table[0][i] == c)
			return i;
	}
}

void revPush(char c[]){

	for(int i=strlen(c)-1;i>0;i--)
		push(c[i]);
}


void main(){

	//Initialize stack
	push("$");
	push("E");
	printf("\ncheck1");

	//Accept Input
	printf("\n Enter the i/p string : ");
	scanf("%s", ip);

	//Parsing begins
	while(top!=-1){

		cur = pop();
		
		curIp = ip[ipInd];
		
		if((cur >= 'a' && cur <= 'z') ||
		  !(cur >= 'A' && cur <= 'Z') ||
			cur != '$' ){

			if(cur == curIp)
				ipInd++;
			else{
				printf("mismatch: %c", curIp);
			} 

		}
		else{

			if(table[getRow(cur)][getCol(curIp)][0] != '-'){
				
				if(strlen(table[getRow(cur)][getCol(curIp)] > 1))
					revPush(table[getRow(cur)][getCol(curIp)]);
				else
					push(table[getRow(cur)][getCol(curIp)][0]);			
			}
			else{
				printf("\n Table value is empty, Aborting.");
				exit(0);
			}

		}

		if(ip[ipInd] == '$'){
			printf("\n String accepted");
			exit(0);
		}
					
		
	}	
}		
