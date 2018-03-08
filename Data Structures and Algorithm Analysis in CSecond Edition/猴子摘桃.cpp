#include<stdio.h>
int main()
{
	unsigned long long n;
	unsigned long long sum;
	int i;
	unsigned long long num1,num2,num3;
	while(scanf("%llu",&n)!=EOF)
	{
       if(n==1||n==2||n==3)
       printf("%d %d\n",1,1);
       else
       {
       	i=2;
       	sum=2;
		num1=1,num2=1;
       	while(sum<n)
       	{
       		num3=num1+num2;
            sum+=num3;
            num1=num2;
            num2=num3;
            i++;
		   }
           num3=n-sum+num3;
           if(num3>num1)
           printf("%llu %llu\n",i,num3);
           else printf("%llu %llu\n",i-1,num1);
	   }
	}
	return 0;
}
