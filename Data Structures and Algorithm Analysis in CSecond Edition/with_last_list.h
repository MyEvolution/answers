#include"list.h"
typedef struct 
{
	Position Last;
	List L;
}A,*_List;

void create(_List*L)
{
   (*L)=(_List)malloc(sizeof(A));
   
   (*L)->Last=(*L)->L=(List)malloc(sizeof(*(*L)->Last));
   (*L)->Last->Next=NULL;
   }
void insert(ElementType X,_List L,Position P)
{
       Insert(X,L->L,P);
		if(P==L->Last)
		L->Last=L->Last->Next;
}
void makeempty(_List L)
{
	L->L=L->Last;
}
int islast(_List L,Position P)
{
	return P==L->Last;
}
int isempty(_List L)
{
	return L->L==L->Last;
}
void deletel(_List L,ElementType X)
{
	Position P;
	P=FindPrevious(X,L->L);
	if(P->Next==L->Last)
	{
		L->Last=P;
		P=P->Next;
		L->Last->Next==NULL;
		free(P);
	}
	else
	  Delete(X,L->L);
	  
}
 

