#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXWORD 100 
struct key{
	char *word;
	int num;
};
int getch(void);
void ungetch(int );
char buf[MAXWORD];
int bufp=0;
int getword(char *,int);
struct key *binsearch(char *,struct key*,int);
#define NKEYS (sizeof keytab/sizeof keytab[0]) 
struct key keytab[]={
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
	struct key *p;//指向结构的指针 	
	char word[MAXWORD];
	while(getword(word,MAXWORD)!=EOF)
		if(isalpha(word[0]))
		if((p=binsearch(word,keytab,NKEYS))!=NULL)
		             p->num++;
       for(p=keytab;p-keytab<NKEYS;p++)
       if(p->num>0)
	    printf("%4d %s\n",p->num,p->word);
	   getchar(); 
	   return 0;
} 
int getword(char *s,int t){
	int c;
	char *p=s;
	while(isspace(c=getch()))//跳过空格键 
	     ;
	if(isalpha(c)){
		for(*p++=c;isalnum(c=getch())&&p-s<t;*p++=c)
	       ;
	      ungetch(c); 
		 *p='\0';
		 return s[0];  	
	}
	else if(c!=EOF)
	  *p++=c;
	  *p='\0';
	  return c;
	  }
	struct key *binsearch(char *word,struct key*tab,int n)
	{
		struct key*low=&tab[0];
		struct key*high=&tab[n-1];
		struct key*mid;
		int cond;
		while(low<=high){
			mid=low+(high-low)/2;
		
			if((cond=strcmp(word,mid->word))>0)
		    low=mid+1;
		    else if(cond<0)
		     high=mid-1;
		     else return mid;
		}
		return NULL;
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