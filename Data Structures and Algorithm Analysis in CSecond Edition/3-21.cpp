#include"Ë«Ïò—£.h"
int main()
{
	int n,i;
	int c;
	Stack S1,S2;
	CreateStack(&S1,&S2,MAXSIZE);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&c);
		Push(c,S1,S2);
		Push(c,S2,S1);
	}
	PrintStack(S1,S2);
	PrintStack(S2,S1);
	return 0;
}
