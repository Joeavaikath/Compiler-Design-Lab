#include<stdio.h>
#include<ctype.h>
#include<string.h>
void main(){

	FILE *fptr;
	fptr = fopen("program", "r");
	int state = 0;
	int i;
	int flag = 0;
	char ch = '1';
	

	int ctr = 0;
	char buf[10];

	char key[20][30] = {"int","float","else","if","printf","void"};
	
	while(ch != EOF){
	    
	    switch(state){

		case 0:
			ctr = 0;
			ch = getc(fptr);
			//printf("Character is %c",ch);
			if(isalpha(ch))
				state = 9;
			else if(isdigit(ch))
				state = 11;
			else if(ch == '<')
				state = 1;
			else if(ch == '>')
				state = 4;
			else if(ch == '!')
				state = 7;
			else if(ch == '=')
				state = 12;
			else if(ch == ';')
				state = 13;
			else if(ch == ')'||ch == '}')
				printf("\n");
			else if(ch == ' '){
				//do nothing
			}
			//printf("character is %c", ch);
			
			
			break;

		case 4: 
			ch = getc(fptr);
			if(ch == '=')
				printf("<GE>");
				
			else{
				printf("<GT>");
				fseek(fptr,-1, SEEK_CUR);			
			}
			state = 0;	
			break;

		case 1:
			ch = getc(fptr);
                        if(ch == '=')
                                printf("<LE>");
                        else{
                                printf("<LT>");
                                fseek(fptr,-1, SEEK_CUR);
                        }       
			state = 0;
                        break;
		
		case 7:
			ch = getc(fptr);
			if(ch == '='){
				state = 0;
				printf("<NE>");
			}
			break;

		case 9:
			//printf("here");
			flag = 0;
			buf[ctr] = ch;
			ctr++;
			ch = getc(fptr);
			if(!isalpha(ch)){
				
				
				
				state = 0;
				fseek(fptr,-1, SEEK_CUR);
				buf[ctr] = '\0';

				for(i = 0;i<10;i++){
				if(strcmp(key[i], buf) == 0){
					printf("<keyword>");
					printf("%s",buf);
					flag = 1;
					break;	
				}
				if(strcmp("include",buf)==0||strcmp("main",buf)==0){
				flag = 1;
				}
				
				}
				if(flag == 1)
					break;
				
				printf("<id>");
				for(i =0;i<ctr;i++)		
					printf("%c",buf[i]);	
			}
			break;
	
		case 11:
			buf[ctr] = ch;
			ctr++;
			ch = getc(fptr);
			if(!isdigit(ch)){
				state = 0;
				fseek(fptr,-1, SEEK_CUR);
				printf("<num>");
				for(i=0;i<ctr;i++)
					printf("%c",buf[i]);
			}	
			break;

		case 12:
			
			printf("<EQ>");
		        state = 0;
			break;	
		case 13:
			printf("\n");	
			state = 0;		
				
	    }
	



	}
	fclose(fptr);
	
	

}
