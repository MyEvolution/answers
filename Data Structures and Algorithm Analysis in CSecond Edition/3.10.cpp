#include"loop_list.h"
void Jsuiph(int N,int M,List L)
{
	MakeEmpty(L);
	int i;
	int j;
	for(i=N;i>=1;i--)
	  Insert(i,L,L);
	  L=L->Next;
	  while(!IsOnly(L))
	  {
	  	j=0;
	  	while(j<M)
	  	{
	  	L=L->Next;
		  j++;	
		  }
	  	  
	  	  printf("%d ",L->Element);
	  	  Delete(L,L);
	  }
	  printf("%d\n",L->Element);
	
}
main()
{
	int n;
	int m;
	List L;
	L=CreateList();
	while(scanf("%d %d",&n,&m)==2)
	  Jsuiph(n,m,L);
}
