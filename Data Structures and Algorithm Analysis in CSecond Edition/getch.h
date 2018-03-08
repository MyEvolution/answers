#include<stdio.h>
#define BUFSIZE 1000
typedef int ElemType;
ElemType buf[BUFSIZE];
int bufp=0;
int getch(void);
void ungetch(int c);


ElemType getch(void)
{
	return bufp>0?buf[--bufp]:getchar();
}
void ungetch(int c)
{
	if(bufp>=BUFSIZ)
	printf("the buf is full!\n");
	else 
	  buf[bufp++]=c;
}
