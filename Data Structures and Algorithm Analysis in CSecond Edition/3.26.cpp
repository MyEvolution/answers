#include"˫�˶���.h"
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
		Push(c,Q);//�Ӷ�ͷ���� 
		Inject(c,Q);//�Ӷ�β���� 
	}
	Print(Q);
	return 0;
}
