#include<stdio.h>
#include<string.h>
#define MAXSIZE 1000
char num[MAXSIZE];
char *byt(int ,int );
void reverse(char *);
main()
{
	int m,n;
	char *p;
	while(scanf("%d %d",&m,&n)==2)
	{
		p=byt(m,n);
		printf("%s\n",p);
	}
 } 
char *byt(int a,int b)
 {
 	int n=a;
 	int i=0;
 	if(n<0)
 	n=-n;

	 	while(n!=0)
	 	{
	 		num[i++]=(n%b>=10)?('a'+n%b-10):('0'+n%b);
	 		n/=b;
	 		
		 }
	 
	 if(a<0)
	 num[i++]='-';
	 num[i]='\0';
	 reverse(num);
	 return &num[0];
	 
 	
  }
  void reverse(char *n)
  {
  	char *q=n;
  
  	char temp;
  	while(*(q+1)!='\0')
  	   q++;
  	   
  	   while(q>n)
  	   {
  	   	temp=*q;
  	   	*q=*n;
  	   	*n=temp;
  	   	q--,n++;
		 }
  }
