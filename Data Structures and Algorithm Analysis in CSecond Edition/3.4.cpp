#include"list.h"
main()
{
	List L,P;
	Position Q,O;
	L=Create();
	P=Create();
	int n;
	int m;
	int i;
	int num[1000];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
		Insert(num[i],L,ToLast(L));
	}
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&num[i]);
		Insert(num[i],P,ToLast(P));
	}
	
	Q=P->Next;
	
	/*while(Q!=NULL)
	{
	Delete(Q->Element,L);
	Q=Q->Next;	
	}*/
	while(Q!=NULL)
	{
		if(!Find(Q->Element,L))
		Insert(Q->Element,L,L);
		Q=Q->Next;
	}
	
    
    printlist(L);
    
}
