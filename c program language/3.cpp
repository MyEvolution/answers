#include<stdio.h>
main()
{
	long long p;
	scanf("%lld",&p);
	int i=0;
	while(p!=0)
	{
		i++;
		p/=10;
	}
	printf("%d",i);
}
