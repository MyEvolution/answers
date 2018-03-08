#include<stdio.h>
#include<math.h>
#define OK 1
#define SORRY 0
int prime(int );
main()
{
	int i,x,y;
	while(scanf("%d %d",&x,&y)==2)
	{
		if(x==0&&y==0)
		break;
		for(i=x;i<=y;i++)
		if(!prime(i*i+i+41))
		break;
		if(i<=y)
		printf("Sorry\n");
		else printf("OK\n");
	}
}
int prime(int n)
{
	int i;
	for(i=2;i<n;i++)
	if(n%i==0)
	break;
	if(i==n)
	return 1;
	else return 0;
}
