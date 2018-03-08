#include<stdio.h>
#include<stdlib.h>
int MinAvlNodes(int H)
{
	int *a;
	int i;
	a=(int *)malloc(H*sizeof(int));
	a[0]=1;a[1]=2;
	for(i=2;i<H;i++)
	a[i]=a[i-1]+a[i-2]+1;
	return a[H-1];
 } 
 int main()
 {
 	int n;
 	scanf("%d",&n);
 	printf("%d",MinAvlNodes(n));
 }
