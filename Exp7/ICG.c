#include<stdio.h>
#include<string.h>

char string[10];
int i, j, flag;

void push(char st[], char c, int *top){

	*top = *top + 1;
	st[*top] = c;

}
char pop(char st[], int *top){

	int temp = *top;
	*top = *top - 1;
	return st[temp];
}

int getP(char c){

	switch(c){

		case '+': return 2;
			  break;
		case '-':return 2;
				break;
		case '*':return 3;
			break;
		case '/':return 3;
			break;
		case '$':return 0;
			break;
		case '=':return 1;
			break;
		}
}


void main(){

	printf("\n Enter the IP string: ");
	scanf("%s", string);
	strcat(string, "$");

	//stack 1 for operands. stack 2 for operators. t for tenmperory variables
	char stack1[10], stack2[10], t[10][10];
	int top1, top2, choice, itr = 2, titr = 0, Ti = 90;
	top1=top2=-1;

	push(stack1, string[0], &top1);
	push(stack2, string[1], &top2);

	printf("\n Operator Op1 Op2 NewOP");

	while(top1!=-1 && itr<strlen(string)){

		//printf("\nitr :%d top1:%d top2:%d", itr, top1, top2);

		if(string[itr] == '+' ||
		   string[itr] == '-' ||
		   string[itr] == '*' ||
		   string[itr] == '/' ||
		   string[itr] == '$'){


			//printf("\nStack:%c IP STring:%c", stack2[top2], string[itr]);
			while(getP(stack2[top2]) >= getP(string[itr])){

				t[titr][2] = pop(stack1, &top1);
				t[titr][0] = pop(stack1, &top1);
				push(stack1, (char)Ti, &top1);
				Ti = Ti-1; 
				t[titr][1] = pop(stack2, &top2);
				t[titr][3] = '\0';

				printf("\n %c         %c    %c    %c", t[titr][1], t[titr][0], t[titr][2], (char)Ti+1);
				titr++;
				//printf("In popping");

			}


			push(stack2, string[itr], &top2);




		}
		else{
			push(stack1, string[itr], &top1);
		}
		itr++;


	}
	Ti = 90;
	printf("\n\n\n t values: \n");
	for(i=0;i<titr;i++)
		printf("\n%c   %s", (char)Ti--, t[i]);



}
