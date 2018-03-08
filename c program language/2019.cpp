#include<stdio.h>
main()
{
	int n,m;
	int i,x;
	int j;
	while(scanf("%d %d",&n,&m)==2)
	
	{
		for(i=0;i<n;i++)
		{
		scanf("%d",&x);
		if(x<m)
		printf("%d ",x);
		else 
		{
			printf("%d %d ",m,x);
			break;
		}
	}
		for(j=i+1;j<n;j++)
		{
			scanf("%d",&x);
		printf(j==(n-1)?"%d":"%d ",x);
		}
		
		if(i==n) printf("%d",m);
		putchar('\n');
			
		}
	
		
	
}
