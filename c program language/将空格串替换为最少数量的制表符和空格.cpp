#include<stdio.h>
#define TAB 8//制表符 
main(){
	int c,i; 
	int pos=1;//记录当前文本的位置 
	int b=0;//记录未输出的字符中第一个字符的位置 
	for(pos=1;(c=getchar())!=EOF;pos++){
			if(c=='\n') {pos=0;											
		b=0;
		putchar(c);	} //遇到回车后初始化 
		
		else if(c==' '){
			b=pos;
			while(c==' '){
			
		      if(pos%TAB==0){
		      	putchar('\t');
		      	b=pos+1;
			      }
			    c=getchar();
		      pos++;
			  }
			  for(i=0;i<pos-b;i++){
			  	putchar(' ');
			  }
			  putchar(c);
			}
		else putchar(c);	

		}
	}
	

