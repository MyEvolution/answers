#include"self_adjusting_list_array.h"
#define MAXSIZE 1000 
main()
{
	int n;
	int c;
	int i;
	List L;
	L=create(MAXSIZE);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	scanf("%d",&c);
	Insert(L,c);	
	}
	PrintList(L);
	Find(5,L);
	PrintList(L);
	Delete(8,L);
	PrintList(L);
	
}
