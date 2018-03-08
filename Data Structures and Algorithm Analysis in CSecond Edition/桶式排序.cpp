#include<stdio.h>
#include<stdlib.h>
void BucketSort(int *num,int n,int m)
{
	int i;
	int j=0;
	int *count=(int *)malloc(m*sizeof(int));
	for(i=0;i<m;i++)//M
	count[i]=0;
	for(i=0;i<n;i++)//N
	count[num[i]]++;
   for(i=0;i<m;i++)
     while(count[i]!=0)
     {
    printf(j==n-1?"%d\n":"%d ",i);
    count[i]--;
    j++;
	 }

}
main() 
{
	int n,m;
	int i;
	int num[1000]; 
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++)
		scanf("%d",&num[i]);
		BucketSort(num,n,m);
	}
}
