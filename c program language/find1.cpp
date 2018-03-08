//打印包含第一个参数模式的行 
#include<stdio.h>
#include<string.h>
#define MAXLEN 1000
int getline(char *line,int maxlen);
main(int argc,char **argv){
	printf("%s\n",argv[1]);
	char line[MAXLEN];//此处不能定义为指针,若为指针结果未定义，只是指针指向一串字符串常量而已 
	int found=0;
	if(argc!=2)
	
	printf("Usage:find pattern\n");
	
	else while(getline(line,MAXLEN)>0){
		if(strstr(line,argv[1])!=NULL){
		
		    printf("%s",line);
		    found++;}
	}
	return found;
}
int getline(char *line,int maxlen){
	int c;
	char *p=line;
	while((c=getchar())!=EOF&&c!='\n'&&(p-line)<maxlen)
	   *p++=c,*p='\0';
	   if(c=='\n') *p++='\n',*p='\0';
	   return p-line;
}
