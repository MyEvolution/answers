#include<stdio.h>
int three(int n,int m)
{//ԭ��Ҫ��֤��3λһ������ô�������ֵĺ���λҪ��һ�� 
	if(m==1)
	return n%1000;
	else if(m==0)
	return 1;
	else 
	return ((n%1000)*three(n,m-1))%1000;
	
}
main()
{
	int n,m;
	while(scanf("%d %d",&n,&m),n+m)
		printf("%d\n",three(n,m));
	
 } 
