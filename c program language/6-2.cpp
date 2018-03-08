#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAXWORD 100
#define N 6
#define YES 1
#define NO 0
struct tnode{
	int match;//об╠Й 
	char *word;
	struct tnode *left;
	struct tnode *right;
};
int rnote(void);
char note[2];
int getch(void);
void ungetch(int );
int getword(char *,int n);
struct tnode *addtree(struct tnode *,char *,int ,int *);
void treeprint(struct tnode *);
struct tnode*talloc(void); 
int compare(struct tnode *,char *,int ,int*);
char buf[MAXWORD];
int bufp=0;
char *strdupp(char *t);
main(int argc,char **argv){
	int n;
	note[0]=note[1]=0;
	char word[MAXWORD];
   n=(--argc>0&&(*++argv)[0]=='-')?atoi(argv[0]+1):N;
	struct tnode *root;
	root=NULL;
	int found;
	while(getword(word,MAXWORD)!=EOF){
		found=NO;
		if(isalpha(word[0])&&strlen(word)>=n)
       root=addtree(root,word,n,&found);
	}
	    
	
	treeprint(root);
	getchar();
	return 0;
}
int getword(char *s,int n)
{
	int c;
	char *p=s;
	while(isspace(c=getch()))
	      ;
	      if(c=='"'){
	      	for(*p++=c;(c=getch())!='"';)
	           ;
	          *p='\0';
			  return '"'; 
		  }else if(c=='/'){
		  	*p++=c;
			  *p='\0';
		  	if((c=getch())=='/')
		  	while(c!='\n')
		  	     c=getch();
		  	     else if(c=='*'){ 
		  	     while((n=rnote())!=2)
		  	     	for(n;n<=1;n++)
		  	     	   note[n]=getch();
		  	     	  note[0]=note[1]=0; 
				 return '/';
				  } 
		  }else if(isalpha(c)){
		  for(*p++=c;isalnum(c=getch());*p++=c)
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
struct tnode *addtree(struct tnode *p,char *w,int num,int *found)
{    int cond;
	if(p==NULL){
		p=talloc();
		p->right=p->left=NULL;
		p->match=*found;
		p->word=strdup(w);	
	}else if((cond=compare(p,w,num,found))>0)
	p->left=addtree(p->left,w,num,found);
	else if(cond<0)
	p->right = addtree(p->right,w,num,found);
	return p;
}
int compare(struct tnode *p,char *t,int num,int*found)
{         char *s=p->word;
           int i;
     for(i=0;*s==*t;i++,t++,s++)
     if(*s=='\0') return 0;
     if(i>=num){
     	p->match=YES;
     	*found=YES;
     }
     return *s-*t;
}
void treeprint(struct tnode *p)
{
	if(p!=NULL){
		treeprint(p->left);
		if(p->match)
		printf("%s\n",p->word);
		treeprint(p->right);
	}
}
struct tnode*talloc(void)
{
	return (struct tnode*)malloc(sizeof(struct tnode));
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
