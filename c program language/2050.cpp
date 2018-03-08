#include<stdio.h>
int face(int n)
{
	if(n==0)
	return 1;
	else return face(n-1)+4*n-2;
}
int main()
{
	int i,n;
	int x;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		printf("%d\n",face(x)-x);
	}
 } 
