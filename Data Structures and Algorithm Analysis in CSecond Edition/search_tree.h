#include<stdio.h>
#include<stdlib.h>

#ifndef _Tree_H

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
typedef int ElementType;
SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X,SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X,SearchTree T);
SearchTree Delete(ElementType X,SearchTree T);
ElementType Retrieve(Position P);
void PrintRange(ElementType Lower,ElementType Upper,SearchTree T);

#endif

struct TreeNode
{
	ElementType Element;
	SearchTree Left;
	SearchTree Right;
};
SearchTree MakeEmpty(SearchTree T)
{
	if(T!=NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}
Position Find(ElementType X,SearchTree T)
{
	if(T==NULL)
	return NULL;
	else
	 if(T->Element>X)
	 return Find(X,T->Left);
	 else if(T->Element<X)
	 return Find(X,T->Right);
	 else return T;
	 
}
Position FindMin(SearchTree T)
{
	SearchTree t=T;
	if(t==NULL)
	return NULL;
	while(t->Left!=NULL)
	t=t->Left;
	return t;
	
}
Position FindMax(SearchTree T)
{
	SearchTree t=T;
	if(t==NULL)
	return NULL;
	else if(t->Right==NULL)
	 return t;
	 else
	 return FindMax(t->Right);
}
SearchTree Insert(ElementType X,SearchTree T)
{
	if(T==NULL)
	{
		T=(SearchTree )malloc(sizeof(*T));
		T->Element=X;
		T->Left=NULL;
		T->Right=NULL;
	
	}
	else
	if(T->Element>X)
	T->Left=(X,T->Left);//�����Ǳ�Ҫde
	//����ԭ����˵  ��������ı�ָ���ָ��  ֻ�ǿ��Ըı��ַ
	//�������û����һ��  ʵ���ϲ�û�н�Ԫ����ӵ������� 
	// ��Ϊָ���ָ��û�иı�  ����ԭ���Ŀ� 
	else if(T->Element<X)
	T->Right=(X,T->Right);
	//�������  ʲôҲ���� 
	return T;
	
}
SearchTree Delete(ElementType X,SearchTree T)
{
	SearchTree t;
	if(T==NULL)
	printf("error:the tree is empty!\n");
    if(X>T->Element)
    T->Right=Delete(X,T->Right);
    else if(X<T->Element)
    T->Left=(X,T->Left);
    else
    if(T->Left&&T->Right)
    {
    	t=FindMin(T->Right);
    	T->Element=t->Element;
        T->Right=Delete(t->Element,T->Right);//һ����Ҷ�ӽڵ� 
    	
	}
	else//ֻ��һ���ӽڵ����û���ӽڵ� 
      {
      	if(T->Left)
      	{
      		t=T;
      	T=T->Left;	
      	free(t);
		  }
		  else if(T->Right)
		  {
		  	t=T;
		  	T=T->Right;
		  	free(t);
		  }
		  else
		  {
		  	free(T);
		  	T=NULL;
		  }
      	
	  }
	  return T;
}
void PrintRange(ELementType Lower,ElementType Upper,SearchTree T)
{
	//ʱ�临�Ӷ�����󣿣��� 
	if(T!=NULL)
	{
		if(T->Element>Upper)
		PrintRange(Lower,Upper,T->Left);
		else if(T->Element<Lower)
		PrintRange(Lower,Upper,T->Right);
		else if(T->Element>=Lower&&T->ELement<=Upper)
		{
	        	if(T->Element!=Lower)
			PrintRange(Lower,Upper,T->Left);
				printf("%d ",T->Element);
				if(T->Element!=Upper)
			PrintRange(Lower,Upper,T->Right);
		}
	/*
	if(T!=NULL)
	{
	if(Lower<T->Element)
	PrintRange(Lower,Upper,T->Left);
	if(T->Element>=Lower&&T->ELement<=Upper)
	PrintLine(T->Element);
	if(Upper>T->Element)
	PrintRange(Lower,Upper,T->Right);
}*/
/*����Ϊ�����㷨��ʱ�临�Ӷ���һ���� 
��Ϊ���ǵı�����һ����   
������д���㷨��˵  �����������  ȥ����Ӧ������ȥѰ��  
����ڽ���֮��   �����������Խ��б���Ѱ��  ���Ǹ��ݹؼ��ִ�С ���� ����ÿ�ο����ų�һ��
���ϵ��㷨�� ����������С�Ľ���  �Ͷ����С���ǲ��ֲ���  С������ �Ͷ���Ľϴ󲿷ֲ���  
���м�ͻ��ӡ
���� �����ø�������������
��� ���м�   �ҵ��㷨�ǻ�������α���  �ֱ���T��ߺ��ұ�
����Ҳ��
����������  ��ɨ���С��
С����С  ɨ��ϴ��
�������ϵ��㷨 ��һ���Ϊ������
���ڵ��ڵ� ��ֻ���  �㲻�ᴦ���� 
�ҵ���Ҫ�Ӹ��ж�  ʵ�ʱ���Ҳû��̫�������� 
*/	
}
