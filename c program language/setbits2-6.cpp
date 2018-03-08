#include <stdio.h>
#include<math.h>
//该函数setbits（x,p,n,y）返回以下结果：将x中从第p位开始的第n个（二进制）位设置为y中最右边n位的值，x其他位置不变 
int setbits(int x, int p, int n,int y);

main(){
	int a,b,p,q;
	printf("输入两个数字（例如29 19）：\n");
	scanf("%d %d",&a,&b);
	printf("输入需要交换的位（例如4 3）：\n");
	scanf("%d %d",&p,&q);
	printf("%d",setbits(a,p,q,b));
}


int setbits(int x, int p, int n,int y)
{     int m=pow(2,(p+1-n));
    return (x |m )& ((y>>(2*n-p-1))|~m);
}
