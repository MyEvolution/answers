#include<stdio.h>
#include<malloc.h> 
#include<ctype.h>
#define MaxSize 1000
typedef char ElementType;
struct TreeNode;
typedef  struct TreeNode *PtrToNode;
typedef PtrToNode Tree;
typedef Tree Leaf;
struct TreeNode
{
	ElementType Element;
	Tree Left;
	Tree Right;
};


Tree Stack[MaxSize];//指向树的智指针数组
int StackCp=0;//棧的下标

Tree CreateTree(ElementType X)
{
	Tree t;
	t=(Tree)malloc(sizeof(*t));
	t->Element=X;
	t->Left=NULL;
	t->Right=NULL;
}
void AddElements(ElementType X,ElementType Y,Tree t)
{
     Leaf L1,L2;
     L1=CreateTree(X);
     L2=CreateTree(Y);
     t->Left=L1;
     t->Right=L2;
}
void AddTree(Tree t1,Tree t2,Tree t)
{
	t->Left=t1;
	t->Right=t2;
}
void Push(Tree t)
{
	Stack[StackCp++]=t;
}
Tree Pop(void)
{
	return Stack[--StackCp];
}
int IsLeaf(Tree t)
{
	return t->Left==NULL&&t->Right==NULL;
}
void PrintTree(Tree t)//为了正确分配括号 废了不少时间 
{
	
	if(t->Left!=NULL)
	{
		if(!IsLeaf(t->Left))
		{
		putchar('(');
		PrintTree(t->Left);
		putchar(')'); 
		}
		else
		  PrintTree(t->Left);

	}	
    printf("%c",t->Element);
    if(t->Right!=NULL)
    {
    	if(!IsLeaf(t->Right))
    	{
    		putchar('(');
    	PrintTree(t->Right);
    	putchar(')');
    	
		}
		else
		PrintTree(t->Right);
	}	
}
void ClearStack(void)
{
	StackCp=0;
}
int main()
{
	Tree t;
	Tree t1,t2;
	int c;
	while((c=getchar())!=EOF)
	{
		if(c=='\t'||c==' ')
		continue;
		if(isalnum(c))
		{
			t=CreateTree(c);
			Push(t);
					}
	else if(c!='\n')
	{
		t=CreateTree(c);
		t1=Pop();
		t2=Pop();
		AddTree(t2,t1,t);
		Push(t);
	}
	else if(c=='\n')
	{
		t=Pop();
		PrintTree(t);
		putchar(c);
		ClearStack();
	}
	}
	return 0;
 } 
