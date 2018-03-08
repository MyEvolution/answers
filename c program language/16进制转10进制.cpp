#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define SIZE 1000
long long htoi(char a[]);
main(){
char a[SIZE];
int c;
int i=0;
long long b;
while((c=getchar())!=EOF){
	
if(c!='\n'){
	a[i]=c;
	i++;
}
else {
	a[i]='\0';
	b=htoi(a);
	printf("%lld\n",b);
	i=0;
}
	
}}
long long htoi(char a[]){
	int b=strlen(a);
	int i;
	long long m=0;
	int n[b];
	for(i=0;i<b;i++){
		if(a[i]>='0'&&a[i]<='9'){
		
	n[i]=a[i]-'0';
		}
		else {
				switch(a[i]){
			case'a':n[i]=10;break;
			case'b':n[i]=11;break;
			case'c':n[i]=12;break;
			case'd':n[i]=13;break;
			case'e':n[i]=14;break;
			case'f':n[i]=15;break;
			case'A':n[i]=10;break;
			case'B':n[i]=11;break;
			case'C':n[i]=12;break;
			case'D':n[i]=13;break;
			case'E':n[i]=14;break;
			case'F':n[i]=15;break;
			case'x':n[i]=0;break;
			case'X':n[i]=0;break;
			case'-':n[i]=0;break;
			case'+':n[i]=0;break;
		    default:break;
		}
	}}
	for(i=b-1;i>=0;i--){
		m=pow(16,b-1-i)*n[i]+m;
	}
	if(a[0]=='-') return -m;
else return m;
}
