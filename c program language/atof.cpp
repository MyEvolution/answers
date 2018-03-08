#include<stdio.h>/*求和计算（支持浮点）*/ 
#include<ctype.h>
double atof(char a[]);
int getline(char s[],int lim);
main(){
double sum;
double atof(char []);
char line[100];

sum=0;
while(getline(line,100)){

	
	printf("\t%g\n",sum+=atof(line));} 
	return 0;

}
int getline(char s[],int lim){
	int c;
	int i=0; 
	while(--lim>=0&&(c=getchar())!=EOF&&c!='\n'){
		s[i++]=c;
	
	}
		s[i]='\0';
		    
       return i;
  

}
double atof(char a[]){
	int i;
	int sign;
double num;
double power;
	for(i=0;isspace(a[i]);i++)
		;
	sign=(a[i]=='-')?-1:1;
	for(;a[i]=='+'||a[i]=='-';i++)
	          ;
	for(num=0.0;isdigit(a[i]);i++){
		num=num*10+a[i]-'0';
	}
	if(a[i]=='.') i++;
	for(power=1.0;isdigit(a[i]);i++)
	power*=10,num=num*10+a[i]-'0';
	return sign*num/power;
	}
