#include <stdio.h>

int main(void)
{
  int n;
  int i,t,p;
  while(scanf("%d",&n)!=EOF)
  {
  	p=1;
  	for(i=0;i<n;i++)
  	{
  	scanf("%d",&t);
  	getchar();
  	if(t%2!=0)//判断是不是奇数  还有个办法是if(a&1)  	scanf("%d",&t);
     
  	p*=t;
	  }

  	printf("%d\n",p);
  }

    return 0;
}

