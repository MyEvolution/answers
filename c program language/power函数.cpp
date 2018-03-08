#include<stdio.h>
	int power(int n,int m);
main(){

	int i;
	for(i=0;i<10;++i){
		printf("%d %d\n",power(2,i),power(-3,i));
	}
	} 
	int power(int n,int m){
		int j,p=1;
		if(n==0) return 0;
		else if(m==0||n==1) return 1;
		else{
		
		for(j=1;j<=m;++j){
		
		p=p*n;}
		return p;
		}
		
	}
	
	

