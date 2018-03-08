#include<stdio.h>//将输入中的单词按照频率降序打印出来，单词前打印频次 
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct tnode{
	int count;//出现次数 
	char *word;//指向单词的指针
	struct tnode *left;
	struct tnode *right;
};//要根据次数大小排序，所以用结构数组的形式 
struct tnode *wordtree[10000];//指向结构的指针数组，用以将二叉树重新排序 
#define MAXWORD 100 
int getword(char *,int);
int getch(void);
void ungetch(int );
void treeprint(struct tnode **);
struct tnode *addtree(struct tnode *p,char *w);
struct tnode *sorttree(struct tnode *,struct tnode *);
void swap(struct tnode **wordtree,int i,int n);
int addwordtree(struct tnode *p);
void sortwordtree(struct tnode **wordtree,int left,int right);
char buf[MAXWORD];
int bufp=0;
 void treeprint(struct tnode **p,int n);
main(){
	  int i;
	struct tnode *root=NULL;
	 char word[MAXWORD];
	 while(getword(word,MAXWORD)!=EOF)
       if(isalpha(word[0]))
       root=addtree(root,word);
     i=addwordtree(root);
      sortwordtree(wordtree,0,i-1); 
     treeprint(wordtree,i);
	 return 0;  
}
int getword(char *s,int n){
	int c;
	char *p=s;
	
	while(isspace(c=getch()))
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
struct tnode *addtree(struct tnode *p,char *w)
{    int cond;
	if(p==NULL){
		p=(struct tnode*)malloc(sizeof(struct tnode));
		p->left=p->right =NULL;
		p->count=1;
		p->word=strdup(w);
	}else if((cond=strcmp(p->word,w))==0)
		p->count ++;
	else if(cond>0)
	 p->left=addtree(p->left,w);
	 else p->right=addtree(p->right,w);
	 return p;
}
int addwordtree(struct tnode *p){
	static int i=0;
	if(p!=NULL){
		wordtree[i++]=p;
		addwordtree(p->left);
		addwordtree(p->right);
	}
   return i;
}
void sortwordtree(struct tnode **wordtree,int left,int right){
	int last;
	int i;
	if(left>=right) return ;
	swap(wordtree,left,(left+right)/2);
	last=left;
	for(i=left;i<=right;i++)
	 if(wordtree[i]->count>wordtree[left]->count)
	    swap(wordtree,++last,i);
	    swap(wordtree,left,last);
	    sortwordtree(wordtree,left,last);
	    sortwordtree(wordtree,last+1,right);
	
}
void swap(struct tnode **wordtree,int i,int n){
	char *temp;
	int tem;
 tem=wordtree[i]->count;
 wordtree[i]->count=wordtree[n]->count;
 wordtree[n]->count=tem;
 temp=wordtree[i]->word;
 wordtree[i]->word=wordtree[n]->word;
 wordtree[n]->word=temp;
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
 void treeprint(struct tnode **p,int n){
 int i=0;
 for(i=0;i<n;i++)
 	printf("%4d %s\n",p[i]->count,p[i]->word);
 }
