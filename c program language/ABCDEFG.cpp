#include<stdio.h>
#include<ctype.h>
void lower(char *);
void higher(char *);
main(int argc,char *argv[]){
	char s[100];
	scanf("%s",&s);
	if(argv[0][0]=='A'){
		lower(s);
		printf("%s",s);
	}
	else if(argv[0][0]=='a')
	{
		higher(s);
		printf("%s",s);
		
	}
	else printf("unknown instruction\n");
	
} 
void lower(char *s)
{   
  
	while(*s!='\0'){
	*s=tolower(*s);
	s++;	
	}
	
}
void higher(char *s)
{      
   
	while(*s!='\0')
	{
		if(*s>='a'&&*s<='z')
		*s+='a'-'A';
		s++;
	}
}
