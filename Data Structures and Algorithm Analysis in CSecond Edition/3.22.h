#include<stdio.h>
#include<stdlib.h>
#ifndef min_stack_h

typedef int ElementType;
struct Node;
typedef struct Node *Stack; 

/*
����ҵ��뷨��һ�����������������
��һ�����鴢�����е�Ԫ��
�ڶ������鴢����СԪ��
Ҳ�����������һ��Ԫ�ؽ�С��Ԫ�� ������������СԪ�ص�����Ԫ�ض����洢��������
������Ķ����ǵ�ǰ������СԪ��
����5 3 9 6 7
����������� 5 3
�ڗ���֮ǰ һֱ����СԪ�� 
*/ 

struct Node
{
ElementType *array;
	ElementType *top;
	ElementType *base;
	ElementType *maymin;
	int min;//��¼��Сֵ��λ��
	int StackSize;//���Ĵ�С 
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
        if(X<=S->maymin[S->min-1])//Ϊʲô����ҲҪ�Ž�ȥ�أ�����Ϊ��Pop��ʱ�򷽱� 
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
