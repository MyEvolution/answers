#include<stdio.h>
#include<stdlib.h>
#ifndef _loop_List_H
typedef int ElementType;
struct Node;
typedef struct Node *List;
typedef struct Node *Position;
struct Node
{
	ElementType Element;
	struct Node *Next;
};
List CreateList(void);
void MakeEmpty(List L); 
int IsEmpty(List L);
void Insert(ElementType X,List L,Position P);
void Delete(List L,Position P);
void printList(List L);
int IsOnly(List L);
#endif
int IsOnly(List L)
{
	return L->Next==L;
}
List CreateList(void)
{
	List L;
	L=(List)malloc(sizeof(*L));
	MakeEmpty(L);
	return L;
}
void MakeEmpty(List L)
{
	L->Next=L;
	L->Element=-1;
}
int IsEmpty(List L)
{
	return L->Next==L&&L->Element==-1;
}
void Insert(ElementType X,List L,Position P)
{
	Position Q;
	if(IsEmpty(L))
	L->Element=X;
	else 
	{
		Q=(List)malloc(sizeof(struct Node));
		if(Q==NULL) return;
		Q->Element=X;
		Q->Next=P->Next;
		P->Next=Q;
		
	}
}
void Delete(List L,Position P)
{
	Position Q;
	if(P->Next!=P)
	{
		Q=P->Next;
		P->Element=Q->Element;
	   P->Next=Q->Next;
	   free(Q);
	}
	else
	return;
}
void printList(List L)
{
   Position Q;
   printf("%d",L->Element);
   Q=L->Next;
   while(Q!=L)
   {
   	printf(" %d",Q->Element);
   	Q=Q->Next;
   }
}
