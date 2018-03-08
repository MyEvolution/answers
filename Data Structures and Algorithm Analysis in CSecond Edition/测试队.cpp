#include"数组队列.h"
#define MAXSIZE 1000
main()
{
	Queue Q;
	Q=CreateQueue(MAXSIZE);
	int n;
	int i;
	int num[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	  {
	  	scanf("%d",&num[i]);
	  	EnQueue(num[i],Q);
	  }
	  for(i=0;i<n;i++)
	  {
	  	printf("%d ",FrontAndQueue(Q));
	  }
}
