#include<stdio.h>
#include<ctype.h>
#define SIZE 10
int buf[10];
int bufe=0;
int getch(void);
void ungetch(int);
int getint(int *);
main(){
	int n,array[SIZE];
	int i;
	int c;
	for(n=0;n<SIZE&&getint(&array[n])!=EOF;n++)
	             ; 
	for(i=0;i<n;i++){
		printf("%d %d\n",i,array[i]);
		
	}

		
	
} 
int getint(int *pn){//�����벻�����ֺͽ�����ʱ  ����0��������Ϊ����ʱ������һ�����룬�����ָ�ֵ��*pn 
	int c;
	int d;//���������� �Ӽ�ʱ����ѹ������ 
	int sign;
	while(isspace(c=getch()))//�����հ׷� 
	    ;
	if(!isdigit(c)&&c!=EOF&&c!='+'&&c!='-'){
		ungetch(c);
		return 0;
	}
	sign=(c=='-')?-1:1;
	if(c=='-'||c=='+')    {
	
	d=getch();
	if(isdigit(d)) 
	c=d;
	else {
	ungetch(c);return 0;}}
	
	for(*pn=0;isdigit(c);c=getch())
	    *pn=10**pn+c-'0';
	*pn*=sign;
	if(c!=EOF) ungetch(c);
	 return c;
}
int getch(void){
	return (bufe>0)?buf[--bufe]:getchar();
}
void ungetch(int c){
	if(bufe>SIZE) printf("�������ٵ�!\n");//��Ȼ��tai���ܻ����   �������� 
	else buf[bufe++]=c;
}
