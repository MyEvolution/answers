#include<stdio.h>
main()
{
	int time[6];
	int t[3]={0,0,0};
	int n,i,j;
	scanf("%d",&n);
	for(j=0;j<n;j++)
	{
		t[0]=t[1]=t[2]=0;
		for(i=0;i<6;i++)
		scanf("%d",&time[i]);
		for(i=2;i>=0;i--)
		{
	   t[i]+=(i==0?time[i]+time[i+3]:(time[i]+time[i+3])%60);
		if(i>0) 
		t[i-1]+=(time[i]+time[i+3])/60;	
		}

		printf("%d %d %d\n",t[0],t[1],t[2]);
			}
 } 
