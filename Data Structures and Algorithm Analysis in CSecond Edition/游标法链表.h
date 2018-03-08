#include<stdio.h>
#ifndef _Cursor_H
#define SpaceSize 1000
typedef int ElementType;
typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;//游标法，没有指针 

void InitializeCursorSpace(void);//初始化
List MakeEmpty(List L);
int IsEmpty(const List L);
int IsLast(const Position P,const List L);
Position Find(ElementType X,const List L);
void Delete(ElementType X,List L);
Position FindPrevious(ElementType X,const List L);
void Insert(ElementType X,List L,Position P);
void DeleteList(List L);
#endif
struct Node
{
	ElementType Element;
	Position Next;
};
struct Node CursorSpace[SpaceSize];
void InitializeCursorSpace(void)
{
	int i;
	for(i=0;i<SpaceSize-1;i++)
	CursorSpace[i].Next=i+1;
	CursorSpace[SpaceSize-1].Next=0;
}
static Position CursorAlloc(void)
{
	Position P;
	P=CursorSpace[0].Next;
	CursorSpace[0].Next=CursorSpace[P].Next;
	return P;
}
static void CursorFree(Position P)
{
	CursorSpace[P].Next=CursorSpace[0].Next;
	CursorSpace[0].Next=P;
}
List MakeEmpty(List L)
{
   L=CursorAlloc();
   CursorSpace[L].Next=0;
   return L;
}
int IsEmpty(List L)
{
	return CursorSpace[L].Next==0;
}
int IsLast(const Position P,const List L)
{
	return CursorSpace[P].Next==0;
}
Position Find(ElementType X,const List L)
{
	Position p;
	p=CursorSpace[L].Next;
	while(p!=0&&CursorSpace[p].Element!=X)
	   p=CursorSpace[p].Next;
	   return p;
}
Position FindPrevious(ElementType X,const List L)
{
	Position P;
	P=L;
	while(CursorSpace[P].Next!=0&&CursorSpace[CursorSpace[P].Next].Element!=X)
	   P=CursorSpace[P].Next;
	   return P;
	
}
void Delete(ElementType X,List L)
{
	Position P,tmp;
	P=FindPrevious(X,L);
	if(!IsLast(P,L))
	{
	tmp=CursorSpace[P].Next;
	CursorSpace[P].Next=CursorSpace[tmp].Next;
	CursorFree(tmp);
	} 

}
void Insert(ElementType X,List L,Position P)
{
     Position Q;
     Q=CursorAlloc();
     if(Q==0)
     {
     	printf("have no space!\n");
     	return;
	 }
     CursorSpace[Q].Element=X;
     CursorSpace[Q].Next=CursorSpace[P].Next;
     CursorSpace[P].Next=Q;
     
}
