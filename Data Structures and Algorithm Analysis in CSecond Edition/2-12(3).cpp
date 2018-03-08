#include<stdio.h>
#include<stdlib.h>
long long maxche(int *num,int n) //O(N^2)
{
  
  int i,j;
  long long max=-0xffffff;	//一个很小的数 
  long long thisc=1;
  for(i=0;i<n;i++)
   {
   	  thisc=1;
   	for(j=i;j<n;j++)
   	{
   		thisc*=num[j];
   		if(thisc>max)
   		max=thisc;
	   }
   } 
   return max; 
}
int max3(int a,int b,int c)
{
	return (a>=b&&a>=c)?a:(b>=c?b:c);
}
int min3(int a,int b,int c)
{
	return (a<=b&&a<=c)?a:(b<=c?b:c);
}
long long maxc(int *num,int n)//若全为整数，则较好判断一点，因为除了0，绝对值不会变小 
{
	long long ma=-1;//如果都小于0，返回-1
	int i;                            //O(N)
  long long *max=(long long *)malloc(n*sizeof(long long));
  long long *min=(long long *)malloc(n*sizeof(long long));//4 -3 5 -2 0 -1 2 6 -2
  max[0]=num[0];//表示以a[i]结尾的最大子序列积 
  min[0]=num[0];//表示以a[i]结尾的最小子序列积 
  for(i=1;i<n;i++)
  {
  	max[i]=max3(num[i],max[i-1]*num[i],min[i-1]*num[i]);
  	min[i]=min3(num[i],max[i-1]*num[i],min[i-1]*num[i]);
  	if(max[i]>ma)
  	ma=max[i];
	   
  	
  }
  free(max);
  free(min);
return ma;
}
main()
{
	int num[1000];
	int n;
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&num[i]);
	printf("%lld\n",maxche(num,n));
 } 
