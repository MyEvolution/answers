#include<stdio.h>
main(){
	int a[12];
	int c,i,num=0;
	for(i=0;i<12;i++){
		a[i]=0;
	}
	while((c=getchar())!=EOF){
		
		if(c>='0'&&c<='9'){
			++a[c-'0'];
		}
		
		else if(c==' '||c=='\n'||c=='\t') a[11]++;
		else a[10]++; 
		
		num++;
	}
	printf("�ַ�����һ����%d���ַ�\n",num);
	for(i=0;i<10;i++){
		printf("������ַ����г�������%d�Ĵ���Ϊ��%d\n",i,a[i]);
		
	}
	
	printf("�հ׷��ĳ��ִ���Ϊ��%d\n",a[11]);
	printf("�����ַ����ִ���Ϊ��%d\n",a[10]);
}
