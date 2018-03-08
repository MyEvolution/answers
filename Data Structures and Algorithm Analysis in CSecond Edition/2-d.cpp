#include <stdio.h>
#include <malloc.h>
#include <string.h>
#ifndef _TwoD_Tree 
typedef char* ElementType;
struct Node;
typedef struct Node *TwodTree;
struct Node
{
	ElementType Key1;
	ElementType Key2;
	TwodTree Left,Right;
 };

#endif

TwodTree MakeEmpty(TwodTree T)
{
	if(T)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
}
TwodTree Insert(ElementType X,ElementType Y,TwodTree T,int num)
{
	int i;
	if(T==NULL)
	{
		T=(TwodTree )malloc(sizeof(*T));
		T->Key1=(ElementType)malloc(strlen(X+1));
		strcpy(T->Key1,X);
		T->Key2=(ElementType)malloc(strlen(Y+1));
		strcpy(T->Key2,Y);
		T->Left=T->Right=NULL;
	}
	else if(num)
	{
		num=(num+1)&1; 
	
		if(strcmp(T->Key2,Y)>0)
		T->Left=Insert(X,Y,T->Left,num); 
		else if(strcmp(T->Key2,Y)<0)
		T->Right=Insert(X,Y,T->Right,num);
	 }
	 else 
	 {
	 	num=(num+1)&1; 
	 
	 	if(strcmp(T->Key1,X)>0)
	 	 T->Left=Insert(X,Y,T->Left,num);
		  else if(strcmp(T->Key1,X)<0)
		 T->Right=Insert(X,Y,T->Right,num);
	 }
	return T;
}
void PrintTree(TwodTree T)
{
	if(T)
	{
    	printf("%s %s\n",T->Key1,T->Key2);
		PrintTree(T->Left);
		PrintTree(T->Right);
	}
}
void PrintRangeTree(ElementType Low1,ElementType High1,ElementType Low2,ElementType High2,TwodTree T)
{
	if(T)
	{
	if(strcmp(Low1,T->Key1)<=0||strcmp(Low2,T->Key2)<=0)
	PrintRangeTree(Low1,High1,Low2,High2,T->Left);
	if(strcmp(Low1,T->Key1)<=0&&strcmp(High1,T->Key1)>=0&&strcmp(Low2,T->Key2)<=0&&strcmp(High2,T->Key2)>=0)
	printf("%s %s\n",T->Key1,T->Key2);
	if(strcmp(High1,T->Key1)>=0||strcmp(High2,T->Key2)>=0)
	PrintRangeTree(Low1,High1,Low2,High2,T->Right);	
	}	
}
int main()
{
	int n,i;
	char name1[100];
	char name2[100];
	char name3[100];
	char name4[100];
	TwodTree T=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s %s",name1,name2);
		T=Insert(name1,name2,T,0);

	}
	printf("**********************************\n");
	PrintTree(T);
	scanf("%s %s %s %s",name1,name2,name3,name4);
	printf("在上述范围的有：\n"); 
	PrintRangeTree(name1,name2,name3,name4,T);
	return 0;
}

