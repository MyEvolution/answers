#include <stdio.h>

int main(void)
{
	int i, j, p[102];
	int l, n, c, t;
	int vr, vr1, vr2;
	int len;
	double dp[102], min, e;
	
   while(scanf("%d",&l)!=EOF)
   {
   	scanf("%d %d %d",&n,&c,&t);
   	scanf("%d %d %d",&vr,&vr1,&vr2);
   	for(i=1;i<=n;i++)
   	scanf("%d",&p[i]);
   	p[n+1]=l;
   	dp[0]=p[0]=0;
   	
   	for(i=1;i<n+2;i++)
   	{
   		min=0xffffff;//一个很大的数
   	for(j=0;j<i;j++)//选择在j站充电，后面的不充点，这样从0遍历到最后，所有的最短时间的可能都会算进去 
   	{
   	  len=p[i]-p[j];
	  if(len>c)
	    e=(0.0+c)/vr1+(len+0.0-c)/vr2;	
	    else e=1.0*len/vr1;
	    e+=dp[j];
	    if(j) e+=t;//加上充电的时间 
	    if(min>e) min=e;
	   }
	   
	   dp[i]=min;//到达地i站的最短时间 
		   	
   		
	   }
	   if(dp[n+1]>(0.0+l)/vr)
	     printf("good job!rabbit!\n");
	     else printf("what a pity rabbit!\n");
   }
			}
