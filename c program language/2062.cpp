#include<stdio.h>
int f(int n)//总的集合de个数 
{
	
	if(n==1)
	  return 1;
	  else return (f(n-1)+1)*n;
}
int g(int n){
	if(n==1)
	  return 1;
	  else return f(n-1)+1;
} 
void add(int *q,int n,int m)
{
	int i;
	for(i=n-1;i<m-1;i++)
	q[i]++;
}
main()
{
	
	int n,m;
	int group[100];//第几组 
	int last;
	int i;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++)
		  group[i]=i+1;
	     last=(m+g(n)-1)/g(n);
		printf("%d",group[last-1]);
		add(group,last,n);
		while(m=(m-(last-1)*g(n)-1))
		{
			putchar(' ');
			n=n-1;
			 
			last=(m+g(n)-1)/g(n);
		printf("%d",group[last-1]);
		add(group,last,n);
			
			
			
		}
		putchar('\n');
		
	}
}
