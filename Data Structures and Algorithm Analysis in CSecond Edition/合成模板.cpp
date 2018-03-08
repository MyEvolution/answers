#include<stdio.h>
#include<stdlib.h>

typedef unsigned long long ElementType;
struct Node;
typedef struct Node *Position;

struct Node
{
	ElementType ELement;
	Position Next; 
};
typedef struct List
{
	Position Top;
	Position Tail;
}*LinkList;

LinkList Create(void)
{
	LinkList L=(LinkList)malloc(sizeof(*L));
	L->Top=L->Tail=(Position )malloc(sizeof(struct Node));
	L->Tail->Next==NULL;
	return L;
}
void Insert(ElementType X,LinkList L)
{
	Position P,Q;
	P=(Position )malloc(sizeof(*P));
	P->ELement=X;
	  	Q=L->Top; 
	  	while(Q!=L->Tail&&Q->Next->ELement<X)
	  	   Q=Q->Next;
	  	   if(Q==L->Tail)
	  	   {
		L->Tail->Next=P;
		L->Tail=P;
		L->Tail->Next=NULL; 	  	   	
			 }
			 else
			 {
			 	P->Next=Q->Next;
				 Q->Next=P; 
			 }
}
ElementType Pop(LinkList L)
{
	Position P;
	ElementType X;
	P=L->Top->Next;
	if(P==L->Tail)
	{
		L->Tail=L->Top;
		L->Top->Next=NULL;
		X=P->ELement;
		free(P);
		return X;
	}else
	{
		L->Top->Next=P->Next;
		X=P->ELement;
		free(P);
		return X;
	}
}
void PrintList(LinkList L)
{
	Position P;
	P=L->Top->Next;
	while(P!=NULL)
	{
		printf("%llu\n",P->ELement);
		P=P->Next;
	}
}
void MakeEmpty(LinkList L)
{
	L->Tail=L->Top;
}
int main()
{
	int n,k;
	int i;
	ElementType c,spa,time;
	LinkList L;
	L=Create();
	while(scanf("%d %d",&n,&k)!=EOF)
	{
		spa=time=0;
		MakeEmpty(L);
    for(i=0;i<n;i++)
    {
    	scanf("%llu",&c);
    	Insert(c,L);
	}
	if(n==1)
	    ;
	else if(n<=k)
	{
		while(L->Top!=L->Tail)
		time+=Pop(L);
	}else
		while(L->Top->Next!=L->Tail)
		{
			spa=0;
			for(i=0;i<k&&L->Top!=L->Tail;i++)
			spa+=Pop(L);
			Insert(spa,L);
			time+=spa;
		}
		printf("%llu\n",time);
}
     return 0;
 }
