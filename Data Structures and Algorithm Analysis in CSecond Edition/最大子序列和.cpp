#include<stdio.h>
/*int MaxSubsequenceSum(const int *a,int n)//求序列中最大子序列和 
{                                     //算法1 
	int thissum,maxsum,i,j,k;
	maxsum=0;
	for(i=0;i<n;i++)
		  for(j=i;j<n;j++)
			{
				thissum=0;
				for(k=i;k<=j;k++)
				    thissum+=a[k];
				if(maxsum<thissum)
				  maxsum=thissum;    
			}
		
	return maxsum;
}*/
/*int MaxSum(const int *a,int n)
{
	int thissum,maxsum,i,j;
	maxsum=0;
	for(i=0;i<n;i++)
	{
		thissum=0;
		for(j=i;j<n;j++)
		{
			 thissum+=a[j];
				if(maxsum<thissum)
				  maxsum=thissum; 
			
		}
	    
	     
	}

	 return maxsum;    
}*/
/*int max3(int a,int b,int c)
{
	if(a>=b&&a>=c)
	  return a;
	  else if(b>=c)
	    return b;
	    else return c;
 } 
int MaxSum(const int *a,int left,int right)
{
	int leftmaxsum,rightmaxsum;
	int lthissum,rthissum;
	int center;
	int n,m;
	int i;
	if(left==right)
  return a[left]>0?a[left]:0;//left
	center=(left+right)/2;
	leftmaxsum=MaxSum(a,left,center);
	rightmaxsum=MaxSum(a,center+1,right);
	  rthissum=n=0;
	  lthissum=m=0;
	for(i=center+1;i<=right;i++)
	{
		n+=a[i];
		
		if(rthissum<n)
		  rthissum=n;

	}
	
	for(i=center;i>=left;i--)
	{
		m+=a[i];
		if(lthissum<m)
		   lthissum=m;
	}
	   
	return max3(rightmaxsum,leftmaxsum,lthissum+rthissum);
  
 } 
 int maxsum(const int *a,int n)
 {
 	return MaxSum(a,0,n-1);
 }*/
int maxsum(const int *a,int n)
{
int thissum,Maxsum,i;
thissum=0;
Maxsum=0;
for(i=0;i<n;i++)
{
	   thissum+=a[i];
   if(thissum>Maxsum) 
     Maxsum=thissum;
     else if(thissum<0)
        thissum=0;
}
return Maxsum;
}
main()
{
	int a[10];
	int i;
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	printf("%d\n",maxsum(a,10));
}
