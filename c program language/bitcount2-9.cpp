#include<stdio.h>
int bitcount(unsigned x);//ͳ�����β�����ֵΪһ�Ķ�����λ�ĸ���
main(){
	int x;
	printf("������num��");
	scanf("%d",&x);
	printf("ת��Ϊ�����ƺ�λ��Ϊ1����%dλ\n",bitcount(x));

	
} 
int bitcount(unsigned x){
	int m=0;
	while(x){
		
		x&=(x-1);/*��ĩβΪ1����-1ʹĩβΪ0������λ&���㲻�䣻
		          ��ĩβ��Ϊ1����-1ʹ���ҵ�1�����ƶ���ĩβ��Ϊ1������λ���䣬&�����ĩβ�͸�λתΪ0.*/ 
		m++;
		
	}
	return m;
}
