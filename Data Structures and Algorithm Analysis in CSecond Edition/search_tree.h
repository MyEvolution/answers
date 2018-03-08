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
	T->Left=(X,T->Left);//这里是必要de
	//正如原来所说  函数不会改变指针的指向  只是可以改变地址
	//所以如果没有这一步  实际上并没有将元素添加到树当中 
	// 因为指针的指向没有改变  还是原来的空 
	else if(T->Element<X)
	T->Right=(X,T->Right);
	//如果等于  什么也不做 
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
        T->Right=Delete(t->Element,T->Right);//一定是叶子节点 
    	
	}
	else//只有一个子节点或者没有子节点 
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
	//时间复杂度如何求？？？ 
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
/*我认为上述算法的时间复杂度是一样的 
因为他们的本质是一样的   
对于我写的算法来说  如果超出界限  去他相应的子树去寻找  
如果在界限之内   对左右子树皆进行遍历寻找  且是根据关键字大小 所以 基本每次可以排除一半
树上的算法是 如果你大于最小的界限  就对你的小的那部分查找  小于最大的 就对你的较大部分查找  
在中间就会打印
所以 可以用个例子来解释下
如果 在中间   我的算法是会进行两次遍历  分别是T左边和右边
书上也是
如果大于最大  则扫描较小的
小于最小  扫描较大的
不过书上的算法 有一点较为有优势
对于等于的 它只输出  便不会处理了 
我的需要加个判断  实际本质也没有太大区别了 
*/	
}
