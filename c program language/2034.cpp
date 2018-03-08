#include<stdio.h>
main()
{
	int n,m;
	int n1[100];
	int m1[100];
	int i,j;
	int p;
	int o[100];
	while(scanf("%d %d",&n,&m)&&(n!=0||m!=0))
	{
		p=0;
		for(i=0;i<n;i++)
		scanf("%d",&n1[i]);
		for(i=0;i<m;i++)
		scanf("%d",&m1[i]);
		for(i=0;i<n;i++)
		{
		for(j=0;j<m;j++)
		if(n1[i]==m1[j])
			break;
		if(j==m)
		o[p++]=n1[i];
		}
		if(p==0)
		printf("NULL\n");
		else
		for(i=0;i<p;i++)
		printf(i==p-1?"%d\n":"%d ",o[i]);	
	}
}
