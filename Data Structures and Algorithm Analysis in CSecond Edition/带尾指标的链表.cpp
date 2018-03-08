#include"with_last_list.h"
int main()
{
	_List L,P;
	create(&P);
	create(&L);
	int n;
	int i;
	int num[1000];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
		insert(num[i],L,L->Last);
		insert(num[i],P,P->L);	
	}
	printlist(L->L);
	printlist(P->L);
	return 0;
}
