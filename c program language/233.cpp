#include<stdio.h>
#include<stdlib.h> 
typedef struct Node *PtrToNode;
struct Node
{
	int Coeff;//系数 
	int Exp;//次数 
	PtrToNode next;//指向下一行的指针 
};//链表式的多项式结构
typedef PtrToNode Polynomial;
void creatlink(Polynomial p)
{
	p=(Polynomial)malloc(sizeof(struct Node));
	p->next=NULL;
	 
}
void Delete(Polynomial P)
{
	Polynomial tmp,p;
	p=P->next;
	P->next=NULL;
	while(p!=NULL)
	{
		tmp=p->next;
		free(p);
		p=tmp;
	}
}
void Add(Polynomial p,int c,int e)
{
	Polynomial q;
	Polynomial ne;
	q=p;
//为什么不能用next？ 
	
	while((q->next!=NULL)&&(q->next->Exp<e))
	   q=q->next;
	   
    if(q->next==NULL)
    {
    	ne=(Polynomial)malloc(sizeof(struct Node));
    	ne->Coeff=c;
    	ne->Exp=e;
    	ne->next=NULL;
    	q->next=ne;
    	printf("haha\n");
	}else if(q->next->Exp==e)
	  q->next->Coeff+=c;//系数 
	  else if(q->next->Exp>e)
	  {
	     printf("hahah\n");
	  	ne=(Polynomial)malloc(sizeof(struct Node));
	  	ne->Coeff=c;
	  	ne->Exp=e;
	  	ne->next=q->next;
	  	q->next=ne;
	  	
	  }
	
     }
void AddPoly(Polynomial p1,Polynomial p2,Polynomial polys)
{
	Delete(polys);
	Polynomial P,Q;
   P=p2->next;
   Q=p1->next;
     while(P!=NULL)
     {
       Add(polys,P->Coeff,P->Exp);
       P=P->next;
	 }
	 while(Q!=NULL)
	 {
	 	Add(polys,Q->Coeff,Q->Exp);
	 	Q=Q->next;
		  }	 
}
void MultPoly(Polynomial p1,Polynomial p2,Polynomial polym)
{
	Delete(polym);
  Polynomial P,Q;
  P=p1->next;
  while(P!=NULL)
  {
  	Q=p2->next;
  	    while(Q!=NULL)
    {
    	Add(polym,P->Coeff*Q->Coeff,P->Exp+Q->Exp);
    	Q=Q->next;
	}
		P=P->next;
  }
	
}
int main()
{
	struct Node a,b,d;//3个链表 
	Polynomial p;
	creatlink(&a);
	creatlink(&b);
	creatlink(&d);
	int i;
	int n,m;
	int c,e;
		scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&c,&e);
		getchar(); 
		Add(&b,c,e);
	}
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&c,&e);
		getchar();
		
		Add(&a,c,e);
		printf("%d\n",a.next->Coeff);
		
	}

	AddPoly(&a,&b,&d);
	p=d.next;
	while(p!=NULL)
	{
	printf("%d %d",p->Coeff,p->Exp);
	p=p->next;	
	}
	
}