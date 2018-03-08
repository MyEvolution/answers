#include<stdio.h>
main()
{
	int n;
	int i,j;
	int x;
	while(scanf("%d",&n)&&n!=0)
	{
		getchar();
		i=0;
		for(j=0;j<n;j++)
		{
			scanf("%d",&x);
			getchar();
		 	i+=x/100;
		 	x=x%100;
		 	i+=x/50;
			 x=x%50;
			 i+=x/10;
			 x=x%10;
			 i+=x/5;
			 x=x%5;
			 i+=x/2;
			 x=x%2;
			 i+=x; 	
		 
		}
		printf("%d\n",i);
	}
 } 
