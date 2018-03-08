#include<stdio.h>
int way1(int );
int way2(int );
main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
		printf("%d\n",way2(n));
	
}
int way1(int n)//n=1，为3种 ，其中末尾为o有1， 
{             //n=2，本来有9种，但是当第一是o是，要少一种，8种 其中末尾为o有2， 所以，结尾是o的个数就等于上次所有的方法减去上次结尾是o的方法
            //同时，这次的排法又是上次的排法的3倍同时减去上次结尾为o的排法,所以互相调用递归即可求出 
	 if(n==1) return 1;//n=3  8*3-2 22  
	 else return way2(n-1)-way1(n-1);
	
}
int way2(int n)
{
	if(n==1) return 3;
	else return way2(n-1)*3-way1(n-1);
}

	
