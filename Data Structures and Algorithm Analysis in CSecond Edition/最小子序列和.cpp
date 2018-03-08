#include<stdio.h>
int min3(int a,int b,int c)
{
	if(a<=b&&a<=c)
	  return a;
	  else if(b<=c)
	    return b;
	    else return c;
}
int minsper(int *per,int left,int right)
{
   int minleft,minright;
   int leftbod,rightbod;
   int i;
   int center=(left+right)/2;
   int thissum;
   if(left==right) return per[left];
   minleft=minsper(per,left,center);//T(N)=2*T(N/2)+N;      O(NlogN);
   minright=minsper(per,center+1,right);
   thissum=0,rightbod=0xffffff;
   for(i=center+1;i<=right;i++)
     {
     	thissum+=per[i];
     	if(thissum<rightbod)
     	  rightbod=thissum;
	 }
	thissum=0,leftbod=0xffffff;
	for(i=center;i>=left;i--)
	{
		thissum+=per[i];
		if(thissum<leftbod)
		  leftbod=thissum;
	}
   return min3(minleft,minright,leftbod+rightbod);
	  
}
int minsum(int *per,int n)
{
	return minsper(per,0,n-1);
}
int minper(int *per,int n)//O(N)

{
	int sum=0;
	int i;
	int min=0xffffff;
	for(i=0;i<n;i++)
	{
		sum+=per[i];
		if(sum<min) min=sum;
		if(sum>0)
		  sum=0;
	}
	return min;
	
 } 
main()
{
	int n;
	int num[1000];
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&num[i]);
	printf("%d\n",minper(num,n));
	
 } 
