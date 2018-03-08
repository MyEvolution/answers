#include<stdio.h>
main()
{
	int n;
	int num[100];
	int temp;
	int n1,i,min;
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%d",&num[0]);
		min=num[0];
		n1=0;
		for(i=1;i<n;i++)
		{
		
		scanf("%d",&num[i]);
		if(num[i]<min){
			min=num[i];
		n1=i;
		}
		
		}
    temp=num[n1];
    num[n1]=num[0];
    num[0]=temp;
    for(i=0;i<n;i++)
    printf(i==(n-1)?"%d":"%d ",num[i]);
    putchar('\n');
		
	}
}
