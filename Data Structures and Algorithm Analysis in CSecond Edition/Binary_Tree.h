#ifndef _binary_tree_h

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct TreeNode;
typedef struct TreeNode *BinaryTree;
typedef struct TreeNode *Position;
typedef int ElementType;

BinaryTree MakeEmpty(BinaryTree *T);
BinaryTree Find(ElementType X,BinaryTree T);
BinaryTree FindMax(BinaryTree T);
BinaryTree FindMin(BinaryTree T);
BinaryTree Insert(ElementType X,BinaryTree *T);
BinaryTree Delete(ElementType X,BinaryTree *T);
void PrintTree(BinaryTree T);
int NumOfNode(BinaryTree T);
int NumOfLeaf(BinaryTree T);
int NumOfFullNode(BinaryTree T);

#endif


 struct TreeNode
 {
 	ElementType Element;
 	BinaryTree Left;
 	BinaryTree Right;
 	int Order;//��ʾ���ǵڼ�����Сֵ 
 };
BinaryTree MakeEmpty(BinaryTree tree)
{
	if(tree!=NULL)
	{
		MakeEmpty(tree->Left);
		MakeEmpty(tree->Right);
		free(tree);
	}
	return NULL;
 } 
 BinaryTree Find(ElementType X,BinaryTree T)
 {
 	if(T==NULL)
     return NULL;
 	 else 
 	 if(T->Element>X)
 	 return Find(X,T->Left);
 	 else if(T->Element<X)
 	 return Find(X,T->Right);
 	 else 
 	   return T;
 }
BinaryTree FindMax(BinaryTree T)
{
	if(T==NULL)
	 return NULL;
	 else if(T->Right==NULL)
	 return T;
	 else return FindMax(T->Right);	 
}
BinaryTree FindMin(BinaryTree T)
{
	if(T==NULL)
	return NULL;
	else
	   if(T->Left==NULL)
	   return T;
	   else return FindMin(T->Left);
}
BinaryTree Insert(ElementType X,BinaryTree *T)
{
	if(*T==NULL)
	{
		(*T)=(BinaryTree)malloc(sizeof(**T));
		if(*T==NULL)
		printf("out of space!\n");
         else
		 {
		 (*T)->Element=X;
         (*T)->Left=NULL;
         (*T)->Right=NULL;
		 }

	}
	else if(X>(*T)->Element)
	  (*T)->Right=Insert(X,&(*T)->Right);
	  else if(X<(*T)->Element)
	  (*T)->Left=Insert(X,&(*T)->Left);
	  return *T;
} 
BinaryTree Delete(ElementType X,BinaryTree *T)
{
	BinaryTree Temp;
	if(*T==NULL)
		printf("error:can't find this element!\n");
		else 
		if(X>(*T)->Element)
		(*T)->Right=Delete(X,&(*T)->Right);
		else if(X<(*T)->Element)
		(*T)->Left=Delete(X,&(*T)->Left);
		else 
		{
         if((*T)->Left!=NULL&&(*T)->Right!=NULL)//���������� 
           {                               //�ҵ�����������С�Ľ��  ��t��λ���滻Ϊ�� 
         	Temp=FindMin((*T)->Right);
         	(*T)->Element=Temp->Element;
         	(*T)->Right=Delete((*T)->Element,&(*T)->Right);
		 }
		 else
		 {
		 	Temp=*T;
		 	 if((*T)->Left==NULL)
		   (*T)=(*T)->Right;
		   else if((*T)->Right==NULL)
		   (*T)=(*T)->Left;
		   free(Temp);
		 }

		 
		}
	return *T;	
	
}

void PrintTree(BinaryTree T)
{
	if(T!=NULL)
	{
	PrintTree(T->Left);
	printf("%d ",T->Element);
	PrintTree(T->Right);	
	}	
}
int RandomInteger(int A,int B)
{
	int num;
	srand((unsigned)time(NULL));
	num=rand()%(B-A+1);
	return num+A;
}
int RandnumNotInTree(int A,int B,BinaryTree T)
{
	int num=RandomInteger(A,B);
	while(Find(num,T))
    num=RandomInteger(A,B);
    return num;
}
int RandnumInTree(int A,int B,BinaryTree T)
{
	int num=RandomInteger(A,B);
	while(!Find(num,T))
	num=RandomInteger(A,B);
	return num;
}
int NumOfNode(BinaryTree T)//ʵ���Ͼ��ǰ������б�����ÿ����һ���ڵ�ͰѸ�����1 
{
	static int num=0;
	if(T!=NULL)
	{
		num++;
	NumOfNode(T->Left);
	NumOfNode(T->Right);	
	}

	return num;
}
int NumOfLeaf(BinaryTree T)
{
	static int num=0;
	if(T!=NULL)
	{
		if(T->Left==NULL&&T->Right==NULL)
		num++;
		NumOfLeaf(T->Left);
		NumOfLeaf(T->Right);
	}
	return num;
}
int NumOfFullNode(BinaryTree T)
{
	static int num=0;
	if(T!=NULL)
	{
		if(T->Left&&T->Right)
		num++;
		NumOfFullNode(T->Left);
		NumOfFullNode(T->Right);
	}
	return num;
}
int IsSimilar(BinaryTree T1,BinaryTree T2)//�ж��������Ƿ����� 
{
	if(T1==NULL||T2==NULL)//�����һ��Ϊ�� �� �����Ƿ�������Ϊ�� 
	return T1==NULL&&T2==NULL; 
	return IsSimilar(T1->Left,T2->Left)&&IsSimilar(T1->Right,T2->Right);//����������֦�Ƿ񶼴��� 
}
int Isomorphic(BinaryTree T1,BinaryTree T2)//�ж������Ƿ�ͬ�� 
{
	if(T1==NULL||T2==NULL)//�и����� �����ڶ��������ʱ  ͬ��ֻ����������ͬ����� 
	return T1==NULL&&T2==NULL;
	else
	if(T1->Element==T2->Element)
	{
		return (Isomorphic(T1->Left,T2->Left)&&Isomorphic(T1->Right,T2->Right))
		||(Isomorphic(T1->Left,T2->Right)&&Isomorphic(T1->Right,T1->Left));
	}
	else return 0;
	 
 }
 ElementType FindKth(BinTree T,int i)
 {
  } 
