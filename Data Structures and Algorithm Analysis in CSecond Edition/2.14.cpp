#include<stdio.h>//求小于n的所有质数
#include<stdlib.h>

void printprime(int n)
{
	int i,j; 
	int *a=(int *)malloc((n-1)*sizeof(int));
for(i=0;i<n-1;i++)
a[i]=i+2;
for(i=0;a[i]*a[i]<=n;i++)//当i>根号n时，是没有必要的 ,与他相乘的数一定会变小，这样与前面重复。 
{                         //
	if(a[i]==0)
	continue;
	j=2;
	while(a[i]*j<=n)//?
	{
		a[a[i]*j-2]=0;//因为这中的数都是下标减去2 
		j++;
	 }
    }
    for(i=0;i<n-1;i++)
    if(a[i]!=0)
    printf(i==0?"%d":" %d",a[i]);
    putchar('\n');
    free(a);
}
main()
{
	int n;
	scanf("%d",&n);
	printprime(n);
 } 
