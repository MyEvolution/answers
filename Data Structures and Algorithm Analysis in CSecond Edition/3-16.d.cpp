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
delete������������ĳ���ʱ��
�����õ�ʱ�临�Ӷ�ΪO(N^2)
*/ 
