#include<stdio.h>
#include<ctype.h>
#include"Êý×é—£.h"
#define MAXSIZE 1000 
main()
{
	Stack S;
	S=Create(MAXSIZE);
	int c;
	int e;
	while((c=getchar())!=EOF)
	{
	
		if(c=='\t'||c==' ')
		  continue;
		
		else if(isalnum(c))
		  {
		  	putchar(c);
		  	putchar(' ');
		  }
		  else
		    {
		    	
		    	if(IsEmpty(S))
		    	  Push(c,S);
		    	  else if(c=='(')
		            Push(c,S);
                  else if(c=='*'||c=='/')
                  {
                  	  while((e=Top(S))=='*'||e=='/')
                  	     {
                  	     	putchar(e);
                  	     	putchar(' ');
                  	     	Pop(S);
						   }
						   Push(c,S);
				  }
                  	
                  	else if(c=='-'||c=='+')
                  	{
                  		while((!IsEmpty(S))&&Top(S)!='(')
                  		{
						  putchar(TopAndPop(S));
                  		   putchar(' ');	
						  }
                  	  
                  	  Push(c,S);
					  }
					  else if(c==')')
                        {
                        	while((!IsEmpty(S))&&(e=Top(S))!='(')
                        	  {
                        	  	putchar(e);
                        	  	 putchar(' ');	
                        	  	Pop(S);
							  }
							  if(e!='(')
							  {
							  	printf("() is no pair!\n");
							  	MakeEmpty(S);
							  }
							else Pop(S);
										  }	
					else if(c=='\n')
					{
						while(!IsEmpty(S))
						{
							e=TopAndPop(S);
						putchar(e);
						putchar(' ');
						}
			              putchar(c);
								  }	
					}
           }
 } 
