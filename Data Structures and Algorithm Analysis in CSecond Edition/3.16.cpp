#include"array_list.h"
#define MAXSIZE 1000
int main()
{
	int n;
	int c;
	int i;
	List L=CreateList(MAXSIZE);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&c);
		Insert(c,i,L);
	}
	PrintList(L);
	Deletethesame(L);
	PrintList(L);
	return 0;
	
}
/*
������ʵ�֣�ÿɾ��һ��Ԫ�ص�ƽ��ʱ�临�Ӷ�ΪO(lN)��
��������ʱ��Ὣÿ��Ԫ�ض����б��� �����ܵ�ʱ�临�Ӷ�ΪO(N^3) 
*/
