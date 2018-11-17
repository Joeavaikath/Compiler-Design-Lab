#include<stdio.h>
#include<string.h>
#include<ctype.h>

char rules[6][10];
char first[10][10], follow[10][10];
int m = 0, n = 0, count = 6;

void first(char c){
	
	for(int rno=0;rno<count;rno++){
		
		if(c == rules[rno][2]){	
			
			m = 0;	
			if(rules[rno][2]>a && rules[rno][2]<z){
	
				first[rno][m++] = rules[rno][2];
			}
			else{
		
				first(rules[rno][2]);
			}
		}
	}
}

void pFirst(){

	for(int i=0;i<count;i++){

		

void main(){
	
	/*
	printf("\n Enter no. of productions: ");
	scanf("%d", n);
	
	for(int i = 0;i < count;i++){
	
		printf("\n Enter rule:");
		scanf("%s", &rules[i]):

	}
	*/

	strcpy(rules[0], "S=AB");
	strcpy(rules[1], "S=cd");
	strcpy(rules[2], "B=cAd");
	strcpy(rules[3], "B=b");
	strcpy(rules[4], "A=a");
	strcpy(rules[5], "A=b");

	

		
}
