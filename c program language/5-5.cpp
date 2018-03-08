#include<stdio.h>

char *strncat(char *s,char *t,int n);//复制t的前n个到s尾部
 int strncmp(char*s,char*t,int n);//比较字符串的前n个 
char *strncpy(char *,char *,int);//复制t前n个到s 
main(){
	char s[100],t[100];
	scanf("%s %s",&s,&t);

printf("%s ",strncat(s,t,5));
printf("%d ",strncmp(s,t,5));
printf("%s ",strncpy(s,t,5));	
}
char *strncat(char *s,char *t,int n){
	int i=0;
	char*p=s;
	while(*s!='\0')
	       s++;
	while(i++<n&&(*s++=*t++)!='\0')
	     ;
	return p;
}
int strncmp(char *s,char *t,int n){
	int i;
for(i=0;*s==*t&&i<n;i++,s++,t++)
	    if(i==n-1) return 0;
	   return *s-*t;
}
char *strncpy(char *s,char*t,int n){
	int i;
	char *p=s;
	for(i=0;i<n;i++){
		if(*t!='\0')
		  *s++=*t++;
		  else *s++='\0';
	}
	*s='\0';
	return p;
}  

