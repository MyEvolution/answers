/*
现在我们利用堆来解决第一章中遇到的一个排序的问题：
 找到N个数中第K个最大值：
 第一章中的算法有两个 1是冒泡排序 找到第K个； 
2是对前K个值排序  然后依次添加后面的（N-K)个值；
两个算法都不是很快  第二个虽优于第一个但是当k=N/2时依然有O(N^2)的时间复杂度
利用堆我们可以把时间复杂度下降至O(NlogN);
同时引出一种新的排序算法——堆排序 
*/ 

#include<stdio.h>
#include<stdlib.h>

void BuildHeap(int *Array,int n);//把数组构建成堆 
void DownFilter(int *Array,int i,int n);//下滤 
int DeleteMax(int *Array,int n);//删除堆顶 
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
	printf("the Kth number is:%d\n",Array[1]);//这个求得是第k个最小值 

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
