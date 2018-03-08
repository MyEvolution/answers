#ifndef Tree_with_coor_h

#include<stdio.h>
#include<stdlib.h>
 
struct TreeNode;
struct QNode; 
typedef int ELementType;
typedef struct TreeNode *SearTree; 
typedef struct TreeNode *Position;

struct TreeNode
{
	SearTree Left;
	SearTree Right;
	ELementType ELement;
	int X;//������ 
	int Y;//������ ,ʵ��������������� 
	int depth;//��� 
};
typedef struct QNode
{
	Position Tree;//����������ŵ���ָ������ָ�� 
	struct QNode *Next;//ָ����һ���ڵ��ָ�� 
}*QPosition;
typedef  struct queue
{
	struct QNode *Tail;
	struct QNode *Front; 
 }*Queue;

SearTree MakeEmpty(SearTree T);
SearTree Insert(ELementType X,SearTree T,int Depth);
SearTree Delete(ELementType X,SearTree T);
SearTree FindMin(SearTree T);
SearTree FindMax(SearTree T);
void GetX(SearTree T);
void GetY(SearTree T);
void PrintByFloor(SearTree T,Queue Q);//�������
Queue CreateQueue(void);
void EnQueue(SearTree T,Queue Q);
SearTree DeQueue(Queue Q);
int IsEmpty(Queue Q);
void PrintQueue(Queue Q);
#endif




SearTree MakeEmpty(SearTree T)
{
	if(T!=NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}
SearTree Insert(ELementType X,SearTree T,int Depth)//�����Depthָ���Ǹ����� ��� Ҳ���� 0 
{

	if(T==NULL)
	{
		T=(SearTree )malloc(sizeof(*T));
		if(T==NULL) printf("out of space!\n");
		else
		{
			T->ELement=X;
			T->Left=NULL;
			T->Right=NULL;
			T->depth=Depth;
		}}
	else if(T->ELement>X)
      T->Left=Insert(X,T->Left,Depth+1);
	  else if(T->ELement<X)
	  T->Right=Insert(X,T->Right,Depth+1);
	  return T; 
}
SearTree Delete(ELementType X,SearTree T)
{
	SearTree Temp;
	if(T==NULL)
	printf("û���Ԫ�أ�\n");
	else if(T->ELement>X)
	T->Left=Delete(X,T->Left);
	else if(T->ELement<X)
	T->Right=Delete(X,T->Right);
	else //�ҵ���X 
	{
		if(T->Left&&T->Right)
		{
			Temp=FindMin(T->Right);
			T->ELement=Temp->ELement;
			Delete(Temp->ELement,T->Right);
		}
		else 
			if(T->Left)
			{
			T=T->Left;
			T->Left->depth--;
			}
			else
			{
				T=T->Right;
				if(T->Right)
				T->Right->depth--;
			}
	}
}
SearTree FindMin(SearTree T)
{
	if(T!=NULL&&T->Left!=NULL)
	return FindMin(T->Left);
	return T;
}
SearTree FindMax(SearTree T)
{
	if(T!=NULL&&T->Right!=NULL)
	return FindMax(T->Right);
	return T;
}
void GetX(SearTree T)
{
	static int i=1;
	if(T!=NULL)
	{
		GetX(T->Left);
		T->X=i++;
		GetX(T->Right);
	}
}
void GetY(SearTree T)
{
	if(T!=NULL)
	{
		GetY(T->Left);
		T->Y=T->depth;
		GetY(T->Right);
	}
}
void PrintTree(SearTree T)
{
	if(T!=NULL)
	{
		PrintTree(T->Left);
		printf("(%d,%d) %d\n",T->X,T->Y,T->ELement);
		PrintTree(T->Right);
	}
}
Queue CreateQueue(void)
{
   QPosition q;
   Queue Q;
   q=(QPosition)malloc(sizeof(*q));
   q->Next==NULL;
    Q=(Queue )malloc(sizeof(*Q));
    Q->Front=Q->Tail=q;
    return Q;
}
int IsEmpty(Queue Q)
{
	return Q->Front==Q->Tail; 
}
void EnQueue(SearTree T,Queue Q)//��Ӳ��� 
{
	QPosition q;
	q=(QPosition )malloc(sizeof(*q));
	q->Tree=T;
	Q->Tail->Next=q;
	Q->Tail=q; 	
	Q->Tail->Next=NULL;
}
void makeEmpty(Queue Q)
{
	while(!IsEmpty(Q))
	   DeQueue(Q); 
}
SearTree DeQueue(Queue Q)
{
	QPosition q; 
	SearTree t; 
	if(!IsEmpty(Q))
	{
		if(Q->Front->Next==Q->Tail)
		{
			t=Q->Tail->Tree;
			free(Q->Tail);
			Q->Tail=Q->Front;
			Q->Tail->Next=NULL;
			 
		}
   else
   {
   q=Q->Front->Next;
	Q->Front->Next=q->Next;
	t=q->Tree; 
	free(q);
	   }	
	return t;
	}
	printf("the Queue is Empty!\n");
	return NULL;
 }
void enQueue(SearTree T,Queue Q)
{	
	  if(T!=NULL)
	{
		if(T->Left)
			EnQueue(T->Left,Q);	
		if(T->Right)
			EnQueue(T->Right,Q);

		
	}
} 
void PrintByFloor(SearTree T,Queue Q)//������� 
{
	 
      SearTree t;
       makeEmpty(Q);//��Q�ƿ� 

      if(T!=NULL) 
      EnQueue(T,Q);
     while(!IsEmpty(Q))
     {	
     	t=DeQueue(Q);	
     	enQueue(t,Q);	
     	printf("%d ",t->ELement);
     	
	 }	 
}
void PrintQueue(Queue Q)
{
	if(IsEmpty(Q))
		return;
	QPosition q;
	q=Q->Front->Next;
	while(q!=NULL)
	{
		printf("%d ",q->Tree->ELement);
		q=q->Next;
	 } 
}
