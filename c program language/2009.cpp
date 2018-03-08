#include<stdio.h>
#include<math.h>
main()
{    
     int b,i;
     double a,sum;
	while(scanf("%lf %d",&a,&b)==2)
	{
		 sum=0.0;
	for(i=0;i<b;i++)
	{
		sum+=a;
		a=sqrt(a);
		}	
		printf("%.2f\n",sum);
	}
}
