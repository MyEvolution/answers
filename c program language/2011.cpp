#include<stdio.h>
#include<math.h>
double ha(double );
main()
{
	int n;
	int i,t;
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		getchar();
		printf("%.2f\n",ha((double)t));
	}
	
	
}
double ha(double t)
{
	if(t==1)
	return 1.0;
	else return pow(-1,t-1)/t+ha(t-1);
}
