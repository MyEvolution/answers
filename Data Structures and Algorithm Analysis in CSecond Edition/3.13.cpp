#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 100//���ѧ������ 
 struct B
{
      long long *a;//Ͱ�Ĵ�С  ����ѧ���ĸ������� 
      int num;//��¼Ͱ�����ֵĸ��� 
	
 }Bucket[1000];
void BuSort(struct B *,long long *,int n);
main()
{

	   long long number[N];
	   int n;//ѧ������ 
	   int m; //��ȫ�볤��
	   int i;

	   scanf("%d",&n);

	
	   getchar();
	   for(i=0;i<n;i++)
	   {
	   	scanf("%lld",&number[i]);
	   	getchar();
	   }
	   BuSort(Bucket,number,n);
	   printf("������������Ϊ��\n");
	   for(i=0;i<n;i++)
          printf("%lld\n",number[i]);
}
int bit(long long x)
{
	int i=0;

	while(x!=0)
	{
		i++;
		x/=10;
	}
	return i;
}
void BuSort(struct B*Bu,long long *nu,int n)
{
	
	int i;
	int j;
	int p;
	int o;
   	   for(i=0;i<1000;i++)
	     {
 	     Bucket[i].num=0;
   	     Bucket[i].a=(long long*)malloc(n*sizeof(int));
	    }
	    i=0;
	 
	while(i<bit(nu[0]))
	{
		j=0;
		
		while(j<n)//�Ȱ��պ���λ�����Ӧ��Ͱ�� 
		{
			p=(nu[j]/((int)pow(10,i)))%1000;
		 Bucket[p].a[Bucket[p].num++]=nu[j];
		 j++;
		}
		  o=n-1; 
		  
		for(j=999;j>=0;j--)//��Ͱ�е��������·Ż����� 
		{
			while(Bucket[j].num>0)
			nu[o--]=Bucket[j].a[--Bucket[j].num];
			
		 } 
		 i+=3; 
	}
	for(i=0;i<1000;i++)
	free(Bucket[i].a); 
}
