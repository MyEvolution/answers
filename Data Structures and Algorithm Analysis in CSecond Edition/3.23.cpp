#include"一个数组3个棧.h"
int main()
{
	Stack s1,s2,s3;
	int a,b,c;
	Create(&s1,&s2,&s3,MAXSIZE);
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		Push(a,s1);
		Push(b,s2);
		Push(c,s3);
	}
	printf("%d %d %d\n",s1->StackSize,s2->StackSize,s3->StackSize);
	PrintWhole(s1,s2,s3);
}
