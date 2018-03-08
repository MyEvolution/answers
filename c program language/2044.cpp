#include <stdio.h>
int way(int n ,int m)
{
	if(m-n<=2)
	 return m-n;
	 else return way(n,m-1)+way(n,m-2);
}
main()
{
	int n;
	int x,y;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d",&x,&y);
		printf("%d\n",way(x,y));
		
	}
}
