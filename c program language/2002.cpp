#include<stdio.h>
#include<math.h>
#define PI 3.1415926
double volume(double r);
main()
{
	int c;
	char d[10];
	char *r=d;
	double b;
	while((c=getchar())!=EOF)
	   if(c!='\n')
	   *r++=c;
	   else {
	   	*r='\0';
	   	b=atof(d);
	   	printf("%.3f\n",volume(b));
	   	r=d;
	   }
	   
 } 
 double volume(double r)
 {
 	double v;
 	v=4*PI*pow(r,3)/3;
 	return v;
 }
