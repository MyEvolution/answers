#include<stdio.h>
int num(int n)
{
if(n==1)
 return 3;
 else if(n==2)///排成一排的n块方格，第一块和最后一块颜色不同，所以若n个前的不动，最后一个只有一种选项 
 return 6;//而前n-1不动的话，除了原来有的还可以填和1同色的  这时候有两种选择 
 else if(n==3)//所以这样算。而当n=2时候，没有第二种选择 
 return 6;
 else return num(n-1)+2*num(n-2);

	
}
main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",num(n));
	}
}
