#include<stdio.h>
#include<stdlib.h>

#ifndef _AvlTree_H

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;
typedef int ElementType;
AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType X,AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType X,AvlTree T);
AvlTree Delete(ElementType X,AvlTree T);
static Position SingleRotateWithLeft(Position K2);
static Position DoubleRotateWithLeft(Position K3);
static Position SingleRotateWithRight(Position K2);
static Position DoubleRotateWithRight(Position K3);

#endif
int Max(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}
struct AvlNode
{
	ElementType Element;
	AvlTree Left;
	AvlTree Right;
	int Height;
};
static int Height(Position P)
{
	if(P==NULL)
	return -1;
	else
	 return P->Height;
}
AvlTree MakeEmpty(AvlTree T)
{
	if(T!=NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}
AvlTree Find(ElementType X,AvlTree T)
{
	if(T==NULL)
	return NULL;
	if(X>T->Element)
	return Find(X,T->Right);
	else if(X<T->Element)
	  return Find(X,T->Left);
	  else
	    return T;
}
AvlTree FindMin(AvlTree T)
{
	while(T!=NULL&&T->Left!=NULL)
	T=T->Left;
	return T;
}
AvlTree FindMax(AvlTree T)
{
	if(T==NULL)
	return NULL;
	else
	if(T->Right==NULL)
	return T;
	else 
	return FindMax(T->Right);
}
AvlTree Insert(ElementType X,AvlTree T)
{
	if(T==NULL)// creat a new node
	{
		T=(AvlTree)malloc(sizeof(*T));
		if(T==NULL) printf("out of space!\n");
		else
		{
		T->Height=0;
		T->Element=X;
		T->Left=NULL;
		T->Right=NULL;	
		}

	}
	else if(X>T->Element)
	{
		T->Right=Insert(X,T->Right);//基本上和二叉查找树的相同 但是下面会有不一样 
		if(Height(T->Right)-Height(T->Left)==2)
		    if(X>T->Right->Element)// 加到右子树的右边 
		      T=SingleRotateWithRight(T);//单旋转 
		      else
			  T=DoubleRotateWithRight(T);//双旋转 
		}
		else if(X<T->Element)
		{
			T->Left=Insert(X,T->Left);
			if(Height(T->Left)-Height(T->Right)==2)
			  if(X>T->Left->Element)
			   T=DoubleRotateWithLeft(T);
			   else 
			   T=SingleRotateWithLeft(T);
		 }
		 T->Height=Max(Height(T->Left),Height(T->Right))+1; //求得该结点的高度 
	}

static Position SingleRotateWithLeft(Position K2)
{
	Position K1;
	K1=K2->Left;
	K2->Left=K1->Left;
	K1->Right=K2;
	K2->Height=Max(Height(K2->Left),Height(K2->Right))+1;
	K1->Height=Max(Height(K1->Left),Height(K2))+1;
	return K1;
}
static Position DoubleRotateWithLeft(Position K3)
{
	Position K1=K3->Left;
	Position K2=K1->Right;
	K1->Right=K2->Left;
	K3->Left=K2->Right;
	K2->Left=K1;
	K2->Right=K3;
	K1->Height=Max(Height(K1->Left),Height(K1->Right))+1;
	K3->Height=Max(Height(K3->Left),Height(K3->Right))+1;
	K2->Height=Max(Height(K1),Height(K2))+1;
	return K2;
}
static Position SingleRotateWithRight(Position K1)
{
	Position K2;
	K2=K1->Right;
	K1->Right=K2->Left;
	K2->Left=K1;
	K1->Height=Max(Height(K1->Left),Height(K1->Right))+1;
	K2->Height=Max(Height(K1),Height(K2->Right))+1;
	return K2;
}
static Position DoubleRotateWithRight(Position K1)
{
	/*
	经过研究发现  实际上的双旋转是通过两次单旋转实现的  
	这样写可以大大简化代码*/
	Position K2=K1->Right;
	K2=SingleRotateWithLeft(K2);
	return SingleRotateWithRight(K1);
	 
}

