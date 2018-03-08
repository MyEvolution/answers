#include<stdio.h>
int main()
{
	unsigned long long n;
	int i;
	unsigned long long sum;
	unsigned long long num[100];
	    num[0]=1;
        num[1]=1;
	while(scanf("%llu",&n)!=EOF)
	{
		sum=0,i=0;
         while(sum<n)
         {
         	if(i>1)
         	num[i]=num[i-1]+num[i-2];
         	sum+=num[i];
         	i++;
		 }	    
		 	num[i-1]=n-sum+num[i-1];
		 	if(i>1){
		 			if(num[i-1]>num[i-2])
		 	printf("%llu %llu\n",i,num[i-1]);
		 	else printf("%lld %lld\n",i-1,num[i-2]);
			 }
			 else
                  printf("%llu %llu\n",i,num[i-1]);

	}
	return 0;
}
