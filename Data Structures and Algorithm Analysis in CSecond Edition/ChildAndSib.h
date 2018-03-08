#ifndef _tree_h

#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;
struct Node;
typedef struct Node *Position;
typedef struct Node *Tree;
struct QNode;
typedef struct QNode *queue;
struct QNode
{
	Tree tree;//指向树的指针 
	struct QNode *Next; 
 };
typedef struct 
{
	queue Front,Tail;
}duilie,*Queue;
 
struct Node
{
	ElementType Element;
	Tree FirstChild;//第一个孩子 
	Tree NextSibling;//下一个兄弟 
 };
 Queue CreateQueue(void);
 void EnQueue(Tree T,Queue Q);
 Tree DeQueue(Queue Q);
 int IsEmpty(Queue Q);
 Tree MakeEmpty(Tree T);
Tree Insert(ElementType X,Tree T);
 Position FindLastChild(Tree T);//找到T的最后一个儿子 
 void PrintTree(Tree T,Queue Q);
 
 
 #endif 

Queue CreateQueue(void)
{
	Queue Q;
	Q=(Queue )malloc(sizeof(*Q));
	queue q;
	q=(queue )malloc(sizeof(*q));
	Q->Front=Q->Tail=q;
	q->Next=NULL;
	return Q;
}
int IsEmpty(Queue Q)
{
	return Q->Front==Q->Tail; 
}
Tree DeQueue(Queue Q)
{
	if(!IsEmpty(Q))
	{
		if(Q->Front->Next==Q->Tail)
		{
			queue p;
			Tree t;
			p=Q->Tail;
			t=p->tree;
			free(p);
			Q->Tail=Q->Front;
			return t;
		}
		else
		{
			queue p;
			Tree t;
			p=Q->Front->Next;
			Q->Front->Next=p->Next;
			t=p->tree;
			free(p);
			return t;
		}
	}
	else
	printf("Empty!\n");
	return NULL; 
}
void EnQueue(Tree T,Queue Q)
{
	queue q;
	q=(queue)malloc(sizeof(*q));
	q->tree=T;
	Q->Tail->Next=q;
	Q->Tail=q;
	Q->Tail->Next=NULL;
 } 
Tree MakeEmpty(Tree T)
{
	if(T!=NULL)
	{
		MakeEmpty(T->FirstChild);
		MakeEmpty(T->NextSibling);
		free(T);
	}
	return NULL;
 } 
Position FindLastChild(Tree T)
{
	if(T==NULL||T->FirstChild==NULL)
	return NULL;
	else 
	{
		T=T->FirstChild;
		while(T->NextSibling!=NULL)
		T=T->NextSibling;
	   return T; 
	}
 } 
Tree Insert(ElementType X,Tree T)
 {
 	if(T==NULL)
 	{
 		T=(Tree)malloc(sizeof(*T));
 		T->Element=X;
 		T->FirstChild=T->NextSibling=NULL;
	 }
	 else 
	 {
	 	Tree t;
	 	t=FindLastChild(T);
	 if(t==NULL)
	 	T->FirstChild=Insert(X,t);
		 else
		 t->NextSibling=Insert(X,t->NextSibling);
	 	
	 }
	 return T;
	 
 }
void enQueue(Tree T,Queue Q)//把Q的孩子放入队列 
 {
 	if(T&&T->FirstChild)
 	{
 		T=T->FirstChild;
 		while(T!=NULL)
 		{
 			EnQueue(T,Q);
 			T=T->NextSibling; 
		 }
	 }
 }
 void PrintTree(Tree T,Queue Q)
 {
 	Tree t; 
 	if(T!=NULL)
 	EnQueue(T,Q);
 	while(!IsEmpty(Q))
	 {
	 	t=DeQueue(Q);
	 	printf("%c ",t->Element);
	 	enQueue(t,Q);
	  } 
 }
