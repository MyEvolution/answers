#include <stdio.h>
#include<math.h>
//�ú���setbits��x,p,n,y���������½������x�дӵ�pλ��ʼ�ĵ�n���������ƣ�λ����Ϊy�����ұ�nλ��ֵ��x����λ�ò��� 
int setbits(int x, int p, int n,int y);

main(){
	int a,b,p,q;
	printf("�����������֣�����29 19����\n");
	scanf("%d %d",&a,&b);
	printf("������Ҫ������λ������4 3����\n");
	scanf("%d %d",&p,&q);
	printf("%d",setbits(a,p,q,b));
}


int setbits(int x, int p, int n,int y)
{     int m=pow(2,(p+1-n));
    return (x |m )& ((y>>(2*n-p-1))|~m);
}
