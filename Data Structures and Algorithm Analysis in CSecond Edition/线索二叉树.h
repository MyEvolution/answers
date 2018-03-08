#include<stdio.h>
#include<stdlib.h>

#ifndef threaded_binary_tree_h

typedef int ElementType;
struct Node;
typedef struct Node *TBTree;//���������� 
typedef TBTree Tree;//������������
//ʵ���������������Ľṹ��һ���� ֻ��Ϊ�����ֶ��� 

struct Node
{
	ElementType Element;
	TBTree Left,Right;
	int Ltag,Rtag;//���ֶ���ָ���е�����ָ�� 
};

int IsSingle(TBTree T);
TBTree MakeEmpty(TBTree T);
TBTree TInsert(ElementType X,TBTree T);//���������������� 
TBTree TDelete(ElementType X,TBTree T);//������������ɾ�� 
Tree Insert(ElementType X,Tree T);//��ͨ����������� 
Tree Delete(ElementType X,Tree T);//��ͨ��������ɾ�� 
ElementType FindMin(TBTree T);
ElementType Findmin(Tree T); 
void PrintTBree(TBTree T);
void MakeItToThreaded(Tree T); 
void PrintTree(Tree T);
void inOrderTravel(TBTree T);
TBTree PFindMin(TBTree T);//������СԪ�ص�λ�� 

#endif

