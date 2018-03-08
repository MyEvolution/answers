#include<stdio.h>
#include<math.h>
/*main()
{
	int n;
	int i;
	int count;
	while(scanf("%d",&n)!=EOF)
	{
		count=0;
		for(i=1;i<=n;i++)
		if(n%i==0) count++;
		if(count&1) printf("%d\n",1);
		else printf("%d\n",0);
	}
}*/
main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if((int)sqrt(n)==sqrt(n))
		printf("1\n");
		else printf("0\n");
	}
	
}
