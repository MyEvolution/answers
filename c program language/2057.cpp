#include<stdio.h>
main()
{
	__int64 a,b;
	while(scanf("%I64X%I64X",&a,&b)!=EOF)
	{
		printf((a+b<0)?"-%I64X\n":"%I64X\n",a+b<0?-a-b:a+b);//无符号输出，所以如果c位负数会强制转化把第一位1表示－号转化为表示一位数字。所以负数要取绝对值 
	}
}
	
