#include"×ø±êÊ÷.h"
int main()
{
	int n,i,c;
	scanf("%d",&n);
	Queue Q;
	Q=CreateQueue();
	SearTree T=NULL;
	for(i=0;i<n;i++)
	{
		scanf("%d",&c);
		T=Insert(c,T,0);
	}
	GetX(T);
	GetY(T); 
	PrintTree(T);
	printf("\n****************************\n");
	PrintByFloor(T,Q);
	return 0;
}

