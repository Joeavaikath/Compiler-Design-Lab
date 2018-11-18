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
char table[6][7][4] = { "NT","i","+","*","(",")","$",
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

//Get row index value from table
int getRow(char c){

	for(int i=0;i<rCount;i++){
		
		if(table[i][0][0] == c)
			return i;
	}

}

//Get column index value from the table
int getCol(char c){

	for(int i=0;i<cCount;i++){
		
		if(table[0][i][0] == c)
			return i;
	}
}

//Push multi-character rules in reverse
void revPush(char c[]){

	for(int i=strlen(c)-1;i>=0;i--)
		push(c[i]);
}


void main(){

	//Initialize stack
	push('$');
	push('E');
	
	//Accept Input
	printf("\n Enter the i/p string : ");
	scanf("%s", ip);

	//Parsing begins
	while(top!=-1){

		cur = pop();
		
		curIp = ip[ipInd];

		printf("\n\nStack Symbol: %c \t Current I/P Symbol:%c", cur, curIp);

		//printf("\n\nStack symbol:%c \n\nCurrent I/P Symbol:%c", cur, curIp);

		//Terminal matching
		if((cur >= 'a' && cur <= 'z') ||
		    cur == '(' ||
 		    cur == ')' ||
		    cur == '+' ||
		    cur == '*' ||
		    cur == '/' ||
		    cur == '-' ){

			
			if(cur == curIp){
				//printf("\n\nMatched %c", cur);
				ipInd++;

			}
			else{
				//printf("\n\nAborting, Mismatch: %c", curIp);
				exit(0);
			} 

		}
		//Non-terminal or Epsilon ( # ), get rule and push
		else{
			
			//Row and column indexes from the stack(cur) and current i/p character(curIp)
			int row = getRow(cur);
			int col = getCol(curIp);
			
			//printf("\n\nRowVal:%d \tColVal:%d", row, col);
			printf("\nRule: %c-->%s", table[row][0][0], table[row][col]);
			
			//Table entry found
			if(table[row][col][0] != '-'){
				
				if(strlen(table[row][col]) > 1)
					revPush(table[row][col]);
				else if(table[row][col][0] != '#')
					push(table[row][col][0]);			
				
				//printf("\n\nPush complete\n\n\n\n\n\n--------------------------------------------------");

			}
			//No entry in table
			else{
				printf("\n Table value is empty, Aborting.");
				exit(0);
			}

		}

		
		if(ip[ipInd] == '$' && stack[top] == '$'){
			printf("\n String accepted");
			exit(0);
		}
					
		
	}	
}		
