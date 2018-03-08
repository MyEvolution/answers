#include<stdio.h>
#include<stdlib.h>

#ifndef threaded_binary_tree_h

typedef int ElementType;
struct Node;
typedef struct Node *TBTree;//线索二叉树 
typedef TBTree Tree;//非线索二叉树
//实际上上面两个树的结构是一样的 只是为了区分而已 

struct Node
{
	ElementType Element;
	TBTree Left,Right;
	int Ltag,Rtag;//区分儿子指针中的线索指针 
};

int IsSingle(TBTree T);
TBTree MakeEmpty(TBTree T);
TBTree TInsert(ElementType X,TBTree T);//线索二叉树的增加 
TBTree TDelete(ElementType X,TBTree T);//线索二叉树的删除 
Tree Insert(ElementType X,Tree T);//普通二叉树的添加 
Tree Delete(ElementType X,Tree T);//普通二叉树的删除 
ElementType FindMin(TBTree T);
ElementType Findmin(Tree T); 
void PrintTBree(TBTree T);
void MakeItToThreaded(Tree T); 
void PrintTree(Tree T);
void inOrderTravel(TBTree T);
TBTree PFindMin(TBTree T);//返回最小元素的位置 

#endif

int IsSingle(TBTree T)
{
   if((T->Ltag==0&&T->Left)||(T->Rtag==0&&T->Right))
   return 0;
   else return 1;
}
ElementType FindMin(TBTree T)
{
	if(T)
	{
		if(T->Ltag==0&&T->Left)
		return FindMin(T->Left); 
		else return T->Element; 
	}
}
TBTree TInsert(ElementType X,TBTree T)//中序线索二叉树   添加元素 
{
	int Y;
	TBTree t; 
	if(T==NULL)
	{
		T=(TBTree )malloc(sizeof(*T));
		T->Element=X;
		T->Left=T->Right=NULL;
		T->Ltag=T->Rtag=0; 
	}
	else
	{
		if(X<T->Element)
	   {
       if(T->Ltag==0&&T->Left)
       T->Left=TInsert(X,T->Left);
       else if(T->Ltag==1||T->Left==NULL)
       {
       	Y=T->Ltag;
       	t=T->Left; 
       	T->Ltag=0;
       	T->Left=NULL;
       	T->Left=TInsert(X,T->Left);
       	T->Left->Rtag=1;
       	T->Left->Right=T; //添加在左边的  他的后继是其父母 
       	T->Left->Ltag=Y;//这两行也很重要  在我看来 
       	T->Left->Left=t;//刷新线索 
	   }
	   }
	   else if(X>T->Element)
	   {
	   	if(T->Rtag==0&&T->Right)
	   	T->Right=TInsert(X,T->Right);
		   else{//找到最低层添加 
		   Y=T->Rtag;
		   t=T->Right; 
		 	T->Rtag=0;
		 	T->Right=NULL;
		   T->Right=TInsert(X,T->Right);
		   T->Right->Ltag=1;
		   T->Right->Left=T;// 添加在右边的 他的前继便是其父母 
		   T->Right->Rtag=Y;
		   T->Right->Right=t; 
		   
		   } 
	   }
	}
	return T;
}
TBTree TDelete(ElementType X,TBTree T)
{
	ElementType Y;
	TBTree t;
	if(T==NULL)
	{
		printf("there is no this ELement!\n");
		return NULL;
	}
	else
	if(T->Element>X)
	{
		if(T->Left&&T->Left->Element==X&&IsSingle(T->Left))
		  T->Ltag=T->Left->Ltag; 
			T->Left=TDelete(X,T->Left);
	}
		else if(X>T->Element)
		{
			if(T->Right&&T->Right->Element==X&&IsSingle(T->Right))
			T->Rtag=T->Right->Rtag;
				T->Right=TDelete(X,T->Right); 
		}		
		else 
		{
			if(T->Rtag==0&&T->Right)
			{
				Y=FindMin(T->Right);
				T->Element=Y; 
				T->Rtag=T->Right->Rtag;
				T->Right=TDelete(Y,T->Right); 
			}
			else if(T->Ltag==0&&T->Left)
			{
				t=T;
				T->Left->Rtag=T->Rtag;
				T->Left->Right=T->Right;
				T=T->Left;
				free(t);
			}
			else
			{
				t=T;
              if(T->Left->Right==t)
              T=T->Right;
              else if(T->Right->Left==t)
              T=T->Left;
              free(t);
			}			 
		}
	return T; 
}
void PrintTBree(TBTree T)
{
	if(T)
	{
		if(!T->Ltag&&T->Left)
		PrintTBree(T->Left);
		if(T->Ltag)
		printf("%d<-%d\n",T->Left->Element,T->Element);
		if(T->Rtag)
		printf("%d->%d\n",T->Element,T->Right->Element);
		if(!T->Ltag&&!T->Rtag)
		printf("%d\n",T->Element); 
		if(!T->Rtag&&T->Right)
		PrintTBree(T->Right);
	 } 
}
ElementType Findmin(Tree T)
{
	if(T)
	{
		if(T->Left)
		return Findmin(T->Left);
		else return T->Element; 
	}
	else
	printf("the tree is empty!\n");
}
Tree Insert(ElementType X,Tree T)
{
	if(T==NULL)
	{
		T=(Tree )malloc(sizeof(*T));
		T->Element=X;
		T->Left=T->Right=NULL; 
	 } 
	 else
	 if(X>T->Element)
	 T->Right=Insert(X,T->Right);
	 else if(X<T->Element)
	 T->Left=Insert(X,T->Left);
	 return T;
}
Tree Delete(ElementType X,Tree T)
{
	ElementType Y;
	if(T==NULL)
	{
		printf("there is no this Element in this tree!\n");
		return NULL;
	 } 
	 else
	 {
	 	if(T->Element>X)
	 	T->Left=Delete(X,T->Left);
	 	else if(T->Element<X)
	 	T->Right=Delete(X,T->Right);
	 	else 
	 	{
	 		if(T->Right)
	 		{
	 			T->Element=Y=Findmin(T->Right);
	 			T->Right=Delete(Y,T->Right);
			 }
			 else
			 T=T->Left;
		 }
	 }
	 return T;
}
void MakeItToThreaded(Tree T,Tree Front,Tree Rear)
{
   if(T->Element<Front->Element)
   Front=T;
   if(T->Element>Rear->Element)
   Rear=T;
   if(T->Left)
   T->Ltag=0,MakeItToThreaded(T->Left,Front,T);
   else if(Front==T)
   T->Left=NULL,T->Ltag=0;
   else
   T->Left=Front,T->Ltag=1;
   if(T->Right)
   T->Rtag=0,MakeItToThreaded(T->Right,T,Rear);
   else if(Rear==T)
   T->Right=NULL,T->Rtag=0;
   else 
   T->Right=Rear,T->Rtag=1; 
}
void PrintTree(Tree T)
{
	if(T)
	{
		PrintTree(T->Left);
		printf("%d\n",T->Element);
		PrintTree(T->Right);
	}
}
TBTree PFindMin(TBTree T)
{	
	if(T)
	{
		if(T->Ltag==0&&T->Left)
		return PFindMin(T->Left); 
		else return T; 
	}
	return NULL;
}
void inOrderTravel(TBTree T)
{
        T=PFindMin(T);
		printf("%d\n",T->Element);
       while(T->Right)
	   {
	   	if(T->Rtag)
	   	{
	   		T=T->Right;
	   		printf("%d\n",T->Element);
		   }
		   else
		   {
		   	T=PFindMin(T->Right);
		   	printf("%d\n",T->Element);
		   }
		} 
}
