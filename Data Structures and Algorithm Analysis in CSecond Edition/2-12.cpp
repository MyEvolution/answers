#include<stdio.h>
#include<stdlib.h>
 struct int1{
	int n;
	int i;//�±� 
}num1[1000];
int cmd(const void *p,const void *q)
{
	int1 *a=(int1 *)p;
	int1 *b=(int1 *)q;
   return a->n-b->n;
}
int pominsum(int *num,int n)//��С�������� 
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
	qsort(num1,n,sizeof(int),cmd);//���ŵ�ʱ�临�Ӷ���O(NlogN�� 
		for(i=0;i<n;i++)//����1��0��0��0��0��0��0��������Ϊ1��1��1��1��1��1���û����һ��������ò���1������ 
	if(num1[i].n>0&&num1[i].n<min)
	 min=num1[i].n;
	for(i=1;i<n;i++)
	if((thissum=num1[i].n-num1[i-1].n)>0&&num1[i].i>num1[i-1].i&&thissum<min)//ȷ������ȷ�������У����С�ڵĻ�������1��3������֮���������ʵ�����ǲ�ĸ��� 
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
 Ϊ��û�еݹ��㷨��
 �ݹ��㷨��Ϊ���룬ǰ���ֺͺ�һ���֣��Լ��м������Ĳ��֣�
 ����ǰ������СΪ��ֵ����ôҪ��������Сֵ�������� 
 4 -2 5 -2 -2 2 6 -2
 ����������� 
 ǰ����СΪ2 
 �����СΪ4 
 �м������� 
 ��α�֤�����������С��
 ��С�ļ�����С��һ���Ǵ�������һ����С�ģ���Ϊ���� 
 ����û�б�Ҫ�����޷���֤�м�Ĳ�����С�� 
 �������и�ֵ�����޷���֤����0. 
 һ��һ��û��ͳһ�Ĺ滮����ɺܴ���鷳��*/ 
 /*
 Ϊ��ԭ����O(N)�㷨�����ã�
 ԭ����O(N)�㷨����¼iǰ���Եĺͣ�
 ��� С��0�����0����Ϊ��Ժ��������в�����С��Ч���������������������ǲ����ģ�����СΪ0��
 �����ڣ��������0�͹�0�����������޷����sum������������ -2+5=3 �����0����ô�ʹ�-2��ʼ�� ������ -2+3�ͱ�������������ȷ��
 ��Ϊ�������0�Ĳ�Ӧ�ñ����ԣ���Ȼ������Ժ���������С��Ӱ�죬������������Ǹ��ģ�����Ҫ�����ӣ��Ѵﵽ��ֵ�ĺ�� 
 С��0��0���Ժ�λ������С��������С��0�����б����� 
 ����Բ����㣬ʵ�����Ǽ����˰�����һ���������������У��ǲ�������
 */ 
