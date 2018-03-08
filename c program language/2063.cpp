#include<stdio.h>
int min(int n)
{
	if(n==1)
	return 2;
	else return 3*min(n-1)+2;
}
main()
{
	int n;
	while(scanf("%d",&n))
	printf("%d\n",min(n));
}
