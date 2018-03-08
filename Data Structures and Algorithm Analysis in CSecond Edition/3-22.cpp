#include"3.22.h"
#define MAXSIZE 1000
int main()
{
	int n,i;
	int c;
	Stack S;
	S=Create(MAXSIZE);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&c);
		Push(c,S);
	}
	PrintStack(S);
	printf("%d\n",FindMin(S));
	Pop(S);
	PrintStack(S);
	printf("%d\n",FindMin(S));
	return 0;
}
