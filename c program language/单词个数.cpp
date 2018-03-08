#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define MAXWORD 100
struct tnode{
    char *word;//指向单词的指针 
    int count;//统计个数
    struct tnode *left;//指向左子树 
	struct tnode *right;//指向右子树 
	
};
int getch(void);
void ungetch(int );
char buf[MAXWORD];
int bufp=0;
int getword(char*,int);
struct tnode *addtree(struct tnode *,char *);
void printftree(struct tnode *);//输出树 
struct tnode *talloc(void);//为新节点分配空间 
char *strdupp(char *);
main(){
	char word[MAXWORD];
	struct tnode *root;
	root=NULL;//根结点 
	while(getword(word,MAXWORD)!=EOF)

		if(isalpha(word[0]))

	    root=addtree(root,word);
	
	  
	    
	printftree(root);
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
struct tnode *addtree(struct tnode *p,char *w)
	{   
	     int cond;
		if(p==NULL){
			p=talloc();//新结点 
			p->count=1;
			p->word=strdupp(w);
			p->left=p->right=NULL;
		}else if((cond=strcmp(w,p->word))==0)
             p->count++;
             else if(cond>0)
            p->right=addtree(p->right,w);//新单词按字典顺序较大，则放入右子树 
             else 
             p->left=addtree(p->left,w);//小,放入左子树 
             return p;
	}  
struct tnode *talloc(void){
    return (struct tnode *)malloc(sizeof(struct tnode));
}
char *strdupp(char *t)
{
   char *p; 
   p=(char *)malloc(strlen(t)+1);//之所以不用sizeod（t） 是因为会浪费多余的空间 +1存放'\0' 
   if(p!=NULL)
   strcpy(p,t);
   return p;	
}
void printftree(struct tnode *p)
{  if(p!=NULL){
	printftree(p->left);
	printf("%4d %s\n",p->count,p->word);//先打印左子树，再打印右子树 
	printftree(p->right);
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