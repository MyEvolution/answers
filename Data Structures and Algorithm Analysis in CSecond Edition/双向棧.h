#ifndef double_stack_h


#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000
typedef int ElementType;

typedef struct 
{
	ElementType *base;
	ElementType *top;
}stack,*Stack;
void CreateStack(Stack *S1,Stack *S2,int MaxSize);
void MakeEmpty(Stack S);
int IsEmpty(Stack S);
void Push(ElementType X,Stack S1,Stack S2);//把X放到S1里 
ElementType Top(Stack S);
void Pop(Stack S1,Stack S2);
void PrintStack(Stack S1,Stack S2);

#endif
 
void CreateStack(Stack *S1,Stack *S2,int MaxSize)
{
	ElementType *P;
	(*S1)=(Stack)malloc(sizeof(**S1));
	(*S2)=(Stack)malloc(sizeof(**S2));
	P=(ElementType*)malloc(MaxSize*sizeof(ElementType));
	if(P==NULL)
	  {
	  	printf("out of space!\n");
	  	return;
	  }
	(*S1)->base=(*S1)->top=P;
	(*S2)->base=(*S2)->top=P+MaxSize-1;
	MakeEmpty(*S1);
	MakeEmpty(*S2);
}
void MakeEmpty(Stack S)
{
	if(S==NULL)
    S->top=S->base;
	*S->top=-1;
}
int IsEmpty(Stack S)
{
	return S->base==S->top&&*S->base==-1;
}
int IsFull(Stack S1,Stack S2)
{
	return (S1->top+1==S2->top)||(S1->top-1==S2->top);
 } 
void Push(ElementType X,Stack S1,Stack S2)//把X放到S1里 
{
	if(IsFull(S1,S2))
    printf("The Stack is full!\n");
    else
    {
    	if(S1->base<S2->base)//s1是以数组头为底的
		{
			if(IsEmpty(S1))
			  *S1->top=X;
			  else 
			    *++S1->top=X;
		 } 
		 else
		 {
		 	if(IsEmpty(S1))
		 	 *S1->top=X;
		 	 else
		 	   *--S1->top=X;
		 }
	}
}
ElementType Top(Stack S)
{
	return *S->top;
}
void Pop(Stack S1,Stack S2)
{
	if(S1->base<S2->base)
	{
	  if(S1->top==S1->base)
	    *S1->top=-1;	
		else
			S1->top--;
			
	}
	else
	{
		if(S1->top==S1->base)
	    *S1->top=-1;	
		else
			S1->top++;
	}
	    
}
void PrintStack(Stack S1,Stack S2)
{
	ElementType *P;
	P=S1->top;
	if(S1->base<S2->base)
	
		while(P>=S1->base)
		{
		 printf(P==S1->base?"%d\n":"%d ",*P);
		 P--;
	 
		}
		else
		
			while(P<=S1->base)
			{
						 printf(P==S1->base?"%d\n":"%d ",*P);
		                      P++;
			}
		
	
}
