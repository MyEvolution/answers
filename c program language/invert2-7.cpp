#include<stdio.h>
#include<math.h>
int invert(int x,int p,int n);//��x��pλ��ʼ��nλ�󷴣�
main(){
	int x;
	int p,n;
	printf("����Ҫ���в��������֣�\n");
	scanf("%d",&x);
	printf("����Ҫ������λ������4 3����\n");
	scanf("%d %d",&p,&n);
	printf("%d",invert(x,p,n));
} 
int invert(int x,int p,int n){
	int m=pow(2,(p+1-n));
	return (~x|~m)&(x|m);
}
