#include"FindKth.h"

int main()
{
	int i,c,n,j;
	Tree T=NULL;
	scanf("%d %d",&n,&j);
	for(i=0;i<n;i++)
	{
		scanf("%d",&c);
		T=Insert(c,T);
	}
	PrintTree(T);
	printf("%d:%d\n",j,FindKth(T,j));
	T=Delete(5,T);
	 	printf("%d:%d\n",j,FindKth(T,j));
	return 0;
}
