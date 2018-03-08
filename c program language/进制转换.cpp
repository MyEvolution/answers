#include<stdio.h>
#include<string.h>
void reverse(char a[]);
void itob(int n,char s[],int b);
void itoa(int n,char a[]);
main(){
printf("      *本转换器适用范围为-2147483648-2147483647*\n");
	int n;
	printf("请输入要转换的十进制数字：\n");
	scanf("%d",&n);
	int b;
	printf("请输入要转化为的进制数：\n");
	scanf("%d",&b);
	char line[1000];
	getchar();
	itob(n,line,b);
	printf("转化后的数字为：\n");
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

void itob(int n,char s[],int b){
	int num;
	char c[b];
	int p=0;
	int i=0;
	int j=0;
if((num=n)<0) num=-num-1;
	if(b<=10){
		
	do{
		s[i++]=num%b+'0';
		num/=b;
      s[i]='\0';
		
	}while(num>0);
	if(n<0) {  
	
	s[0]+=1;
	while(s[j]>(b+'0')){
		s[j++]='0';
		if(s[j]=='\0') s[j]='0';
		s[j]+=1;
	
	}
	if(j>=i) i=j+1;
	s[i++]='-';
	s[i]='\0';
	
	
	
	}}
	else {
			
		printf("请依次输入代表小于%d数字的字符（如b=16，输入0123456789abcdef代表0到15）：\n",b);
		while(p<b){
			scanf("%c",&c[p++]);
			
		}
	  
			do{
		s[i++]=c[num%b];
		num/=b;
      s[i]='\0';
		
	}while(num>0);
	if(n<0){
	n=-n-1;
		s[0]=c[n%b+1];
		while(n%b+1>b-1){
			
			s[j++]=c[0];
			n=n/b;
			s[j]=c[n%b+1];
		}
		if(j>=i) i=j+1;
		s[i++]='-';
		
	
	}
	s[i]='\0';
		
	}
	reverse(s);
}
