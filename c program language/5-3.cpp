#include<stdio.h>
#include<string.h>
void strcat(char *s,char *t);//��tָ����ַ������Ƶ�sָ����ַ�����β�� 
int strend(char *s,char *t);//�ж��ַ���t�Ƿ������s��β�����Ƿ���1��Ϊ0 
main(){
	char s[100],t[100];
	scanf("%s %s",&s,&t);
	strcat(s,t);
	int b=strend(s,t);
	printf("%d %s",b,s);
	
}
void strcat(char *s,char *t){
	while(*s!='\0')
	     s++;
	while(*s++=*t++)
	       ;
	       
	         
	
	
}
int strend(char *s,char *t){//5-5
	int b=strlen(s)-strlen(t);
          s=s+b;
 while(*s++==*t++)
 if(*s=='\0'&&*t=='\0')  return 1;
      return 0;
	
}
