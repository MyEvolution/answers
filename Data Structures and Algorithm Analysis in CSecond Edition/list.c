#include"list.h"
#include<malloc.h>
#include<stdio.h>
List L;
List MakeEmpty(List L)
{
	L=(List)malloc(sizeof(struct Node));
	L->Next=NULL;
}
int IsEmpty(List L)
{
	return L->Next==NULL;
}
int IsLast(Position P,List L)//p����ǰλ�� 
{
	return P->Next==NULL;	
}
Position Find(ElementType X, List L)
{
	Position P=L->Next;
	while(P->Element!=X&&P!=NULL)
	   P=P->Next;
	   return P;
}

Position FindPrevious(ElementType X,List L)//����x�� ǰ�� 
{                                            //û���ҵ��ͷ������һ��Ԫ�� 
	Position P;
	while(P->Next->Element!=X&&P->Next!=NULL)
	P=P->Next;
	return P;
}
void Delete(ElementType X,List L)//ɾ�����еĳ��ֵĵ�һ��x 
{
	Position P,Q;
	P=L;
 P=FindPrevious(X,L);
 if(!IsLast(P,L))
 {
 	Q=P->Next;
 	P->Next=Q->Next;
 	free(Q);
 }
  
}
void Insert(ElementType x,List L,Position P)//��x�ӵ�P֮�� 
{
	Position Q=(Position)malloc(sizeof(struct Node));
	if(Q==NULL) return;
	Q->Element=x;
	Q->Next=P->Next;
	P->Next=Q;
}
void DeleteList(List L)//ɾ��һ���� 
{
	Position P,Q;
	P=L->Next;
	L->Next=NULL;
	while(P!=NULL)
	{
		Q=P;
		P=P->Next;
		free(Q);
	}
	
}
Position Header(List L)
{
	return L;
}
Position First(List L)
{
	return L->Next;
}
Position Advance(Position P)//ǰ������ //P�������ڵ�һ��λ�� 
{
	Position Q=L->Next;
	ElementType e;
	while(Q->Next!=P)
	Q=Q->Next;
	e=Q->Element;
	Q->Element=P->Element;
	P->Element=e;
	return Q;
}
ElementType Retrieve(Position P)
{
	return P->Element;
}
