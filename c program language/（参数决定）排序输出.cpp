#include<stdio.h>
#include<stdlib.h>//-n��ʾ����ֵΪ�Ƚϱ�׼�����-r��ʾ�������
#include<ctype.h>
#define MAXLINES 5000//�ȴ�������������
#define ALLOCSIZE 10000//-num(���֣���ʾ�ȽϺ�n���ַ�����ҳ��ʱ���ǣ� 
#define MAXLEN 1000
//�����Nλ���� 
char *lineptr[MAXLINES];
int readlines(char *line[],int nlines);
void writelines(char **,int ,void(*p)(char **,int ));
void qsort(void *lineptr[],int m,int n,int i,int p,//ָ������ָ�룬���� 
      int (*comp)(void *,void *,int i,int n));
int numcmp(char *,char *,int i,int n);
static char allocbuf[ALLOCSIZE];
static char *allocp=allocbuf;
void swap(void *v[],int i,int j);
char *alloc(int);
int getline(char*);
static char line[MAXLEN];
 int strcmp(char *s,char *t,int i,int n);
 void strcpy(char *s,char *t);
 void rewritelines(char **s,int nlines);
 void cowritelines(char **s,int nlines);
int strrcmp(char *s,char *t,int i,int n); 
int isabc(char s);
int strlen(char *s); 
main(int argc,char **argv)
{   
	int nlines;
	int c;
	int numeric=0;//��������ֵ������numeric����ֵΪ1
	int reorder=0;//�������������reorder����ֵΪ1 
	int only=0;
	int n=1;

	int (*p)(char *,char *,int,int );//�����ָ������ָ�� 
     while(--argc>0&&(*++argv)[0]=='-')
     
          while(c=*++argv[0]){
		  switch(c){
		  	case 'n':
		  		 numeric=1;
		  		 break;
		  	case 'r':
			     reorder=1;
			     break;
			case 'f':
				  numeric=2;
				  break;//������n��f���ܲ��棬�������ڣ��������ĸ���ǰһ����Ч�� 
			case 'd':
				 only=1;
				 break;
	
			default:	 
			  n=atoi(argv[0]);
		
			  break;
		  }
          	
		  }
	  if((nlines=readlines(lineptr,MAXLINES))>=0){

		  
	  	if(numeric==0) p=strcmp;
	  	else if(numeric==1) p=numcmp;
	  	else if(numeric==2) p=strrcmp;
	  	qsort((void **)lineptr,0,nlines-1,only,n,(int (*)(void *,void *,int ,int))(p));//��������Ϊǿ��ת�� 
	  	writelines(lineptr,nlines,reorder?rewritelines:cowritelines);
	  	return 0;
	  } 
	  else {
	  	printf("input too big to sort\n");
	  	return 1;
	  }
 } 
 int getline(char *line,int maxlen){ 
 	char *p=line;
 	int c;
 	while((c=getchar())!=EOF&&c!='\n'){
 		*p++=c;
 		*p='\0';
	 }
	 if(c=='\n')  *p++='\n',*p='\0';
	 return p-line;
 }
 int readlines(char *lineptr[],int maxlines){
 	int i;
 	int len;
 	while((len=getline(line,MAXLEN))>0){
 		if(i<MAXLINES&&(lineptr[i]=alloc(len))!=NULL){
 			line[len-1]='\0';
 			strcpy(lineptr[i++],line);
		 }
		 else return -1;
	 }
	 return i;
 }
 char *alloc(int n){
 	if(allocbuf+ALLOCSIZE-allocp>n)
 	{
	 allocp+=n;
 	return allocp-n;
	 }
 	return 0;
 }
 int numcmp(char *p,char *q,int i,int n){//ת������ֵ���� 
 
   	char *m,*s;
  	if(n!=0)
  	  m=p+strlen(p)-n,s=q+strlen(q)-n;
	else s=p,m=q;
 	double v1,v2;
 	v1=atof(m);
 	v2=atof(s);
 	if(v1>v2) return 1;
 	else if(v1==v2) return 0;
 	else  return -1;
 }
 void swap(void *v[],int i,int j){
 	void *temp;
 	temp=v[i];
 	v[i]=v[j];
 	v[j]=temp;
 }
 void qsort(void *lineptr[],int left,int right,int only,int n,int(*comp)(void *,void *,int,int)){
 	int last,i;
 	if(left>=right) return;
 	last=left;
 	swap(lineptr,left,(left+right)/2);
 	for(i=left+1;i<=right;i++)
 	  if((*comp)(lineptr[i],lineptr[left],only,n)<0)
 	     swap(lineptr,++last,i);
 	     swap(lineptr,left,last);
 	     qsort(lineptr,left,last,only,n,comp);
 	     qsort(lineptr,last+1,right,only,n,comp);
	   
 }
 void cowritelines(char *line[],int nlines)
 {
 	int i;
 	for(i=0;i<nlines;i++)
 	   printf("%s\n",line[i]);
  } 
  int strcmp(char *p,char *q,int i,int n){
  
  	char *s,*t;
  	if(n!=0)
  	  s=p+strlen(p)-n,t=q+strlen(q)-n;
	else s=p,t=q;
	  
  
	    
	
	       
  	if(i==0){
	  
	while(*s++==*t++)
	   if(*s=='\0'&&*t=='\0') return 0;
	 return *--s-*--t;  }
	 else if(i==1){
	 	        while(*s!='\0'&&*t!='\0'){
				 
	 		if((isdigit(*s)||isspace(*s)||isabc(*s))&&(isdigit(*t)||isspace(*t)||isabc(*t))){
			 
	 		        if(*s==*t) s++,t++;
	 		        else  return *s-*t;
	 	
	 }
	        else {
	    if(!isdigit(*s)&&!isspace(*s)&&!isabc(*s))	 s++;
	    if(!isdigit(*t)&&!isspace(*t)&&!isabc(*t))	 t++;
		}
	        
   }  
     return 0;
   }
}
void strcpy(char *s,char *t){
	while(*s++=*t++)
	    ;
}
void rewritelines(char **s,int nlines){
	int i;
	for(i=nlines-1;i>=0;i--)
	  printf("%s\n",s[i]);
}
void writelines(char **line,int nlines,void(*mom)(char **,int )){
	(*mom)(line,nlines);//��һ�������Ǳ���ģ���Ϊ�����ȼ��ϴ� 
}
int strrcmp(char *p,char *q,int i,int n){
	 	char *s,*t;
  	if(n!=0)
  	  s=p+strlen(p)-n,t=q+strlen(q)-n;
	else s=p,t=q;
	  
	char b,d;//��дת��ΪСд�Ƚ� 
	if(i==0){
	
	while(*s!='\0'&&*t!='\0'){
		if(*s==*t) s++,t++;
	else {
	if(*s>='A'&&*s<='Z') b=*s-('A'-'a'); 
	 else b=*s;
	if(*t>='A'&&*t<='Z') d=*t-('A'-'a');
	  else d=*t;
	if(d==b) s++,t++;
	else return b-d;
 		}
		 
		 }
		 }
	else if(i==1){
			while(*s!='\0'&&*t!='\0'){
		if((isdigit(*s)||isspace(*s)||isabc(*s))&&(isdigit(*t)||isspace(*t)||isabc(*t))){
		
		if(*s==*t) s++,t++;
	else {
	if(*s>='A'&&*s<='Z') b=*s-('A'-'a'); 
	 else b=*s;
	if(*t>='A'&&*t<='Z') d=*t-('A'-'a');
	  else d=*t;
	if(d==b) s++,t++;
	else return b-d;
	}}
	else {
	    if(!isdigit(*s)&&!isspace(*s)&&!isabc(*s))	 s++;
	    if(!isdigit(*t)&&!isspace(*t)&&!isabc(*t))	 t++;
		}
		}
		
	
    }
	return 0; 
	 }
int isabc(char a){
	if(a>='A'&&a<='Z'||a>='a'&&a<='z')
	  return 1;
	  else return 0;
}

int strlen(char *s){
	char *q=s;
	while(*q!='\0')
	q++;
	return q-s;
}
