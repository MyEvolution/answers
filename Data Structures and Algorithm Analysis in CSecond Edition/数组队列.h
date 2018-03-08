#include<stdio.h>
#define MinElement 100
#include<stdlib.h>
typedef int ElementType;
#ifndef _Queue_h

struct QueueRecord;
typedef struct QueueRecord *Queue;
int IsEmpty(Queue Q);
int IsFUll(Queue Q);
Queue CreateQueue(int MaxElement);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void EnQueue(ElementType X,Queue Q);
ElementType Front(Queue Q);
void DeQueue(Queue Q);
ElementType FrontAndQueue(Queue Q);

#endif
struct QueueRecord
{
	int Capacity;//容量 
	int Front;
	int Rear;
	ElementType *array;
	int size;
};
int IsEmpty(Queue Q)
{
	return Q->size==0;
 } 
 int IsFull(Queue Q)
 {
 	return Q->size==(Q->Capacity-1);
 }
 Queue CreateQueue(int MaxElement)
 {
 	Queue Q;
 	if(MaxElement<MinElement)
 	{
 		printf("the Queue is too short!\n");
 		  return NULL;
	 }
	 else 
	 {
	 	Q=(Queue)malloc(sizeof(struct QueueRecord));
	 	if(Q==NULL)
	 	{
	 		printf("out of space!\n");
	 		return NULL;
		 }
		 Q->array=(ElementType *)malloc(MaxElement*sizeof(ElementType));
		 if(Q->array==NULL)
		 {
		 		printf("out of space!\n");
	 		return NULL;
		 }
		 Q->Capacity=MaxElement;
		 MakeEmpty(Q);
		 return Q;
	 }
 }
 void MakeEmpty(Queue Q)//若队列为空 rear=front-1； 
 {
 	Q->size=0;
 	Q->Front=Q->Rear=0;
 
 }
 int Susu(int v,Queue Q)
 {
 	if(v==(Q->Capacity-1))
 	  return 0;
 	  else return ++v;
 }
 void EnQueue(ElementType X,Queue Q)
 {
 	if(!IsFull(Q))
 	{
 		Q->array[Q->Rear=Susu(Q->Rear,Q)]=X;
 		Q->size+=1;
	 }
     
	 
	  else
	 	printf("the Queue is full of Elements\n"); 
  } 
ElementType Front(Queue Q)
{
	return Q->array[Susu(Q->Front,Q)];
}
void DeQueue(Queue Q)
{
	if(!IsEmpty(Q))
	{
		Q->Front=Susu(Q->Front,Q);
		Q->size-=1; 
	}
	
	 
		
	else {
		printf("Queue is Empty!\n");
		return;
	}
}
ElementType FrontAndQueue(Queue Q)
{
	if(!IsEmpty(Q))
	{
		Q->size-=1; 
		return  Q->array[Q->Front=Susu(Q->Front,Q)];
	}
	else{
	printf("Queue is Empty!\n");
		return 0;
		
	}
}
