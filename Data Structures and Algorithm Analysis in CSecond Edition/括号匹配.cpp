#include<stdio.h>
#include"Êý×é—£.h"
#define MAXSIZE 1000
main()
{
	int c;
	Stack S;
	S=Create(MAXSIZE);
	int error=0;
	ElemType e;
	while((c=getchar())!=EOF)
	{
	
	  switch(c)
	  {
	  	case '(':
	  	case '{':
	  	case '[':
	  		Push(c,S);
	     break;
	    case ')':
	    	e=TopAndPop(S);
	    	if(e!='(')
	       error=1;
		   break;
		case '}':
			e=TopAndPop(S);
			if(e!='{')
          error=1;	
			
			break;
		case ']':
			e=TopAndPop(S);
			if(e!='[')
		   error=1;
			break;
		case '\n':
			
			if(IsEmpty(S)&&error==0)
			  printf("Yes!\n");
			  else 
			  printf("No!\n");
			  MakeEmpty(S);
			  error=0;
			 break;
		default:
			break;
			}

	  }

	}

