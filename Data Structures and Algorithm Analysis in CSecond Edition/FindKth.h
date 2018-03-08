#include<stdio.h>
#include<malloc.h>

#ifndef Tree_h

typedef int ELementType;
struct Node;
typedef struct Node *Tree;

ELementType FindMin(Tree T);
ELementType FindMax(Tree T);
Tree MakeEmpty(Tree T);
void Add1(Tree T);
void Sub1(Tree T);
Tree Insert(ELementType X,Tree T);
Tree Delete(ELementType X,Tree T);
ELementType FindKth(Tree T,int i);
void PrintTree(Tree T);

#endif


 struct Node
{
	ELementType Element;
	Tree Left;
	Tree Right; 
	int Order;
 };
ELementType FindMin(Tree T)
{
	if(T==NULL)
	printf("the Tree is Empty!\n");
	else if(T->Left)
	return FindMin(T->Left);
	else return T->Element;
}
ELementType FindMax(Tree T)
{
		if(T==NULL)
	printf("the Tree is Empty!\n");
	else if(T->Right)
	return FindMax(T->Right);
	else return T->Element;
 } 
Tree MakeEmpty(Tree T)
{
	if(T!=NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T); 
	}
	return NULL;
}
void Add1(Tree T)
{
	if(T)
	{
	Add1(T->Left);
	Add1(T->Right);
	T->Order+=1;	
	}
}
void Sub1(Tree T)
{
	if(T)
	{
		Sub1(T->Left);
		Sub1(T->Right);
		T->Order-=1;
	}
}
Tree Insert(ELementType X,Tree T)
{
	if(T==NULL)
	{
		T=(Tree )malloc(sizeof(*T));
		if(T==NULL) 
		{
			printf("out of space!\n");
			return NULL;
		}
		T->Element=X;
		T->Order=0;
		T->Left=T->Right=NULL; 
	}
	else
      if(X>T->Element)
      { 
      if(!T->Right)
      { 
      	T->Right=Insert(X,T->Right);
      	T->Right->Order=T->Order+1;
		  }
		  else
		   T->Right=Insert(X,T->Right);
	  }
	  else 
	  if(X<T->Element)
	  {
      T->Order=T->Order+1;
      if(!T->Left)
      {
      T->Left=Insert(X,T->Left);
	  T->Left->Order=T->Order-1;
	  }
	  else 
	  T->Left=Insert(X,T->Left);
         Add1(T->Right);
	  }
	  return T;
}
Tree Delete(ELementType X,Tree T)
{
	ELementType Y;
	if(T==NULL)
	{
		printf("there is no this Element!\n");
		return NULL;
	}
	else if(T->Element>X)
	{
		T->Left=Delete(X,T->Left);
		T->Order-=1;
		Sub1(T->Right);
	}
	else if(T->Element<X)
		T->Right=Delete(X,T->Right);
	else if(T->Element==X)
	{
		if(T->Right)
		{
			Y=FindMin(T->Right);
			T->Element=Y;
			T->Right=Delete(Y,T->Right);
		}
		else 
		T=T->Left;
 }
 return T;
}
ELementType FindKth(Tree T,int i)
{
	static int j=i-1;
	if(!T) 
	printf("The Tree's Elements are not enough.\n");
	else
	{
		if(j>T->Order)
         return FindKth(T->Right,j);
		 else if(j<T->Order)
		 return FindKth(T->Left,j);
		 else return T->Element;		
	}
} 
void PrintTree(Tree T)
{
	if(T)
	{
		printf("%d %d\n",T->Element,T->Order);
		PrintTree(T->Left);
		PrintTree(T->Right);
	}
}
