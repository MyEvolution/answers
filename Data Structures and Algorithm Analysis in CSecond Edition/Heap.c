#include"Heap.h"



int IsEmpty(PriorityQueue H)
{

	return H->Size==0;
}
int IsFull(PriorityQueue H)
{
	return H->Size==H->Capacity;
}
void MakeEmpty(PriorityQueue H)
{
	H->Size=0;
 } 
 ElementType FindMin(PriorityQueue H)
 {
 	return H->Element[1];
 }
 void Error(const char *string)
 {
 	printf("%s",string);
 	exit(0);
 }


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
   for(i=1;i*2<H->Size;i=child)//表示到了叶子节点 
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

