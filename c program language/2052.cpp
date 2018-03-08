#include<stdio.h>
main()
{
	int wid,hei;
	int i,j;
	scanf("%d %d",&wid,&hei);
	putchar('+');
	for(i=0;i<wid;i++)
	putchar('-');
	putchar('+');
	putchar('\n');
	for(i=0;i<hei;i++)
	{
		putchar('|');
		for(j=0;j<wid;j++)
		putchar(' ');
		putchar('|');
		putchar('\n');
	}
	putchar('+');
		for(i=0;i<wid;i++)
	putchar('-');
	putchar('+');
	putchar('\n');
}
