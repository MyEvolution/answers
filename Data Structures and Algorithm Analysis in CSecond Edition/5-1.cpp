#include"∑÷¿Î…¢¡–±Ì.h"
int main()
{
	HashTable H;
	int i,c,n;
	H=InitailizeTable(10);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&c);
		Insert(c,H);
	 } 
	 PrintTable(H);
	 return 0;
}
