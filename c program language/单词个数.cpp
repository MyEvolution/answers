#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define MAXWORD 100
struct tnode{
    char *word;//ָ�򵥴ʵ�ָ�� 
    int count;//ͳ�Ƹ���
    struct tnode *left;//ָ�������� 
	struct tnode *right;//ָ�������� 
	
};
int getch(void);
void ungetch(int );
char buf[MAXWORD];
int bufp=0;
int getword(char*,int);
struct tnode *addtree(struct tnode *,char *);
void printftree(struct tnode *);//����� 
struct tnode *talloc(void);//Ϊ�½ڵ����ռ� 
char *strdupp(char *);
main(){
	char word[MAXWORD];
	struct tnode *root;
	root=NULL;//����� 
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
	while(isspace(c=getch()))//�����ո�� 
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
			p=talloc();//�½�� 
			p->count=1;
			p->word=strdupp(w);
			p->left=p->right=NULL;
		}else if((cond=strcmp(w,p->word))==0)
             p->count++;
             else if(cond>0)
            p->right=addtree(p->right,w);//�µ��ʰ��ֵ�˳��ϴ������������ 
             else 
             p->left=addtree(p->left,w);//С,���������� 
             return p;
	}  
struct tnode *talloc(void){
    return (struct tnode *)malloc(sizeof(struct tnode));
}
char *strdupp(char *t)
{
   char *p; 
   p=(char *)malloc(strlen(t)+1);//֮���Բ���sizeod��t�� ����Ϊ���˷Ѷ���Ŀռ� +1���'\0' 
   if(p!=NULL)
   strcpy(p,t);
   return p;	
}
void printftree(struct tnode *p)
{  if(p!=NULL){
	printftree(p->left);
	printf("%4d %s\n",p->count,p->word);//�ȴ�ӡ���������ٴ�ӡ������ 
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