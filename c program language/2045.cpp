#include<stdio.h>
int num(int n)
{
if(n==1)
 return 3;
 else if(n==2)///�ų�һ�ŵ�n�鷽�񣬵�һ������һ����ɫ��ͬ��������n��ǰ�Ĳ��������һ��ֻ��һ��ѡ�� 
 return 6;//��ǰn-1�����Ļ�������ԭ���еĻ��������1ͬɫ��  ��ʱ��������ѡ�� 
 else if(n==3)//���������㡣����n=2ʱ��û�еڶ���ѡ�� 
 return 6;
 else return num(n-1)+2*num(n-2);

	
}
main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",num(n));
	}
}
