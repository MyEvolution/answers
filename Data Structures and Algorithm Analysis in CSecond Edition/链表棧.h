#include<stdio.h>
#include<stdlib.h>
#ifndef _Stack_h
typedef double ElementType;
struct Node{
	struct Node *next;
	ElementType element;
};
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
 
int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X,Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
#endif

int IsEmpty(Stack S)
{
	return S->next==NULL;
}
Stack CreateStack(void)
{
	Stack S;
	S=(Stack )malloc(sizeof(struct Node));
	if(S==NULL)
	{
		printf("out of space!\n");
		exit(0);
	}
	S->next=NULL;
	MakeEmpty(S);
	return S;
}
void MakeEmpty(Stack S)
{
	if(S==NULL)
	{
		printf("Must use createstack first\n");
		return ;
	}
	else 
	   while(!IsEmpty(S))
	     Pop(S);
}
void Pop(Stack S)
{
    Stack p;
    
	if(!IsEmpty(S))
	{
	  p=S->next;
	  S->next=p->next;
	  free(p);
	}
	else 
	 {
      printf("Empty\n");
	 }
  
 }
 void Push(ElementType X,Stack S)
 {
 	Stack n;
 	n=(Stack)malloc(sizeof(struct Node));
 	if(n==NULL)
 	{
 		printf("out of space\n");
 		return ;
	 }
	 n->element=X;
    n->next=S->next;
    S->next=n;
    
 }
 ElementType Top(Stack S)
 {
 	if(!IsEmpty(S))
 	return S->next->element;
 	else 
 	{
 	printf("stack is empty!\n");
	 	return -1;
	 }
	 
 }	
 ElementType TopAndPop(Stack S)
 {
 	Stack S1;
	 ElementType e;
 	if(!IsEmpty(S))
 	{
 		S1=S->next;
 		e=S1->element;
 		S->next=S1->next;
 		free(S1);
 		return e;
	 }
	 else 
	 {
	 	printf("Empty!\n");
	 	return 0;
	 }
 }
