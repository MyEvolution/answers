#include"list.h"
int main()
{
	int n;
	int c;
	int i;
	List L;
	Position P;
	L=Create();
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	scanf("%d",&c);
	Insert(c,L,L);
	}
	printlist(L);
	reverse(&L);
	printlist(L);
	P=FinD(5,L);
	printf("%d\n",P->Element);
	Reverse(L);
	printlist(L);
	ReversE(L);
	printlist(L);
	return 0;

}
