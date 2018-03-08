#include<stdio.h>
#include<ctype.h>
main()
{
	int n;
	int m;
	int i,c;
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++){
		m=0;
		
	while((c=getchar())!='\n')
	   {
		if(isdigit(c))
		m++;
	  }
	printf("%d\n",m);
	}

}
