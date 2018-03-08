#include"PriorityQueue.h"

int main()
{
	int m,n;
	int i;
	ElementType Element; 
	PriorityQueue H1,H2;
	H1=H2=NULL;
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++)
	{
		scanf("%d",&Element);
		H1=Insert1(Element,H1);
	 } 
	 	for(i=0;i<n;i++)
	{
		scanf("%d",&Element);
		H2=Insert1(Element,H2);
	 } 
	 	 printf("(((())))\n");
	 PrintHeap(H1);
	 printf("(((())))\n");
	 PrintHeap(H2);
	 printf("((((()))))\n");
	 PrintHeap(Merge(H1,H2));
	 return 0;
}
