#include<stdio.h>
#include<math.h>
int rightrot(int x,int n);//���ؽ�xѭ������nλ�����õ�ֵ
main(){
	int x,n;
	printf("���������֣�\n");
	scanf("%d",&x);
	printf("�������ƶ���λ����\n");
	scanf("%d",&n);
	printf("�ƶ������ֵΪ��%d",rightrot(x,n));
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
