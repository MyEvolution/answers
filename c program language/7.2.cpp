#include <stdio.h>
#include <ctype.h>
#define MAXLINE    100    
#define PMAXLINE 20
main(){
	int c;
	int pos;//记录该字符为目前行的第几个
	pos=0; 
	while((c=getchar ())!=EOF)
	{   
	if(!iscntrl(c)&&c!=' '||c=='\n')
		if(c!='\n'&&pos<PMAXLINE)
		{
			putchar(c);
			pos++;
		}
		else if(c=='\n')
		{
			putchar('\n');
			pos=0;
		}
		else if(pos>=PMAXLINE)
		{
			putchar('\n');
			putchar(c);
			pos=1;
		}
	}
}
