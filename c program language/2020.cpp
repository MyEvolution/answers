#include<stdio.h>
void sort(int *,int);
main()
{
	int n;
	int num[100];
	int i;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
		break;
		for(i=0;i<n;i++)
		scanf("%d",num+i);
		sort(num,n);
		for(i=0;i<n;i++)
		printf(i==(n-1)?"%d\n":"%d ",num[i]);
		
	}
	
}
void sort(int *num,int n)
{
	int temp;
	int i,j;
	for(i=0;i<n;i++)
	for(j=i;j<n;j++)
	if((num[i]<0?-num[i]:num[i])<(num[j]<0?-num[j]:num[j]))
	{
		temp=num[i];
		num[i]=num[j];
		num[j]=temp;
	}
	
}
