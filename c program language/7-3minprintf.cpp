#include<stdio.h>
#include<stdarg.h>//���а���һ��궨�壬����α�������������˶���
#include<ctype.h>
#include<stdlib.h>
 void minprintf(char *,...);

 main(){
 /*	char p[100];
 	char fim[100];
 	scanf("%s%s",p,fim);*/
     
 	int a;
 	float b;
 	scanf("%f",&b);
 	minprintf("%lf ",b);
 /*	minprintf(fim,atof(p));
 	minprintf("\n");
 	minprintf("%-8x",17);*/

//��Ҫ���%����ǰ��Ĳ�����Ӧ��������%% 
 
 	
 	
 }
 void minprintf(char *fim,...)
 {
 	va_list ap;//����ָ��ÿ����������
	 char *p,*sval;
	 int ival;
	 double dval;
	 char lim[100];
	 char *q;
	 va_start(ap,fim);
	 for(p=fim;*p;p++)
	 {
	 	if(*p!='%'){
	 		putchar(*p);
	 		continue;
		 }
		 
		 
    for(q=lim,*q++=*p++;!isalpha(*p)||*p=='h'||*p=='l';)
         *q++=*p++;
         *q++=*p;
         *q='\0';
    
		 switch(*p){
		 	case 'd':
		 	case 'i':

		 		ival=va_arg(ap,int);
		 		printf(lim,ival);
		 		break;
		 	case 'u':
		 	case 'x':
		 	case 'X':
		 	case 'o':
		 	case 'c':
			 ival=va_arg(ap,unsigned);
			 printf(lim,ival);
			 break;		 		
		 	case 'f':
		 	case 'g':
		 	case 'e':
		 	case 'E':
			    dval=va_arg(ap,double);
			    printf(lim,dval);
			    break;
			case 's':
			    for(sval=va_arg(ap,char *);*sval;sval++)
				   putchar(*sval);
				   break;
		
			case '%':
			putchar('%');
			break;
			case 'p':
				sval=va_arg(ap,char *);
				printf(lim,(void*)sval);
				break;
			     		 		   
			default:
			putchar(*p);
			break;	   	
		 }
	  } 
	  va_end(ap);//��������ʱ�Ĺ��� 
 }

   	
