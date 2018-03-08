#include<stdio.h>
#include<string.h>
void itoa(int n,char a[],int b);
main(){
	int n,b;
	char a[1000];
	scanf("%d %d",&n,&b);
	itoa(n,a,b);
	printf("%s",a);
	
	
}
void reverse(char a[]){
	int i=0,j=strlen(a)-1;
	char temp;
	for(;i<=j;i++,j--){
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
}
void itoa(int n,char a[],int b){
	int num;
	int i=0,j=0;
	if((num=n)<0) num=-num-1;
	do{
		
		a[i++]=num%10+'0';
		a[i]='\0';
		num/=10;
	}while(num>0);
	if(n<0) {
		while(a[j]>'9'){
			a[j++]='0';
			if(a[j]=='\0') a[j]='0';
			a[j]+=1;
		}
		if(j>=i) i=j+1;
		a[i++]='-';
		a[i]='\0';
	}
	while(i<b){
		a[i]=' ';
		i++;
		
	}
	reverse(a);
	
}
