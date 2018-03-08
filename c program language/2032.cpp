#include<stdio.h>
#define MAX 30//还以三角形输出了 
int san[MAX][MAX];
void YangH(int );
main()
{
	int n,i,j;
	int m;
	while(scanf("%d",&n)!=EOF)
	{
		YangH(n);
		for(i=0;i<n;i++)
		{
			for(m=0;m<n-i-1;m++)
				printf("  ");
		
		for(j=1;j<=i+1;j++)
		

		printf(j==(i+1)?"%2d\n":"%2d  ",san[i][j]);
		
		}

	putchar('\n');	
	}
}
void YangH(int n)
{
	int i,j;
	san[0][1]=1;
	if(n>1)
	for(j=1;j<n;j++)
	for(i=1;i<=n;i++)
	san[j][i]=san[j-1][i-1]+san[j-1][i];
}
