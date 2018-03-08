#include<stdio.h>
#include<stdlib.h>//生成随机数
#include<time.h> 
#define MAXSIZE 1000 
//霍纳法则 
//计算多项式求和  如A0*x^0+A1*x^1+A2*x^2+....+An*x^n;
//直接计算需要的步骤    0+1+2+3+4+n O(n^2)
//霍纳法则       ((（(0*x+An)*x+A(n-1))*x+A(n-2)) ......+A1) *x+A0    需要计算2n次 O(n)
void swap(int *i,int *j)
{
	int temp;
	temp=*i;
	*i=*j;
	*j=temp;
}
int RandInt(int i,int j)//生成从i到j的随机数 
{
	int num;
	srand(unsigned(time(NULL)));
	num=rand()%(j-i+1);
	return num+i;
	
} 
main()
{
	int num[MAXSIZE];
    int n;
    int i;
    int x;
    int Poly=0;
    scanf("%d %d",&n,&x);
    for(i=0;i<n;i++)
      num[i]=i+1;
    for(i=1;i<n;i++)
    swap(&num[i],&num[RandInt(0,i)]);
    for(i=0;i<n;i++)
    printf(i==n-1?"%d\n":"%d ",num[i]);
  for(i=n-1;i>=0;i--)
  	Poly=Poly*x+num[i];
  printf("%d\n",Poly);
}
