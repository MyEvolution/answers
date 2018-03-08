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
用数组实现，每删除一个元素的平均时间复杂度为O(lN)；
而遍历的时候会将每个元素都进行遍历 所以总的时间复杂度为O(N^3) 
*/
