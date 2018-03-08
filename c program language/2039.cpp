#include<stdio.h>
main()
{
	int m;
	int a,b,c;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d %d %d",&a,&b,&c);
		if(a+b>c&&b+c>a&&c+a>b)
		printf("YES\n");
		else printf("NO\n");
	}
}
