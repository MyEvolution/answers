#include"Ë«É¢ÁÐ.h"
int main()
{
	HashTable H;
	H=InitailizeTable(11);
	int i,n,c;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&c);
		Insert(c,H);
	}
	PrintTable(H);
	H=ReHash(H);
	printf("**************************\n");
	PrintTable(H);
	return 0;
 } 
