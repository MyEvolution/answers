/*
�����������ö��������һ����������һ����������⣺
 �ҵ�N�����е�K�����ֵ��
 ��һ���е��㷨������ 1��ð������ �ҵ���K���� 
2�Ƕ�ǰK��ֵ����  Ȼ��������Ӻ���ģ�N-K)��ֵ��
�����㷨�����Ǻܿ�  �ڶ��������ڵ�һ�����ǵ�k=N/2ʱ��Ȼ��O(N^2)��ʱ�临�Ӷ�
���ö����ǿ��԰�ʱ�临�Ӷ��½���O(NlogN);
ͬʱ����һ���µ������㷨���������� 
*/ 

#include<stdio.h>
#include<stdlib.h>

void BuildHeap(int *Array,int n);//�����鹹���ɶ� 
void DownFilter(int *Array,int i,int n);//���� 
int DeleteMax(int *Array,int n);//ɾ���Ѷ� 
void Insert(int *Array,int n,int Element);
int main()
{
	int Array[100];
	int Order[100];
	int Element;
	printf("this program is built to find the Kth maximum in N numbers.\n");
	printf("Please scanf the N and K\n");
	int n,k;
	int i,num; 
	scanf("%d %d",&n,&k);
	printf("Please scanf the  N numbers(Press Enter to end)\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&Element);
		Array[i]=Element;
	}
	/*
	BuildHeap(Array,n);
	for(i=1;i<=n;i++)
	Order[i]=DeleteMax(Array,n-i+1);	
	printf("the Kth number is:%d\n",Order[k]);
	printf("the Array in order is:\n");
	for(i=1;i<=n;i++)
	printf("%d\n",Order[i]);
	*/
	BuildHeap(Array,k);
	for(i=k+1;i<=n;i++)
	Insert(Array,k,Array[i]);
	printf("the Kth number is:%d\n",Array[1]);//�������ǵ�k����Сֵ 

	return 0;	
}
void BuildHeap(int *Array,int n)
{
	int i;
	for(i=n/2;i>=1;i--)
	DownFilter(Array,i,n); 
}
void DownFilter(int *Array,int i,int n)
{
	int Position;
	Position = i;
	int Temp;
	while(Position *2<=n)
	{
		if((Position = Position *2)!=n&&Array[Position+1]>Array[Position])
		 Position ++ ;
		 if(Array[i]<Array[Position])
		 {
		 	Temp=Array[i];
		 	Array[i]=Array[Position];
		 	Array[Position]=Temp;
		 	i=Position;
		 }
		 else
		 break;
	}
}
int DeleteMax(int *Array,int n)
{
	int i,Position;
   int max=Array[1];
   int Wait=Array[n];
   if(n>1)
   {
   	Position=1;
   	while((i=Position)&&Position*2<=n)
   	{
   		if((Position=Position*2)!=n&&Array[Position]<Array[Position+1])
   		      Position++;
   		      if(Wait>Array[Position])
   		      break;
   		      else
   		      Array[i]=Array[Position];
	   }
	   Array[i]=Wait;
   }
	return max;
}
void Insert(int *Array,int n,int num)
{
	int Wait;
	int Position,last;
	if(num>Array[1])
	return;
	else
	  {
	  	Wait=num;
	  	Position=1;
	  	while((last=Position)&&Position*2<=n)
	  	{
	  		if((Position=Position*2)!=n&&Array[Position+1]>Array[Position])
	  		Position++;
	  		if(Wait>Array[last])
	  		break;
	  		else
	  		Array[last]=Array[Position];
		  }
		  Array[last]=Wait;
	  }
}
