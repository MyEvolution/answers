#include<stdio.h>//复制文件a内容到b 
#include<unistd.h>
#include<stdarg.h>
#include<ctype.h>
#include<fcntl.h>
#define PERMS 0666//对所有者，所有者组和其他成员均可读写
void error(char *,...); 
void vvfprintf(FILE*,char *,va_list);
main(int argc,char **argv)
{   char buf[BUFSIZ];
	int f1,f2,n;
	if(argc!=3)
	  error("Usage:cp from to");//usage用法，从一个复制到另一个 
	  if((f1=open(argv[1],O_RDONLY,0))==-1)
	  error("cp:can't open %s",argv[1]);
	    if((f2=creat(argv[2],PERMS))==-1)
	    error("cp:can't create %s,mode %03o",argv[2],PERMS);
	  
	while((n=read(f1,buf,BUFSIZ))>0)
	if(write(f2,buf,n)!=n)
	error("cp:write error on file %s",argv[2]);
	return 0;
}
void error(char *fmt,...)
{
	va_list args;//指向无名参数
	va_start(args,fmt);
	fprintf(stderr ,"error:");
	 vvfprintf(stderr,fmt,args);
	fprintf(stderr,"\n");
	va_end (args);
	exit(1); 
}
void vvfprintf(FILE *f,char *s,va_list ap)
{
	char *p=s;
	char lim[100];
	char *q;
		 int ival;
	 double dval;
	 char *sval;
	while(*p!='\0'){
		 
		if(*p!='%'){
		fprintf(stderr,"%c",*p++);
	continue;
	}
	for(q=lim,*q++=*p++;!isalpha(*p)||*p=='h'||*p=='l';*q++=*p++)
	                      ;
	             *q++=*p;
				 *q='\0';
				 switch(*p){
		 	case 'd':
		 	case 'i':

		 		ival=va_arg(ap,int);
		 		fprintf(f,lim,ival);
		 		break;
		 	case 'u':
		 	case 'x':
		 	case 'X':
		 	case 'o':
		 	case 'c':
			 ival=va_arg(ap,unsigned);
			 fprintf(f,lim,ival);
			 break;		 		
		 	case 'f':
		 	case 'g':
		 	case 'e':
		 	case 'E':
			    dval=va_arg(ap,double);
			    fprintf(f,lim,dval);
			    break;
			case 's':
			    for(sval=va_arg(ap,char *);*sval;sval++)
				   fprintf(f,"%c",*sval);
				   break;
		
			case '%':
			fprintf(f,"%%");
			break;
			case 'p':
				sval=va_arg(ap,char *);
				fprintf(f,lim,(void*)sval);
				break;
			     		 		   
			default:
			fprintf(f,"%c",*p);
			break;	   	
		 }
		 p++;    
	}
	
	
	
	
	
}
