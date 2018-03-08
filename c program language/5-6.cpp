#include<stdio.h>
#include<ctype.h>

int getline(char *s){
	int c;
	char *q=s;
	while((c=getchar())&&c!=EOF&&c!='\n')
	     *s++=c;
	     *s='\0';
	   return   s-q;
		 }
int atoi(char *s){
	int num,sign;
	while(isspace(*s)) s++;
	while(!isdigit(*s)&&*s!='-'&&*s!='+')
	     s++;
	     sign=(*s=='-')?-1:1;
	  if(*s=='-'||*s=='+')
	   s++;
	   for(num=0;isdigit(*s);s++)
	     num=num*10+*s-'0';
		 return  sign*num;   
	
}


void reverse(char *s){
	char *q=s;
	while(*s!='\0') s++;
	s--;
	char temp;
	while(q!=s){
		temp=*q;
		*q=*s;
		*s=temp;
		q++,s--;
	}
}
void itoa(int n,char *s)
{ 
char *q=s;
int num;
if((num=n)<0) num=-num;
while(num){
	*s++=num%10+'0';
	*s='\0';
	 num/=10;
	
}
if(n<0)  *s++='-',*s='\0';
reverse(q);

}
/*int getop(char *s){
	while(isspace(*s=c=getch()))
	     ;
	     *++s='\0';
if(!isdigit(c))	  
   return c;
 
 
  for(isdigit(*s++=c=getch()))
        ;
        *s='\0';
  if(c!=EOF) ungetch(c);
  return NUMB;
	    
	
}*/
main(){
	char s[100];
	scanf("%s",&s);
	
	
	int b=atoi(s);
	printf("%d\n",b);
	itoa(b,s);
	printf("%s\n",s);
	reverse(s);
	printf("%s\n",s); 
}
