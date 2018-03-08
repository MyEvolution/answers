#ifndef _List_H
typedef int ElementType;
struct Node
{
	ElementType Element;
	struct Node * Next;
 };

typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List Create(void);
void MakeEmpty(List L);//创建一个空表 
int IsEmpty(List L);//判断是否为空表
int IsLast(Position P,List L);
Position Find(ElementType x,List L);
void Delete(ElementType X,List L);
Position FindPrevious(ElementType X,List L);
void Insert(ElementType x,List L,Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);
void printlist(List L);
Position ToLast(List L);
Position FinD(ElementType X,List L);
void reverse(List L);//新建一个链表以实现
void Reverse(List L);//通过交换结点之间的指针实现 
void DeleteTheSame(List L);

#endif

#include<malloc.h>
#include<stdio.h>
List Create(void)
{
	List L;
	L=(List)malloc(sizeof(struct Node));
	MakeEmpty(L);
	return L;
}

   
void MakeEmpty(List L)
{
	L->Next=NULL;//原来为什么会出错？ 
}             //参数是指针，又返回指针，因为函数并不会本质该表什么， 
/*void MakeEmpty(List *L)
{
 *L=(List)malloc(sizeof(struct Node));
 (*L)->Next=NULL;
}
都知道函数的参数是copy进去的，所以不会不用指针无法实际上改变一个值，
用了指针，指针指向的是地址，地址内的值转换了，也就实际上转化看了 
但是实际上指针也是参数，也是一个地址，只是它指向另一个地址
参数若为指针，也是copy一个同样指向该地址的指针进去，所以函数中改变指针的指向，实际上
只是改变了copy的指针的指向，原来的指针指向并未改变
那么如何在函数中改变指针的地址呢？
和变量一样，指针也有自己的地址
所以我们用一个指向指针的指针，例如上述的 List *L 也就是struct Node **L 
L是一个指向指针地址的指针，
*L也就是原来的L指向的指针的地址了，
改变*L的指针，也就是这个地址的指针的指向被改变了；
这样就达到修改指针的指向的目的； 
*/
int IsEmpty(List L) 
{
	return L->Next==NULL;
}
int IsLast(Position P,List L)//p代表当前位置 
{
	return P->Next==NULL;	
}

Position Find(ElementType X, List L)
{
	Position P=L->Next;
	while(P!=NULL&&P->Element!=X)
	   P=P->Next;
	   return P;
}

Position FindPrevious(ElementType X,List L)//返回x的 前驱 
{                                            //没有找到就返回最后一个元素 
	Position P;
	P=L;
	while((P->Next!=NULL)&&(P->Next->Element!=X))
	P=P->Next;
	
	return P;
}
void Delete(ElementType X,List L)//删除表中的出现的第一个x 
{
	Position P,Q;
 P=FindPrevious(X,L);
 if(!IsLast(P,L))
 {
 	Q=P->Next;
 	P->Next=Q->Next;
 	free(Q);
 }
  
}
void Insert(ElementType x,List L,Position P)//把x加到P之后 
{
	Position Q=(Position)malloc(sizeof(struct Node));
	if(Q==NULL) return;
	
	Q->Element=x;	
	Q->Next=P->Next;
	P->Next=Q;
	
}
void DeleteList(List L)//删除一个表 
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
Position Advance(Position P)//前进？？ //P不可能在第一个位置 
{
	Position Q=P->Next;
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
void printlist(List L)
{
	Position P;
	P=L->Next;
	if(P!=NULL)
	{
		printf("%d",P->Element);
		P=P->Next;
	}
	 
	while(P!=NULL)
	{
		putchar(' ');
	printf("%d",P->Element);
		P=P->Next;
	}
	putchar('\n');
}
void ExchangeElem(List L,Position P)
{
	Position Q,q;
	Q=L;
	while(Q->Next!=P)
	Q=Q->Next;
	Q->Next=P->Next;
	P->Next=P->Next->Next;
	Q->Next->Next=P;
 } 
 Position ToLast(List L)
 {
 	Position P;
 	P=L;
 	while(P->Next!=NULL)
 	   P=P->Next;
 	   return P;
 }
 Position FinD(ElementType X,List L)
 {
 	Position P;
 	P=L->Next;
 	if(P==NULL||P->Element==X)
 	  return P;
 	  else 
	   return FinD(X,P);
 }
 void reverse(List *L)
 {
 	static List Q;
 	Position P=(*L)->Next;
 	Q=Create();
 	while(P!=NULL)
 	{
 		Insert(P->Element,Q,Q);
 		P=P->Next;
	 }
 		
 	P=(*L);
 	(*L)=Q;
 		free(P);
 }
 void Reverse(List L)
 {
 	Position P;
 	Position Q;
 	Position I;
	 P=L->Next;
	 while(P->Next!=NULL)
	 {
	  Q=L->Next;
	  L->Next=P->Next;
	  P->Next=P->Next->Next;
	  L->Next->Next=Q;
	  
	  } 
 }
 void ReversE(List L)
 {
 	Position P,Q;
 	P=L;
 	while(P->Next!=NULL)
 	P=P->Next;
 	while(L->Next!=P)
 	{
 		Q=L->Next;
 		L->Next=Q->Next;
 		Q->Next=P->Next;
 		P->Next=Q;
	 }
  } 
void DeleteTheSame(List L)
{
	Position P;
	Position Q;
	Position M;
	P=L->Next;
	while(!IsLast(P,L))
	{
		Q=P;
		while(Q->Next!=NULL)
		  if(Q->Next->Element==P->Element)//Q->已经得到了改变 
		  {
		  	M=Q->Next;
		  	Q->Next=Q->Next->Next;
		  	free(M);
		  }
		  else Q=Q->Next;
		  P=P->Next;	  
	}
}
