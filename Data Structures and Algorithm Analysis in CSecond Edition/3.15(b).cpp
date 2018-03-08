#include"self_adjusting_list_link.h"
int main()
{
	int n,i,c;
	List L;
	L=Create();
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&c);
		Insert(L,c);
	}
	PrintList(L);
	Find(5,L);
	PrintList(L);
	Delete(L,8);
	PrintList(L);
	
}
