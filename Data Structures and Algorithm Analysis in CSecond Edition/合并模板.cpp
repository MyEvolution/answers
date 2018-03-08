#include<stdio.h>
#include<stdlib.h>

unsigned int Array[1000];
int cmd(const void *a,const void *b)
{
	return (unsigned int *)a-(unsigned int *)b;
}
int main()
{
	int n,k;
	int i,j;
	unsigned long long sum,spa,tmd;
	while(scanf("%d %d",&n,&k)!=EOF)
	{
		sum=tmd=0;
		for(i=0;i<n;i++)
		scanf("%d",&Array[i]);
		if(n<=1)
	       ;
		else 
		if(k>=n)
		{
			for(i=0;i<n;i++)
			sum+=Array[i];
		}
		else
		{
			qsort(Array,n,sizeof(int),cmd);
			i=0;
			while(i<n)
			{
				spa=0;
			for(j=0;j<k&&i<n;j++)
			{
				if(tmd>0&&tmd<=Array[i])//1 2 3 4 5 6 7
			       spa+=tmd;        //4 5 6 7 6     6
			     else    	
				  spa+=Array[i++];   //6 7 15     6 + 15
      		 } 
			    tmd=spa;             //28 + 6 + 15=  49
				sum+=spa;
			}
	
		}
		
		printf("%d\n",sum);
		
	}
	return 0;
}
