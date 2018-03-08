#include<stdio.h>
int three(int n,int m)
{//原理：要保证后3位一样，那么两个数字的后三位要求一致 
	if(m==1)
	return n%1000;
	else if(m==0)
	return 1;
	else 
	return ((n%1000)*three(n,m-1))%1000;
	
}
main()
{
	int n,m;
	while(scanf("%d %d",&n,&m),n+m)
		printf("%d\n",three(n,m));
	
 } 
