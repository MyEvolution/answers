#include<stdio.h>
void reverse(char *num);
main()
{
	int n;
     int i=0;
	scanf("%d",&n);
	getchar();
	char num[100];
	int p;
	scanf("%d",&p);
	while(p!=0)
	{
		num[i++]=(p%n+'0');
		p/=n;
	}
	num[i]='\0';
	reverse(num);
	printf("%s",num);
}
void reverse(char *num)
{   char temp;
	char *q=num;
	while(*q!='\0')
	q++;

	for(q--;num<=q;num++,q--)
	{
		temp=*q;
		*q=*num;
		*num=temp;
		
	}
}
