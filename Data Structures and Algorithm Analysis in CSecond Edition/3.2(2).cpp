#include"Ë«ÏòÁ´±í.h"
int main()
{
	DoubleLink D;
	int n,i;
	int num[1000];
	CreateDList(&D);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	Insert(num[i],D,D->First);
	}
	zprintlist(D);
	fprintlist(D);
	Exchange(D,D->First->Next);
	zprintlist(D);

}
