#include<stdio.h>
#include<malloc.h>

#define  LEFT 1
#define RIGHT 2

struct BNode;
typedef struct BNode *BinTree;
typedef char ElementType;

struct BNode
{
	BinTree Left,Right;
	ElementType Element;
};

BinTree Insert(ElementType X,BinTree T,int where)
{
	if(where==0){
		if(T==NULL)
	{
		T=(BinTree )malloc(sizeof(*T)); 
		T->Element=X;
		T->Left=T->Right=NULL;
	}
	else
	T->Element=X;
	}	
	else if(where==LEFT)
	T->Left=Insert(X,T->Left,0);
	else if(where==RIGHT)
	T->Right=Insert(X,T->Right,0);
	return T;
}

int Isomorphic(BinTree T1,BinTree T2)//�ж������Ƿ�ͬ�� 
{
	if(T1==NULL||T2==NULL)//�и����� �����ڶ��������ʱ  ͬ��ֻ����������ͬ����� 
		return T1==NULL&&T2==NULL;
	else
	if(T1->Element==T2->Element)

			return (Isomorphic(T1->Left,T2->Left)&&Isomorphic(T1->Right,T2->Right))
		||(Isomorphic(T1->Left,T2->Right)&&Isomorphic(T1->Right,T2->Left));
	else 
		return 0;
	 
 } 
 
 void PrintTree(BinTree T)
 {
 	if(T!=NULL)
 	{
 			putchar(T->Element);
 		PrintTree(T->Left);
 	
 		PrintTree(T->Right);
	 }
  } 
