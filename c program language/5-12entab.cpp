#include<stdio.h>
#include<stdlib.h>
#define TABINC 8
void spacetotab(int n,int m);//从n列开始，隔m-1行一个制表符停止位 
main(int argc,char**argv){
	if(argc<=1) spacetotab(0,TABINC);
	else if(argc==2) spacetotab(0,atoi(argv[1]));
	   else spacetotab(-atoi(argv[1]),atoi(argv[2]));
	   
}
void spacetotab(int start,int tabinc){
	
	int c;
	int i=1;//记录当前位置 
	int m,j;
	while((c=getchar())!=EOF){
		if(i<=start&&c!='\n'&&c!=' '){
			if(c=='\t')  putchar(c),i=tabinc+start+1;
			else putchar(c),i++;
	
		}
	else if(i>start&&c!='\n'&&c!=' '){
		if(c=='\t') putchar(c),i=i+tabinc+(i-start)%tabinc;
		else putchar(c),i++;
		
	}	
	if(c==' '&&(j=i)){
	
	while(c==' '){
			c=getchar();
		j++;
	if((j-start-1)%tabinc==0) putchar('\t'),i=j;
	}
	for(m=0;m<j-i;m++) putchar(' ');
	if(c!='\n') putchar(c);
	 }

	if(c=='\n') putchar('\n'),i=1;
	}
}

