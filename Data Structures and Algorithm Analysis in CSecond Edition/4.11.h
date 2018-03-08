#ifndef _binary_tree_h

#include<stdio.h>
#include<stdlib.h>

struct TreeNode;
typedef struct TreeNode *BinaryTree;
typedef struct TreeNode *Position;
typedef int ElementType;
 struct TreeNode
 {
 	ElementType Element;
 	BinaryTree Left;
 	BinaryTree Right;
 };
typedef struct
{
	struct TreeNode *Tree;
	int IsEmpty;
}B,*BinTree;

BinTree CreateTree(void);
BinaryTree makeEmpty(BinaryTree T);
BinaryTree find(ElementType X,BinaryTree T);
BinaryTree findMax(BinaryTree T);
BinaryTree findMin(BinaryTree T);
void insert(ElementType X,BinaryTree T);
void delet(ElementType X,BinaryTree T);
void printTree(BinaryTree T);
void MakeEmpty(BinTree T);
Position Find(ElementType X,BinTree T);
Position FindMax(BinTree T);
Position FindMin(BinTree T);
void Insert(ElementType X,BinTree T);
void Delete(ElementType X,BinTree T);
void PrintTree(BinTree T);
 
#endif

BinTree CreateTree(void)
{
	BinTree T;
	T=(BinTree)malloc(sizeof(*T));
	T->IsEmpty=1;
	T->Tree=NULL;
	return T;
}
BinaryTree makeEmpty(BinaryTree T)
{
	if(T!=NULL)
	  {
	  	makeEmpty(T->Left);
	  	makeEmpty(T->Right);
	  	free(T);
	  }
	  return NULL;
}
void MakeEmpty(BinTree T)
{
	T->Tree=makeEmpty(T->Tree);
	T->IsEmpty=1;
}
Position find(ElementType X,BinaryTree T)
{
	while(T!=NULL&&T->Element!=X)
	{
		if(X>T->Element)
		T=T->Right;
		else 
		  T=T->Left;
	}
	return T;
}
Position Find(ElementType X,BinTree T)
{
	return find(X,T->Tree);
}
Position findMax(BinaryTree T)
{
	while(T!=NULL&&T->Right!=NULL)
	T=T->Right;
	return T;     
}
Position FindMax(BinTree T)
{
	return findMax(T->Tree);
}
Position findMin(BinaryTree T)
{
	while(T!=NULL&&T->Left!=NULL)
	 T=T->Left;
	 return T;
}
Position FindMin(BinTree T)
{
	return findMin(T->Tree);
}
void insert(ElementType X,BinaryTree T)
{
	BinaryTree Temp;
     while(T!=NULL&&T->Element!=X)
     {
     	Temp=T;
     	if(T->Element>X)
     	T=T->Left;
     	else 
     	T=T->Right;
	 }
	 if(T==NULL)
	 {
	 T=(BinaryTree)malloc(sizeof(*T));
	 T->Element=X;
	 T->Left=NULL,T->Right=NULL;
	 Temp->Element>X?(Temp->Left=T):(Temp->Right=T);
	 }
	 
}
void Insert(ElementType X,BinTree T)
{
	if(T->IsEmpty)
	 {
	 	T->Tree=(BinaryTree)malloc(sizeof(*T->Tree));
	 	T->Tree->Element=X;
	 	T->Tree->Left=NULL;
	 	T->Tree->Right=NULL;
	 	T->IsEmpty=0;
	 }
	 else
     insert(X,T->Tree);
    
}
void delet(ElementType X,BinaryTree T)
{
	BinaryTree Temp;
    while(T!=NULL&&T->Element!=X)
    {
    	Temp=T;
    	if(T->Element>X)
    	T=T->Left;
    	else T=T->Right;
	}
	if(T==NULL)
	{
		printf("no element!\n");
		return;
	}
	else 
	{
		if(T->Left&&T->Right)//有两个儿子 
		{
			Temp=findMin(T->Right);
			T->Element=Temp->Element;
			delet(Temp->Element,T->Right);
		}
		else 
		{
			
		if(T->Left)
		(Temp->Left==T?Temp->Left:Temp->Right)=T->Left;
		else 
		(Temp->Left==T?Temp->Left:Temp->Right)=T->Right;
		free(T);
    	}
	}
}
void Delete(ElementType X,BinTree T)
{
   if(T->IsEmpty)
   return;
   else 
   if((T->Tree->Left==NULL)&&(T->Tree->Right==NULL)&&(T->Tree->Element==X))
   {
   	free(T->Tree);
   	T->Tree=NULL;
   	T->IsEmpty=1;
   }
     
   else delet(X,T->Tree);
}
void printTree(BinaryTree T)
{
	if(T!=NULL)
	{
	printTree(T->Left);
	printf("%d ",T->Element);
	printTree(T->Right);	
	}		
}
void PrintTree(BinTree T)
{
	printTree(T->Tree);
}
