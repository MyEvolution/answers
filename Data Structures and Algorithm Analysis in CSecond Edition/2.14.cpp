#include<stdio.h>//��С��n����������
#include<stdlib.h>

void printprime(int n)
{
	int i,j; 
	int *a=(int *)malloc((n-1)*sizeof(int));
for(i=0;i<n-1;i++)
a[i]=i+2;
for(i=0;a[i]*a[i]<=n;i++)//��i>����nʱ����û�б�Ҫ�� ,������˵���һ�����С��������ǰ���ظ��� 
{                         //
	if(a[i]==0)
	continue;
	j=2;
	while(a[i]*j<=n)//?
	{
		a[a[i]*j-2]=0;//��Ϊ���е��������±��ȥ2 
		j++;
	 }
    }
    for(i=0;i<n-1;i++)
    if(a[i]!=0)
    printf(i==0?"%d":" %d",a[i]);
    putchar('\n');
    free(a);
}
main()
{
	int n;
	scanf("%d",&n);
	printprime(n);
 } 
