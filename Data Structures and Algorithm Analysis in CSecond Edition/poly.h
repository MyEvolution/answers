#include<stdio.h>
#include<stdlib.h>
#ifndef _Poly_List
typedef double ElementType;
typedef struct Poly *List;
typedef List Position;

void MakeEmpty(List L);
void Create(List *L);
void ZeroPoly(List L);//把多项式置为0） 
void Insert(ElementType C,ElementType P,List L,Position p);//（加入一个项） 
void Order(List L,List P);//将L加到P中 （按幂次由大到小） 
void AddPoly(List L1,List L2,List L);//把多项式1和多项式2相加，得到的结果储存在L内
 Position Find(ElementType P,List L);//找到幂次为p的项 
 Position FindPrevious(ElementType P,List L);//用来找到P次之前的项 
 void printlist(List L);
 void MultPoly(List L1,List L2,List L);//（两个多项式相乘） 
 void Mult(ElementType C,ElementType P,List L,List p);//（一个项乘一个多项式）
 List PowPoly(List L,int P);//(多项式L的P次方） 
 #endif 
 struct Poly{
	ElementType Coeff;
	ElementType Power;
	 List Next;
};
void MakeEmpty(List L)
{
	L->Next=NULL;
}
void Create(List *L)
{
	(*L)=(List)malloc(sizeof(struct Poly));
	MakeEmpty(*L);
}

void ZeroPoly(List L)
{
	MakeEmpty(L);
}
void Insert(ElementType C,ElementType P,List L,Position p)
{
	Position Q;
	Q=(List)malloc(sizeof(struct Poly));
	if(Q==NULL)
	{
		printf("out of space!\n");
		return;
	}
     Q->Coeff=C;
     Q->Power=P;
     Q->Next=p->Next;
     p->Next=Q;
}
Position Find(ElementType P,List L)
{
	Position Q;
	Q=L->Next;
	while(Q!=NULL&&Q->Power!=P)
	   Q=Q->Next;
	   return Q;
}
Position FindPrevious(ElementType X,List L)
{
	Position Q;
	while(Q->Next!=NULL&&Q->Next->Power!=X)
	Q=Q->Next;
	return Q;
}
void Order(List L,List P)//将L按幂的大小放进P 
{
	Position Q=L->Next;
	Position O;
	Position tmp;
	while(Q!=NULL)
	{
		
	    O=P;
    while(O->Next!=NULL&&(Q->Power<O->Next->Power))
       O=O->Next;
	   if(O->Next==NULL||Q->Power>O->Next->Power)
		 Insert(Q->Coeff,Q->Power,P,O);//如果大于下一项或者到了结尾，则把这个指数的项插入链表中        
       else//指数相同的话，系数相加 
       {  
       	 tmp=O->Next;
       	 tmp->Coeff+=Q->Coeff;
	   }

	   Q=Q->Next;	   	
	}

}
void printlist(List L)
{
	L=L->Next;
	while(L!=NULL)
	{
		printf("%10.2lf %10.2lf\n",L->Coeff,L->Power);
		L=L->Next;
	}
}
void AddPoly(List L1,List L2,List L)
{
	MakeEmpty(L);
	Order(L1,L);
	Order(L2,L);

}
void Mult(ElementType C,ElementType P,List L,List p)//O(N)
{
	Position Q;
	Q=L->Next;
	MakeEmpty(p);
	while(Q!=NULL)
	{
	 
  Insert((Q->Coeff*C),(Q->Power+P),p,p);//
  Q=Q->Next;
}
	
}
void MultPoly(List L1,List L2,List L)
{
	Position p1;
	List P;
	Create(&P);
	p1=L1->Next;
	MakeEmpty(L);
	while(p1!=NULL)
	{
		Mult(p1->Coeff,p1->Power,L2,P);
		Order(P,L);
		p1=p1->Next;
	} 
	free(P);

}	
List PowPoly(List L,int P)
{
     static List Q;
	 Create(&Q);

       if(P==0)
	   {
	   Insert(1,0,Q,Q);
	   return Q;
	   }
	   	 else if(P==1)
	  {
	  	Order(L,Q);//排下顺序 
	  	return Q;
	  }
	   else if(P&1)
	   {
	   	 MultPoly(L,L,Q);
	   	 Q=PowPoly(Q,P/2);
	   	 MultPoly(Q,L,Q);
	   	 return Q;
	   	 
	   }
	   else
	   {
	   	MultPoly(L,L,Q);
	   	return PowPoly(Q,P/2);
	   }
}
