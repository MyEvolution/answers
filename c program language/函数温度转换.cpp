#include<stdio.h>
double changeFtoC(double f);
main(){
	
	int upper=300;
	int lower=0;
	int step=20;
	double i;
	
	for(i=lower;i<=upper;i+=step){
		printf("%3.0f\t%3.1f\n",i,changeFtoC(i));
	}
	
} 
double changeFtoC(double f){
	return 5*(f-32)/9;
}
