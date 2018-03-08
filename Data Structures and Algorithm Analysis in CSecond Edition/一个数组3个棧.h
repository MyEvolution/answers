#ifndef three_stack_h


#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10000

struct Node;
typedef struct Node *Stack;
typedef int ElementType;
void Create(Stack *s1,Stack *s2,Stack *s3,int MaxElements);//一个数组3个棧 ,最后是可以装的最多元素（三个棧的和）
int IsEmpty(Stack S);
int IsFull(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X,Stack S);
void Pop(Stack S);
void Print(Stack S);
void PrintWhole(Stack S,Stack S2,Stack S3);

#endif

struct Node
{
	ElementType *array;
	ElementType *base,*top;
	int StackSize;
};

void Create(Stack *s1,Stack *s2,Stack *s3,int MaxElements)
{
	(*s1)=(Stack )malloc(sizeof(**s1));
	(*s2)=(Stack )malloc(sizeof(**s1));
	(*s3)=(Stack )malloc(sizeof(**s1));
	int size;
	size=(MaxElements+2)/3*3+3;//使每个棧的容量相同，并且每个棧多出一个空间出来 
	if((*s1)==NULL||(*s2)==NULL||(*s3)==NULL)
	{
		printf("out of space!\n");
		return;
	}
	(*s1)->array=(ElementType*)malloc(size*sizeof(ElementType));
	if((*s1)->array==NULL)
	{
		printf("out of space!\n");
		return;
	}
	(*s1)->StackSize=size/3-1;
	(*s2)->StackSize=size/3-1;
	(*s3)->StackSize=size/3-1;
	(*s1)->top=(*s1)->base=(*s1)->array;
	(*s2)->top=(*s2)->base=(*s2)->array=(*s1)->array+1;
	(*s3)->top=(*s3)->base=(*s3)->array=(*s1)->array+2; 
}

void MakeEmpty(Stack S)
{
	S->top=S->base;
}
int IsEmpty(Stack S)
{
	return S->top==S->base;
}
int IsFull(Stack S)
{
	return (S->top+3)>=(S->top+S->StackSize);
}
void Pop(Stack S)
{
	if(!IsEmpty(S))
	S->top-=3;
	else
	{
		printf("the stack is empty!\n");
		return;
	}
}
void Push(ElementType X,Stack S)
{
	if(!IsFull(S))
	{
		*S->top=X;
		S->top+=3;
	}
	else
	{
		printf("the stack is full!\n");
		return;
	}
	
}
ElementType Top(Stack S)
{
	if(!IsEmpty(S))
	return *(S->top-3);
	printf("the stack is Empty!\n");
	return 0;
}
void Print(Stack S)
{
	ElementType *P;
	P=S->top-3;
	while(P>=S->base)
	{
		printf(P==S->base?"%d\n":"%d ",*P);
		P-=3;
	}
}
void PrintWhole(Stack s1,Stack s2,Stack s3)
{
   Print(s1);
   Print(s2);
   Print(s3);
}
