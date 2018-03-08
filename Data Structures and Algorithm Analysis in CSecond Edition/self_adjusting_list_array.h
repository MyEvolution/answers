#include<stdio.h>
#include<malloc.h>
#ifndef _selt_adjusting_h
#define HEAD 0

typedef int ElementType;
typedef ElementType *list;
typedef struct
{
	list l;
	int Lsize;
	int num;
}A,*List;
#endif
List create(int size)
{
   List L;
   L=(List )malloc(sizeof(*L));
   L->l=(list)malloc(size*sizeof(ElementType));
   L->Lsize=size;
   L->num=0;
   return L;
}
int IsEmpty(List L)
{
	return L->num==HEAD;
}
int IsFull(List L)
{
	return L->num==L->Lsize;
}
void Insert(List L,ElementType X)
{
	int i;
	if(IsFull(L)) 
	{
		printf("FULL!\n");
		return ;
	}
	if(IsEmpty(L))
	  {
	  	L->l[HEAD]=X;
	  	L->num++;
	  }
	  else
	  {
	  	for(i=L->num;i>HEAD;i--)
	  	    L->l[i]=L->l[i-1];
	  	    L->l[HEAD]=X;
	  	    L->num++;  	  
	  }
}
int Find(ElementType X,List L)
{
	int i=0,j;
	   
	while(i<L->num&&L->l[i]!=X)
              i++;
             
        if(i==L->num)
          {
          	printf("there is no this Elem!\n");
          	return -1;
		  }
		  else 
		  {
		  	for(j=i;j>0;j--)
		  	L->l[j]=L->l[j-1];
		  	L->l[HEAD]=X;
		  	printf("This Elem has been taken to the head.\n");
		  	return 0;
		  }
}
void Delete(ElementType X,List L)
{
	int i;
	if(Find(X,L)==-1)
       return;
       else
       {
       	for(i=HEAD;i<L->num-1;i++)
         L->l[i]=L->l[i+1];
         L->num-=1;
         printf("This ELem has been deleted!\n");
	   }
}
void PrintList(List L)
{
	int i;
	for(i=0;i<L->num;i++)
	printf(i==L->num-1?"%d\n":"%d ",L->l[i]);
}
void MakeEmpty(List L)
{
	L->num=HEAD;
}
