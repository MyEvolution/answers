#include<stdio.h>
main()
{
	int sum;
	int n,m;
	int i,j;
	while(scanf("%d%d",&n,&m),n+m)
         for(i=1;i<n;i++)
		{	
		sum=0;	
		j=i;
		while(sum<m)
			sum+=j++;
			if(sum==m)
			printf("[%d,%d]\n",i,j-1);
		}

		
		
	
}
