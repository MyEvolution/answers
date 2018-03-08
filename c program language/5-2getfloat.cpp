#define SIZE 10
#include<stdio.h>
#include<ctype.h>
int buf[SIZE];
int bufe=0;
int getfloat(double*);
int getch(void);
void ungetch(int c);
main(){
	double array[SIZE];
	int n;
	for(n=0;n<SIZE&&getfloat(&array[n])!=EOF;n++)
	     ;
	int i;
	for(i=0;i<n;i++)
	printf("%d %g\n",i,array[i]);    
	
}
int getfloat(double*pn){
	int c,sign;
	int d;
	double power;
	while(isspace(c=getch())) 
	   ;
	if(!isdigit(c)&&c!='-'&&c!='+'&&c!=EOF)    {
	
	   ungetch(c);return 0;}
  sign=(c=='-')?-1:1;
    if(c=='+'||c=='-'){
	d=getch();
    if(isdigit(d)) 
	    c=d;
	    else{
		  ungetch(c);
		    return 0;   }
	}
    for(*pn=0.0;isdigit(c);c=getch())
           *pn=10**pn+c-'0';
      if(c=='.') c=getch();
	for(power=1.0;isdigit(c);c=getch()){
		*pn=10**pn+c-'0';
		   power*=10;
	}       
	*pn=sign**pn/power;
	if(c!=EOF) ungetch(c);
	return c;
}
int getch(void){
	return bufe>0?buf[--bufe]:getchar();
}
void ungetch(int c){
	if(bufe>=SIZE) printf("Òç³ö\n");
	else buf[bufe++]=c;
}
