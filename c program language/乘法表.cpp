#include<stdio.h>
int main()
{
	 int i,j; 
	for(i=1;i<10;i++)
	{
		for(j=i;j<10;j++)
	  	printf("%d*%d=%-2d ",i,j,j*i);
	  	putchar('\n');
	}	    
}
