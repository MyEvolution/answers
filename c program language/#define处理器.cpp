#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAXWORD 100
#define HASHSIZE 101//哈希表size
 void hashprint(struct nlist **p);
 unsigned hash(char *s);
 void undef(struct nlist **s,char *name);
  struct nlist *install(char *name,char *defp);
 struct nlist *lookup(char *s);
int getword(char *,int );
void listprint(struct nlist *); 
void hashprint(struct nlist **);
int getch(void);
void ungetch(int);
char buf[MAXWORD];
int bufp=0;
struct nlist {
	char *name;//变量名 
	char *defp;//替换文本
	struct nlist *next;//指向后继 
}; 
struct nlist *hashtab[HASHSIZE];
enum{
	NONE,
	Getname,
	Getvalue,
	Getundefn
}status;
main(){
	char word[MAXWORD];
	char name[MAXWORD];
	char defp[MAXWORD];
	status=NONE;
	struct nlist *np;
	while(getword(word,MAXWORD)!=EOF)
	{    
		if(strcmp(word,"#define")==0)
		{
			status=Getname;
			
			continue;
		}
		if(strcmp(word,"#undef")==0)
		{
			status=Getundefn;
			continue;
		}
		if(status==Getname)
		{
			strcpy(name,word);
			status=Getvalue;
			continue;
		}
		if(status==Getvalue)
		{
			strcpy(defp,word);
			np=install(name,defp);
			status=NONE;
			continue;
		}
		if(status==Getundefn)
		{
			undef(hashtab,word);
			status=NONE;
			continue;
		}
		
	}
	hashprint(hashtab);
	return 0;
}
unsigned hash(char *s)//字符串对应的散列数
{
	unsigned hashval=0;//哈希数 
	for(;*s!='\0';s++)
	hashval=*s+hashval*31;
	return hashval%HASHSIZE;
 } 
 struct nlist *lookup(char *s)//查找，找到返回指向该name的指针
 {   
  struct nlist*np;
     unsigned hashval;
	 hashval=hash(s);
	 np=hashtab[hashval]; 
	
	 for(;np!=NULL;np=np->next)
	   if(strcmp(np->name,s)==0)
	   return np;
	   return NULL;   
 }
 struct nlist *install(char *name,char *defp)
 {
 	struct nlist *np;
 	unsigned hashval=hash(name);
 	if((np=lookup(name))==NULL)
 	{
 		np=(struct nlist *)malloc(sizeof(*np));
 		if(np==NULL||(np->name=strdup(name))==NULL)
 		return NULL;
 		np->next=hashtab[hashval];
 		hashtab[hashval]=np;
 	}else 
 	  free((void*)np->defp);
 	  if((np->defp=strdup(defp))==NULL)
 	  return NULL;
 	  return np;
}
void undef(struct nlist **s,char *name){
	struct nlist *np;
	struct nlist *prev;
	unsigned hashval;
	prev=NULL;
	if((np=lookup(name))!=NULL)
	{
		hashval=hash(name);
		prev=hashtab[hashval];
		if(prev==np){//查找的元素就在表头
		 hashtab[hashval]=np->next;
		 free(np->defp);
		 free(np->name);
		 free(np); 
			
		}
		else
		{
			for(;prev->next!=np;prev=prev->next)
			        ;
			prev->next=np->next;
				 free(np->defp);
		         free(np->name);
		           free(np); 
		}
	}
	else printf("没有这个宏定义\n");
}
int getword(char *s,int n){
	int c;
	char *p=s;
	
	while(isspace(c=getch()))
	         ;
	 if(c!=EOF)
	 {
	 	for(*p++=c;isalnum(c=getch())&&p-s<=n;*p++=c)
	 	           ;
	 	     *p='\0';
		ungetch(c);
		return s[0];      
						  }	
			else 
			return c;			  		         
} 
 void hashprint(struct nlist **p)
 {
 	int i=0;
 	for(i;i<HASHSIZE;i++)
 listprint(p[i]);
 }
 void listprint(struct nlist *p){
    if(p!=NULL){
    	listprint(p->next);
    	printf("%10s %10s\n",p->name,p->defp);
	}
 }
 int getch(void)
 {
 	return bufp>0?buf[--bufp]:getchar();
 }
 void ungetch(int c){
 	if(bufp>=MAXWORD)
 	 printf("too many!");
 	 else buf[bufp++]=c;
 }
