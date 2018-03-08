#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define MAXWORD 100
#define N (sizeof form/sizeof form[0])
struct linelist{
	int line;//�к� 
	struct linelist *next;//ָ����һ�� 
};
struct wordtree{
	char *word;
	struct linelist *firstline;//ָ���һ�γ��ֵ��� 
	struct linelist *lastline;//ָ��� 
	struct wordtree *left;//ָ�������� 
	struct wordtree *right; //ָ�������� 
}; 
void printlist(struct linelist *);
int getch(void);
void ungetch(int );
int getword(char *,int n);
struct wordtree*addwordtree(struct wordtree*,char *,int );
void treeprint(struct wordtree *);
struct linelist *addlink(int );
int binsearch(char *,int );
char buf[MAXWORD];
int bufp=0;
char *form[]={
	   "I",//�۰���� �����������У�����д��asciiС��Сд�� 
	   "a", 
	   "an",     
	   "and", 
	   "am",
	   "are",    
	   "be",    
	   "but",     
	   "by",     
	   "he",     
	   "i",     
	   "is",     
	   "it",     
	   "off",     
	   "on",     
	   "she",     
	   "so",     
	   "the",     
	   "they",     
	   "you"
	   
};
main(){
	   int line=1;
	   struct wordtree *root;//����� 
	   root=NULL;
	   char word[MAXWORD];
	while(getword(word,MAXWORD)!=EOF){
		if(word[0]=='\n')
	        line++;
		if(isalpha(word[0])&&binsearch(word,N)==-1)//����word���ڷ�ʵ�ⵥ��֮�� 

	      root=addwordtree(root,word,line);
	
	}
        treeprint(root);
	return 0;
}
struct linelist *addlink(int line){
	struct linelist *new1=(struct linelist*)malloc(sizeof(struct linelist));
	if(new1!=NULL){
		new1->line=line;
		new1->next=NULL;
		
	}
   return new1;
}
struct wordtree*addwordtree(struct wordtree *p,char *w,int line)
{     int cond;
	if(p==NULL){
		p=(struct wordtree*)malloc(sizeof(struct wordtree));
		p->word=strdup(w);
		p->lastline=p->firstline=addlink(line);
		
		p->left=p->right=NULL;
	}else if((cond=strcmp(p->word,w))==0&&line!=p->lastline->line){
	     p->lastline->next=addlink(line);
	     p->lastline=p->lastline->next;
	     
	}
	
		else if(cond>0)
		p->left=addwordtree(p->left,w,line);
		else if(cond<0)p->right=addwordtree(p->right,w,line);
		return p;	
}
int getword(char *s,int n){
	int c;
	char *p=s;
	while((c=getch())==' '||c=='\t')//��Ҫ�ûس��������У����Բ������� 
	         ;
	 if(isalpha(c)){
  		for(*p++=c;isalpha(c=getch())&&p-s<n;*p++=c)
	              ;
	   *p='\0';
	   ungetch(c);
	   return s[0];
   }else if(c!=EOF)
  	  *p++=c;
  	  *p='\0';
  	  return c;				         
}
int binsearch(char *s,int n)
{     
   int low,high,mid,cond;
   low=0;
   high=n-1;
   while(low<=high)
   {
   	mid=(low+high)/2;
   	if((cond=strcmp(s,form[mid]))>0)
   	 low=mid+1;
   	else if(cond<0)
   	 high=mid-1;
   	 else 
		return mid;
   }
    return -1;	
}
void treeprint(struct wordtree*p)
{
	 
	if(p!=NULL){
		
		treeprint(p->left);
		printf("%10s ",p->word);
	     printlist(p->firstline);
	     printf("\n");
		treeprint(p->right);
	}
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
 void printlist(struct linelist *p){
 	if(p!=NULL){
	 
 	
 	printf("%d ",p->line);
 	printlist(p->next);
	 }
 	
 }
