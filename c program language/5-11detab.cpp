#include <stdio.h>
#include<stdlib.h>
#define		MAX	10	//�������Ϊ10 
#define		TABINC		8		//Ĭ�ϵ��Ʊ��ֹͣλ
#define MAXLINE 1000

void tabtospace(char a[100][10],int tabinc);//�ö�ά���������棬����ȱ�����ɿռ��˷� 
main(int argc,char**argv){
	int c;
	char a[100][MAX];
	if(argc>1) tabtospace(a,atoi(argv[1]));
	else tabtospace(a,TABINC);
	
}
void tabtospace(char a[][10],int tabinc){
 
int c;
	int i=0;//��¼�ڶ����±� 
	int j=0;//��¼��һ���±� 
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
