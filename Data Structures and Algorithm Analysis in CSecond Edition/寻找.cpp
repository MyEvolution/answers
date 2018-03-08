#include<stdio.h>

int main()
{
	int x,y,a;
	int i=0;
	while(scanf("%d %d %d",&x,&y,&a)!=EOF)
	{
		while(a>0)
		{
			if(i&1)
			a-=y;
			else
			a-=x;
			i++;
		}
		if(i&1)
		printf("wanshen\n");
		else printf("Light\n");
	}
 } 
