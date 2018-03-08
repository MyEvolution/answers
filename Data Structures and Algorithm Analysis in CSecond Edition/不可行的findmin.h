#include<stdio.h>
#include<stdlib.h>
#ifndef min_stack_h

typedef int ElementType;
typedef ElementType* Position;
struct Node;
typedef struct Node *Stack;
struct Node
{
	Position min;
	/*
	����ʵ��������һ��ָ���ע��Сֵ�ǲ���ʵ�ģ�
	��Ϊ�����Сֵ��ջ���޷���O(1)�ҵ���Сֵ
	*/ 
	ElementType *base;
	ElementType *top;
	ELementType *array;
	int stacksize;
};
Stack Create(int MaxElements);
void MakeEmpty(Stack S);
int IsEmpty(Stack S);
int IsFull(Stack S);
void Pop(Stack S);
void Push(Stack S);
Postiont FindMin(Stack S);
void PrintfStack(Stack S);

#endif
Stack Create(int MaxElements)
{
	Stack S;
	S=(Stack)malloc(sizeof(*S));
	if(S==NULL)
	{
		printf("out of space!\n");
		return NULL;
	}
	S->array=(ELementType*)malloc(MaxElements*sizeof(ElementType));
	if(S->array==NULL)
	{
		printf("out of space!\n");
		return NULL;
	}
	S->stacksize=MaxElements;
	MakeEmpty(S);
	return S;
}
void MakeEmpty(Stack S)
{
	S->top=S->min=S->base;
}
int IsEmpty(Stack S)
{
	return S->base==S->top;
}
int IsFull(Stack S)
{
	return S->top-S->base+1==S->stacksize;
}
Position FindMin(Stack S)
{
	return S->min;
}

