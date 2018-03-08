#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXLEN 1000
#define MAXLINE 100
#define N 10
#define ALLOCSIZE 10000
static char *lines[MAXLINE];
static char line[MAXLEN];//每行最长长度 
static char allocbuf[ALLOCSIZE];
static char *allocp=allocbuf;
char *alloc(int n);
int getline(char *line);
int readlines(char *lines[]);
void writelines(char *lines[],int m,int n);
main(int argc,char **argv){
	int lie;//列数 
	if(argc<=1) 
	while((lie=readlines(lines))>0)
		writelines(lines,lie,N);
	else if((*++argv)[0]=='-'){
		if(isdigit(argv[0][1]))
			while((lie=readlines(lines))>0)
		   writelines(lines,lie,-atoi(argv[0]));
		   else {printf("illegal pattern!\n");
		   return -1;
		   
		   }
	}
	else {
	
	printf("illegal pattern!\n");
		   return -1;
		   
		   }
}
char *alloc(int n){
	if(allocbuf+ALLOCSIZE-allocp>n)
	   allocp+=n;
	   return allocp-n;
	
}
int getline(char *line,int maxlen){
	char *p=line;
	int c;
	while((c=getchar())!=EOF&&c!='\n'&&(p-line)<maxlen)
	   *p++=c,*p='\0';
	 if(c=='\n') *p++=c,*p='\0';
	 return p-line;  
}
int readlines(char *lines[]){
	int i=0;
	int len;
	while((len=getline(line,MAXLEN))>0){
		
	if((lines[i]=alloc(len))!=NULL&&i<MAXLINE){
	
	   
	   line[len-1]='\0';
		
		strcpy(lines[i++],line);
		}
		else {
		printf("too many datas!\n");
		    return -1;
			}
	}
	return i;
	
}
void writelines(char *lines[],int m,int n){
	int j;
	if(m<=n)
	for(j=0;j<m;j++)
	printf("%s\n",lines[j]);
	else 
	for(j=m-n;j<m;j++)
	printf("%s\n",lines[j]);
		
	
}
