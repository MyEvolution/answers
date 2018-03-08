#ifndef self_adjusting_list_link_h

#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
struct Node;
typedef struct Node *List;
typedef List Position;

List Create(void);
void MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(List L,Position);
int Find(ElementType X,List L);
void Insert(List L,ElementType X);
void Delete(List L,ElementType X);
void PrintList(List L);

#endif

struct Node
{
	ElementType Element;
	 Position Next;
};
List Create(void)
{
	List L;
	L=(List)malloc(sizeof(*L));
	MakeEmpty(L);
	return L;
	
}
void MakeEmpty(List L)
{
	L->Next=NULL;
}
int IsEmpty(List L)
{
	return L->Next==NULL;
}
int IsLast(List L,Position P)
{
	return P->Next==NULL;
}
Position FindPrevious(ElementType X,List L)
{
	Position P;
	P=L;
	while(P->Next!=NULL&&P->Next->Element!=X)
	  P=P->Next;
	  return P;
}
int Find(ElementType X,List L)
{
	Position P;
	Position Q;
    P=FindPrevious(X,L);
    if(IsLast(L,P))
      {
      	printf("this is no the element!\n");
      	return -1;
	  }
	  else//把X放到第一位 
	  {
	  	Q=P->Next;
	  	P->Next=P->Next->Next;
	  	Q->Next=L->Next;
	  	L->Next=Q;
        printf("this Elem has been moven to the first.\n");
	  }
}
void Insert(List L,ElementType X)
{
	Position P;
	P=(Position )malloc(sizeof(*P));
	if(P==NULL)
	{
		printf("out of space!\n");
		return;
	}
	P->Element=X;
	P->Next=L->Next;
	L->Next=P;
}
void Delete(List L,ElementType X)
{
	if(Find(X,L)==-1)
	  return;
	  else
	  {
	  	Position P;
	  	P=L->Next;
	  	L->Next=L->Next->Next;
	  	free(P);
	  	printf("this Elem has been deleted!\n");
	  }
}
void PrintList(List L)
{
	L=L->Next;
	while(L!=NULL)
	{
		printf(L->Next==NULL?"%d\n":"%d ",L->Element);
		L=L->Next;
	}
}
