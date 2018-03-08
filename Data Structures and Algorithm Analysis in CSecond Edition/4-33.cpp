#include"×ø±êÊ÷.h"

int main()
{
	SearTree T=NULL;
	int n;
	int i,c;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&c);
		T=Insert(c,T,0);
	}
	GetX(T);
	GetY(T);
	PrintTree(T);
	return 0;
}
