#include<stdio.h>
int bitcount(unsigned x);//统计整形参数的值为一的二进制位的个数
main(){
	int x;
	printf("请输入num：");
	scanf("%d",&x);
	printf("转化为二进制后位数为1的有%d位\n",bitcount(x));

	
} 
int bitcount(unsigned x){
	int m=0;
	while(x){
		
		x&=(x-1);/*若末尾为1，则-1使末尾为0，其他位&运算不变；
		          若末尾不为1，则-1使最右的1向右移动，末尾变为1，其他位不变，&运算后，末尾和该位转为0.*/ 
		m++;
		
	}
	return m;
}
