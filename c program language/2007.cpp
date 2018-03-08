#include<stdio.h>
#include<math.h>
main()
{
	 int x,y;
	 int sum1,sum2;
	 
	 int i;
	while(scanf("%d %d",&x,&y)==2)
	{
		getchar();
		 sum2=sum1=0;
		
		for(i=x;i<=y;i++)
		if(i&1)
		sum1+=pow(i,3);
		else sum2+=pow(i,2);
		
		printf("%d %d\n",sum2,sum1);
	}
}
