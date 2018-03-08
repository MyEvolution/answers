#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#define ERROR 0
#define OK 1
#define MAXSIZE 1000
#define NUMB '0'
#define SIN '1'
#define COS '2'
#define EXP '3'
void print();
int buf[MAXSIZE];
int bufe=0;
void clear(void);
char s[MAXSIZE];
int j=0;
void push(double a);
double pop(void);
double val[MAXSIZE];//��; 
 char gettop(char s[]);

main(){printf("��������ȷ���沨��ʽ�ӣ�������С��������:\n");
       double m;
	   int type;
	   double o[MAXSIZE];//4-6���������ֵ�ı��� 
	   int O=0;
	while((type=gettop(s))!=EOF){
		switch(type){
			case NUMB:{
				push(atof(s));
				break;
			}
			case '+':{
				push(pop()+pop());
				break;
			}		
			case '-':{
				m=pop();
				push(pop()-m);
			
				break;
			}
			case '*':{
				push(pop()*pop());
				break;
			}
			case '/':{
				m=pop();
				if(m!=0) push(pop()/m);
				else {
				printf("ERROR������Ϊ�㣡\n");
			     clear();
					}
				break;
			}
			case'%':{
				int n;
				n=pop();
				if(n!=0) push((int)pop()%n);
				else {
				printf("ERROR������Ϊ�㣡\n");
			       clear();     
						}
				break;
			} 
			case '^':{
				m=pop();
				push(pow(pop(),m));
				break;
			}
			case EXP:{
				push(exp(pop()));
				break;
			}
			case SIN:{
				push(sin(pop()));
				break;
			}
			case COS:{
				push(cos(pop()));
				break;
			}
			case'\n':{
				if(j>1) {
				printf("��������޷��ó�������\n");
				clear(); }
				else printf("%g\n",o[O++]=pop());
		
				break;
			}
			default:{
				printf("ERROR������δ֪���ţ�\n");
				clear();
				break;
			}
			}
		
	}
	return OK;
}
char getch(void){
	return (bufe>0)?buf[--bufe]:getchar();
}
/*void ungetch(int c){
	if(bufe>MAXSIZE) printf("�������ٵ�!\n");//��Ȼ�����ܻ����   ����Ա�������� 
	else buf[bufe++]=c;
}*/
char gettop(char s[]){
	int c,i=0;
	static int un=EOF;
	if(un!=EOF){
	
       c=s[0]=un;}
       else c=s[0]=getch();
    while(s[0]==' '||s[0]=='\t'){
    	c=s[0]=getch();
		
	}
	s[1]='\0';
	if(!isdigit(c)&&c!='.'&&c!='('&&c!=')'&&c!='s'&&c!='c'&&c!='e') return c;
	if (c=='c') {
	getchar();
	getchar();
     return COS;}
     if(c=='s'){
     	getchar();
     	getchar();
     	return SIN;
	 }
	 if(c=='e'){
	 	getchar();
	 	getchar();
	 	return EXP;	 }
	if(c==EOF) return EOF;

	if(isdigit(c)) 
	while(isdigit(s[++i]=c=getch()))
	     ;
    if(c=='.')
    while(isdigit(s[++i]=c=getch()))
	     ;
	if(c=='(') {
	
	while((s[i++]=c=getch())!=')')
	;
	s[--i]='\0';}
	if(c!=EOF&&c!=')')
	un=c; 
	
	return NUMB;
}
void push(double a){
	val[j++]=a;
	val[j]='\0';
}
double pop(void){
	double p;
	p=val[--j];
	val[j]='\0';
	return p;
}
void clear(void){
	val[0]=='\0';
	j=0;
}
void print(void){//��ӡջ��Ԫ�� 
	double p;
	p=pop();
	printf("%g\n",p);
	push(p);
	
}
void exchange(void){//����ջ��������Ԫ�� 
	double p,q;
	p=pop();
	q=pop();
	push(p);
	push(q);
}
void copy(void){//����ջ��Ԫ�� 
	double p;
	p=pop();
	push(p);
	push(p);
}
/*void ungets(char s[]){

	while(j>0)
	ungetch(s[--j]);
}*/
/*4-8//ѹ��һ���ַ� 
int buf=EOF;
int getch(void){
int m
if((m=buf)!=EOF){
buf=EOF;
return m;


}
else return getchar();}
void ungetch(){
if(buf==EOF)
buf=c;
else printf("����\n");}*/

