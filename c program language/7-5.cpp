#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define MAXLEN 100
float val[MAXLEN];
float pop(void);
void push(float );
void clear(int *);
int i;
main(){
	printf("��������ȷ���沨��ʽ�����������'�ո�+#'�Խ����ó��������\n");
	int m;
	char s[MAXLEN];
	while(scanf("%s",s)==1)
	{    
		if(isdigit(s[0]))
		push(atof(s));
		else 
		switch(s[0])
		{
			case '+':
				push(pop()+pop());
				break;
			case '*':
			    push(pop()*pop());
				break;
			case '-':
			    m=pop();
				push(pop()-m);
				break;
			case '/':
			    m=pop();
				if(m!=0)
				 push(pop()/m);
				 else
				 {
				 printf("����Ϊ0��\n");
				 clear(&i);
							 }
				break;
			case '#':
			    
			    	printf("%g\n",pop());
			    	clear(&i);
			    	
				   break;
			default :
			    printf("δ֪����!\n");
				break;				 			
		}
	}
	
	
}
float pop(void)
{
	return val[--i];
}
void push(float c)
{
	if(i<MAXLEN)
	val[i++]=c;
	else printf("������\n");
}
void clear(int *i)
{
	i=0;
}
