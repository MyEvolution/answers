#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXLEN 10000
#define TOKENSIZE 100
char buf[MAXLEN];
int bufp=0;
char token[TOKENSIZE];
int tokentype;
int gettoken(void);
int getch(void);
void ungetch(int);
char out[MAXLEN];//Êä³ö´®
enum{NAME,PARENS,BRACKETS};
/*sprintf(char *,const char *,...)  ×Ö·û´®¸ñÊ½»¯ÃüÁî£¬½«×Ö·û´®Ð´Èë»º´æÇø*/ 
main(){
	int type;
	int c;
	char temp[MAXLEN];
	while(gettoken()!=EOF){
		strcpy(out,token);
		while((type=gettoken())!='\n')
		  if(type==PARENS||type==BRACKETS)
		   strcat(out,token);
		   else if(type=='*'){
		   	sprintf(temp,"*%s",out);
		   	strcpy(out,temp);
		   	while((c=getch())=='\t'||c==' ')
		   	      ;
		   	   if(isalpha(c)) 
				  	ungetch(c);
					   else{
					   	ungetch(c);
					   	sprintf(temp,"(%s)",out);
					   	strcpy(out,temp);
					   }
				     
		   }else if(type==NAME){
		   	
		   sprintf(temp,"%s %s",token,out);
		   strcpy(out,temp);}
		   else printf("illegal\n");
		   printf("%s\n",out);
		   
		   
	}
	
	
}


int gettoken(void){
	int c;
	char *p=token;
	
	while((c=getch())==' '||c=='\t')
	      ;
	      if(c=='('){
	      	c=getch();
	      	if (c!=')'){
	      		 ungetch(c);
	      		return tokentype='(';
			  }
			  else {
			  	strcpy(token,"()");
			  	return tokentype=PARENS;
			  	
			  }
		  }
		  else if(c=='[')
		  {
		  	for(*p++=c;(*p++=getch())!=']';)
		  	           ;
		  	           *p='\0';
		  	           return tokentype=BRACKETS;
		  }
		  else if(isalpha(c)){
		  	for(*p++=c;isalnum(c=getch());)
		  	           *p++=c;
		  	           *p='\0';
		  	           ungetch(c);
		  	           return tokentype=NAME;
		  }else return tokentype=c;
}
int getch(void)
{  return bufp>0?buf[--bufp]:getchar();
}
void ungetch(int c)
{
	if(bufp>=MAXLEN) printf("too many!\n");
	else buf[bufp++]=c;
}
