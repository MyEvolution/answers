#include<stdio.h>
#define TAB 8//�Ʊ�� 
main(){
	int c,i; 
	int pos=1;//��¼��ǰ�ı���λ�� 
	int b=0;//��¼δ������ַ��е�һ���ַ���λ�� 
	for(pos=1;(c=getchar())!=EOF;pos++){
			if(c=='\n') {pos=0;											
		b=0;
		putchar(c);	} //�����س����ʼ�� 
		
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
	

