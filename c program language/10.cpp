#include<stdio.h>
int equal(int *,int);
main()
{
	
	 
	int sugar[]={12,2,8,22,16,4,10,6,14,20};
	int n=sizeof sugar/sizeof sugar[0];
	
	int a[n];
	int m=0,i;
	while(equal(sugar,n))
	{     
		for(i=0;i<n;i++)
		  sugar[i]=a[i]=sugar[i]/2;
		  for(i=0;i<n;i++){
		  	sugar[i]+=a[i>0?i-1:n-1];
		  	if(sugar[i]%2!=0)
			  sugar[i]++; 
		  }
		 m++;  
	}
	printf("%d %d",m,sugar[0]);
}
int equal(int *p,int n)
{
	    int i;
	for(i=0;i<n;i++)
	 if(p[0]!=p[i])
	  return 1;
	  return 0;
	
}
