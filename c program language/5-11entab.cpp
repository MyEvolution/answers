#include<stdio.h>
#include<stdlib.h>
#define TABINC 8//默认制表符停止
#define MAX 10//参数不得超过10
#define MAXLEN 1000 
void spacetotab(char [][MAX],int n);
main(int argc,char **argv){
	char a[MAXLEN/MAX][MAX];
	if(argc>1) spacetotab(a,atoi(argv[1]));
	else spacetotab(a,TABINC);
	
	
} 
void spacetotab(char a[][MAX],int tabinc){
int c;
	int i=0;//记录第二个下标 
	int j=0;//记录第一个下标 
	int m,n;
while((c=getchar())!=EOF){

if(i<tabinc&&c!='\n')
  a[j][i++]=c;
  if(c=='\t') j++,i=0;
  if(i==tabinc&&a[j][i-1]==' '){
  	i=i-1;
  	for(i;i>=0&&a[j][i]==' ';i--)
  	         ;
  	a[j][i+1]='\t';
	  j++,i=0;         
  		}
  if(i>=tabinc) j++,i=0;
  if(c=='\n'){
  		for(m=0;m<j;m++)
	  for(n=0;n<tabinc;n++){
	  
	   if(a[m][n]!='\t') printf("%c",a[m][n]);
	   else {
	   printf("%c",a[m][n]);
	   break;
	         }
	   }
	   
	  for(m=j,n=0;n<i;n++){
	  
	   if(a[m][n]!='\t') printf("%c",a[m][n]);
	   else{
	   printf("%c",a[m][n]);
	   break;
	   }
	  }
	  
	  i=0,j=0;
	  putchar('\n');
  }		
}
}
  
  
  


