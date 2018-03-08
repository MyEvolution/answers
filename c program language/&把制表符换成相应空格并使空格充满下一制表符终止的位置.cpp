#include<stdio.h>
#define tab 8// 制表符占8个位置 
main(){
	int c;
	int b,a;
	int p,i=0,m=0;//记录制表符的位置 
	
	while((c=getchar())!=EOF){
		i++;
		if(c=='\n'){
			m=i=0;
		}
		if(c=='\t'){
			
			b=(i-m)%tab;a=(i-m)/tab;
				if(b!=0) a=a+1;
		
		for(p=0;p<=(a*tab-i+m);p++){
			putchar(' ');
		}
		m=i;
	
	}
	else putchar(c);
	

	}
}
