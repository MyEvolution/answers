#include <stdio.h>
#include<stdlib.h>
#define		MAX	10	//参数最大为10 
#define		TABINC		8		//默认地制表符停止位
#define MAXLINE 1000

void tabtospace(char a[100][10],int tabinc);//用二维数组来储存，不过缺点会造成空间浪费 
main(int argc,char**argv){
	int c;
	char a[100][MAX];
	if(argc>1) tabtospace(a,atoi(argv[1]));
	else tabtospace(a,TABINC);
	
}
void tabtospace(char a[][10],int tabinc){
 
int c;
	int i=0;//记录第二个下标 
	int j=0;//记录第一个下标 
	int m,n;
while((c=getchar())!=EOF){

if(i<tabinc&&c!='\t'&&c!='\n')
  a[j][i++]=c;



else if(c=='\t')
	for(;i<tabinc;i++)
	
	   a[j][i]=' ';
	if(i>=tabinc) i=0,j++;
       if(c=='\n'){
	for(m=0;m<j;m++)
	  for(n=0;n<tabinc;n++)
	    printf("%c",a[m][n]);
	  for(m=j,n=0;n<i;n++)
	  putchar(a[m][n]);  
	  i=0,j=0;
	  putchar('\n');
}


}}
