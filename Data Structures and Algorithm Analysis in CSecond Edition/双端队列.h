#include<stdio.h>
#include<stdlib.h> 
#ifndef deque_h

typedef int ElementType;

typedef struct QNode
{
	struct QNode *Next;
	struct QNode *Previous;
	ElementType Element;
}*Position;
typedef struct
{
	Position Front;
	Position Tail;
}Q,*Queue;

Queue Create(void);
void MakeEmpty(Queue Q);
int IsEmpty(Queue Q);
ElementType Pop(Queue Q);
void Push(ElementType X,Queue Q);
ElementType Eject(Queue Q);
void Inject(ElementType X,Queue Q);
void Print(Queue Q);

#endif

Queue Create(void)
{
	Queue Q;
	Q=(Queue)malloc(sizeof(*Q));
	if(Q==NULL)
	{
		printf("out of space!\n");
		return NULL;
	}
	Q->Front=(Position)malloc(sizeof(*Q));
	Q->Tail=(Position)malloc(sizeof(*Q));
	Q->Front->Next=Q->Tail;
	Q->Front->Previous=NULL;
	Q->Tail->Next=NULL;
	Q->Tail->Previous=Q->Front;
	return Q;
	
}
int IsEmpty(Queue Q)
{
	return Q->Front->Next==Q->Tail&&Q->Tail->Previous==Q->Front;
}
ElementType Pop(Queue Q)//队头释放 
{
	ElementType P;
	Position p;
	if(!IsEmpty(Q))
	{
		
		p=Q->Front->Next;
		P=p->Element;
		Q->Front->Next=p->Next;
		p->Next->Previous=Q->Front;
		free(p);
		return P;
		
	}
	else
	{
		printf("the queue is empty!\n");
		return -1;
	}
	
}
void Push(ElementType X,Queue Q)//插入队头 
{
	Position P;
	P=(Position )malloc(sizeof(*P));
	if(P==NULL)
	{
		printf("out of space!\n");
		return;
	}
	P->Element=X;
	P->Next=Q->Front->Next;
	P->Next->Previous=P;
	Q->Front->Next=P;
	P->Previous=Q->Front;
}
void Inject(ElementType X,Queue Q)//插入队尾 
{
	Position P;
	P=(Position )malloc(sizeof(*P));
	if(P==NULL)
	{
		printf("out of space!\n");
		return;
	}
	P->Element=X;
	Q->Tail->Previous->Next=P; 
	P->Previous=Q->Tail->Previous;
	P->Next=Q->Tail;
	Q->Tail->Previous=P;

}
ElementType Eject(Queue Q)
{
	if(!IsEmpty(Q))
	{
		Position P1=Q->Tail->Previous;
		Position P2=P1->Previous;
		P2->Next=Q->Tail;
		Q->Tail->Previous=P2;
		ElementType X;
		X=P1->Element;
		free(P1);
		return X;
		
	}
	else
	{
		printf("Queue is empty!\n");
		return NULL;
	}
}
void Print(Queue Q)
{
	Position P;
	P=Q->Front->Next;
	while(P!=Q->Tail)
	{
		printf("%d ",P->Element);
		P=P->Next;
	}
}
