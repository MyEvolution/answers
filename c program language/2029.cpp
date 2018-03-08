#include<stdio.h>
#include<string.h>
void huiwen(char *);
main()
{
	char t[100];
	int n;
	int i=0;
	scanf("%d",&n);
	getchar();
	while(i<n)
	{
		gets(t);
	  huiwen(t);
	  i++;
	}
}
void huiwen(char *s)
{
	char *q;
	q=s+strlen(s)-1;
	while(q>=s&&*q--==*s++)
	        ;
	        if(q<s)
	        printf("yes\n");
	        else printf("no\n");
	
}
