#include"AvlTree.h"
int main()
{
	int Height;
	AvlTree T;
	scanf("%d",&Height);
	T=GetDreamAvl(Height);
	PrintTree(T);
	printf("**************************\n");
	T=GetFewestAvl(Height);
	PrintTree(T);
	return 0;
}
