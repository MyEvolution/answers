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
 	int Order;//表示他是第几个最小值 
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
         if((*T)->Left!=NULL&&(*T)->Right!=NULL)//有两个结点的 
           {                               //找到其左子树最小的结点  把t的位置替换为他 
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
int NumOfNode(BinaryTree T)//实际上就是把树进行遍历，每遍历一个节点就把个数加1 
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
int IsSimilar(BinaryTree T1,BinaryTree T2)//判断两颗树是否相似 
{
	if(T1==NULL||T2==NULL)//如果有一个为空 则 返回是否两个都为空 
	return T1==NULL&&T2==NULL; 
	return IsSimilar(T1->Left,T2->Left)&&IsSimilar(T1->Right,T2->Right);//否则看其他树枝是否都存在 
}
int Isomorphic(BinaryTree T1,BinaryTree T2)//判断两树是否同构 
{
	if(T1==NULL||T2==NULL)//有个问题 就是在二查查找树时  同构只有两棵树相同的情况 
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
