#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>//没看清题  这个比他更高级  算一行数中奇数的乘积 
#define MAXSIZE 100

int getline(char *,int );
int product(char *s);
main()
{
	  char line[MAXSIZE];
	while(getline(line,MAXSIZE)>0)
	
		printf("%d\n",product(line));
	
}
int getline(char *l,int max)
{
	char *q=l;
	int c;
	while((c=getchar())!=EOF&&c!='\n'&&q-l<max)
		*q++=c;
		if(c=='\n')
		{
			*q++='\n';
			*q='\0';
		}
		
	return q-l;
}
int product(char *s)
{
	  char *q;
	  char num[100];
	  int n;
	  int sum=1;
	int i=0;
	while(*s!='\n')
  {
		if(*s==' '||*s=='\t')
	{
		 	s++;
	       continue;
	}

	   if(isdigit(*s)){
	   	for(q=num,*q++=*s++;isdigit(*s);*q++=*s++)   
	               ;
	               *q='\0';
		if((n=atoi(num))%2!=0)
		sum*=n;
	   }
  }

  return  sum;
	                   
}
