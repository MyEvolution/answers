#include"Spaly_Tree.h"
int main()
{
	int n;
	int i,c;
	scanf("%d",&n);
	SplTree T=NULL;
	for(i=n;i>=1;i--)
     T=Insert(i,T);	
	PrintTree(T);
	T=Find(1,T);
	printf("\n**********\n");
	
	PrintTree(T);
    return 0;
}
