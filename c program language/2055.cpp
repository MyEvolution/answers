#include<stdio.h>
#include<math.h>
int f(char a)
{
	if(a=='A')
	  return 1;
	if(a=='a')
	  return -1;
	else return  f(a-1)>=0?(f(a-1)+1):(f(a-1)-1);
}
main()
{
	char a;
	int b;
	int n,i;
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		scanf("%c %d",&a,&b);
		getchar();
		
		
		
    	printf("%d\n",b+f(a));	
	}

	
 } 
