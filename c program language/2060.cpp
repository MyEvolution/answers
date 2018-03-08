#include<stdio.h>
main()
{
	int n;
	scanf("%d",&n);
	int i;
	int l,p,o;
	for(i=0;i<n;i++)
	{
	scanf("%d %d %d",&l,&p,&o);
	if(l>6)
 p+=(l-6)*7+(l-6)+7+6+5+4+3+2;
		else 
		{
			int q=6-l+2;
			for(i=0;i<l;i++)
			   p+=q++;
		}

	if(p>=o)
	printf("YES\n");
	else printf("NO\n");
			
	}
	
	
}
