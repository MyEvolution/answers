#define ALLOCSIZE 10000
#include<stdio.h>
static char allocbuf[ALLOCSIZE];//alloc的储存区 
static char *allocp=allocbuf;//下一个空闲位置 
int strcmp(char *s,char *t);
char * alloc(int n){
	if(allocbuf+ALLOCSIZE-allocp>=n){
		allocp+=n;
		return allocp-n;
	}
	else return 0;
}
void afree(char *p){
	if(p>=allocbuf&&p<allocbuf+ALLOCSIZE)//allocbuf相当于allocbuf[0]; 
	allocp=p;
}
main(){
	char s[100],t[100];
	scanf("%s %s",&s,&t);
	int b=strcmp(s,t);
	printf("alloc and afree()%d",b);
}
void strcpy(char *s,char *t){
	int i;
	i=0;
	for(i;(s[i]=t[i])!='\0';i++)
	     ;
}
void sstrcpy(char *s,char *t){
	
while(*s++=*t++)
     ;
}
int sstrcmp(char *s,char *t){
	int i;
	for(i=0;s[i]==t[i];i++)
if(s[i]=='\0')    return 0;
    return s[i]-t[i];       
	
}
int strcmp(char *s,char *t){
	while(*s++==*t++)
	   if(*s=='\0') return 0;
	 return *s-*t;  
}
