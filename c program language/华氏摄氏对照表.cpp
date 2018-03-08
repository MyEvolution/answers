#include<stdio.h>
main(){
	printf(" 华氏温度和摄氏温度对照表\n");
	float f,c;
	int upper,lower;
	int step=20;
	upper=300;
	lower=0;
	f=0;
	while(f<=upper){
		c=5*(f-32)/9;
		printf("%3.0f\t%6.1f\n",f,c);
		f=f+step;
		
	}
	
	
} 
