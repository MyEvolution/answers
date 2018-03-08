#include<stdio.h>
#include<ctype.h>
#include<math.h>
double atof(char a[]);
main(){

	char a[1000];
	scanf("%s",&a);
	getchar();

	printf("%g\n",atof(a));


}
double atof(char a[]){
	int i;
	int signo;
	double val,power=1.0;;
	double num;
	double log;
	for(i=0;isspace(a[i]);i++) ;
	signo=(a[i]=='-')?-1:1;
	if(a[i]=='-'||a[i]=='+') i++;
	for(val=0.0;isdigit(a[i]);i++) 
	val=val*10+a[i]-'0';
	while(a[i]!='E'&&a[i]!='e'&&a[i]!='\0'){
	
	if(a[i]=='.') i++;
	for(;isdigit(a[i]);i++){
		val=val*10+a[i]-'0';
		power*=10;
	}}
	num=val/power;

	if(a[i]!='\0') i++;
	
	int signt=(a[i]=='-')?-1:1;
	if(a[i]=='-'||a[i]=='+') i++;
	for(log=0.0;isdigit(a[i]);i++){
		log=log*10+a[i]-'0';
	}
	
return signo*num*pow(10,signt*log);
}
