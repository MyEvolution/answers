#ifndef _List_H
typedef int ElementType;
struct Node
{
	ElementType Element;
	struct Node * Next;
 };

typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List Create(void);
void MakeEmpty(List L);//����һ���ձ� 
int IsEmpty(List L);//�ж��Ƿ�Ϊ�ձ�
int IsLast(Position P,List L);
Position Find(ElementType x,List L);
void Delete(ElementType X,List L);
Position FindPrevious(ElementType X,List L);
void Insert(ElementType x,List L,Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);
void printlist(List L);
Position ToLast(List L);
Position FinD(ElementType X,List L);
void reverse(List L);//�½�һ��������ʵ��
void Reverse(List L);//ͨ���������֮���ָ��ʵ�� 
void DeleteTheSame(List L);

#endif

#include<malloc.h>
#include<stdio.h>
List Create(void)
{
	List L;
	L=(List)malloc(sizeof(struct Node));
	MakeEmpty(L);
	return L;
}

   
void MakeEmpty(List L)
{
	L->Next=NULL;//ԭ��Ϊʲô����� 
}             //������ָ�룬�ַ���ָ�룬��Ϊ���������᱾�ʸñ�ʲô�� 
/*void MakeEmpty(List *L)
{
 *L=(List)malloc(sizeof(struct Node));
 (*L)->Next=NULL;
}
��֪�������Ĳ�����copy��ȥ�ģ����Բ��᲻��ָ���޷�ʵ���ϸı�һ��ֵ��
����ָ�룬ָ��ָ����ǵ�ַ����ַ�ڵ�ֵת���ˣ�Ҳ��ʵ����ת������ 
����ʵ����ָ��Ҳ�ǲ�����Ҳ��һ����ַ��ֻ����ָ����һ����ַ
������Ϊָ�룬Ҳ��copyһ��ͬ��ָ��õ�ַ��ָ���ȥ�����Ժ����иı�ָ���ָ��ʵ����
ֻ�Ǹı���copy��ָ���ָ��ԭ����ָ��ָ��δ�ı�
��ô����ں����иı�ָ��ĵ�ַ�أ�
�ͱ���һ����ָ��Ҳ���Լ��ĵ�ַ
����������һ��ָ��ָ���ָ�룬���������� List *L Ҳ����struct Node **L 
L��һ��ָ��ָ���ַ��ָ�룬
*LҲ����ԭ����Lָ���ָ��ĵ�ַ�ˣ�
�ı�*L��ָ�룬Ҳ���������ַ��ָ���ָ�򱻸ı��ˣ�
�����ʹﵽ�޸�ָ���ָ���Ŀ�ģ� 
*/
int IsEmpty(List L) 
{
	return L->Next==NULL;
}
int IsLast(Position P,List L)//p����ǰλ�� 
{
	return P->Next==NULL;	
}

Position Find(ElementType X, List L)
{
	Position P=L->Next;
	while(P!=NULL&&P->Element!=X)
	   P=P->Next;
	   return P;
}

Position FindPrevious(ElementType X,List L)//����x�� ǰ�� 
{                                            //û���ҵ��ͷ������һ��Ԫ�� 
	Position P;
	P=L;
	while((P->Next!=NULL)&&(P->Next->Element!=X))
	P=P->Next;
	
	return P;
}
void Delete(ElementType X,List L)//ɾ�����еĳ��ֵĵ�һ��x 
{
	Position P,Q;
 P=FindPrevious(X,L);
 if(!IsLast(P,L))
 {
 	Q=P->Next;
 	P->Next=Q->Next;
 	free(Q);
 }
  
}
void Insert(ElementType x,List L,Position P)//��x�ӵ�P֮�� 
{
	Position Q=(Position)malloc(sizeof(struct Node));
	if(Q==NULL) return;
	
	Q->Element=x;	
	Q->Next=P->Next;
	P->Next=Q;
	
}
void DeleteList(List L)//ɾ��һ���� 
{
	Position P,Q;
	P=L->Next;
	L->Next=NULL;
	while(P!=NULL)
	{
		Q=P;
		P=P->Next;
		free(Q);
	}
	
}
Position Header(List L)
{
	return L;
}
Position First(List L)
{
	return L->Next;
}
Position Advance(Position P)//ǰ������ //P�������ڵ�һ��λ�� 
{
	Position Q=P->Next;
	ElementType e;
	while(Q->Next!=P)
	Q=Q->Next;
	e=Q->Element;
	Q->Element=P->Element;
	P->Element=e;
	return Q;
}
ElementType Retrieve(Position P)
{
	return P->Element;
}
void printlist(List L)
{
	Position P;
	P=L->Next;
	if(P!=NULL)
	{
		printf("%d",P->Element);
		P=P->Next;
	}
	 
	while(P!=NULL)
	{
		putchar(' ');
	printf("%d",P->Element);
		P=P->Next;
	}
	putchar('\n');
}
void ExchangeElem(List L,Position P)
{
	Position Q,q;
	Q=L;
	while(Q->Next!=P)
	Q=Q->Next;
	Q->Next=P->Next;
	P->Next=P->Next->Next;
	Q->Next->Next=P;
 } 
 Position ToLast(List L)
 {
 	Position P;
 	P=L;
 	while(P->Next!=NULL)
 	   P=P->Next;
 	   return P;
 }
 Position FinD(ElementType X,List L)
 {
 	Position P;
 	P=L->Next;
 	if(P==NULL||P->Element==X)
 	  return P;
 	  else 
	   return FinD(X,P);
 }
 void reverse(List *L)
 {
 	static List Q;
 	Position P=(*L)->Next;
 	Q=Create();
 	while(P!=NULL)
 	{
 		Insert(P->Element,Q,Q);
 		P=P->Next;
	 }
 		
 	P=(*L);
 	(*L)=Q;
 		free(P);
 }
 void Reverse(List L)
 {
 	Position P;
 	Position Q;
 	Position I;
	 P=L->Next;
	 while(P->Next!=NULL)
	 {
	  Q=L->Next;
	  L->Next=P->Next;
	  P->Next=P->Next->Next;
	  L->Next->Next=Q;
	  
	  } 
 }
 void ReversE(List L)
 {
 	Position P,Q;
 	P=L;
 	while(P->Next!=NULL)
 	P=P->Next;
 	while(L->Next!=P)
 	{
 		Q=L->Next;
 		L->Next=Q->Next;
 		Q->Next=P->Next;
 		P->Next=Q;
	 }
  } 
void DeleteTheSame(List L)
{
	Position P;
	Position Q;
	Position M;
	P=L->Next;
	while(!IsLast(P,L))
	{
		Q=P;
		while(Q->Next!=NULL)
		  if(Q->Next->Element==P->Element)//Q->�Ѿ��õ��˸ı� 
		  {
		  	M=Q->Next;
		  	Q->Next=Q->Next->Next;
		  	free(M);
		  }
		  else Q=Q->Next;
		  P=P->Next;	  
	}
}
