#include<stdio.h>
int howmany(int );
main()
{
	int n,m,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		printf(i==n?"%d":"%d\n",howmany(m));
	}
	
}
int howmany(int n)
{
	if(n==0) return 3;
	else return 2*(howmany(n-1)-1);
}
