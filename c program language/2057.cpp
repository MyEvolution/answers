#include<stdio.h>
main()
{
	__int64 a,b;
	while(scanf("%I64X%I64X",&a,&b)!=EOF)
	{
		printf((a+b<0)?"-%I64X\n":"%I64X\n",a+b<0?-a-b:a+b);//�޷���������������cλ������ǿ��ת���ѵ�һλ1��ʾ����ת��Ϊ��ʾһλ���֡����Ը���Ҫȡ����ֵ 
	}
}
	
