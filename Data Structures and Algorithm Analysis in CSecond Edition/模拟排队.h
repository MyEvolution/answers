#ifndef _Heap_h

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>


#define MINSIZE 10
#define MINELEMENT -1

struct HeapQueue;
typedef struct HeapQueue* Heap;
typedef int Time;
struct Customer;
typedef struct Customer Client;
struct TheTime;
typedef struct TheTime theTime;
typedef int Position;


Heap InitailizeHeap(int Size);
void DisorderInsert(int num,Client *TimeTable,Heap H);
void BuildHeap(Heap H);//把无序树构建成堆
void Insert(TheTime T,Heap H);//向堆中插入 
void Delete(Heap H);
void PrintHeap(Heap H);
void Error(const char *string);
void DownFilter(Heap H,Position P);


struct HeapQueue
{
	int HeapSize;
	int num;//堆中元素的个数 
	theTime *List;
};
struct Customer
{
	Time come_time;//来的时间
	Time stay_time;//呆的时长 
	int Deal_Time;
	int assistant;
};
struct TheTime
{
	int TheNum;//标志着哪个顾客 
	Time time;//时刻
	int Time_Kind;//标志是来还是走 
	int assistant;//哪个店员在服务 
};

#endif
 theTime Re;
  
Heap InitailizeHeap(int Size)
{
	Heap H;
	if(Size<MINSIZE)
	Error("the Heap size is too small!\n");
	H=(Heap )malloc(sizeof(struct HeapQueue));
	if(H==NULL)
	Error("out of space!\n");
	H->HeapSize=Size;
	H->num=0;
	H->List=(theTime *)malloc(sizeof(struct TheTime)*(H->HeapSize+1));
	if(H->List==NULL)
	Error("out of space!\n");
	H->List[0].time=MINELEMENT;
	return H;
}
void DisorderInsert(int num,theTime *TimeTable,Heap H)
{
	int i;
	for(i=1;i<=num;i++)
	{
      H->List[i].time=TimeTable[i].time;
      H->List[i].Time_Kind=TimeTable[i].Time_Kind;
      H->List[i].TheNum=TimeTable[i].TheNum;
      H->List[i].assistant=TimeTable[i].assistant;
	}
	H->num=num;
}
void BuildHeap(Heap H)
{
	int i;
	for(i=H->num/2;i>=1;i--)
	DownFilter(H,i);
}
void DownFilter(Heap H,Position P)
{
	Position position;
	position = P;
	Time Temp1,Temp2,Temp3,Temp4;
	while(position*2<=H->num)
	{
		if((position=position*2)!=H->num&&H->List[position+1].time<H->List[position].time)
		  position++;
		 if(H->List[P].time>H->List[position].time)
		 {
		 	Temp1=H->List[P].time,Temp2=H->List[P].Time_Kind,Temp3=H->List[P].TheNum,Temp4=H->List[P].assistant;
		 	H->List[P].time=H->List[position].time,H->List[P].Time_Kind=H->List[position].Time_Kind,H->List[P].TheNum=H->List[position].TheNum,H->List[P].assistant=H->List[position].assistant;
		 	H->List[position].time=Temp1,H->List[position].Time_Kind=Temp2,H->List[position].TheNum=Temp3,H->List[position].assistant=Temp4;	 	
		 	P=position;
		 }
		 else break;
	}
}
void Insert(TheTime T,Heap H)
{
	if(H->num<H->HeapSize)
	{
	
	Position P;
	P=++H->num;
	
		while(P>0)
		{
			if(T.time<H->List[P/2].time)
			{
			  H->List[P].time=H->List[P/2].time,H->List[P].Time_Kind=H->List[P/2].Time_Kind,H->List[P].TheNum=H->List[P/2].TheNum,H->List[P].assistant=H->List[P/2].assistant;
			  P=P/2;	
			}
			else break;
		}
	H->List[P].time=T.time,H->List[P].Time_Kind=T.Time_Kind,H->List[P].TheNum=T.TheNum,H->List[P].assistant=T.assistant;
}
else
   printf("the Heap is full!\n");
}
void Delete(Heap H)
{	
	Position P,last;
	theTime Wait;
	Wait.time=H->List[H->num].time;
	Wait.Time_Kind=H->List[H->num].Time_Kind;
	Wait.assistant=H->List[H->num].assistant;
	Wait.TheNum=H->List[H->num].TheNum; 
	if(H->num==0)
	Error("the Heap is Empty!\n");
	Re.time=H->List[1].time;
	Re.Time_Kind=H->List[1].Time_Kind;
	Re.TheNum=H->List[1].TheNum;
	Re.assistant=H->List[1].assistant; 
	if(--H->num)
	{
		P=1;
	   while((last=P)*2<=H->num)
	   {
	   	if((P=P*2)!=H->num&&H->List[P+1].time<H->List[P].time)
	   	   P++;
	   	if(H->List[P].time>Wait.time)
	   	break;
	   	else
	   	{ 
	   	  H->List[last].time=H->List[P].time;
	   	  H->List[last].Time_Kind=H->List[P].Time_Kind; 
	   	  H->List[last].TheNum=H->List[P].TheNum;
	   	  H->List[last].assistant=H->List[P].assistant;
	   	  } 
	   }
	   H->List[last].time=Wait.time;
	   H->List[last].Time_Kind=Wait.Time_Kind;
	   H->List[last].TheNum=Wait.TheNum;
	   H->List[last].assistant=Wait.assistant; 
	}
	
}
void Error(const char *string)
{
	printf("%s",string);
	exit(0);
}
void PrintHeap(Heap H)
{
	int i;
	if(H->num>0)
	for(i=1;i<=H->num;i++)
	{
		printf(H->List[i].Time_Kind==0?"到达时刻：":"离去时刻：");
		printf("%d\n",H->List[i].time);
	}
}
void RandCustomer(int n,Client *C)
{
	srand(time(NULL)); 
	int i;
	for(i=0;i<n;i++)
	{
		C[i].come_time=rand()%2;
		C[i].stay_time=rand()%3+1;
		C[i].assistant;
		C[i].Deal_Time;
	}
}

