#include<stdio.h>
#include<string.h>
void reverse(char a[]);
void itoa(int n,char a[]);//改进后，可输出最大的负数 
/*有符号的数表示在计算机中负数比正数多一位
在计算机数用补码表示以方便计算负数
-128的补码为10000000*/

main(){int num;
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
	if((num=n)<0) num=-num-1;
	do{
		a[i++]=num%10+'0';
		a[i]='\0';
		num/=10;
		
	}while(num>0);
	if(n<0) {
		a[0]+=1;
int j=0;
while(a[j]>'9'){
	a[j++]='0';
	if(a[j]=='\0') a[j]='0';
	a[j]+=1;
} 
	if(j>=i) i=j+1;
	
	a[i++]='-';}
	a[i]='\0';
	reverse(a);
}
