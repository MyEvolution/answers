#include<stdio.h>
int _MIN(int *a,int n);
int _MAX(int *a,int n);
main()
{
	int a[10];
	int i;
	int sum=0;
	for(i=0;i<10;i++)
	scanf("%d",&a[i]);
	for(i=0;i<10;i++)
	if(i!=_MAX(a,10)&&i!=_MIN(a,10))
	sum+=a[i];
	printf("%d",sum/8);
}
int _MAX(int *a,int n)
{  int i,j; 
	for(i=0;i<n;i++)
	 {
	 for(j=0;j<n;j++)
	  if(a[i]<a[j])
	   break;
       if(j==n) 
	   return i;    }
}
int _MIN(int *a,int n)
{    int i,j;
		for(i=n-1;i>=0;i--)
	 {
	 for(j=0;j<n;j++)
	  if(a[i]>a[j])
	   break;
       if(j==n) 
	   return i;    }
}
