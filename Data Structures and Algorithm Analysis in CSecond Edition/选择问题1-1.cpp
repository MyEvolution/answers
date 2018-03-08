#include<stdio.h>
main()
{
	int n;
	int k;
	int a[1000];
	int i,j;
	int p,temp,x;
	/*while(scanf("%d %d",&n,&k),k<=n&&k)
	{
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		for(i=0;i<n;i++)
		for(j=i;j<n;j++)
			if(a[i]<a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
			printf("%d\n",a[k-1]);
		
	}
}
	*/while(scanf("%d %d",&n,&k),k<=n&&k)
	{
		for(i=0;i<k;i++)
		scanf("%d",&a[i]);
			for(i=0;i<k;i++)
		for(j=i;j<k;j++)
			if(a[i]<a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		for(p=k;p<n;p++)	
		{
		scanf("%d",&x);
		for(i=0;i<k;i++)
		if(a[i]<x)
		{
			for(j=k-1;j>i;j--)
			  a[j]=a[j-1];
			  a[i]=x;
			  break;
		}
			
		}
         printf("%d\n",a[k-1]);
	}
}
