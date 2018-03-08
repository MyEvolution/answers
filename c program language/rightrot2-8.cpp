#include<stdio.h>
#include<math.h>
int rightrot(int x,int n);//返回将x循环右移n位后所得的值
main(){
	int x,n;
	printf("请输入数字：\n");
	scanf("%d",&x);
	printf("请输入移动的位数：\n");
	scanf("%d",&n);
	printf("移动后的数值为：%d",rightrot(x,n));
} 
int rightrot(int x,int n){
	int m=0;
	int i;
	int b=x;
	while(b!=0){
		b=b/2;
		m++;
	}

	for(i=0;i<n%m;i++){
		
		x=(x>>1)+((x&1)<<(m-1));
		
	}
	return x;
}
