#include<stdio.h>
int way(int n)
{
	if(n<=2) return n;
	else 
	return way(n-1)+way(n-2);
}
main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	printf("%d\n",way(n));
}
