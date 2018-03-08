#include"list.h"
int main()
{
	int n;
	int i,c;
	List L=Create();
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&c);
		Insert(c,L,L);
	}
	printlist(L);
	DeleteTheSame(L);
	printlist(L);
	return 0;
	
}
/*
delete的链表操作消耗常数时间
所以用的时间复杂度为O(N^2)
*/ 
