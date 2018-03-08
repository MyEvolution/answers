#include<stdio.h>
#include<ctype.h> 
#include"Á´±í—£.h"
#define NUM 'n'
char buf[1000];
int bufp=0;
int getch();
void ungetch(int c);
int getnum(char *);
main()
{
	int c;
	char line[1000];
	Stack s;
	s=CreateStack();
	int e;
	while((c=getnum(line))!=EOF)
	{
	          switch(c)
		      {
		    	case NUM:
		    		Push(atof(line),s);
		    		break;
		    	case '+':
		    		Push((TopAndPop(s)+TopAndPop(s)),s);
		    		break;
		    	case '-':
		    		e=TopAndPop(s);
		    		Push((TopAndPop(s)-e),s);
		    		break;
		        case '*':
		        	Push((TopAndPop(s)*TopAndPop(s)),s);
		        	break;
		        case '/':
		        	e=TopAndPop(s);
			    	Push((TopAndPop(s)/e),s);
				   break;
				case '\n':
					printf("%g\n",TopAndPop(s));
					MakeEmpty(s);
					break;
				default:
					break;
			}
	}
}
int getch(void)
{
	return bufp==0?getchar():buf[--bufp];
}
void ungetch(int c)
{
	if(bufp<1000)
	buf[bufp++]=c;
}
int getnum(char *p)
{
	
	int f;
	char *q=p;
	int c;
	while((c=getch())==' '||c=='\t')
	          ;

	  if(isdigit(c))
	  {
	for(*q++=c;isdigit(c=getch());)
	        *q++=c;
	  if(c=='.')
	  for(*q++=c;isdigit(c=getch());)
	         *q++=c;
	         *q++='\0';
	   ungetch(c);
	   return NUM;
	  }
	  else return c;
}
