#include<stdio.h>
#include<stdlib.h>
#ifndef _Stack_h
#define MinStackSize 100
typedef int ElemType;
struct StackRecord
{
	ElemType *array;
	int Stacksize;
	int TopOfSize;//栈顶的下标(空栈为-1） 
};
typedef struct StackRecord *Stack;

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack Create(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElemType,Stack S);
void Pop(Stack S);
ElemType Top(Stack S);
ElemType TopAndPop(Stack S);
#endif
int IsEmpty(Stack S)
{
return S->TopOfSize==-1;
 } 
int  IsFull(Stack S)
{
	return S->TopOfSize==S->Stacksize-1;
}
Stack Create(int MaxElements)
{
	Stack s;
	if(MaxElements<MinStackSize)
	 {
	 	printf("too small\n");
	 	exit(0);
	 }
	 s=(Stack)malloc(sizeof(struct StackRecord));
	 if(s==NULL)
	  {
	  	printf("out of space!\n");
	  	exit(0);
	  }
	s->array=(ElemType *)malloc(MaxElements*sizeof(ElemType));
	if(s->array==NULL)
	{
		printf("out of space!\n");
	  	exit(0);
	}
	s->Stacksize=MaxElements;
	MakeEmpty(s);
	return s;
}
void MakeEmpty(Stack S)
{
	S->TopOfSize=-1;
}
void Push(ElemType X,Stack S)
{
	if(!IsFull(S))
	S->array[++S->TopOfSize]=X;
	else 
	{
	printf("Full stack!\n");
	  	
	}
}
ElemType Top(Stack S)
{
	if(!IsEmpty(S))
	return S->array[S->TopOfSize];
	else 
	{
	printf("Empty!\n");
	  	return 0;
	}
}
void Pop(Stack S)
{
	if(!IsEmpty(S))
   S->TopOfSize--;
		else 
		{
			printf("Empty Stack\n");
			return;
		}
	
}
ElemType TopAndPop(Stack S)
{
	if(!IsEmpty(S))
	
		return S->array[S->TopOfSize--];
	else
	{
		printf("Empty Stack\n");
			return -1;
	}
}
