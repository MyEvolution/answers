#include"lazylist.h"
int main()
{
	Head H;
	H=Create();//fuck   在这里耗了一下午！！只是因为一个简单的问题！！！ 

	int n,i;
	int c;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&c);
	
		Insert(c,H->L,H);
	}
	Print(H);
	for(i=0;i<n;i++)
	{
		Delete(i,H);
		Print(H);
	}
	return 0;
}
