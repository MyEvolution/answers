#include"模拟排队.h"
/*
这个算法主要用于模拟银行排队现象，用于统计得出店员和人数之间的规律
数字越大效果越好 
*/ 
int IsFree(int *assistant,int n);
int main()
{

	int k,n;
	int i;
	int num;
	int now;
	Client *C;
	Heap H1,H2;
	int theStart,theEnd;
	theTime *T;
	theTime NextHappen;
	theTime *IsHappening;
	int *assistant;
	printf("请输入顾客数目和接线员的数目：\n");
	scanf("%d %d",&n,&k);
	C=(Client *)malloc(n*sizeof(*C)); 
	assistant=(int *)malloc(sizeof(int)*k);
	T=(theTime *)malloc(sizeof(theTime)*n);
	printf("计算机模拟各个顾客随机到达时间和处理时长如下：\n");
/*	RandCustomer(n,C);*/
for(i=0;i<n;i++)
scanf("%d %d",&C[i].come_time,&C[i].stay_time);
	for(i=0;i<n;i++)
	printf("顾客%3d:到达时间：%3d 处理时长： %3d\n",i,C[i].come_time,C[i].stay_time);
	for(i=0;i<k;i++)
	assistant[i]=0;//0表示空闲 
	H1=InitailizeHeap(10000);
	H2=InitailizeHeap(10000);
	for(i=1;i<=n;i++)
	T[i].time=C[i-1].come_time,T[i].Time_Kind=0,T[i].TheNum=i-1,T[i].assistant=-1;//到达时间  也就是等待的时刻，0表示到达,以及哪个顾客 
	DisorderInsert(n,T,H1);
	BuildHeap(H1);
	theStart=H1->List[1].time;
	now=theStart;
	while(H1->num!=0||H2->num!=0)
	{

      if(((H1->num!=0&&H2->num==0)||(H1->num!=0&&H1->List[1].time<=H2->List[1].time))&&(num=IsFree(assistant,k))!=-1)//最近事件是顾客到达，并且有接线员空闲 
      {                               /*这里是否需要等于号？
	                                如果等于 也就是 有一个人到达的同时有一个人离开
									理论上应该让人先离开
									如果a到达了 没有空 并且b此时离开，会推到下一次
									如果a到达了 且有空，并且b此时离开，则a现在就可以进入
									所以加上等于是没有错误的
									如果不加等于 a到达了有空，b离开，且这时候有空  a本可以占另一个空 现在有两个选择
									所以实际上是无关紧要的 
							*/ 
		if(now<=H1->List[1].time)
      	now=H1->List[1].time;
      	
		  Delete(H1);
      	NextHappen.TheNum=Re.TheNum;
      	NextHappen.time=C[Re.TheNum].stay_time+now;
      	NextHappen.Time_Kind=1;
      	NextHappen.assistant=num;
      	Insert(NextHappen,H2);
      	assistant[num]=1;
      	C[Re.TheNum].assistant=num;
      	C[Re.TheNum].Deal_Time=now;

	  }
	  else
	  {
	  	if(now<=H2->List[1].time)
      	now=H2->List[1].time;
	  	Delete(H2);
	  	assistant[num=Re.assistant]=0;
	  	printf("%d ",num);
	  	if(H1->num!=0&&H1->List[1].time<=Re.time)
	  	{
	  			  	Delete(H1);
	  			  	Re.assistant=num;
	  			  	Re.time=now+C[Re.TheNum].stay_time;
					Re.Time_Kind=1;
					Insert(Re,H2);
					      	C[Re.TheNum].assistant=num;
      	                C[Re.TheNum].Deal_Time=now;
      	                assistant[num]=1;
		  }

		   
	  } /*if(((H1->num!=0&&H2->num==0)||H1->List[1].time>=H2->List[1].time)&&IsFree(assistant,n)==-1)*/
/*如果最近事件不是顾客到达，而是离开 则记录离开时间，并把店员释放，这时候继续如果下一事件是到达 则有店员空闲
  如果是到达  但是却没有接线员 则记录最早离开的时间 ，定义现在时刻为离开时间  释放店员，并将最先到达的人插入
  */ 

/*
在这里出现了问题  导致无限循环
原来考虑的是谁在前面谁就处理 却忽略了 有时候如果好几个人在前面，接线员满员，同时离开得却比下一个到达的要更晚
这样应该处理的是到达 但是实际上它只能在某个人离去后处理，所以进入了无限循环
立马想到的解决办法是如果没有接线员  则把到达的时间改为最早离开的时间 
但是这样还有一个问题 如果多余一名的到达在最近的离开之前，那么可能导致他们的优先级是相同的 ，但是实际上他们优先级应该是
有所不同的
另一个解决办法是做两个堆
一个表示来到 另一个表示离开 
*/ 
	 /* else 
	    if(H->List[1].Time_Kind==1)//事件是顾客离去 
	    {
	       IsHappening=Delete(H);
	       assistant[IsHappening->assistant]=0;//表示店员空闲 
		}*/
	}
	theEnd=now;
	
	for(i=0;i<n;i++)
	printf("顾客%3d到达时间：%3d  开始处理时间: %3d 离开时间：%3d 服务员工：%3d号\n",i,C[i].come_time,C[i].Deal_Time,C[i].stay_time+C[i].Deal_Time,C[i].assistant);
	printf("%d %d 花费时长：%d\n",theStart,theEnd,theEnd-theStart);
	return 0;
}
int IsFree(int *assistant,int n)
{
	int i;
	for(i=0;i<n;i++)
	if(!assistant[i])
	return i;
	return -1;
}
/*
//测试随机数是否可用 
int main()
{
	int i,n;
	Client C[10];
	RandCustomer(10,C);
	for(i=0;i<10;i++)
	printf("%d %d\n",C[i].come_time,C[i].stay_time);
	return 0;
 } */

/*int main()
{
//检测堆操作是否可用的一些代码 
	int i;
	Heap H;
	theTime time[11]; 
	theTime T,*t;
	H=InitailizeHeap(20);
	for(i=1;i<=10;i++)
	scanf("%d %d",&time[i].time,&time[i].Time_Kind);
	DisorderInsert(10,time,H);
	PrintHeap(H);
	BuildHeap(H);
	PrintHeap(H);
	T.time=11;
	T.Time_Kind=1;
	Insert(T,H);
	PrintHeap(H);
	t=Delete(H);
	PrintHeap(H);
	printf("%d %d",t->time,t->Time_Kind);
	
	return 0;
 } */
