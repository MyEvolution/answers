#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
void minscanf(char *,...);
main(){
	float  p;
	minscanf("%f",&p);
	printf("%.5f",p);
}
void minscanf(char *fim,...)
{
	va_list ap;//遍历格式串的指针
	char *p;
	int *ival;
	unsigned *uval;
	long *lval;
	short *hval;
	char *cval;
    float *fval;
    double *dval;
		char *sval;
	char lim[100];
	char *q;
	va_start(ap,fim);
	for(p=fim;*p;p++)
	{
		if(*p!='%')
		{
			getchar();
			continue;
		}
	
		for(q=lim,*q++=*p++;!isalpha(*p)||*p=='h'||*p=='l'||*p=='L';p++)
		*q++=*p++;
		*q++=*p;
		*q='\0';
		switch(*p)
		{
			case 'd':
			case 'i':
			case 'o':
			case 'x':
		       if(*(p-1)=='l')
			    {
			   lval=va_arg(ap,long*);
			   scanf(lim,lval);
			   }	
			    else if(*(p-1)=='h') 
				{
					hval=va_arg(ap,short*);
					scanf(lim,hval);
				}
			    else {
			    	ival=va_arg(ap,int*);
			    	scanf(lim,ival);
				}
				break;
			case 'u':		
				uval=va_arg(ap,unsigned*);
				scanf(lim,uval);
				break;
			case 'c':
			    cval=va_arg(ap,char*);
			    scanf(lim,cval);
			    break;
			case 's':
			    for(sval=va_arg(ap,char *);!isspace(*sval=getchar());sval++)
			                          ;
			      *sval='\0';
			      break;
			case 'e':
			case 'f':
			case 'g':
				if(*(p-1)=='l')
				{
					dval=va_arg(ap,double*);
					scanf(lim,dval);
				}
			   else {
			   	fval=va_arg(ap,float*);
			   scanf(lim,fval);
			   }
			   break;
			case '%':
			    break;
			default :
			   getchar();
			   break;	         	
		}
		
	}
	va_end(ap);
	

}

