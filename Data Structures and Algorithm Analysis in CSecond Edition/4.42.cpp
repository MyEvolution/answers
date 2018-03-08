#include"Binary_Tree.h"

int main()
{
	BinaryTree T1,T2;
	T1=T2=NULL; 
	int n;
	int i;
	int c;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&c);
		Insert(c,&T1);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&c);
		Insert(c,&T2);
	}
	
	printf("%d %d",IsSimilar(T1,T2),Isomorphic(T1,T2));
}
