#include<stdio.h>
int way(int n)
{
	if(n==2||n==3)
	return n-1;
	else return way(n-1)+way(n-2);
}
main()
{
	int n,m;
	int i;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&m);
		printf(i==n-1?"%d":"%d\n",way(m));
	}
}
