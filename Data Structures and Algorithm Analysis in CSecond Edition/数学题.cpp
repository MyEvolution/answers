#include<stdio.h>

struct Node
{
   unsigned long long num;
   unsigned long long Element;
};
typedef struct Node Array;
int main()
{
	
	unsigned long long l,r;
	unsigned long long i,j;
	unsigned long long sum;
    Array Array[4];

	while(scanf("%llu %llu",&l,&r)!=EOF)
	{
             sum=0;
		    for(i=0;i<=3;i++)
    {
    	Array[i].Element=1;
    	Array[i].num=i;
	}
		if(l>=3)
		   ; 
		else 
		{
			for(i=l;i<3;i++)
			sum+=Array[i].Element;
		}
		for(i=3;i<=r;i++)
		{
          
			}
		}
            printf("%llu\n",sum);
	}
	return 0;
}
