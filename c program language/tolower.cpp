#include<stdio.h>
#include<ctype.h>
void wtolower(char *);
main(){//�ó����Сд��Ϊ��д 
	char s[100];
	scanf("%s",&s);
     wtolower(s);
	printf(s);
}
void wtolower(char *p)
{

while(*p!='\0'){
if(*p>='a'&&*p<='z')
*p+='A'-'a';
p++;
}

}
