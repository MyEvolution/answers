#include<stdio.h>
#include<stdlib.h>
 struct int1{
	int n;
	int i;//下标 
}num1[1000];
int cmd(const void *p,const void *q)
{
	int1 *a=(int1 *)p;
	int1 *b=(int1 *)q;
   return a->n-b->n;
}
int pominsum(int *num,int n)//最小正子序列 
{
	int thissum;
	int min=0xffffff;
	int i;
	int sum;
  for(i=0;i<n;i++)
  {
  	sum+=num[i];
  	num1[i].n=sum;
  	num1[i].i=i;
	    }
	qsort(num1,n,sizeof(int),cmd);//快排的时间复杂度是O(NlogN） 
		for(i=0;i<n;i++)//比如1，0，0，0，0，0，0，排完序为1，1，1，1，1，1如果没有这一步，将会得不到1这个结果 
	if(num1[i].n>0&&num1[i].n<min)
	 min=num1[i].n;
	for(i=1;i<n;i++)
	if((thissum=num1[i].n-num1[i-1].n)>0&&num1[i].i>num1[i-1].i&&thissum<min)//确定是正确的子序列，如果小于的话，比如1和3；他们之间的自序里实际上是差的负数 
	min=thissum;
	return min;
} 
 int minsum(int *num,int n)//O(N^3) 
 {
 	int i,j,k;
 	int thissum;
 	int min=0xffffff;
 	for(i=0;i<n;i++)
     for(j=i;j<n;j++)
     {
     	thissum=0;
     	for(k=i;k<=j;k++)
     	  thissum+=num[k];
     	  if(thissum>0&&thissum<min)
     	  min=thissum;
	 }
	 return min;
	 
 }
int minper(int *num,int n)
{
	int i,j;
	int thissum=0;
	int min=0xffffff;
	for(i=0;i<n;i++)
	{
		thissum=0;
		for(j=i;j<n;j++){
		thissum+=num[j];
		if(thissum<min&&thissum>0)
		min=thissum;	
		}
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
 /*
 为何没有递归算法？
 递归算法分为两半，前部分和后一部分，以及中间相连的部分，
 假设前部分最小为负值，那么要求其正最小值并不容易 
 4 -2 5 -2 -2 2 6 -2
 比如这个数列 
 前半最小为2 
 后半最小为4 
 中间的如何求？ 
 如何保证两半加起来最小？
 最小的加上最小的一定是大于其中一个最小的（皆为正） 
 反倒没有必要，但无法保证中间的不是最小的 
 但是若有负值，则无法保证大于0. 
 一正一负没有统一的规划，造成很大的麻烦。*/ 
 /*
 为何原来的O(N)算法不适用？
 原来的O(N)算法，记录i前所以的和，
 如果 小于0，则归0，因为会对后续的序列产生减小的效果，对于求最大的子序列是不利的（且最小为0）
 而现在，如果大于0就归0，遇到负数无法填进sum，上述例子中 -2+5=3 如果归0，那么就从-2开始算 ，这样 -2+3就被错过，错过了正确答案
 因为这个大于0的不应该被忽略，虽然他不会对后续产生减小的影响，但是如果后续是负的，便需要其增加，已达到正值的后果 
 小于0归0，对后位产生减小但不至于小于0的序列被忽略 
 如果皆不归零，实际上是计算了包含第一个数的所有子序列，是不完整的
 */ 
