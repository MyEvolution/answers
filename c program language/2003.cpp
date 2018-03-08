#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
double fan(double);
main()
{ 
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
		   printf("%.2f\n",fan(b));
		   n=num;	
		}
	}
}
double fan(double i)
{
	if(i>=0)
	return i;
	else 
	return 0-i;
}
