#include<stdio.h>
#include<string.h>
#include<ctype.h>
void isor(char *);
main()
{
	char a[50];
	while(scanf("%s",a)!=EOF)
	
	     isor(a);
	
 } 
 void isor(char *s)
 {
 	int i;
 	while(isspace(s[i]))
 	         i++;
 	if(isalpha(s[i++]))
 	{
 		 	for(i;i<strlen(s);i++)
 	if(!isalnum(s[i])&&s[i]!='_')
 	{
 		printf("no\n");
 		return;
	 }
	 if(i=strlen(s))
	 printf("yes\n");
	 return;
	 }
	 printf("no\n");

 	
 }
