#ifndef _splay_tree_h

#include<stdlib.h>
#include<stdio.h>

struct TreeNode;
typedef int ElementType;
typedef struct TreeNode *SplTree;
typedef struct TreeNode *Position;

SplTree MakeEmpty(SplTree T);
SplTree FindMin(SplTree T);
SplTree FindMax(SplTree T);
SplTree Find(ElementType X,SplTree T);
SplTree Insert(ElementType X,SplTree T);
SplTree Delete(ElementType X,SplTree *T);
void PrintTree(SplTree T);
SplTree SingleRight(SplTree T);
SplTree SingleLeft(SplTree T);
SplTree DSingleRight(SplTree T);
SplTree DSingleLeft(SplTree T);
SplTree DoubleRight(SplTree T);
SplTree DoubleLeft(SplTree T);


#endif


struct TreeNode
{
	ElementType Element;
	SplTree Left;
	SplTree Right;
};
SplTree MakeEmpty(SplTree T)
{
	if(T!=NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}
/*Position find(ElementType X,SplTree T)
{
	  Position it=T;
      Position Father=T;
      Position GrandFather=T;
      if(it==NULL)
      return NULL;
      else
      while(it!=NULL&&it->Element!=X)//�õ�father ,�游 
      {
      	GrandFather=Father; 
      	Father=it;
      	if(X>it->Element)
      	it=it->Right;
      	else it=it->Left;
	  }
	 if(it==NULL)
	 return NULL;
	   else if(it==Father)
	   return it;
	   else if(GrandFather==Father)
	   return Father;
	   else return GrandFather;    
}*/ 
Position Find(ElementType X,SplTree T)
{
	static int i=0; //�����Ҫ��¼��ת����  ֻҪ�趨һ����̬���� ��ÿ����ת��ʱ��������1 �����ʵ�� 
	static SplTree root=T;
     if(T==NULL)
     printf("û���Ԫ�أ�\n");
     else if(X>T->Element)
       {	
       if(T->Right&&T->Right->Element==X)
       	T=SingleRight(T);
       	else if(T->Right->Right&&T->Right->Right->Element==X)
       		T=DSingleRight(T);
		else if(T->Right->Left&&T->Right->Left->Element==X)
		     T=DoubleRight(T);
       	 else 
       	{
       		T->Right=Find(X,T->Right);
       		if(T==root)
       		T=Find(X,T);
       		else if(T->Right&&T->Right->Right&&T->Right->Right->Element==X)
       		T=DSingleRight(T);
       		else if(T->Right&&T->Right->Left&&T->Right->Left->Element==X)
       		T=DoubleRight(T);
       		else if(T->Left&&T->Left->Left&&T->Left->Left->Element==X)
       		T=DSingleLeft(T);
       		else if(T->Left&&T->Left->Right&&T->Left->Right->Element==X)//��ô���ж�  ֻ��Ϊ�����Ч�� 
       		T=DoubleLeft(T);                   //ֻҪ��һ��Ϳ��ԣ�����ص����ڵ��ʱ�� ���ٴλ�������  ���ҽ�����ת 
		   }                                    //���������Ļ�Ч�ʺܵ� ��Ϊÿ�ζ�Ҫ�ص����ڵ�  �ٻ�ȥ������ 
			                                    //���Բ�һ������̾��Ǻõ�   
	   }
	   else if(X<T->Element)
	   {
	   if(T->Left&&T->Left->Element==X)
       	T=SingleLeft(T);
       	else if(T->Left->Left&&T->Left->Left->Element==X)
       		T=DSingleLeft(T);
		else if(T->Left->Right&&T->Left->Right->Element==X)
		     T=DoubleLeft(T);
       	 else 
       	{
       		T->Left=Find(X,T->Left);
       		if(T==root)
       		T=Find(X,T);
       		else if(T->Right&&T->Right->Right&&T->Right->Right->Element==X)
       		T=DSingleRight(T);
       		else if(T->Right&&T->Right->Left&&T->Right->Left->Element==X)
       		T=DoubleRight(T);
       		else if(T->Left&&T->Left->Left&&T->Left->Left->Element==X)
       		T=DSingleLeft(T);
       		else if(T->Left&&T->Left->Right&&T->Left->Right->Element==X)
       		T=DoubleLeft(T);
		   }

	   }
	   return T;
}
Position FindMin(SplTree T)
{
	if(T==NULL||T->Left==NULL)
	return T;
	else return FindMin(T->Left);
}
Position FindMax(SplTree T)
{
	if(T==NULL||T->Right==NULL)
	return T;
	else return FindMax(T->Right);
}
SplTree SingleLeft(SplTree T)
{
	SplTree t=T->Left;
	T->Left=t->Right;
	t->Right=T;
	return t;
}
SplTree SingleRight(SplTree T)
{
	SplTree t=T->Right;
	T->Right=t->Left;
	t->Left=T;
	return t;
}
SplTree DoubleLeft(SplTree T)
{
	SplTree t=T->Left;
	T->Left=SingleRight(t);
	return SingleLeft(T);
}
SplTree DoubleRight(SplTree T)
{
	SplTree t=T->Right;
	T->Right=SingleLeft(t);
	return SingleRight(T);
}
SplTree DSingleLeft(SplTree T)
{
    T=SingleLeft(T);
    return SingleLeft(T);
}
SplTree DSingleRight(SplTree T)
{
	T=SingleRight(T);
	return SingleRight(T);
}
SplTree Insert(ElementType X,SplTree T)
{
	if(T==NULL)
	{
	T=(SplTree )malloc(sizeof(*T));
	if(T==NULL)
	printf("out of space!\n");
	else
	 {
	 	T->Element=X;
	 	T->Left=NULL;
	 	T->Right=NULL;
		 }	
	}
	else if(T->Element>X)
	T->Left=Insert(X,T->Left);
	else if(T->Element<X)
	T->Right=Insert(X,T->Right);
	return T;
}
SplTree Delete(ElementType X,SplTree *T)
{
	SplTree t;
	ElementType x;
    *T=Find(X,*T);
    x=(FindMax((*T)->Left))->Element;
    (*T)->Left=Find(x,(*T)->Left);
    (*T)->Left->Right=(*T)->Right;
    t=(*T);
    (*T)=(*T)->Left;
    free(t);
    return (*T);
}
void PrintTree(SplTree T)
{
	if(T!=NULL)
	{
	printf("%d ",T->Element);
	PrintTree(T->Left);	
	PrintTree(T->Right);	
	}
}
