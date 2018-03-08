#ifndef Binomial_Queues_h

#include<stdio.h>
#include<stdlib.h>
#define MINSIZE 10 

typedef int ElementType;
struct TreeNode;
typedef struct TreeNode *Tree; 
typedef struct ForestList
{
	int The_Highest;
	Tree* TreeNum;
	int ForestSize;
}*Forest;

int Max(int a,int b);
void Error(const char *string);
void Insert(ElementType Element,Forest H);
Forest Merge(Forest H1,Forest H2);
Tree FindAndDeleteMinTree(Forest H,int *Min,int *TheNum); 
ElementType DeleteMin(Forest H);
Forest DeleteMinElementAndResolve(Tree T,int Num);
void PrintForest(Forest H);
Forest InitailizeForest(int Size);
void PrintTree(Tree T);
void PrintForest(Forest H);

#endif

struct TreeNode
{
 ElementType Element;
 struct TreeNode *FirstChild;
 struct TreeNode *RightBrother;	
};

ElementType DeleteMin(Forest H)
{
	Tree TheMin;
	ElementType Min;
	Forest H2;
	int TheNum;
	if(H->The_Highest==-1)
	Error("the Forest is Empty!\n");
	else
	{
		TheMin=FindAndDeleteMinTree(H,&Min,&TheNum);
		H2=DeleteMinElementAndResolve(TheMin,TheNum);
		H=Merge(H,H2);
	   return Min;
	}
}
void Error(const char *string)
{
	printf("%s",string);
	exit(0);
 } 
Forest InitailizeForest(int Size)
{
	Forest H;
	if(Size<MINSIZE)
    Size=MINSIZE;
	H=(Forest )malloc(sizeof(*H));
	if(H==NULL)
	Error("out of space!\n");
	H->ForestSize=Size;
	H->The_Highest=-1;
	H->TreeNum=(Tree *)malloc(sizeof(Tree )*H->ForestSize);
	if(H->TreeNum==NULL)
	Error("out of space!\n");
	return H;
}
Forest DeleteMinElementAndResolve(Tree T,int Num)
{
	Forest H1;
	int i=0;
   H1=InitailizeForest(Num);
	T=T->FirstChild;
	while(T!=NULL)
	{
		H1->TreeNum[i++]=T;
		T=T->RightBrother;
	}
		H1->The_Highest=Num-1;
		free(T);
		return H1;
}
Tree FindAndDeleteMinTree(Forest H,int *Min,int *TheNum)
{
	int min=0xfffff;
	int i;
	Tree T;
	if(H->The_Highest==-1)
	Error("the Forest is Empty!");
	for(i=0;i<=H->The_Highest;i++)
	  	if(H->TreeNum[i]->Element<min)
	  	{
	  	min=H->TreeNum[i]->Element;
	  	*TheNum=i;
	  }
	  *Min=min;
	  T=H->TreeNum[*TheNum]; 
	H->TreeNum[*TheNum]=NULL;
	if(H->The_Highest==*TheNum)
	{
	 
	   for(i=H->The_Highest-1;i>=0;i--)
	   if(H->TreeNum[i]!=NULL)
	   break;
	   H->The_Highest=i;
	   if(i==0&&H->TreeNum[0]==NULL)
	   H->The_Highest=-1; 
	   } 
	return T;
}
Tree MergeTree(Tree T1,Tree T2)
{
	if(T1==NULL)
	return T2;
	else if(T2==NULL)
	return T1;
	else
	if(T1->Element<T2->Element)
	{
		T2->RightBrother=T1->FirstChild;
		T1->FirstChild=T2;
		return T1;
	}
	else
	{
				T1->RightBrother=T2->FirstChild;
		T2->FirstChild=T1;
		return T2;
	}

}
Forest Merge(Forest H1,Forest H2)
{
	int i;
	Tree T;
	Tree Ready=NULL;
	if((H2->The_Highest+1)==H1->ForestSize)
	{
		H1->TreeNum=(Tree *)realloc(H1->TreeNum,MINSIZE);
		H1->ForestSize+=MINSIZE;
	}
	else if((H2->The_Highest+1)>H1->ForestSize)
              return Merge(H2,H1); 
               

	for(i=0;i<=H1->The_Highest||i<=H2->The_Highest;i++)
	{
		if(H1->TreeNum[i]==NULL)
		H1->TreeNum[i]=H2->TreeNum[i];
		else if(H2->TreeNum!=NULL)
		  {
		  	T=MergeTree(H1->TreeNum[i],H2->TreeNum[i]);
		  	H1->TreeNum[i++]=Ready;
		  	Ready=NULL;
		  	if(H1->TreeNum[i]==NULL)//有两个高度相同的树了  
		  	H1->TreeNum[i]=T;
		  	else if(H2->TreeNum[i]==NULL)
			  H2->TreeNum[i]=T;
			  else 
		  		Ready=T; 
		  		i--;
		  }
	}
		  if(H1->TreeNum[i]!=NULL)
		   H1->The_Highest=i;
		   else
		   H1->The_Highest=Max(H1->The_Highest,H2->The_Highest);
	
	return H1;
}
int Max(int a,int b)
{
	return a>b?a:b;
}
void PrintForest(Forest H)
{
	int i;
	for(i=0;i<=H->The_Highest;i++)
	{
		printf("%d:\n");
		if(H->TreeNum[i]==NULL)
		printf("NULL\n");
		else
		PrintTree(H->TreeNum[i]);
	}
}
void PrintTree(Tree T)
{
	 if(T!=NULL)
	 {
	 	printf("%d ",T->Element);
	 	PrintTree(T->FirstChild);
	 	PrintTree(T->RightBrother);
	 }
}

