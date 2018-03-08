#include<stdio.h>
#include<stdlib.h>
#ifndef _Lazy_List_h
typedef int ElementType;

typedef struct Node
{ 
     unsigned int IsDeleted:1;
     ElementType Element;
     struct Node *Next;
}*List,*Position;

typedef struct 
{
	List L;
	int numd;//被删除的元素 
	int nums;//未被删除的元素 
}B,*Head;
void Delete(ElementType X,Head H); 
Head Create(void);
void MakeEmpty(Head H); 
int IsEmtpy(Head H);
int IsLast(Position P,Head H); 
void InsertList(ElementType X,Position P,List L);
void Insert(ElementType X,Position P,Head H);
Position Find(ElementType X,List L);
Position FindPrevious(ElementType X,List L);
void DeleteElem(ElementType X,List L);
void Delete(ElementType X,Head H);
void PrintList(List L);
void Print(Head H);

#endif


Head Create(void)
{
	Head H;
	H=(Head)malloc(sizeof(*H));
	if(H==NULL) return NULL;
	H->L=(List )malloc(sizeof(struct Node));
	if(H->L==NULL) return NULL;
    MakeEmpty(H);
    return H;
}
void MakeEmpty(Head H)
{
	H->numd=H->nums=0;
	H->L->Next=NULL;
}
int IsEmtpy(Head H)
{
	return H->L->Next==NULL;
}
int Is_last(Position P,List L)
{
	return P->Next==NULL;
}
int IsLast(Position P,Head H)
{
	return Is_last(P,H->L);
}
void InsertList(ElementType X,Position P,List L)//复制的p指针，和p为一个指向 
{
	Position Q;
	Q=(Position)malloc(sizeof(struct Node));
	
	if(Q==NULL) {
		printf("out of scape!\n");
		return;
	}
	
	Q->Element=X;
	Q->IsDeleted=0;
	Q->Next=P->Next;
    	P->Next=Q;	

}
void Insert(ElementType X,Position P,Head H)//复制的p指针，和p为一个指向 
{

        H->nums++;
        
	InsertList(X,P,H->L);//再一次复制,H的指向和原来的指针相同 ，复制H->L



}
Position Find(ElementType X,List L)
{
	Position P;
	P=L->Next;
	while(P!=NULL&&P->Element!=X)
	  P=P->Next;
	  return P;
}
Position FindPrevious(ElementType X,List L)
{
	Position P;
	P=L;
	while(P->Next!=NULL&&P->Next->Element!=X)
	  P=P->Next;
	  return P;
}
Position DeleteElem(Position P,List L)
{
Position Q,q;
Q=L;
while(Q->Next!=P)
Q=Q->Next;
q=Q->Next;
Q->Next=q->Next;
free(q);
return Q;
	
}
void Delete(ElementType X,Head H)
{
	Position P;
//被删除的元素个数小于未被删除的元素个数 
	P=Find(X,H->L);
	if(P==NULL)
	{
		printf("there is no this Element!\n");
		return;
	}
  	P->IsDeleted=1;
  
  	H->numd++;
  	H->nums--;
  	if(H->numd>=H->nums)
  	  {
  	  	P=H->L;
  	  	while(P!=NULL)
  	  	{
  	  		if(P->IsDeleted==1)
  	  		{
  	  			P=DeleteElem(P,H->L);
  	  			H->numd--;
  	  			
				}
  	           
  	           P=P->Next;
			}
		
		}
  }		

void PrintList(List L)
{
	Position P;
	P=L->Next;
	while(P!=NULL)
	{
		printf("%d %d\n",P->Element,P->IsDeleted);
		P=P->Next;
	}
}
void Print(Head H)
{
	printf("the num of elements that should be deleted :%d\n",H->numd);
	printf("the num of elements that shouldn't be deleted :%d\n",H->nums);
	PrintList(H->L);
}
