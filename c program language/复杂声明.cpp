#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAXLINE 1000 
#define MAXTOKEN 100
int tokentype;//���һ���Ǻŵ����� 
char token[MAXTOKEN];//���һ���Ǻ� 
enum{NAME,PARENS,BRACKETS};//��������ͣ�����ö�� 
char out[MAXLINE];
char datatype[MAXTOKEN];//��������int��char�ȵ� 
char buf[MAXLINE];
int bufp=0;
char name[MAXTOKEN];
int gettoken(void);
void dcl(void);
void dirdcl(void);
int getch(void);
void ungetch(int);
int error[3];//����1 Ϊ�������� 
char tokenbuf[10][MAXTOKEN];//������ ����token[]; 
int tokenbufp[10];//����tokentype 
int t;//�±� 
int checkabc(void);
void ungettoken(char *s,int p); 
char function[10][10];//�����Ĳ��� <10
int lf=0,f=0;
main(){
	int i;
	int j=0;
	char temp[MAXTOKEN];
	while(gettoken()!=EOF)
	{   
	    out[0]='\0';
	    name[0]='\0';
	 for(i=0;i<3;i++)
	       error[i]=0;
	if(tokentype==NAME)
		strcpy(datatype,token);
	     else {
		      strcpy(datatype,token);
	           error[0]=1;
			   }
			   if(checkabc()){
   				
   			
    if(gettoken()==NAME){
    	 strcpy(temp,token);
    	if(gettoken()!=PARENS&&tokentype!=BRACKETS&&tokentype!='\n')
    	    {
			ungettoken(token,tokentype);
			
    	    strcat(datatype," ");
			strcat(datatype,temp);
    	    dcl();
			}
    	    else //�ڶ�������������֣�Ӧ�ý���dirdcl����
			{  ungettoken(token,tokentype);  
			   ungettoken(temp,NAME);
				dcl();
			}
    	    
			}
    }
		
	else dcl();
	
		if(tokentype=='\n'&&error[0]!=1&&error[1]!=1&&error[2]!=1) 
		 printf("%s:%s%s\n",name,out,datatype);
		 else {
		 printf("syntax error:\n");//syntax�﷨ 
	    if(error[0]==1) printf("ERROR:the first scanf should be the datatype!\n");
	    if(error[1]==1) printf("ERROR:missing ')'!\n");
	    if(error[2]==1) printf("ERROR:expected name or (dcl)!\n");
	    if(tokentype!='\n') printf("ERROR:illegal state!\n");
	 
	 
	     } 
	 
	    }
	return 0;
}

void dcl(void)//����ָ�벢���ɵݹ鴦������һ�� 
{
int ns;
for(ns=0;gettoken()=='*';ns++)
    ;
    dirdcl();//int (*c)()
    while(ns-->0)
      strcat(out,"pointer to ");
}
void dirdcl(void)//����������Ž���dcl��������������������룬 
{
	int type;
	int m;
	if(tokentype=='('){
	
	dcl();
	 if(tokentype!=')'){
	 
	 	
	 	error[1]=1;
	 }
  }
	else if(tokentype==NAME)
     strcpy(name,token);
    else {
	
	error[2]=1;
        }
     while((type=gettoken())==PARENS||type==BRACKETS)
       if(type==PARENS)	{
       	strcat(out ,"function ");
       	if(!(f==0&&lf==0)) strcat(out,"with ");
       	if(f==1)  {
		   strcat(out,function[f-1]);
		   strcat(out," ");
       	    }
       	for(m=0;m<f-2;m++)
       	   {
       	   	
   	       	strcat(out,function[m]);
   	       	strcat(out,",");
   	       	
   	       }
   	       if(m==f-2){
       	   	strcat(out,function[m]);
       	   	strcat(out," and ");
       	   	strcat(out,function[f-1]);
       	   	strcat(out," ");
       	   }
   	       f=0,lf=0;
       	 strcat(out,"returning ");       
         
       }
         else {strcat(out ,"array");
              strcat(out,token);
              strcat(out,"of ");}
		 }
int gettoken(void){
	int c;
	char *p=token;
	if(t>0) {
			strcpy(token,tokenbuf[--t]);
        	return tokentype=tokenbufp[t];
	}

	while((c=getch())==' '||c=='\t')//�����ո�� 
	          ;
	 if(c=='('){
	 	if((c=getch())!=')')
	 	 {
	 	 	while(c==' '||c=='\t')
	 	 	    c=getch();
	 	 	    if(isalpha(c)){
    	 	 		for(function[f][lf++]=c;isalpha(c=getch())||c=='*';)
    	 	 		                     function[f][lf++]=c;
    	 	 		                     function[f][lf]='\0'; 
                                      while(c==' '||c=='\t')
    	 	 		                    c=getch();
    	 	 		            while(c==',') {
    	 	 		            	lf=0,f++; 
								  c=getch(); 
								 for(function[f][lf++]=c;isalpha(c=getch())||c=='*';)
    	 	 		                     function[f][lf++]=c;
    	 	 		                   function[f][lf]='\0';  
										 while(c==' '||c=='\t')
    	 	 		                    c=getch(); 
    	 	 		                 }
    	 	 		                 f++;
    	 	 		              
    	 	 		                 if(c!=')') {
									   error[1]=1;
    	 	 		                 ungetch(c);
									   }
								   return tokentype=PARENS;
								         
    	 	 	}
		   	 else ungetch(c);
	 	    return tokentype='(';
	 	}
	 	else {
	 		strcpy(token,"()");
	 		return tokentype=PARENS;
		 }
	 	
	 }else if(c=='['){
	 
  for(*p++=c;(c=getch())&&c!=']';)
  	       *p++=c;
  	 *p++=']';
  	 *p='\0';
  	return tokentype=BRACKETS;
        }
		else if(isalpha(c))
    {
	for(*p++=c;isalnum(c=getch());)//��һ��ִֻ��һ�� ,���һ����ѭ��ĩβִ�� 
                 *p++=c;
                 *p='\0';
             ungetch(c);    
       return tokentype=NAME;
    	
	}
	else  return tokentype = c;
		
	
}
int getch(void){
	return (bufp>0)?buf[--bufp]:getchar();	
}
void ungetch(int c){
	if(bufp>=MAXLINE)
	   printf("too many!\n");
	   else buf[bufp++]=c;
}
int checkabc(void){
	int c;
	while(isspace(c=getch()))
	        ;
	  if(isalpha(c))
	      {
      		ungetch(c);
      		return 1;
      	}    
		  else {
  			ungetch(c);
  			return 0;
  		}  
	
}
void ungettoken(char *s,int p){
	if(t>=10) printf("too many datas!");
	else {
	strcpy(tokenbuf[t],s);
	tokenbufp[t++]=p;
	}
}