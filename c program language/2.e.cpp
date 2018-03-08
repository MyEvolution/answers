#include<stdio.h>
double e(double);
main()
{
	/*int i=30;
	double p=0.0;
  for(i=1;i<=30;i++)
  p+=e((double)i);
	printf("%.10f",p);*/
	double p=1.0;
	int i=1;
	double sum=0.0;
	while(p>10e-4){
		p=e((double)i++);
		sum+=p;
	}
	printf("%.20f",sum);
	
	
}
double e(double i)//Çó½×³Ë 
{   
 
 if(i==1.0)
 return i;
 else return (1/i)*e(i-1);
    	  
	
}

