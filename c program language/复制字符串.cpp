#include<stdio.h>
void escape(char to[],char from[]);//�����ַ������Ұѡ�/t���Ȼ��ɿɼ���ת���ַ����У� 
void iescape(char to[],char from[]);// �����ַ����ѿɼ���ת���ַ����л���ʵ���ַ��� 
main(){
	char a[100],b[100],c[100];
	int d;
	int i; 
	while((d=getchar())!=EOF){
		b[i++]=d;
	}
	b[i]='\0';
	escape(a,b);
	iescape(c,a);
	printf("%s\n",a);
	printf("%s",c);
}
void escape(char to[],char from[]){
	int i,j=0;
	for(i=0;from[i]!='\0';i++){
		
		switch(from[i]){
			case'\n':{
				to[j++]='\\';
				to[j++]='n';
				break;
			}
			case'\t':{
				to[j++]='\\';
				to[j++]='t';
				break;
			}
				default:{
					to[j++]=from[i];
					
					break;
				}
		}
		
	}
	to[j]='\0';
}
void iescape(char to[],char from[]){
		int i,j=0;
	for(i=0;from[i]!='\0';i++){
		
		switch(from[i]){
			case'\\':{
				if(from[i+1]=='n'){
				
				to[j++]='\n';
				i++;
				
		}
				else if(from[i+1]=='t'){
					
					to[j++]='\t';
					i++;
				
				}
				else {
				to[j++]=from[i];
			}
				break;
			}
			
				default:{
					to[j++]=from[i];
					
					break;
				}
		}
		
	}
	to[j]='\0';
}
