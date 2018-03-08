#include<stdio.h>
#include<time.h>
#include<stdlib.h>//exit()和return的区别： 
/*int returnexit(int);//1.递归过程中，return只返回到上一级，而exit结束程序 
main()             //2.除了主函数外的其他函数运行到exit也会结束程序 
{
	int i;
	scanf("%d",&i);
	returnexit(i);
	printf("%d",100);
}
int returnexit(int i)
{
	if(i>4)
	returnexit(i-1);
	printf("%d\n",i);
	return 1;
}*/
#define frand() ((double)rand()/(RAND_MAX+1))//生成0-1之间的随机小数 
main()
{   
srand(time(NULL));//srand生成一个种子， 不返回任何值 
	int i;
	for(i=0;i<10;i++)
	printf("%f ",frand());
	
}
