#include<stdio.h>
main()
{
	int n,m;
	int i,j;//––∫≈¡–∫≈ 
	int a,b,max=0;
     int x;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	  for(j=1;j<=m;j++)
	    {
	    	scanf("%d",&x);
	    	
	    	if((x<0?-x:x)>(max<0?-max:max))
	    	{
	    		max=x;
	    		a=i,b=j;
			}
	    
		}
		printf("%d %d %d\n",a,b,max);
}
