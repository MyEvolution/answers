#include<stdio.h>
#include<stdlib.h>
#ifndef _double_link_list_h
typedef int ElementType; 
struct Node;
typedef struct Node *List;
typedef struct Node *Position;
struct Node
{
	ElementType element;
	Position Next;
	Position Previous;
};
typedef struct 
{
	Position First;
	Position Last;
}A, *DoubleLink;
void CreateDList(DoubleLink *D);
int IsEmpty(DoubleLink D,Position P);
int IsLast(DoubleLink D);
void MakeEmpty(DoubleLink D);
Position Find(ElementType X,DoubleLink D);
void Delete(ElementType X,DoubleLink D);
void Insert(ElementType X,DoubleLink D,Position P);
void Exchange(DoubleLink D,Position P);
void zprintlist(DoubleLink L);
void fprintlist(DoubleLink L);

#endif
void CreateDList(DoubleLink *D)
{
	Position P,Q;
   (*D)=(DoubleLink)malloc(sizeof(A));//如果没有这一步 则（*D）指向的地址是未知的 
   if(*D==NULL) return;
    P=(Position )malloc(sizeof(struct Node));
	Q=(Position )malloc(sizeof(struct Node));
    if(P==NULL||Q==NULL)
    {
    	printf("out of space!\n");
    	return ;
	}
	
    (*D)->First=P;
    (*D)->Last=Q;
    MakeEmpty(*D);
}
int IsEmpty(DoubleLink D)
{
	return D->First->Next==D->Last;
}
int IsLast(DoubleLink D,Position P)
{
	return P->Next==D->Last;
}
void MakeEmpty(DoubleLink D)
{
	D->First->Previous=NULL;
	D->Last->Previous=NULL;
D->First->Next=D->Last;
D->Last->Previous=D->First;
}
Position Find(ElementType X,DoubleLink D)
{
   Position P;
   P=D->First->Next;
   while(P!=D->Last&&P->element!=X)
     P=P->Next;
     if(P!=D->Last)
     return P;
     else return NULL;

}
void Delete(ElementType X,DoubleLink D)
{
	Position P;
	P=Find(X,D);
	if(P!=NULL)
	{
		P->Previous->Next=P->Next;
		P->Next->Previous=P->Previous;
		free(P);
	}
}
void Insert(ElementType X,DoubleLink D,Position P)
{
	Position Q;
	
	Q=(Position)malloc(sizeof(struct Node));
	
	if(Q==NULL) return;
	Q->element=X;
	Q->Next=P->Next;
	Q->Previous=P;
	P->Next->Previous=Q;
	P->Next=Q;
	

}
void Exchange(DoubleLink D,Position P)
{
	
	 
       if(IsLast(D,P))
       {
       	printf("P is last!\n");
       	return;
	   }
	Position Q=P->Previous;
	 Position O=P->Next;
	 Q->Next=O;
	 O->Previous=Q;
	 P->Next=O->Next;
	 O->Next=P;
	 P->Previous=O;
}
void zprintlist(DoubleLink L)
{
	Position P;
	P=L->First->Next;
	while(P!=L->Last)
	{
	printf(P->Next==L->Last?"%d\n":"%d ",P->element);
	P=P->Next;	
	}

	
}
void fprintlist(DoubleLink L)
{
	Position P;
	P=L->Last->Previous;
	while(P!=L->First)
	{
		printf(P->Previous==L->First?"%d\n":"%d ",P->element);
		P=P->Previous;
	}
	
}
