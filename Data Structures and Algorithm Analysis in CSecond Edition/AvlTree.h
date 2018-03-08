#ifndef _avl_tree_h

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct TreeNode;
typedef struct TreeNode *AvlTree;
typedef struct TreeNode *Position;
typedef int ElementType;

int Height(AvlTree T);
AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType X,AvlTree T);
Position FindMax(AvlTree T);
Position FindMin(AvlTree T);
AvlTree Insert(ElementType X,AvlTree *T);
AvlTree Delete(ElementType X,AvlTree *T);
AvlTree SingleLeft(AvlTree T);
AvlTree DoubleLeft(AvlTree T);
AvlTree SingleRight(AvlTree T);
AvlTree DoubleRight(AvlTree T);
void PrintTree(AvlTree T);
int RandInt(int A,int B);

#endif


struct TreeNode
{
	int Height;
	AvlTree Left;
	AvlTree Right;
	ElementType Element;
};
int Max(int a,int b)
{
	return a>b?a:b;
}
int Height(AvlTree T)
{
	if(T==NULL)
	return -1;
	else return T->Height;
}
AvlTree MakeEmpty(AvlTree T)
{
	if(T!=NULL)
	{
	 MakeEmpty(T->Left);
	 MakeEmpty(T->Right);
	 free(T);
	}
	return NULL;
}
Position Find(ElementType X,AvlTree T)
{
	if(T!=NULL&&T->Element!=X)
	  {
	  	if(X>T->Height)
	  	return Find(X,T->Right);
	  	else return Find(X,T->Left);
	  }
	  return T;
}
Position FindMax(AvlTree T)
{
	if(T!=NULL&&T->Right!=NULL)
	return FindMax(T->Right);
	return T;
}
Position FindMin(AvlTree T)
{
	while(T!=NULL&&T->Left!=NULL)
	T=T->Left;
	return T;
}
AvlTree Insert(ElementType X,AvlTree *T)
{
	if(*T==NULL)
	{
	
		(*T)=(AvlTree )malloc(sizeof(**T));
		if((*T)==NULL)
		{
			printf("out of space!\n");
			return NULL;
		}
		(*T)->Element=X;
		(*T)->Height=0;
		(*T)->Left=NULL;
		(*T)->Right=NULL;
		
	}
	else if((*T)->Element>X)
	{
		(*T)->Left=Insert(X,&(*T)->Left);
		if(Height((*T)->Left)-Height((*T)->Right)==2)
		{
			if(Height((*T)->Left->Left)>Height((*T)->Left->Right))
			(*T)=SingleLeft(*T);
			else 
			(*T)=DoubleLeft(*T);
		}
		(*T)->Height=Max(Height((*T)->Left),Height((*T)->Right))+1;
		
	}
	else if((*T)->Element<X)
	{
	   	(*T)->Right=Insert(X,&(*T)->Right);
		if(Height((*T)->Right)-Height((*T)->Left)==2)
		{
			if(Height((*T)->Right->Right)>Height((*T)->Right->Left))
			(*T)=SingleRight(*T);
			else 
			(*T)=DoubleRight(*T);
		}
		(*T)->Height=Max(Height((*T)->Left),Height((*T)->Right))+1;	
	    }
		return *T;	
}
AvlTree SingleLeft(AvlTree T)
{
	AvlTree T1;
	T1=T->Left;
	T->Left=T1->Right;
	T1->Right=T;
	T->Height=Max(Height(T->Right),Height(T->Left))+1;//很重要 节点的高度改变了
//可以实施的原因是他们的儿子的高度并没有改变
//我认为这就是高度的必要性  如果用深度形容  儿子的深度都会改变 （深度是到根节点的距离
 //   高度是到树叶的距离（最远的） 
	T1->Height=Max(Height(T1->Left),Height(T1->Right))+1;
	return T1;
}
AvlTree DoubleLeft(AvlTree T)
{
	AvlTree T1=T->Left;
	T->Left=SingleRight(T1);
	return SingleLeft(T);	
}
AvlTree SingleRight(AvlTree T)
{
	AvlTree T1;
	T1=T->Right;
	T->Right=T1->Left;
	T1->Left=T;
	T->Height=Max(Height(T->Right),Height(T->Left))+1;
	T1->Height=Max(Height(T1->Right),Height(T1->Left))+1;
	return T1;
}
AvlTree DoubleRight(AvlTree T)
{
	AvlTree T1=T->Right;
	T->Right=SingleLeft(T1);
	return SingleRight(T);
}
AvlTree Delete(ElementType X,AvlTree *T)
{
	if(T==NULL)
	  printf("this Element is not exist in this tree!\n");
	  else 
	  if((*T)->Element>X)
	  {
	  	(*T)->Left=Delete(X,&(*T)->Left);
      if(Height((*T)->Right)-Height((*T)->Left)==2)//一定要这样 写  而不能写成（*T）->left->Height;                                                         
      {                                               ////因为有可能t的左子树是空的  
      	if(Height((*T)->Right->Right)>Height((*T)->Right->Left))
      	(*T)=SingleRight((*T));
      	else (*T)=DoubleRight((*T));
	  }
	  	
	(*T)->Height=Max(Height((*T)->Left),Height((*T)->Right))+1;
	  	
	  }
	  else if((*T)->Element<X)
	  {
	  	(*T)->Right=Delete(X,&(*T)->Right);
      if(Height((*T)->Left)-Height((*T)->Right)==2)
      {
      	if(Height((*T)->Left->Left)>Height((*T)->Left->Right))
      	  (*T)=SingleLeft(*T);
      	  else
      	  (*T)=DoubleLeft(*T);
	  }
	  	(*T)->Height=Max(Height((*T)->Left),Height((*T)->Right))+1;
	  }
	  else
	  {
	  	Position Temp;
	  	if((*T)->Left&&(*T)->Right)
	  	{
	  	Temp=FindMin((*T)->Right);
	  	(*T)->Element=Temp->Element;
	  	(*T)->Right=Delete(Temp->Element,&(*T)->Right);
	  	(*T)->Height=Max(Height((*T)->Left),Height((*T)->Right))+1;
	  	
		  }
		  else 
		  {
		  	if((*T)->Left)
		  	(*T)=(*T)->Left;
		  	else (*T)=(*T)->Right;
		  	if(*T)
		  	(*T)->Height=Max(Height((*T)->Left),Height((*T)->Right))+1;
		  	else return NULL;
		  }
	  }
	  return *T; 
}
void PrintTree(AvlTree T)
{
	if(T!=NULL)
	{
		printf("Height:%d Element:%d\n",T->Height,T->Element);
		PrintTree(T->Left);
		PrintTree(T->Right);	
	}

	
}
AvlTree Rotate(AvlTree *Temp)
{
	if(Height((*Temp)->Left)-Height((*Temp)->Right)==2)
		{
			if(Height((*Temp)->Left->Left)>Height((*Temp)->Left->Right))
			(*Temp)=SingleLeft((*Temp));
			else
			(*Temp)=DoubleLeft((*Temp));
		}
		else if(Height((*Temp)->Right)-Height((*Temp)->Left)==2)
		{
			if(Height((*Temp)->Right->Right)>Height((*Temp)->Right->Left))
			(*Temp)=SingleRight((*Temp));
			else (*Temp)=DoubleRight((*Temp));
		}
         (*Temp)->Height=Max(Height((*Temp)->Left),Height((*Temp)->Right))+1;
         return *Temp;
	
}
AvlTree insert1(ElementType X,AvlTree T)//T不是空 
{
	AvlTree Temp=NULL;
	AvlTree Root1,Root2;
	AvlTree root=T;
	Root1=Root2=T;
	int He;//高度 
	while(T!=NULL&&T->Element!=X)
	{
		Temp=T;//此处记录T的父母 
	  if(T->Element>X)
	   T=T->Left;
     	else T=T->Right;
	}
	if(T==NULL)//找到了该插入的位置 如果不是空的话 说明该元素 已经存在在树中，对此我们不错任何处理。
    {
    	He=Temp->Height;
		T=(AvlTree)malloc(sizeof(*T));
		if(T==NULL)
		return NULL;
		T->Element=X;
		T->Left=NULL;
		T->Right=NULL;
		T->Height=0;
		(X>Temp->Element?Temp->Right:Temp->Left)=T;
         Temp->Height=Max(Height(Temp->Left),Height(Temp->Right))+1;
			}
          
		while(Root2!=Temp&&Root2->Left!=Temp&&Root2->Right!=Temp)//寻找Temp的parent
		{
			Root1=Root2;//记录Root的父母 
			if(Root2->Element>X)
			Root2=Root2->Left;
			else Root2=Root2->Right;
		}
		He=Root2->Height; //记录他原来的高度 
		if(root==Root2)
		root=Rotate(&Root2);
		else	
		{
			Rotate(&Root2);
			(Root1->Element>Root2->Element)?(Root1->Left=Root2):(Root1->Right=Root2);
	         	Root1=root; 
		}

		         if(He-Root2->Height)
			  while(Root1!=NULL&&Root1!=Root2)
			  {
			  	Root1->Height+=1;
			  	if(Root1->Element>X)
			  	Root1=Root1->Left;
			  	else Root1=Root1->Right;
			  }
	return root;
}
void insert(ElementType X,AvlTree *T)
{
	if((*T)==NULL)
	{
	(*T)=(AvlTree)malloc(sizeof(**T));
	(*T)->Element=X;
	(*T)->Height=0;
	(*T)->Left=(*T)->Right=NULL;	
	}
	else
		(*T)=insert1(X,*T);
}
int RandInt(int A,int B)
{
	int num;
	srand((unsigned)time(NULL));
	num=rand()%(B-A+1);
	return num+A;
}
int NumOfFewestNode(int Height)
{
   int i;
   int Num[Height+1];
   Num[0]=1;
   Num[1]=2;
   for(i=2;i<=Height;i++)
   Num[i]=Num[i-1]+Num[i-2]+1;
   return Num[Height];
}
void Tian(AvlTree T)
{
	static int i=1;
	if(T!=NULL)
	{
		Tian(T->Left);
		T->Element=i++;
		Tian(T->Right);
		
	}
}
AvlTree GetFewestAvlTree(int Height)
{
	AvlTree T,t;
    int num=NumOfFewestNode(Height);
    if(Height==0)
    {
    	T=(AvlTree )malloc(sizeof(*T));
    	T->Left=NULL;
    	T->Right=NULL;
    	T->Height=0;
	}
	else if(Height==1)
	{
		T=(AvlTree )malloc(sizeof(*T));
		t=(AvlTree )malloc(sizeof(*t));
		T->Left=NULL;
		T->Right=t;
		T->Height=1,t->Height=0;
		t->Left=NULL;
		t->Right=NULL;
	}
	else 
	{
	    T=(AvlTree )malloc(sizeof(*T));
	    T->Height=Height;
	    T->Left=GetFewestAvlTree(Height-2);
	    T->Right=GetFewestAvlTree(Height-1);
	}
    return T;
}
AvlTree GetFewestAvl(int Height)
{
	AvlTree T;
	T=GetFewestAvlTree(Height);
	Tian(T);
	return T;
}
AvlTree GetDreamAvlTree(int Height)
{
	AvlTree T;
	if(Height==0)
	{
		T=(AvlTree)malloc(sizeof(*T));
		T->Height=0;
		T->Left=NULL;
		T->Right=NULL;
	}
	else 
	{
		T=(AvlTree)malloc(sizeof(*T));
		T->Height=Height;
		T->Left=GetDreamAvlTree(Height-1);
		T->Right=GetDreamAvlTree(Height-1);
	}
	return T;
}
AvlTree GetDreamAvl(int Height)
{
	AvlTree T;
	T=GetDreamAvlTree(Height);
	Tian(T);
	return T;
}
