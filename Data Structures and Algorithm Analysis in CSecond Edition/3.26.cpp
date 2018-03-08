#include"双端队列.h"
int main()
{
	Queue Q;
	Q=Create();
	int n;
	int i;
	int c;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&c);
		Push(c,Q);//从队头插入 
		Inject(c,Q);//从队尾插入 
	}
	Print(Q);
	return 0;
}
