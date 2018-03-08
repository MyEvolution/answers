#include<stdio.h>
int all_y(int );
main()
{
	int m;
	int x,y;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d %d",&x,&y);
	if(all_y(x)==y&&x==all_y(y))
	printf("YES\n");
		else printf("NO\n");
	}
}
int all_y(int n)
{
	int sum=0;
	int i;
	for(i=1;i<(n/2+1);i++)
	if(n%i==0)
	sum+=i;
	return sum;
	
}
