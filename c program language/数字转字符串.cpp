#include<stdio.h>
#include<string.h>
void reverse(char a[]);//���ַ����������� 
void itoa(int n,char a[]);//������ת��Ϊ�ַ��� 
main(){
	int num;
	char line[1000];
	scanf("%d",&num);
	itoa(num,line);
	printf("%s",line);
	
}
void reverse(char a[]){
	int i,j;
	char temp;
	for(i=0,j=strlen(a)-1;i<=j;i++,j--){
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}

}
void itoa(int n,char a[]){
	int num;
	int i=0;
	if((num=n)<0) num=-num;
	do{
		a[i++]=num%10+'0';
		num/=10;
		
	}while(num>0);
	if(n<0) a[i++]='-';
	a[i]='\0';
	reverse(a);
	
}

