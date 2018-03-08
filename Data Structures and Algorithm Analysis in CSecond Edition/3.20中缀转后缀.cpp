#include"Êý×é—£.h"
#include<ctype.h>
#define MAXSIZE 1000
int main()
{
	int c;
	int e;
	Stack S;
	S=Create(MAXSIZE);
	while((c=getchar())!=EOF)
	{
		if(c=='\t'||c==' ')
		  continue;
		  if(isalnum(c))
		  {
            putchar(c);
		  	putchar(' ');
		  }
		  	
	   else
		switch(c)
		{
			case '(':
		        Push(c,S);
		        break;
		    case '^':
		    	 Push(c,S);
		    	 break;
		    case '*':
		    case '/':

		    	  while(!IsEmpty(S)&&((e=Top(S))=='*'||e=='/'||e=='^'))
		    	      {
		    	      	
		    	      	putchar(e);
		    	      	putchar(' ');
		    	      	Pop(S);
					  }
					  Push(c,S);
					  break;
			case '+':
			case '-':
			     while(!IsEmpty(S)&&Top(S)!='(')
				 {
                        putchar(Top(S));
                        putchar(' ');
		    	      	Pop(S);				 	
				   } 
				   Push(c,S); 
					  break;
			case ')':
			       while(Top(S)!='(')
				   {
				   	putchar(Top(S));
                        putchar(' ');
		    	      	Pop(S);
							 }
					 Pop(S);
		             break;
			case '\n':
			      while(!IsEmpty(S))
				     {
				     	putchar(TopAndPop(S));
				     	putchar(' ');
							   }	
					 putchar(c);
					 break;	  
			default:
				break;
		}
	}
}
