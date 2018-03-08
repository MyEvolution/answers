#include<stdio.h>
#include<math.h>
int flower(int );
main()
{
	int m,n;
	int i,j;
	while(scanf("%d %d",&m,&n)==2)
	{
		getchar();
		j=0;
		for(i=m;i<=n;i++)
		if(flower(i))
		{
			printf("%d ",i);
			j++;
		}
		if(j==0)
		printf("no");
		
		putchar('\n');
	}
}
int flower(int num)
{
	int n=num;
	int m=0;
 while(n!=0)
 {
 	m+=pow(n%10,3);
 	n/=10;
 }
 if(m==num)
 return 1;
 else return 0;
}
