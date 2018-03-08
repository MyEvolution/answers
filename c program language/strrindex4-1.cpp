#include<stdio.h>//返回字符串t在s中最右边的位置;
#include<string.h>
int strrindex(char s[],char t[]);
int getline(char s[],int lim);
int strindex(char *s,char *t);
main(){
	char line[1000];
	char t[1000];
	scanf("%s",&t);
	getchar();
	while(getline(line,1000)){
		printf("%d\n",strindex(line,t));
	}
}
int getline(char s[],int lim){
	int c;
	int i=0; 
	while(--lim>=0&&(c=getchar())!=EOF&&c!='\n'){
		s[i++]=c;
	
	}
		s[i]='\0';
       return i;

}
int strrindex(char s[],char t[]){
	int i,j,k;
	int b=-1;
	for(i=0;s[i]!='\0';i++){
		for(j=i,k=0;s[j]==t[k]&&t[k]!='\0';j++,k++)
			;
		if(k>0&&t[k]=='\0') b=i;
		
	}
	return b;
} 
int strindex(char *s,char *t){
	char *p=s;//s的初始 
	char*q=t;//t的初始 
	char *now;
	
	for(now=s;*s!='\0';s++){
	
	while(*s==*t&&*t!='\0')
		s++,t++;
	
	if(*t=='\0') return s-(t-q)-p;
	t=q;  s=++now;}
	return -1;
}
