#include<stdio.h>
#include<ctype.h>
main()
{//toupper ±ä´óÐ´ 
	char t[100];
	int i;
	while(gets(t))
	{
		i=0;
		while(t[i]!='\0')
		{
		   while(isspace(t[i]))
		   putchar(t[i++]);
		   if(t[i]>='a'&&t[i]<='z')
		   {
		   	t[i]-='a'-'A';
		   putchar(t[i++]);
		   }
		   
		   while(isalpha(t[i]))
		       putchar(t[i++]);
		}
		putchar('\n');

	}
}
