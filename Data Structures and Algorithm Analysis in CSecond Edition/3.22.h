#include<stdio.h>
#include<stdlib.h>
#ifndef min_stack_h

typedef int ElementType;
struct Node;
typedef struct Node *Stack; 

/*
这次我的想法是一个棧里包含两个数组
第一个数组储存所有的元素
第二个数组储存最小元素
也就是相对于上一个元素较小的元素 这样可能是最小元素的所有元素都被存储在数组里
切数组的顶端是当前棧的最小元素
比如5 3 9 6 7
存入数组的有 5 3
在棧空之前 一直有最小元素 
*/ 

struct Node
{
ElementType *array;
	ElementType *top;
	ElementType *base;
	ElementType *maymin;
	int min;//记录最小值的位置
	int StackSize;//棧的大小 
};
Stack Create(int MaxElements);
void MakeEmpty(Stack S);
int IsEmpty(Stack S);
int IsFull(Stack S);
ElementType FindMin(Stack S);
void Pop(Stack S);
void Push(ElementType X,Stack S);
void PrintStack(Stack S);

#endif

Stack Create(int MaxElements)
{
	Stack S;
	S=(Stack )malloc(sizeof(*S));
	if(S==NULL)
	{
		printf("out of space!\n");
		return NULL;
	}
	S->array=(ElementType*)malloc((MaxElements+1)*sizeof(ElementType));
	if(S->array==NULL)
	{
		printf("out of space!\n");
		return NULL;
	}
	S->top=S->base=S->array;
	S->maymin=(ElementType*)malloc((MaxElements+1)*sizeof(ElementType));
	if(S->maymin==NULL)
	{
		printf("out of space!\n");
		return NULL;		
	}
	S->StackSize=MaxElements;
	MakeEmpty(S);
	return S;
}
void MakeEmpty(Stack S)
{
	S->min=0;
	S->top=S->base;

}
int IsEmpty(Stack S)
{
	return S->top==S->base;
}
int IsFull(Stack S)
{
	return S->top-S->base==S->StackSize;
}
void Push(ElementType X,Stack S)
{
	*S->top++=X;
	if(S->min==0)
	S->maymin[S->min++]=X;
	else
        if(X<=S->maymin[S->min-1])//为什么等于也要放进去呢？就是为了Pop的时候方便 
          S->maymin[S->min++]=X;
	
}
void Pop(Stack S)
{
	if(!IsEmpty(S))
	{
	   if(S->maymin[S->min-1]==*(S->top-1))
	     S->min--;

      S->top--;
	}
	else
	{
		printf("The is stack is Empty!\n");
		return;
	}
}
ElementType FindMin(Stack S)
{
	return S->maymin[S->min-1];
}
void PrintStack(Stack S)
{
	ElementType *P;
	P=S->top-1;
	while(P>=S->base)
	{
		printf(S->base==P?"%d\n":"%d ",*P);
		P--;
	}
	 

}
