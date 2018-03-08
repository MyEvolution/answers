#include"4.11.h"
int main()
{
	BinTree T;
	T=CreateTree();
	int i;
	int n,c;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&c);
		Insert(c,T);
	}
	PrintTree(T);
	putchar('\n');
	Delete(5,T);
	PrintTree(T);
	putchar('\n');
	printf("%d %d\n",(FindMax(T))->Element,(FindMin(T))->Element);
	return 0;
}
