#include"5-7.h"

int main()
{
	int n,m;
	int Co,In;
	int i;
	Monomial M1,M2,M3;
	HashTable H;
	H=InitailizeTable(10);
	M1=CreateMono();
	M2=CreateMono();
	M3=CreateMono();
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&Co,&In);
		MonoInsert(In,Co,M1); 
	}
	scanf("%d",&m);
		for(i=0;i<m;i++)
	{
		scanf("%d %d",&Co,&In);
		MonoInsert(In,Co,M2); 
	}
	Multiply(M1,M2,M3,H);
	printf("***************************\n"); 
	PrintMono(M3);
	return 0;
}
