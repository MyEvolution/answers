#include<stdio.h>
#include<stdlib.h>
#define TABINC 8//默认制表符停止位
void tabtospace(int s,int t);
main(int argc,char **argv){
	if(argc<=1) tabtospace(0,TABINC);
	else if(argc==2) tabtospace(0,atoi(argv[1]));
	   else tabtospace(-atoi(argv[1]),atoi(argv[2]));
	   
	   
} 
void tabtospace(int start,int tabinc){
	int c;
	int i=1;

	int j;
	while((c=getchar())!=EOF){
	
		if(i<=start&&c!='\n'){
			if(c!='\t') putchar(c),i++;
			else 
			  for(i;i<=start+tabinc;i++)
			     putchar(' ');
			  
		}
		else if(i>start&&c!='\n'){
			if(c!='\t') putchar(c),i++;
			else {
			
			  for(j=0;j<tabinc-(i-start-1)%tabinc;j++)
			      putchar(' ');
			    i+=j;  
			}
		}
		if(c=='\n')  putchar('\n'),i=1;
		  
		
	}
	
}
