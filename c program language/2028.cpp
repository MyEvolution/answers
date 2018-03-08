#include<stdio.h>
int gbs(int ,int );
int main()
{
	int n;
	int x;
	int num,i;//最小公倍数 
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%d",&num);
		for(i=1;i<n;i++)
		{
	      scanf("%d",&x);
	      num=gbs(num,x);
	
		}

		printf("%d\n",num);
		
	}
	return 0;
}
int gbs(int a,int b)
{
	int i;
	for(i=a;;i+=a)
	if((i%a)==0&&(i%b)==0)
	return i;


	

}
