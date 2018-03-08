#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#define MAXWORD 100 
int getword(char *,int);
int binsearch(char*,struct key*,int);//折半查找 
int getch(void);
void ungetch(int );
char buf[MAXWORD];
int bufp=0;
#define NKEYS (sizeof keytab/sizeof (struct key)) 
char note[2];
int rnote(void);
void untiln(void);
struct key{
	char *word;
	int num;
}keytab[]={
	{"auto",0},
	{"break",0},
	{"case",0},
	{"char",0},
	{"const",0},
	{"continue",0},
	{"default",0},
	{"do",0},
	{"double",0},
	{"else",0},
	{"enum",0},
	{"extern",0},
	{"float",0},
	{"for",0},
	{"goto",0},
	{"if",0},
	{"int",0},
	{"long",0},
	{"register",0},
	{"return",0},
	{"short",0},
	{"signed",0},
	{"sizeof",0},
	{"static",0},
    {"struct",0},
    {"switch",0},
    {"typedef",0},
    {"union",0},
    {"unsigned",0},
    {"void",0},
    {"volatite",0},
    {"while",0}
	
		
	
};
main(){
	note[0]=note[1]=0;
	char word[MAXWORD];
	int c;
	int i,n;
    
	while(getword(word,MAXWORD)!=EOF)

		if(isalpha(word[0]))
		 if((n=binsearch(word,keytab,NKEYS))>=0)
		     keytab[n].num++;
		    
		for(i=0;i<NKEYS;i++)
		if(keytab[i].num>0)
		printf("%4d:%s\n",keytab[i].num,keytab[i].word);
		getchar();
	return 0;
}
int getword(char *s,int t){
	int n;
	int c;
	char *p=s;
	while(isspace(c=getch()))//因为不用回车控制输入，所以跳过即可 
	           ;
         if(isalpha(c)||c=='_'){
         	for(*p++=c;isalnum(c=getch())&&p-s<t;*p++=c)
         	           ;
         	           *p='\0';
         	        ungetch(c);      
        	
         }
         else if(c=='"'){
         	for(*p++='"';(c=getch())!='"'&&c!='\n';)
         	             ;
         	       *p='\0';      
         	return '"';
         }
         else if(c=='#'){
        	*p='#';
        	untiln();
        	return '#';
         }
         else if(c=='/'){
         	c=getch();
         	*p++='/',*p='\0';
         	if(c!='*'&&c!='/')
         	  ungetch(c);
			 
         	  else if(c=='/')
  	         	for(;(c=getch())!='\n';)
         	        ;
         	        
  	        else if(c=='*')
              while((n=rnote())<2)
            {    for(n;n<=1;n++)
            	note[n]=getch();
            }
	         	return '/';
	         
         }
        	 
       else if(c!=EOF)   
            *p++=c;
            *p='\0';
            return c;
         
               
	      
   }
   int binsearch(char *word,struct key*kentab,int n)
   {
   	int low,high,mid;
   	low=0;
   	high=n-1;
   	
   	while(low<=high)
   	{
	   mid=(low+high)/2;
	   	if(strcmp(word,kentab[mid].word)>0){
	   		
	   		low=mid+1;
	   	}
	   	else if(strcmp(word,kentab[mid].word)<0)
	   	    high=mid-1;
	   	    else return mid;
	   }
	   return -1;//表示没有找到 
   }
  int getch(void)
  {
  	return bufp>0?buf[--bufp]:getchar();
  }    
 void ungetch(int c){
 	if(bufp>=MAXWORD)
 	   printf("too many!\n");
 	   else buf[bufp++]=c;
 	
 }
void untiln(void)
{
	int c;
	
	while((c=getch())!='\n')
	     if(c=='\\') {
     		while((c=getch())=='\n')
     		           ;
             untiln();    
     	}
	     
}
int rnote(void)
{
	
	if(note[1]=='*'){
		note[0]='*';
	     return 1;
	}
	   
	   else if(note[1]=='/'&&note[0]=='*')
	      return 2;
	     else return 0;
}