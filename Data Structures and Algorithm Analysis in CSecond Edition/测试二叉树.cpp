#include"Binary_Tree.h"
int main()
{
	int i;
	int n,c;
    BinaryTree T=NULL;
    T=MakeEmpty(T);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&c);
		Insert(c,&T);
	}
	PrintTree(T);
	putchar('\n');
	Delete(5,&T);
	PrintTree(T);
	printf("\n%d %d",RandnumNotInTree(5,10,T),RandnumInTree(5,10,T));
	
	return 0;
}
