#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
int fan(double);
main(){
	      int c;
      char num[SIZE];
      char *n=num;
      double b;
	while((c=getchar())!=EOF)
	{
		if(c!='\n')
		*n++=c;
		else{
			*n='\0';
		   b=atof(num);
		   fan(b);
		   n=num;	
		}
	}
}
int fan(double i)
{
	if(i>=90&&i<=100)
	putchar('A');
	else if(i>=80&&i<=89)
	putchar('B');
	else if(i>=70&&i<=79)
	putchar('C');
	else if(i>=60&&i<=69)
	putchar('D');
	else if(i>=0&&i<=59)
	putchar('E');
	else printf("Score is error!");
	putchar('\n');
	return 0;
}
