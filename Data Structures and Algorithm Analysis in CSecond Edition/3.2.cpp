#include"list.h"
void print(List L,int n)
{
	Position P;
	P=L;
	int i=0;
	while(P!=NULL&&i<n)
	{
		P=P->Next;
		i++;
	}
	if(P==NULL)
	return;
	printf("%d\n",P->Element);
}
void PrintLots(List L,List P)
{
      Position Q;
      Q=P->Next;
      while(Q!=NULL)
      {
      	print(L,Q->Element);
      	Q=Q->Next;
	  }
    
	  
}
int main()
{
	List L,P;//ԭ��Ϊʲô����� 
    /*L=Create();// 
    P=Create();*/
    MakeEmpty(&L);
    MakeEmpty(&P);
	int n,m;
	int num[1000];
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
		Insert(num[i],L,L);//�Է����˳����� 
	}
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
	 scanf("%d",&num[i]);
	 Insert(num[i],P,P);
	}
	PrintLots(L,P);//��˳���ȡ��������Ϊ���÷�������P����LҲ�Ƿ��� �����������������
	printlist(L);
	ExchangeElem(L,L->Next);
	printlist(L); 
	return 0;
}
