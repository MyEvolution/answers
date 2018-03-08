#include"数组棧.h"
#include"getch.h"
#include<string.h>
#include<ctype.h>
#define BEGIN 0200//代表begin
#define END 0201//代表end 
#define MAXSIZE 1000
char word[10];
int w=0;
int getsymbol(void);
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
	
	while((c=getsymbol())!=EOF)
	{
		e=0;
        switch(c)
        {
        	case BEGIN:
        	case '(':
        	case '{':
        	case '[':
        		Push(c,S);
        		break;
        	case END:
        		e=Top(S);
        		if(e!=BEGIN)
        		{
        		   error[0]=1;//0代表begin出先错误 
        		   error[4]=1;
        	    }
        	     else
				 Pop(S);
        		   break; 	
				

			case ')':
			    e=Top(S);
				if(e!='(') 
				{
				 error[1]=1;//1代表小括号出现错误
				   error[4]=1;
				 } 
				  else
        	       Pop(S);
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
        		  
        		
		}
	        if(error[4]==0&&IsEmpty(S))
				      printf("Yes!\n");
		     else
			{
			      if(error[0]==1)
				    printf("error 101:the \"begin\"and\"end\" are not a pair!\n");
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
int getsymbol(void)
{
	
	int c;
	while((c=getch())=='\t'||c==' ')
	            ;
        if(c=='b')
        {
       for(word[w++]=c;isalpha(c=getch());word[w++]=c)
                        ;
              word[w]='\0';
              ungetch(c);
         if(!strcmp(word,"begin"))
         {
         	w=0;
         	return BEGIN;
		 }
           
           else
            word[w=0];
               
		   
		}
		else if(c=='e')
		{
		for(word[w++]=c;isalpha(c=getch());word[w++]=c)
                        ;
              word[w]='\0';
              ungetch(c);
              if(!strcmp(word,"end"))
              {
              	w=0;
              	return END;
			  }
                
                else
                return word[w=0];
		}
		else return c;
	   		
}
