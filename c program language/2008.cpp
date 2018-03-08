#include<stdio.h>
main()
{
	int n,i,o1,o2,o3;
	double t;
	
	while(scanf("%d",&n)!=EOF)
	{
		
		getchar();
		if(n==0) break;
		o1=o2=o3=0;
	for(i=0;i<n;i++)
	{
			scanf("%lf",&t);//double一定要用lf来输入 否则可能输入错误 
			
	if(t>0) o1++;
	else if(t<0) o2++;
	else o3++;
	}

	printf("%d %d %d\n",o2,o3,o1);
	}
}
