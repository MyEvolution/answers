#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 10//桶的个数 
 typedef struct 
  {
  	int *buck;
  	int i;
  }Bucket;
  Bucket B[N];
int max(int *num,int n)
{
  int maxw=0;
  int w=0;
  int i;
  for(i=0;i<n;i++)
   if(num[i]>maxw)
      maxw=num[i];
    while(maxw!=0)
      {
      	maxw/=10;
      	w++;
	  }
	return w;
	  
}
void rsort(int *num,int n)//基数排序 
{
   int ma=max(num,n);
   int i;
   int j;
   int m=0;
   int b;
  for(i=0;i<N;i++)
  {
  	B[i].buck=(int *)malloc(n*sizeof(int));
  	B[i].i=0;
  }
  
	
	while(ma!=0)
	{
		
	   for(i=0;i<n;i++)
   	B[b=((num[i]/((int)pow(10,m)))%N)].buck[B[b].i++]=num[i];
   	     j=n-1;
	   for(i=N-1;i>=0;i--)	
	   {
	   	     
	   	 while(B[i].i!=0)
	num[j--]=B[i].buck[--B[i].i];
	   }
	   m++;
	   ma--;
	    
	}
	for(i=0;i<N;i++)
	free(B[i].buck);
}
main()
{
	int n,i;
	int num[1000];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	  scanf("%d",&num[i]);
	  rsort(num,n);
	  for(i=0;i<n;i++)
	  printf("%d ",num[i]);
}
