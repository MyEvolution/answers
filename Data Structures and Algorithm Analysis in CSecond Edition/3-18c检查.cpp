#include"数组棧.h"
#include"getch.h"
#define NOTE1 0200
#define NOTE2 0201
#define MAXSIZE 1000 
int getnote(void);
int main()
{   
	int c;
	Stack S;
	int e;
	int i;
	S=Create(MAXSIZE);
	int error[5];//错误种类 
	for(i=0;i<=4;i++)
		error[i]=0;
	while((c=getnote())!=EOF)
		switch(c)
		{
			case NOTE1:
		    case '(':
		    case '[':
		    case '{':
		    	Push(c,S);
		    	break;
		    case NOTE2:
		    	e=Top(S);
		    	if(e==NOTE1)
		    	   Pop(S);
		    	 else
		    	 {
		    	 	error[0]=1;
		    	 	error[4]=1;
				 }
				 break;
			case ')':
				e=Top(S);
				if(e=='(')
				  Pop(S);
				  else
				  {
				  	error[0]=1;
				  	error[4]=1;
				  }
				  break;
			case ']':
				 e=Top(S);
				 if(e!='[')
				 {
				error[2]=1;//2代表中括号 
				 error[4]=1;
				 }
				  else
        	       Pop(S);
				 
			      break;
			case '}':
				  e=Top(S);
				  if(e!='{')
				  {
				  	 error[3]=1;//3代表大括号 
				    error[4]=1;//4代表有没有出错 
				  }
				   else
        	       Pop(S);
		
			break;
		    default:
			break; 
		}
    if(error[4]==0&&IsEmpty(S))
	 printf("Yes!\n");
	 else
		{
			      if(error[0]==1)
				    printf("error 101:the \"/*\"and\"*/\" are not a pair!\n");
			      if(error[1]==1)
				     printf("error 102:the '()' are not a pair!\n");
				if(error[2]==1)
				    printf("error 103:the '[]' are not a pair!\n");
				if(error[3]==1)
				      printf("error 104:the '{}' are not a pair!\n");
				if(!IsEmpty(S))
					printf("error 105:I think you haven't done the scanf!\n"); 
				   }
		
		return 0; 
	
}
int getnote(void)
{
	int c;
	while((c=getch())=='\t'||c==' ')
	        ;
	    if(c=='/')
	    {
	    	if((c=getch())=='*')
	    	  return NOTE1;
	    	  else ungetch(c);
	    	  return '/';
		}
	    

		
		else if(c=='*')
		{
				if((c=getch())=='/')
				return NOTE2;
				else ungetch(c);
				return '*';				
		}	
		else
		   return c;
	   
}
