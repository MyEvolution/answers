#include"平方探测开放定址散列表.h"
int main()
{
	HashTable H;
	H=InitailizeTable(10);
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