int IsSingle(TBTree T)
{
   if((T->Ltag==0&&T->Left)||(T->Rtag==0&&T->Right))
   return 0;
   else return 1;
}
ElementType FindMin(TBTree T)
{
	if(T)
	{
		if(T->Ltag==0&&T->Left)
		return FindMin(T->Left); 
		else return T->Element; 
	}
}
TBTree TInsert(ElementType X,TBTree T)//��������������   ���Ԫ�� 
{
	int Y;
	TBTree t; 
	if(T==NULL)
	{
		T=(TBTree )malloc(sizeof(*T));
		T->Element=X;
		T->Left=T->Right=NULL;
		T->Ltag=T->Rtag=0; 
	}
	else
	{
		if(X<T->Element)
	   {
       if(T->Ltag==0&&T->Left)
       T->Left=TInsert(X,T->Left);
       else if(T->Ltag==1||T->Left==NULL)
       {
       	Y=T->Ltag;
       	t=T->Left; 
       	T->Ltag=0;
       	T->Left=NULL;
       	T->Left=TInsert(X,T->Left);
       	T->Left->Rtag=1;
       	T->Left->Right=T; //�������ߵ�  ���ĺ�����丸ĸ 
       	T->Left->Ltag=Y;//������Ҳ����Ҫ  ���ҿ��� 
       	T->Left->Left=t;//ˢ������ 
	   }
	   }
	   else if(X>T->Element)
	   {
	   	if(T->Rtag==0&&T->Right)
	   	T->Right=TInsert(X,T->Right);
		   else{//�ҵ���Ͳ���� 
		   Y=T->Rtag;
		   t=T->Right; 
		 	T->Rtag=0;
		 	T->Right=NULL;
		   T->Right=TInsert(X,T->Right);
		   T->Right->Ltag=1;
		   T->Right->Left=T;// ������ұߵ� ����ǰ�̱����丸ĸ 
		   T->Right->Rtag=Y;
		   T->Right->Right=t; 
		   
		   } 
	   }
	}
	return T;
}
TBTree TDelete(ElementType X,TBTree T)
{
	ElementType Y;
	TBTree t;
	if(T==NULL)
	{
		printf("there is no this ELement!\n");
		return NULL;
	}
	else
	if(T->Element>X)
	{
		if(T->Left&&T->Left->Element==X&&IsSingle(T->Left))
		  T->Ltag=T->Left->Ltag; 
			T->Left=TDelete(X,T->Left);
	}
		else if(X>T->Element)
		{
			if(T->Right&&T->Right->Element==X&&IsSingle(T->Right))
			T->Rtag=T->Right->Rtag;
				T->Right=TDelete(X,T->Right); 
		}		
		else 
		{
			if(T->Rtag==0&&T->Right)
			{
				Y=FindMin(T->Right);
				T->Element=Y; 
				T->Rtag=T->Right->Rtag;
				T->Right=TDelete(Y,T->Right); 
			}
			else if(T->Ltag==0&&T->Left)
			{
				t=T;
				T->Left->Rtag=T->Rtag;
				T->Left->Right=T->Right;
				T=T->Left;
				free(t);
			}
			else
			{
				t=T;
              if(T->Left->Right==t)
              T=T->Right;
              else if(T->Right->Left==t)
              T=T->Left;
              free(t);
			}			 
		}
	return T; 
}
void PrintTBree(TBTree T)
{
	if(T)
	{
		if(!T->Ltag&&T->Left)
		PrintTBree(T->Left);
		if(T->Ltag)
		printf("%d<-%d\n",T->Left->Element,T->Element);
		if(T->Rtag)
		printf("%d->%d\n",T->Element,T->Right->Element);
		if(!T->Ltag&&!T->Rtag)
		printf("%d\n",T->Element); 
		if(!T->Rtag&&T->Right)
		PrintTBree(T->Right);
	 } 
}
ElementType Findmin(Tree T)
{
	if(T)
	{
		if(T->Left)
		return Findmin(T->Left);
		else return T->Element; 
	}
	else
	printf("the tree is empty!\n");
}
Tree Insert(ElementType X,Tree T)
{
	if(T==NULL)
	{
		T=(Tree )malloc(sizeof(*T));
		T->Element=X;
		T->Left=T->Right=NULL; 
	 } 
	 else
	 if(X>T->Element)
	 T->Right=Insert(X,T->Right);
	 else if(X<T->Element)
	 T->Left=Insert(X,T->Left);
	 return T;
}
Tree Delete(ElementType X,Tree T)
{
	ElementType Y;
	if(T==NULL)
	{
		printf("there is no this Element in this tree!\n");
		return NULL;
	 } 
	 else
	 {
	 	if(T->Element>X)
	 	T->Left=Delete(X,T->Left);
	 	else if(T->Element<X)
	 	T->Right=Delete(X,T->Right);
	 	else 
	 	{
	 		if(T->Right)
	 		{
	 			T->Element=Y=Findmin(T->Right);
	 			T->Right=Delete(Y,T->Right);
			 }
			 else
			 T=T->Left;
		 }
	 }
	 return T;
}
void MakeItToThreaded(Tree T,Tree Front,Tree Rear)
{
   if(T->Element<Front->Element)
   Front=T;
   if(T->Element>Rear->Element)
   Rear=T;
   if(T->Left)
   T->Ltag=0,MakeItToThreaded(T->Left,Front,T);
   else if(Front==T)
   T->Left=NULL,T->Ltag=0;
   else
   T->Left=Front,T->Ltag=1;
   if(T->Right)
   T->Rtag=0,MakeItToThreaded(T->Right,T,Rear);
   else if(Rear==T)
   T->Right=NULL,T->Rtag=0;
   else 
   T->Right=Rear,T->Rtag=1; 
}
void PrintTree(Tree T)
{
	if(T)
	{
		PrintTree(T->Left);
		printf("%d\n",T->Element);
		PrintTree(T->Right);
	}
}
TBTree PFindMin(TBTree T)
{	
	if(T)
	{
		if(T->Ltag==0&&T->Left)
		return PFindMin(T->Left); 
		else return T; 
	}
	return NULL;
}
void inOrderTravel(TBTree T)
{
        T=PFindMin(T);
		printf("%d\n",T->Element);
       while(T->Right)
	   {
	   	if(T->Rtag)
	   	{
	   		T=T->Right;
	   		printf("%d\n",T->Element);
		   }
		   else
		   {
		   	T=PFindMin(T->Right);
		   	printf("%d\n",T->Element);
		   }
		} 
}
