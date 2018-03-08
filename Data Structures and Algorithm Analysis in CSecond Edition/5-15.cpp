#include"©ию╘и╒ап.h"
int main()
{
	HashTable H;
	H=InitailizeTable(2);
	int n;
	scanf("%d",&n);
	int i,c;
	for(i=0;i<n;i++)
	{
		scanf("%d",&c);
		H=Insert(c,H);
	}
   PrintTable(H);
   getchar();
	return 0;
}
