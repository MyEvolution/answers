#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define MAXSIZE 1000 
#define NUMB '0'

int getline(char []);
char s[MAXSIZE];//����ʽ�� 
char q[MAXSIZE];//�������� 
int j=0;//���Ɨ� 
int i=0;
double val[MAXSIZE];//�� 
void push(double a);
double pop(void);
void clear(void);
int exnum(char []);

main(){;

printf("**************************��������ֻ֧�ּӼ��˳���������***********************\n");
printf("��������ȷ���沨��ʽ�ӣ��������������𣩣�\n");
double n;
	while(getline(s)){

		while(s[i]!='\0'){
		
	
		switch(exnum(s)){
			case NUMB:{
				push(atof(q));
				break;
			}
			case '+':{
				push(pop()+pop());
				i++;
				break;
			}		
			case '-':{
				n=pop();
				push(pop()-n);
			i++;
				break;
			}
			case '*':{
				push(pop()*pop());
				i++;
				break;
			}
			case '/':{
				n=pop();
			
				if(n!=0){
				 push(pop()/n);i++;}
				else {
				printf("ERROR������Ϊ�㣡\n");
			     clear();
			     i=0;
			     s[i]='\0';
					}
					
				break;
			}
			
			default: i++;break;
		}
			 
			 
			}
		if(j>1) {
				printf("��������޷��ó�������\n");
				clear(); }
				else printf("%g\n",pop());
				i=0;	
		}
		
 
		}
int getline (char s[]){
	int c;
     int l=0;
	while((c=getchar())!=EOF&&c!='\n'){
	
	s[l++]=c;
	}
	s[l]='\0';
    return l;
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
int exnum(char s[]){
	int m=0;
	for(;isspace(s[i]);i++)
			       ;
			if(s[i]=='('){
			i=i+1;
				for(;s[i]!=')';i++) 
				     q[m++]=s[i];
		q[m-1]='\0';
		m=0;
				return NUMB;   }
			else if(isdigit(s[i])){
				
				for(;isdigit((q[m]=s[i]));i++,m++)
				          ;
				if(s[i]=='.') i++,m++;
					for(;isdigit((q[m]=s[i]));i++,m++)
				         ;
				  q[m]='\0';
				  
				  m=0;    
				     
		
				return NUMB;
			}
		else return s[i];
				}

