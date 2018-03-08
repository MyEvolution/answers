#include<stdio.h>
#include<stdlib.h>
#ifndef _arrar_list_h

typedef int ElementType;
struct Node;
typedef struct Node *List;
typedef int Position;

struct Node
{
	ElementType *array;
	int ListSize;
	int LastPosition;
 };
List CreateList(int size);
void MakeEmpty(List L);
int IsEmpty(List L);
int IsFull(List L);
void Delete(Position P,List L);
void Insert(ElementType X,Position P,List L);
void PrintList(List L);
void DeleteTheSame(List L);
void Deletethesame(List L);

#endif
List CreateList(int size)
{
	List L;
	L=(List)malloc(sizeof(*L));
	if(L==NULL)
	  {
	  	printf("out of space!\n");
	  	return NULL;
	  }
	 L->array=(ElementType*)malloc(size*sizeof(ElementType));
	 L->ListSize=size;
	 if(L->array==NULL)
	 {
	 	printf("out of space!\n");
	  	return NULL;
	 }
	 
	 MakeEmpty(L);
}
void MakeEmpty(List L)
{
	if(L==NULL||L->array==NULL)
	{
		printf("Must create a list first!\n");
		return;
	}
	L->LastPosition=-1;
}
int IsEmpty(List L)
{
	return L->LastPosition==-1;
}
int IsFull(List L)
{
	return L->LastPosition==L->ListSize-1;
}
void Delete(Position P,List L)
{
	int i;
	if(IsEmpty(L))
	{
		printf("the list is empty!\n");
		return;
	}
	for(i=P;i<L->LastPosition;i++)
	L->array[i]=L->array[i+1];
	L->LastPosition-=1;
}
void Insert(ElementType X,Position P,List L)
{
	int i;
	if(IsFull(L))
	{
		printf("the list has been full!\n");
		return;
	}
	for(i=L->LastPosition+1;i>P;i--)
	  L->array[i]=L->array[i-1];
	  L->array[P]=X;
	  L->LastPosition+=1;
}
void PrintList(List L)
{
	int i;
	for(i=0;i<=L->LastPosition;i++)
	printf(i==L->LastPosition?"%d\n":"%d ",L->array[i]);
}
void DeleteTheSame(List L)
{
	int i,j;
	i=0;
	while(i<L->LastPosition)
	{
		j=i+1;
		while(j<=L->LastPosition)
		  if(L->array[i]==L->array[j])
		  Delete(j,L);//已经删除也就相当于j向前递进了一位 
		  else j++;
		  i++;
	}
}
int cmd(const void *a,const void *b)
{
	ElementType *p,*q;
	p=(ElementType *)a;
	q=(ElementType *)b;
	return *p-*q;
}
void Deletethesame(List L)
{
	int i=0;
	qsort(L->array,L->LastPosition+1,sizeof(ElementType),cmd);//快速排序 时间复杂度为O(n*logn) 
	while(i<L->LastPosition)//时间复杂度为N； 
	{                                            //总的时间复杂度为O(NlogN) 
		if(L->array[i]==L->array[i+1])
		 Delete(i+1,L);
		 else i++;
	}
}
