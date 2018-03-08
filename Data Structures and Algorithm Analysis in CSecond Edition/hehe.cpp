
#define MinElements 20

#define MinData -1
#include<stdio.h>
#include<stdlib.h>

#ifndef _BinHeap_H

typedef int ElementType;
 struct HeapStruct;//heap ��
typedef struct HeapStruct *PriorityQueue;//priority ����

PriorityQueue Initialize(int MaxElements);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType X,PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);
void Error(const char *string);

#endif

struct HeapStruct
{
	int Capacity;//����
	int Size;//Ԫ�صĸ���
	ElementType *Element;//Ԫ�� 
}; 
PriorityQueue Initailize(int MaxElements)
{
	PriorityQueue H;
	if(MaxElements<MinElements)
	   Error("the Queue's Caracity is too small!\n");
	   H=(PriorityQueue )malloc(sizeof(struct HeapStruct));
	   if(H==NULL)
	   Error("out of space!\n");
	   H->Element=(ElementType *)malloc(sizeof(ElementType)*(MaxElements+1));
	   if(H->Element==NULL)
	   Error("out of space!\n");
	   H->Capacity=MaxElements;
	   H->Size=0;
	   H->Element[0]=MinData;
	   return H;
 } 
void Insert(ElementType X,PriorityQueue H)
{
	int i;
	if(IsFull(H))
		Error("PriorityQueue is Full!\n");
	for(i=++H->Size;X<H->Element[i/2];i=i/2)
	  H->Element[i]=H->Element[i/2];
	H->Element[i]=X;
}
ElementType DeleteMin(PriorityQueue H)
{
	int i,child;
	ElementType MinElement,LastElement;
	if(IsEmpty(H))
	Error("the Queue is Empty!\n");
	MinElement=H->Element[1];
	LastElement=H->Element[H->Size--];
   for(i=1;i*2<H->Size;i=child)//��ʾ����Ҷ�ӽڵ� 
   {
   	child=i*2;
   	if(child!=H->Size&&(H->Element[child]>H->Element[child+1])&&(H->Element[child+1]<LastElement))
   	     H->Element[i]=H->Element[child+1];
   	     else if(H->Element[child]<LastElement)
   	     H->Element[i]=H->Element[child];
   	     else 
   	       break;
   }
   	       H->Element[i]=LastElement;
   	       return MinElement;
}

