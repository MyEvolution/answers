#include<stdio.h>
char lower(char c);//��дת��ΪСд��
main(){
	
	char c[1000];
	int i;
	scanf("%s",&c);
	for(i=0;c[i]!='\0';i++){
		c[i]=lower(c[i]);
	}
	printf("%s",c);
} 
char lower(char c){

	
	return (c>='A'&&c<='Z')?c-('A'-'a'):c;}

