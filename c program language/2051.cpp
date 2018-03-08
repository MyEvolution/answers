#include<stdio.h>
#include<stdlib.h>
void reverse(char *p)
{
	char *q=p;
	char temp;
	while(*(q+1)!='\0')
	q++;
	while(q>=p)
	{
		temp=*q;
		*q=*p;
		*p=temp;
		q--,p++;
	}
}
int tob2(int n)
{
	char a[100];
	char *q=a;
	int num=(n>=0?n:-n);
	while(num!=0)
	{
	*q++=(num%2+'0');
	num/=2;
	}
	if(n<0) *q++='-';
	*q='\0';
	reverse(a);
	
	return atoi(a);
}
main()
{
	int n;//on base ten 10½øÖÆ 
	int num;
	while(scanf("%d",&n)!=EOF)
	printf("%d\n",tob2(n));
	return 0;
}
