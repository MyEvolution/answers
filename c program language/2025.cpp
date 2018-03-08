#include<stdio.h>
#include<string.h>
main()
{
	char a[100];
	int max[100];
	int m;
	int i,j;
	while(scanf("%s",a)!=EOF)
	{
		m=0;
		for(i=0;i<strlen(a);i++)
		{
		for(j=0;j<strlen(a);j++)
		if(a[i]<a[j])
		break;
		if(j==strlen(a))
		max[m++]=i;
		
			
		}
		for(i=0;i<strlen(a);i++)
		{
		for(j=0;j<m;j++)
		if(max[j]==i) break;
		printf(j==m?"%c":"%c(max)",a[i]);
			
		}
        putchar('\n');

	}
}

