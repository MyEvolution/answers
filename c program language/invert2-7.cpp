#include<stdio.h>
#include<math.h>
int invert(int x,int p,int n);//对x从p位开始的n位求反；
main(){
	int x;
	int p,n;
	printf("输入要进行操作的数字：\n");
	scanf("%d",&x);
	printf("输入要操作的位数（如4 3）：\n");
	scanf("%d %d",&p,&n);
	printf("%d",invert(x,p,n));
} 
int invert(int x,int p,int n){
	int m=pow(2,(p+1-n));
	return (~x|~m)&(x|m);
}
